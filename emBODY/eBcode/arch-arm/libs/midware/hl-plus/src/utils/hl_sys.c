/*
 * Copyright (C) 2013 iCub Facility - Istituto Italiano di Tecnologia
 * Author:  Marco Accame
 * email:   marco.accame@iit.it
 * website: www.robotcub.org
 * Permission is granted to copy, distribute, and/or modify this program
 * under the terms of the GNU General Public License, version 2 or any
 * later version published by the Free Software Foundation.
 *
 * A copy of the license can be found at
 * http://www.robotcub.org/icub/license/gpl.txt
 *
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General
 * Public License for more details
*/


/* @file       hl_sys.c
	@brief      This file contains internal implementation of the hl sys utilities.
	@author     marco.accame@iit.it
    @date       10/21/2013
**/


// - modules to be built: contains the HL_USE_* macros ----------------------------------------------------------------

#include "hl_cfg_plus_modules.h"

#if     defined(HL_USE_UTIL_SYS)

// --------------------------------------------------------------------------------------------------------------------
// - external dependencies
// --------------------------------------------------------------------------------------------------------------------

#include "stdlib.h"
#include "string.h"


#include "hl_core.h"


extern uint32_t SystemCoreClock;
 
// --------------------------------------------------------------------------------------------------------------------
// - declaration of extern public interface
// --------------------------------------------------------------------------------------------------------------------

#include "hl_sys.h"



// --------------------------------------------------------------------------------------------------------------------
// - declaration of extern hidden interface 
// --------------------------------------------------------------------------------------------------------------------

#include "hl_sys_hid.h"


// --------------------------------------------------------------------------------------------------------------------
// - #define with internal scope
// --------------------------------------------------------------------------------------------------------------------
// empty-section


// --------------------------------------------------------------------------------------------------------------------
// - definition (and initialisation) of extern variables, but better using _get(), _set() 
// --------------------------------------------------------------------------------------------------------------------
// empty-section



// --------------------------------------------------------------------------------------------------------------------
// - typedef with internal scope
// --------------------------------------------------------------------------------------------------------------------
// empty-section


// --------------------------------------------------------------------------------------------------------------------
// - declaration of static functions
// --------------------------------------------------------------------------------------------------------------------

//static uint8_t s_hl_sys_howmanyARMv7ops(void);


// --------------------------------------------------------------------------------------------------------------------
// - definition (and initialisation) of static const variables
// --------------------------------------------------------------------------------------------------------------------
// empty-section


// --------------------------------------------------------------------------------------------------------------------
// - definition (and initialisation) of static variables
// --------------------------------------------------------------------------------------------------------------------
// empty-section


// --------------------------------------------------------------------------------------------------------------------
// - definition of __asm functions
// --------------------------------------------------------------------------------------------------------------------

__asm static int s_hl_sys_asm_getstacksize (void) {
        IMPORT  Stack_Size
        LDR     R0,=Stack_Size
        BX      LR
}


__asm static int s_hl_sys_asm_getheapsize (void) {
        IMPORT  Heap_Size
        LDR     R0,=Heap_Size
        BX      LR
}

// it should use 4 cycles per iteration: subs 1, and bne 3. however, we have 1.25 gain of cortex, and access to flash whcih may slows it.
__asm static void s_hl_sys_asm_xnumARMv7ops(uint32_t numberof) 
{
   align
dowaitloop
   subs r0,r0,#1
   bne dowaitloop
   bx lr 
   align    
}

// --------------------------------------------------------------------------------------------------------------------
// - definition of extern public functions
// --------------------------------------------------------------------------------------------------------------------


extern uint32_t hl_sys_stack_totalsize_get(void)
{
    return(s_hl_sys_asm_getstacksize());   
}


extern uint32_t hl_sys_heap_totalsize_get(void)
{
    return(s_hl_sys_asm_getheapsize());   
}

__weak extern void* hl_sys_heap_new(uint32_t size)
{
    return(calloc(size, 1));    
}


__weak extern void hl_sys_heap_delete(void* p)
{
    free(p);
}

#if 0
extern hl_result_t hl_sys_delay(hl_reltime_t reltime)
{
    static uint32_t s_hl_sys_numofops1usec = 0;
    if(0 == s_hl_sys_numofops1usec)
    {
        if(0 == SystemCoreClock)
        {
            return(hl_res_NOK_generic);
        }
        // to occupy a microsec i execute an operation for a number of times which depends on: SystemCoreCloc and 1.25 dmips/mhz, 
        //s_hl_sys_numofinstructions1usec = ((SystemCoreClock/1000000) * 125l) / 100l;
        s_hl_sys_numofops1usec = (SystemCoreClock/1000000) / s_hl_sys_howmanyARMv7ops();

    }
        
    s_hl_sys_asm_someARMv7ops(s_hl_sys_numofops1usec * reltime);

    return(hl_res_OK);
}
#else

extern hl_result_t hl_sys_delay(hl_reltime_t reltime)
{
    static uint64_t s_hl_sys_numofops1sec = 0;
    if(0 == s_hl_sys_numofops1sec)
    {
        if(0 == SystemCoreClock)
        {
            return(hl_res_NOK_generic);
        }
        // to occupy a millisec i execute an operation for a number of times which depends on: 
        // SystemCoreClock, cortex gain(1.25 dmips/mhz), flash access, etc.
        // to overcome all this i just consider SystemCoreClock w/out 1.25 gain and i measures
        // extra gain with on a simple assembly function which should take 4 cycles per iteration (?).      
        //s_hl_sys_numofops1sec = (5*(SystemCoreClock)) / 4; 
        s_hl_sys_numofops1sec = (1*(SystemCoreClock)) / 1;
       
#if     defined(HL_USE_MPU_NAME_STM32F103RB)
        s_hl_sys_numofops1sec /= 6;             // 2 wait states, prefetching enabled.      
#elif   defined(HL_USE_MPU_NAME_STM32F107VC)
        s_hl_sys_numofops1sec /= 6;             // 2 wait states, prefetching enabled.        
#elif   defined(HL_USE_MPU_NAME_STM32F407IG)
        s_hl_sys_numofops1sec /= 3;             // 5 wait states, art technology enabled    
#else //defined(HL_USE_MPU_NAME_*)
    #error ERROR --> choose a HL_USE_MPU_NAME_*
#endif         
    }
    
    
    volatile uint64_t num = s_hl_sys_numofops1sec * reltime;
    num /= 1000000; 
//    num -= 40; //we may remove some cycles to compensates for previous instructions, but ... we dont do it.   
//__disable_irq();    
    s_hl_sys_asm_xnumARMv7ops((uint32_t)num);
//__enable_irq();
    return(hl_res_OK);
}

#endif


extern hl_result_t hl_sys_systemreset(void) 
{
    NVIC_SystemReset();   
    return(hl_res_NOK_generic);
}


extern void hl_sys_irq_disable(void) 
{
    __disable_irq();
}    


extern void hl_sys_irq_enable(void) 
{
     __enable_irq();    
}


extern void hl_sys_irqn_disable(hl_irqn_t irqn) 
{
    NVIC_DisableIRQ((IRQn_Type)irqn);
}    


extern void hl_sys_irqn_enable(hl_irqn_t irqn) 
{
     NVIC_EnableIRQ((IRQn_Type)irqn);    
}  

extern void hl_sys_irqn_priority_set(hl_irqn_t irqn, hl_irqpriority_t prio) 
{
#if     !defined(HL_BEH_REMOVE_RUNTIME_PARAM_CHECK)     
    if(hl_irqpriorityNONE == prio)
    {
        return;
    }
#endif  
    
    NVIC_SetPriority((IRQn_Type)irqn, prio);    
} 

extern hl_irqpriority_t hl_sys_irqn_priority_get(hl_irqn_t irqn) 
{
    return((hl_irqpriority_t)NVIC_GetPriority((IRQn_Type)irqn));    
}


extern int hl_sys_itm_puts(const char* str) 
{    
#if     !defined(HL_BEH_REMOVE_RUNTIME_PARAM_CHECK)     
    if(NULL == str)
    {
        return(0);
    }
#endif 
    
    uint32_t ch;
    int num = 0;
    while('\0' != (ch = *str))
    {
        ITM_SendChar(ch);
        str++;
        num++;
    }
     
    ITM_SendChar('\n');
    return(++num);    
}


__weak extern void hl_sys_on_warning(const char * warningmsg)
{
    hl_sys_itm_puts(warningmsg);
    for(;;);
}

__weak extern void hl_sys_on_error(hl_errorcode_t errorcode, const char * errormsg)
{
    errorcode = errorcode;
    hl_sys_itm_puts(errormsg);
    for(;;);
}

// --------------------------------------------------------------------------------------------------------------------
// - definition of extern hidden functions 
// --------------------------------------------------------------------------------------------------------------------

// ---- isr of the module: begin ----
// empty-section
// ---- isr of the module: end ------



// --------------------------------------------------------------------------------------------------------------------
// - definition of static functions 
// --------------------------------------------------------------------------------------------------------------------

// static uint8_t s_hl_sys_howmanyARMv7ops(void)
// {
// #if     defined(HL_USE_MPU_ARCH_STM32F1)
//     //return(3+3);
//     return(3+3+3);      // number seems to be rather empirical. can anybody help me finding a rule?
// #elif   defined(HL_USE_MPU_ARCH_STM32F4)
//     //return(3+1);
//     return 3;
// #else //defined(HL_USE_MPU_ARCH_*)
//     #error ERROR --> choose a HL_USE_MPU_ARCH_*
// #endif  
// }


#endif//defined(HL_USE_UTIL_SYS)

// --------------------------------------------------------------------------------------------------------------------
// - end-of-file (leave a blank line after)
// --------------------------------------------------------------------------------------------------------------------





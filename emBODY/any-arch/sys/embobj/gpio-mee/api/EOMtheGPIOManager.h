/*
 * Copyright (C) 2011 Department of Robotics Brain and Cognitive Sciences - Istituto Italiano di Tecnologia
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

// - include guard ----------------------------------------------------------------------------------------------------
#ifndef _EOMTHEGPIOMANAGER_H_
#define _EOMTHEGPIOMANAGER_H_

#ifdef __cplusplus
extern "C" {
#endif

/** @file       EOMtheGPIOManager.h
    @brief      This header file implements public interface to the GPIO manager singleton for the MEE
    @author     marco.accame@iit.it
    @date       08/25/2011
**/

/** @defgroup eom_thegpiomanager Singleton EOMtheGPIOManager
    The EOMtheGPIOManager is a type derived from #EOtheGPIOManager and allows management of GPIOs
    in a multi-tasking execution environment MEE.
    
    @{        
 **/


// - external dependencies --------------------------------------------------------------------------------------------

#include "EoCommon.h"
#include "EOtheGPIO.h"

// - public #define  --------------------------------------------------------------------------------------------------
// empty-section
  

// - declaration of public user-defined types ------------------------------------------------------------------------- 
 

/** @typedef    typedef struct EOMtheGPIOManager_hid EOMtheGPIOManager
    @brief      EOMtheGPIOManager is an opaque struct. It is used to implement data abstraction for the GPIO manager 
                object so that the user cannot see its private fields and he/she is forced to manipulate the
                object only with the proper public functions. 
 **/  
typedef struct EOMtheGPIOManager_hid EOMtheGPIOManager;



/**	@typedef    typedef struct eOmgpioman_cfg_t 
 	@brief      Contains the configuration for the eOmgpioman_cfg_t. 
 **/ 
typedef struct
{
    uint8_t             priority;           /**< The priority of the worker task */
    uint16_t            stacksize;          /**< The stack size of the worker task */
    eOreltime_t         period;             /**< The execution period of the worker task in microsec */
} eOmgpioman_cfg_t;

    
// - declaration of extern public variables, ... but better using use _get/_set instead -------------------------------

extern const eOmgpioman_cfg_t eom_gpioman_DefaultCfg; // = {200, 512, 10000};


// - declaration of extern public functions ---------------------------------------------------------------------------
 
 
 
/** @fn         extern EOMtheGPIOManager * eom_gpioman_Initialise(EOtheGPIO *thegpio, const eOmgpioman_cfg_t *gpiomancfg)
    @brief      Initialises the singleton gpio manager for the MEE.
    @arg        thegpio         The EOtheGPIO singleton which we want to manage.
    @arg        gpiomancfg      The configuration. If NULL, then it is used eom_gpioman_DefaultCfg.
    @return     The EOMtheGPIOManager singleton. If any problem, the #EOtheErrorManager issues a fatal error.
 **/
extern EOMtheGPIOManager * eom_gpioman_Initialise(EOtheGPIO *thegpio, const eOmgpioman_cfg_t *gpiomancfg); 


/** @fn         extern EOMtheGPIOManager * eom_gpioman_GetHandle(void)
    @brief      Gets the initialised singleton.
    @return     The EOMtheGPIOManager singleton or NULL
 **/
extern EOMtheGPIOManager * eom_gpioman_GetHandle(void); 
 

/** @}            
    end of group eom_thegpiomanager  
 **/

#ifdef __cplusplus
}       // closing brace for extern "C"
#endif 

#endif  // include-guard


// - end-of-file (leave a blank line after)----------------------------------------------------------------------------




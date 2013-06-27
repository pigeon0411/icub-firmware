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

/* @file       EoProtocolEPmn_rom.c
    @brief      This file keeps ....
    @author     marco.accame@iit.it
    @date       06/06/2013
**/


// --------------------------------------------------------------------------------------------------------------------
// - external dependencies
// --------------------------------------------------------------------------------------------------------------------

#include "stdlib.h" 
#include "string.h"
#include "stdio.h"

#include "EoCommon.h"
#include "EOnv_hid.h"
#include "EOconstvector_hid.h"


#include "EoManagement.h"
#include "EoProtocolEPmn.h"
#include "EoProtocolEPmn_fun.h"

// --------------------------------------------------------------------------------------------------------------------
// - declaration of extern public interface
// --------------------------------------------------------------------------------------------------------------------

#include "EoProtocolEPmn_rom.h"


// --------------------------------------------------------------------------------------------------------------------
// - declaration of extern hidden interface 
// --------------------------------------------------------------------------------------------------------------------
// empty-section


// --------------------------------------------------------------------------------------------------------------------
// - #define with internal scope
// --------------------------------------------------------------------------------------------------------------------


// --------------------------------------------------------------------------------------------------------------------
// - typedef with internal scope
// --------------------------------------------------------------------------------------------------------------------
// empty-section


// --------------------------------------------------------------------------------------------------------------------
// - declaration of static functions
// --------------------------------------------------------------------------------------------------------------------

static uint16_t s_eoprot_ep_mn_rom_epid2index_of_folded_descriptors(eOprotID_t id);

static uint16_t s_eoprot_ep_mn_rom_comm_ramoffset(uint16_t tag);
static uint16_t s_eoprot_ep_mn_rom_appl_ramoffset(uint16_t tag);



// --------------------------------------------------------------------------------------------------------------------
// - definition (and initialisation) of static variables
// --------------------------------------------------------------------------------------------------------------------

// - default value of a comm

#if 1
const eOmn_comm_t eoprot_ep_mn_rom_comm_defaultvalue = { 0 };
#else
const eOmn_comm_t eoprot_ep_mn_rom_comm_defaultvalue =
{
    EO_INIT(.config)             
    {
        EO_INIT(.filler04)                  {0xf1, 0xf2, 0xf3, 0xf4} 
    },
    EO_INIT(.status)             
    {
        EO_INIT(.filler04)                  {0xf1, 0xf2, 0xf3, 0xf4} 
    },
    EO_INIT(.cmmnds)                       
    {
        EO_INIT(.ropsigcfg)                 
        {
            EO_INIT(.array)
            {
                EO_INIT(.head)
                {
                    EO_INIT(.capacity)      NUMOFROPSIGCFG,
                    EO_INIT(.itemsize)      sizeof(eOropSIGcfg_t),
                    EO_INIT(.size)          0
                },
                EO_INIT(.data)              {0}    
            },
            EO_INIT(.cmmnd)                 ropsigcfg_cmd_none,
            EO_INIT(.filler03)              {0xf1, 0xf2, 0xf3}
        }
    }
}; 
#endif

// - default value of a appl

#if 1
const eOmn_appl_t eoprot_ep_mn_rom_appl_defaultvalue = { 0 };
#else
const eOmn_appl_t eoprot_ep_mn_rom_appl_defaultvalue =
{
    EO_INIT(.config)
    {
        EO_INIT(.cycletime)         1000,
        EO_INIT(.filler04)          {0xf1, 0xf2, 0xf3, 0xf4}    
    },
    EO_INIT(.status)
    {
        EO_INIT(.currstate)         applstate_config,  
        EO_INIT(.runmode)           applrunMode__default,
        EO_INIT(.filler06)          {0xf1, 0xf2, 0xf3, 0xf4, 0xf5, 0xf6}    
    },
    EO_INIT(.cmmnds)
    {
        EO_INIT(.go2state)          applstate_config,        
        EO_INIT(.filler07)          {0xf1, 0xf2, 0xf3, 0xf4, 0xf5, 0xf6, 0xf7}    
    }       
};  
#endif

// - descriptors for the variables of a comm

EOnv_rom_t eoprot_ep_mn_rom_comm_descriptor_cmmnds__ropsigcfg =
{   
    EO_INIT(.capacity)  sizeof(eoprot_ep_mn_rom_comm_defaultvalue.cmmnds.ropsigcfg),
    EO_INIT(.rwmode)    eoprot_ep_mn_comm_rwmode_cmmnds__ropsigcfg,
    EO_INIT(.dummy)     0,    
    EO_INIT(.resetval)  (const void*)&eoprot_ep_mn_rom_comm_defaultvalue.cmmnds.ropsigcfg,
    EO_INIT(.init)      eoprot_ep_mn_fun_INIT_comm_cmmnds__ropsigcfg,
    EO_INIT(.update)    eoprot_ep_mn_fun_UPDT_comm_cmmnds__ropsigcfg
};


// - descriptors for the variables of a appl

EOnv_rom_t eoprot_ep_mn_rom_comm_descriptor_config =
{   
    EO_INIT(.capacity)  sizeof(eoprot_ep_mn_rom_appl_defaultvalue.config),
    EO_INIT(.rwmode)    eoprot_ep_mn_appl_rwmode_config,
    EO_INIT(.dummy)     0,    
    EO_INIT(.resetval)  (const void*)&eoprot_ep_mn_rom_appl_defaultvalue.config,
    EO_INIT(.init)      eoprot_ep_mn_fun_INIT_appl_config,
    EO_INIT(.update)    eoprot_ep_mn_fun_UPDT_appl_config
};

EOnv_rom_t eoprot_ep_mn_rom_comm_descriptor_status =
{   
    EO_INIT(.capacity)  sizeof(eoprot_ep_mn_rom_appl_defaultvalue.status),
    EO_INIT(.rwmode)    eoprot_ep_mn_appl_rwmode_status,
    EO_INIT(.dummy)     0,    
    EO_INIT(.resetval)  (const void*)&eoprot_ep_mn_rom_appl_defaultvalue.status,
    EO_INIT(.init)      eoprot_ep_mn_fun_INIT_appl_status,
    EO_INIT(.update)    eoprot_ep_mn_fun_UPDT_appl_status
};

EOnv_rom_t eoprot_ep_mn_rom_comm_descriptor_cmmnds__go2state =
{   
    EO_INIT(.capacity)  sizeof(eoprot_ep_mn_rom_appl_defaultvalue.cmmnds.go2state),
    EO_INIT(.rwmode)    eoprot_ep_mn_appl_rwmode_cmmnds__go2state,
    EO_INIT(.dummy)     0,    
    EO_INIT(.resetval)  (const void*)&eoprot_ep_mn_rom_appl_defaultvalue.cmmnds.go2state,
    EO_INIT(.init)      eoprot_ep_mn_fun_INIT_appl_cmmnds__go2state,
    EO_INIT(.update)    eoprot_ep_mn_fun_UPDT_appl_cmmnds__go2state
};




// --------------------------------------------------------------------------------------------------------------------
// - definition (and initialisation) of extern variables
// --------------------------------------------------------------------------------------------------------------------


const EOnv_rom_t * const eoprot_ep_mn_rom_folded_descriptors[] =
{
    // here are eoprot_ep_mn_comm_tags_numberof descriptors for the comms (equal for every comm)
    &eoprot_ep_mn_rom_comm_descriptor_cmmnds__ropsigcfg,

    // here are eoprot_ep_mn_appl_tags_numberof descriptors for the appls (equal for every appl)
    &eoprot_ep_mn_rom_comm_descriptor_config,
    &eoprot_ep_mn_rom_comm_descriptor_status,
    &eoprot_ep_mn_rom_comm_descriptor_cmmnds__go2state
         
};  EO_VERIFYsizeof(eoprot_ep_mn_rom_folded_descriptors, sizeof(EOnv_rom_t*)*(eoprot_ep_mn_comm_tags_numberof+eoprot_ep_mn_appl_tags_numberof));





const EOconstvector  eoprot_ep_mn_rom_constvector_of_folded_descriptors_dat = 
{
    EO_INIT(.size)              sizeof(eoprot_ep_mn_rom_folded_descriptors)/sizeof(EOnv_rom_t*), 
    EO_INIT(.item_size)         sizeof(EOnv_rom_t*),
    EO_INIT(.item_array_data)   eoprot_ep_mn_rom_folded_descriptors
};



// --------------------------------------------------------------------------------------------------------------------
// - definition of extern public functions
// --------------------------------------------------------------------------------------------------------------------



extern uint16_t eoprot_ep_mn_rom_comm_get_offset(eOprotTag_t tag)
{
    return(s_eoprot_ep_mn_rom_comm_ramoffset(tag));
}

extern uint16_t eoprot_ep_mn_rom_appl_get_offset(eOprotTag_t tag)
{
    return(s_eoprot_ep_mn_rom_appl_ramoffset(tag));
}

extern void* eoprot_ep_mn_rom_get_nvrom(eOprotID_t id)
{
    uint16_t indexoffoldeddescriptors = s_eoprot_ep_mn_rom_epid2index_of_folded_descriptors(id);
    
    if(EOK_uint16dummy == indexoffoldeddescriptors)
    {
        return(NULL);
    }
    
    return((void*)eoprot_ep_mn_rom_folded_descriptors[indexoffoldeddescriptors]);   
}

extern uint16_t eoprot_ep_mn_rom_get_sizeofvar(eOprotID_t id)
{     
    EOnv_rom_t* rom = eoprot_ep_mn_rom_get_nvrom(id);  
    if(NULL == rom)
    {
        return(0);
    }    
    return(rom->capacity); 
}

extern uint16_t eoprot_ep_mn_rom_get_prognum(eOprotID_t id)
{   // we assume that the variables are inserted in a progressive way without holes. and even if there are a few holes never mind.
    return(eoprot_ep_variable_ID2tag(eoprot_endpoint_management, id));
}



// --------------------------------------------------------------------------------------------------------------------
// - definition of extern hidden functions 
// --------------------------------------------------------------------------------------------------------------------
// empty-section


// --------------------------------------------------------------------------------------------------------------------
// - definition of static functions 
// --------------------------------------------------------------------------------------------------------------------

static uint16_t s_eoprot_ep_mn_rom_epid2index_of_folded_descriptors(eOprotID_t id)
{      
    uint16_t tag = eoprot_ep_variable_ID2tag(eoprot_endpoint_management, id);
    
    if(EOK_uint16dummy == tag)
    {
        return(EOK_uint16dummy);
    }
    
    eOprotEntity_t entity = eoprot_ep_variable_ID2entity(eoprot_endpoint_management, id);
    
    switch(entity)
    {
        case eomn_entity_comm:
        {   // nothing to add as the comm vars are in first position
            ; 
        } break;
        
        case eomn_entity_appl:
        {   // must add the number of vars in a comm
            tag += eoprot_ep_mn_comm_tags_numberof; 
        } break;      

        default:
        {   // error
            tag = EOK_uint16dummy;
        } break;
    
    }
    
    return(tag);   
}


// returns the offset form the start of the struct eOmn_comm_t of the variable with a given tag 
static uint16_t s_eoprot_ep_mn_rom_comm_ramoffset(uint16_t tag)
{   
    //return(eoprot_ep_mn_rom_comm_offsets[tag]);
    uint32_t tmp = ((uint32_t) eoprot_ep_mn_rom_folded_descriptors[tag]->resetval) - ((uint32_t) &eoprot_ep_mn_rom_comm_defaultvalue);
    return((uint16_t)tmp); 
}

// returns the offset form the start of the struct eOmn_appl_t of the variable with a given tag 
static uint16_t s_eoprot_ep_mn_rom_appl_ramoffset(uint16_t tag)
{
    //return(eoprot_ep_mn_rom_appl_offsets[tag]);
    uint32_t tmp = ((uint32_t) eoprot_ep_mn_rom_folded_descriptors[tag]->resetval) - ((uint32_t) &eoprot_ep_mn_rom_appl_defaultvalue);
    return((uint16_t)tmp); 
}


// --------------------------------------------------------------------------------------------------------------------
// - end-of-file (leave a blank line after)
// --------------------------------------------------------------------------------------------------------------------




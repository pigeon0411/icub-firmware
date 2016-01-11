/*
 * Copyright (C) 2014 iCub Facility - Istituto Italiano di Tecnologia
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

/* @file       EOtheBoardConfig.c
    @brief      This file keeps ...
    @author     marco.accame@iit.it
    @date       Nov 10 2014
**/


// --------------------------------------------------------------------------------------------------------------------
// - external dependencies
// --------------------------------------------------------------------------------------------------------------------

#include "stdlib.h" 
#include "string.h"
#include "stdio.h"
#include "EOconstvector_hid.h"
#include "EOtheCANmapping.h"
#include "EOappEncodersReader.h"

#include "EOmcController.h"

// --------------------------------------------------------------------------------------------------------------------
// - declaration of extern public interface
// --------------------------------------------------------------------------------------------------------------------

#include "EOtheBoardConfig.h"


// --------------------------------------------------------------------------------------------------------------------
// - declaration of extern hidden interface 
// --------------------------------------------------------------------------------------------------------------------
// empty-section


// --------------------------------------------------------------------------------------------------------------------
// - #define with internal scope
// --------------------------------------------------------------------------------------------------------------------
// empty-section


// --------------------------------------------------------------------------------------------------------------------
// - typedef with internal scope
// --------------------------------------------------------------------------------------------------------------------



// --------------------------------------------------------------------------------------------------------------------
// - declaration of static functions
// --------------------------------------------------------------------------------------------------------------------


// --------------------------------------------------------------------------------------------------------------------
// - definition (and initialisation) of static variables
// --------------------------------------------------------------------------------------------------------------------

// --------------------------------------------------------------------------------------------------------------------
// - definition (and initialisation) of extern variables
// --------------------------------------------------------------------------------------------------------------------

//#if 0
//// for eb1 / eb3
//extern EOconstvector s_eo_vectorof_des_jomo_eb1;
//extern EOconstvector s_eo_vectorof_des_strain_eb1;
//extern EOconstvector s_eo_vectorof_des_mais_eb1;


//// for eb2 / eb4
//extern EOconstvector s_eo_vectorof_des_jomo_eb2;
//extern EOconstvector s_eo_vectorof_des_strain_eb2;
//extern EOconstvector s_eo_vectorof_des_mais_eb2;
////extern EOconstvector s_eo_vectorof_des_inertial_eb2;
//extern EOconstvector s_eo_vectorof_des_skin_eb2; 


//// for eb5
//extern EOconstvector s_eo_vectorof_des_jomo_eb5;

//// for eb6 / eb8
//extern EOconstvector s_eo_vectorof_des_jomo_eb6;
//extern EOconstvector s_eo_vectorof_des_strain_eb6;


//// for eb7 / eb9
//extern EOconstvector s_eo_vectorof_des_jomo_eb7;
//extern EOconstvector s_eo_vectorof_des_strain_eb7;

//// for eb10 / eb11
//extern EOconstvector s_eo_vectorof_des_skin_eb10; 

//// for eb15
//extern EOconstvector s_eo_vectorof_des_jomo_eb15;


//// for eb21
//extern EOconstvector s_eo_vectorof_des_jomo_eb21;


//const EOconstvector s_eo_empty_constvector_board = 
//{
//    .capacity       = 0,
//    .size           = 0,
//    .item_size      = sizeof(eOcanmap_board_properties_t),
//    .dummy          = 0,
//    .stored_items   = NULL,
//    .functions      = NULL   
//};

//const EOconstvector s_eo_empty_constvector_encstream = 
//{
//    .capacity       = 0,
//    .size           = 0,
//    .item_size      = sizeof(eOappEncReader_stream_t),
//    .dummy          = 0,
//    .stored_items   = NULL,
//    .functions      = NULL   
//};

//const EOconstvector s_eo_empty_constvector_entity = 
//{
//    .capacity       = 0,
//    .size           = 0,
//    .item_size      = sizeof(eOcanmap_entitydescriptor_t),
//    .dummy          = 0,
//    .stored_items   = NULL,
//    .functions      = NULL   
//};


//const EOconstvector * const entitiesmapB1[eoprot_endpoints_numberof][eoboardconfig_maxvalueofsupportedentity+1] =
//{
//    { // mn
//        &s_eo_empty_constvector_entity, &s_eo_empty_constvector_entity, &s_eo_empty_constvector_entity, &s_eo_empty_constvector_entity
//    },
//   
//    { // mc
//        &s_eo_vectorof_des_jomo_eb1, &s_eo_vectorof_des_jomo_eb1, &s_eo_empty_constvector_entity, &s_eo_empty_constvector_entity
//    }, 

//    { // as
//        &s_eo_vectorof_des_strain_eb1, &s_eo_vectorof_des_mais_eb1, &s_eo_empty_constvector_entity, &s_eo_empty_constvector_entity
//    },
//    { // sk
//        &s_eo_empty_constvector_entity, &s_eo_empty_constvector_entity, &s_eo_empty_constvector_entity, &s_eo_empty_constvector_entity
//    }
//};

//const EOconstvector * const entitiesmapB2[eoprot_endpoints_numberof][eoboardconfig_maxvalueofsupportedentity+1] =
//{
//    { // mn
//        &s_eo_empty_constvector_entity, &s_eo_empty_constvector_entity, &s_eo_empty_constvector_entity, &s_eo_empty_constvector_entity
//    },
//   
//    { // mc
//        &s_eo_vectorof_des_jomo_eb2, &s_eo_vectorof_des_jomo_eb2, &s_eo_empty_constvector_entity, &s_eo_empty_constvector_entity
//    }, 

//    { // as
//        &s_eo_vectorof_des_strain_eb2, &s_eo_vectorof_des_mais_eb2, &s_eo_empty_constvector_entity, &s_eo_empty_constvector_entity
//    },
//    { // sk
//        &s_eo_vectorof_des_skin_eb2, &s_eo_empty_constvector_entity, &s_eo_empty_constvector_entity, &s_eo_empty_constvector_entity
//    }
//};

//const EOconstvector * const entitiesmapB5[eoprot_endpoints_numberof][eoboardconfig_maxvalueofsupportedentity+1] =
//{
//    { // mn
//        &s_eo_empty_constvector_entity, &s_eo_empty_constvector_entity, &s_eo_empty_constvector_entity, &s_eo_empty_constvector_entity
//    },
//   
//    { // mc
//        &s_eo_vectorof_des_jomo_eb5, &s_eo_vectorof_des_jomo_eb5, &s_eo_empty_constvector_entity, &s_eo_empty_constvector_entity
//    }, 

//    { // as
//        &s_eo_empty_constvector_entity, &s_eo_empty_constvector_entity, &s_eo_empty_constvector_entity, &s_eo_empty_constvector_entity
//    },
//    { // sk
//        &s_eo_empty_constvector_entity, &s_eo_empty_constvector_entity, &s_eo_empty_constvector_entity, &s_eo_empty_constvector_entity
//    }
//};

//const EOconstvector * const entitiesmapB6[eoprot_endpoints_numberof][eoboardconfig_maxvalueofsupportedentity+1] =
//{
//    { // mn
//        &s_eo_empty_constvector_entity, &s_eo_empty_constvector_entity, &s_eo_empty_constvector_entity, &s_eo_empty_constvector_entity
//    },
//   
//    { // mc
//        &s_eo_vectorof_des_jomo_eb6, &s_eo_vectorof_des_jomo_eb6, &s_eo_empty_constvector_entity, &s_eo_empty_constvector_entity
//    }, 

//    { // as
//        &s_eo_vectorof_des_strain_eb6, &s_eo_empty_constvector_entity, &s_eo_empty_constvector_entity, &s_eo_empty_constvector_entity
//    },
//    { // sk
//        &s_eo_empty_constvector_entity, &s_eo_empty_constvector_entity, &s_eo_empty_constvector_entity, &s_eo_empty_constvector_entity
//    }
//};


//const EOconstvector * const entitiesmapB7[eoprot_endpoints_numberof][eoboardconfig_maxvalueofsupportedentity+1] =
//{
//    { // mn
//        &s_eo_empty_constvector_entity, &s_eo_empty_constvector_entity, &s_eo_empty_constvector_entity, &s_eo_empty_constvector_entity
//    },
//   
//    { // mc
//        &s_eo_vectorof_des_jomo_eb7, &s_eo_vectorof_des_jomo_eb7, &s_eo_empty_constvector_entity, &s_eo_empty_constvector_entity
//    }, 

//    { // as
//        &s_eo_vectorof_des_strain_eb7, &s_eo_empty_constvector_entity, &s_eo_empty_constvector_entity, &s_eo_empty_constvector_entity
//    },
//    { // sk
//        &s_eo_empty_constvector_entity, &s_eo_empty_constvector_entity, &s_eo_empty_constvector_entity, &s_eo_empty_constvector_entity
//    }
//};

//const EOconstvector * const entitiesmapB10[eoprot_endpoints_numberof][eoboardconfig_maxvalueofsupportedentity+1] =
//{
//    { // mn
//        &s_eo_empty_constvector_entity, &s_eo_empty_constvector_entity, &s_eo_empty_constvector_entity, &s_eo_empty_constvector_entity
//    },
//   
//    { // mc
//        &s_eo_empty_constvector_entity, &s_eo_empty_constvector_entity, &s_eo_empty_constvector_entity, &s_eo_empty_constvector_entity
//    }, 

//    { // as
//        &s_eo_empty_constvector_entity, &s_eo_empty_constvector_entity, &s_eo_empty_constvector_entity, &s_eo_empty_constvector_entity
//    },
//    { // sk
//        &s_eo_vectorof_des_skin_eb10, &s_eo_empty_constvector_entity, &s_eo_empty_constvector_entity, &s_eo_empty_constvector_entity
//    }
//};

//const EOconstvector * const entitiesmapB15[eoprot_endpoints_numberof][eoboardconfig_maxvalueofsupportedentity+1] =
//{
//    { // mn
//        &s_eo_empty_constvector_entity, &s_eo_empty_constvector_entity, &s_eo_empty_constvector_entity, &s_eo_empty_constvector_entity
//    },
//   
//    { // mc
//        &s_eo_vectorof_des_jomo_eb15, &s_eo_vectorof_des_jomo_eb15, &s_eo_empty_constvector_entity, &s_eo_empty_constvector_entity
//    }, 

//    { // as
//        &s_eo_empty_constvector_entity, &s_eo_empty_constvector_entity, &s_eo_empty_constvector_entity, &s_eo_empty_constvector_entity
//    },
//    { // sk
//        &s_eo_empty_constvector_entity, &s_eo_empty_constvector_entity, &s_eo_empty_constvector_entity, &s_eo_empty_constvector_entity
//    }
//};


//const EOconstvector * const entitiesmapB21[eoprot_endpoints_numberof][eoboardconfig_maxvalueofsupportedentity+1] =
//{   // as eb6 but without strain .....
//    { // mn
//        &s_eo_empty_constvector_entity, &s_eo_empty_constvector_entity, &s_eo_empty_constvector_entity, &s_eo_empty_constvector_entity
//    },
//   
//    { // mc
//        &s_eo_vectorof_des_jomo_eb21, &s_eo_vectorof_des_jomo_eb21, &s_eo_empty_constvector_entity, &s_eo_empty_constvector_entity
//    }, 

//    { // as
//        &s_eo_empty_constvector_entity, &s_eo_empty_constvector_entity, &s_eo_empty_constvector_entity, &s_eo_empty_constvector_entity
//    },
//    { // sk
//        &s_eo_empty_constvector_entity, &s_eo_empty_constvector_entity, &s_eo_empty_constvector_entity, &s_eo_empty_constvector_entity
//    }
//};

//static const eOcandiscovery_target_t s_candiscoverytarget_mc_eb1 =
//{   
//    .boardtype          = eobrd_cantype_1foc,
//    .filler             = {0},
//    .firmwareversion    = {0, 0},
//    .protocolversion    = {1, 3},
//    .canmap             = {0x001e, 0x0000}
//};

//static const eOcandiscovery_target_t s_candiscoverytarget_mc_eb2 =
//{   
//    .boardtype          = eobrd_cantype_mc4,
//    .filler             = {0},
//    .firmwareversion    = {0, 0},
//    .protocolversion    = {1, 2},
//    .canmap             = {0x01f8, 0x0000}
//};

//static const eOcandiscovery_target_t s_candiscoverytarget_mc_eb5 =
//{   
//    .boardtype          = eobrd_cantype_1foc,
//    .filler             = {0},
//    .firmwareversion    = {0, 0},
//    .protocolversion    = {1, 3},
//    .canmap             = {0x001a, 0x0000}
//};

//static const eOcandiscovery_target_t s_candiscoverytarget_mc_eb6 =
//{   
//    .boardtype          = eobrd_cantype_1foc,
//    .filler             = {0},
//    .firmwareversion    = {0, 0},
//    .protocolversion    = {1, 3},
//    .canmap             = {0x001e, 0x0000}
//};

//static const eOcandiscovery_target_t s_candiscoverytarget_mc_eb7 =
//{   
//    .boardtype               = eobrd_cantype_1foc,
//    .filler             = {0},
//    .firmwareversion    = {0, 0},
//    .protocolversion    = {1, 3},
//    .canmap             = {0x0006, 0x0000}
//};


//static const eOcandiscovery_target_t s_candiscoverytarget_mais_eb2 =
//{   
//    .boardtype          = eobrd_cantype_mais,
//    .filler             = {0},
//    .firmwareversion    = {0, 0},
//    .protocolversion    = {1, 0},
//    .canmap             = {0x4000, 0x0000}
//};


//static const eOcandiscovery_target_t s_candiscoverytarget_strain_eb1 =
//{   
//    .boardtype          = eobrd_cantype_strain,
//    .filler             = {0},
//    .firmwareversion    = {0, 0},
//    .protocolversion    = {1, 0},
//    .canmap             = {0x0000, 0x2000}
//};


//static const eOcandiscovery_target_t s_candiscoverytarget_strain_eb6 =
//{   
//    .boardtype          = eobrd_cantype_strain,
//    .filler             = {0},
//    .firmwareversion    = {0, 0},
//    .protocolversion    = {1, 0},
//    .canmap             = {0x0000, 0x2000}
//};


//static const eOcandiscovery_target_t s_candiscoverytarget_strain_eb7 =
//{   
//    .boardtype          = eobrd_cantype_strain,
//    .filler             = {0},
//    .firmwareversion    = {0, 0},
//    .protocolversion    = {1, 0},
//    .canmap             = {0x0000, 0x0002}
//};

//static const eOcandiscovery_target_t s_candiscoverytarget_mc_eb15 =
//{   
//    .boardtype          = eobrd_cantype_1foc,
//    .filler             = {0},
//    .firmwareversion    = {0, 0},
//    .protocolversion    = {1, 3},
//    .canmap             = {0x001e, 0x0000}
//};


//static const eOcandiscovery_target_t s_candiscoverytarget_mc_eb21 =
//{   
//    .boardtype          = eobrd_cantype_1foc,
//    .filler             = {0},
//    .firmwareversion    = {0, 0},
//    .protocolversion    = {1, 3},
//    .canmap             = {0x001e, 0x0000}
//};

//#endif

// --------------------------------------------------------------------------------------------------------------------
// - definition of extern public functions
// --------------------------------------------------------------------------------------------------------------------

//#if 0
//extern const eOcandiscovery_target_t * eoboardconfig_code2mcdiscoverytarget(uint32_t code) 
//{
//    const eOcandiscovery_target_t *ret = NULL;
//    
//    switch(code)
//    {
//        case 0:    
//        case 2:
//        {            
//            ret = &s_candiscoverytarget_mc_eb1; 
//        } break;
//        
//        case 1:     
//        case 3:
//        {
//            ret = &s_candiscoverytarget_mc_eb2; 
//        } break;  

//        case 4:     
//        {
//            ret = &s_candiscoverytarget_mc_eb5; 
//        } break;      

//        case 5: 
//        case 7:             
//        {
//            ret = &s_candiscoverytarget_mc_eb6; 
//        } break;         
//    
//        case 6: 
//        case 8:             
//        {
//            ret = &s_candiscoverytarget_mc_eb7; 
//        } break; 
//        
//        case 9: 
//        case 10:             
//        {
//            ret = NULL; 
//        } break;         

//        case 14:             
//        {
//            ret = &s_candiscoverytarget_mc_eb15; 
//        } break;

//        
//        case 20:             
//        {
//            ret = &s_candiscoverytarget_mc_eb21; 
//        } break;
//        
//        default:    
//        {
//            ret = ret;
//        } break;    
//    }
//    
//    
//    return(ret);
//       
//}


//extern const eOcandiscovery_target_t * eoboardconfig_code2maisdiscoverytarget(uint32_t code) 
//{
//    const eOcandiscovery_target_t *ret = NULL;
//    
//    switch(code)
//    {
//        case 0:    
//        case 2:
//        {            
//            ret = NULL; 
//        } break;
//        
//        case 1:     
//        case 3:
//        {
//            ret = &s_candiscoverytarget_mais_eb2; 
//        } break;  

//        case 4:     
//        {
//            ret = NULL; 
//        } break;      

//        case 5: 
//        case 7:             
//        {
//            ret = NULL; 
//        } break;         
//    
//        case 6: 
//        case 8:             
//        {
//            ret = NULL; 
//        } break; 
//        
//        case 9: 
//        case 10:             
//        {
//            ret = NULL; 
//        } break;         

//        case 14:             
//        {
//            ret = NULL; 
//        } break; 

//        case 20:             
//        {
//            ret = NULL; 
//        } break;
//        
//        default:    
//        {
//            ret = ret;
//        } break;    
//    }
//    
//    
//    return(ret);
//       
//}


//extern const eOcandiscovery_target_t * eoboardconfig_code2straindiscoverytarget(uint32_t code) 
//{
//    const eOcandiscovery_target_t *ret = NULL;
//    
//    switch(code)
//    {
//        case 0:    
//        case 2:
//        {            
//            ret = &s_candiscoverytarget_strain_eb1; 
//        } break;
//        
//        case 1:     
//        case 3:
//        {
//            ret = NULL; 
//        } break;  

//        case 4:     
//        {
//            ret = NULL; 
//        } break;      

//        case 5: 
//        case 7:             
//        {
//            ret = &s_candiscoverytarget_strain_eb6; 
//        } break;         
//    
//        case 6: 
//        case 8:             
//        {
//#if     defined(ICUB_MEC_V1)
//            ret = NULL;
//#else            
//            ret = &s_candiscoverytarget_strain_eb7; 
//#endif            
//        } break; 
//        
//        case 9: 
//        case 10:             
//        {
//            ret = NULL; 
//        } break;         

//        case 14:             
//        {
//            ret = NULL; 
//        } break;  

//        case 20:             
//        {
//            ret = NULL; 
//        } break;
//        
//        default:    
//        {
//            ret = ret;
//        } break;    
//    }
//    
//    
//    return(ret);
//       
//}


//extern EOconstvector* eo_vectorof_boardprops_eb1;   // eb1/2
//extern EOconstvector* eo_vectorof_boardprops_eb2;   // eb2/4
//extern EOconstvector* eo_vectorof_boardprops_eb5;   // eb5
//extern EOconstvector* eo_vectorof_boardprops_eb6;   // eb6/8
//extern EOconstvector* eo_vectorof_boardprops_eb7;   // eb7/9
//extern EOconstvector* eo_vectorof_boardprops_eb10;  // eb10/11
//extern EOconstvector* eo_vectorof_boardprops_eb15;  // eb15
//extern EOconstvector* eo_vectorof_boardprops_eb21;  // eb21

//// of eOcanmap_board_properties_t
//// the constvector contains all the boards in can1 and can2. or ... is empty.
//extern EOconstvector * eoboardconfig_code2canboards(uint32_t code)
//{
//    EOconstvector *ret = (EOconstvector*) &s_eo_empty_constvector_board;
//    
//    // so far the code is just an index equal to board number but starting from 0. eb1 is 0, etc....
//    switch(code)
//    {
//        case 0:    
//        case 2:
//        {            
//            ret = eo_vectorof_boardprops_eb1; 
//        } break;
//        
//        case 1:     
//        case 3:
//        {
//            ret = eo_vectorof_boardprops_eb2; 
//        } break;  

//        case 4:     
//        {
//            ret = eo_vectorof_boardprops_eb5; 
//        } break;      

//        case 5: 
//        case 7:             
//        {
//            ret = eo_vectorof_boardprops_eb6; 
//        } break;         
//    
//        case 6: 
//        case 8:             
//        {
//            ret = eo_vectorof_boardprops_eb7; 
//        } break; 
//        
//        case 9: 
//        case 10:             
//        {
//            ret = eo_vectorof_boardprops_eb10; 
//        } break;         

//        case 14:
//        {
//            ret = eo_vectorof_boardprops_eb15; 
//        } break;
//        
//        case 20:
//        {
//            ret = eo_vectorof_boardprops_eb21; 
//        } break;        

//        default:    
//        {
//            ret = ret;
//        } break;    
//    }

//    return(ret);
//} 

//// of eOcanmap_entitydescriptor_t
//// the const vector contains reference to the boards used to offer service to a given entity.
//// or ... is empty in case of there is not such an entity on the board or the entity is not served by can
//extern EOconstvector * eoboardconfig_code2entitydescriptors(uint32_t code, eOprotEndpoint_t ep, eOprotEntity_t entity)
//{
//    EOconstvector *ret = (EOconstvector*) &s_eo_empty_constvector_entity;
//    
//    if(entity > eoboardconfig_maxvalueofsupportedentity)
//    {
//        return(ret);
//    }
//    
//    // so far the code is just an index equal to board number but starting from 0. eb1 is 0, etc....
//    switch(code)
//    {
//        case 0:    
//        case 2:
//        {       
//            ret = (EOconstvector*)entitiesmapB1[ep][entity]; 
//        } break;
//        
//        case 1:
//        case 3: 
//        {   
//            ret = (EOconstvector*)entitiesmapB2[ep][entity];  
//        } break;  

//        case 4:
//        {   
//            ret = (EOconstvector*)entitiesmapB5[ep][entity];  
//        } break;          

//        case 5:
//        case 7:    
//        {   
//            ret = (EOconstvector*)entitiesmapB6[ep][entity];  
//        } break;

//        case 6:
//        case 8:    
//        {   
//            ret = (EOconstvector*)entitiesmapB7[ep][entity];  
//        } break;

//        case 9:
//        case 10:    
//        {   
//            ret = (EOconstvector*)entitiesmapB10[ep][entity]; 
//        } break;
//        
//        case 14:
//        {
//            ret = (EOconstvector*)entitiesmapB15[ep][entity];
//        } break;
//        
//        case 20:
//        {
//            ret = (EOconstvector*)entitiesmapB21[ep][entity];
//        } break;        
//        
//        default:    
//        {
//            ret = ret;
//        } break;
//    
//    }

//    if(NULL == ret)
//    {   // it can be NULL if someone forgets to fill in a proper way entitiesmapBxx with the empty vector pointer up to position eoboardconfig_maxvalueofsupportedentity
//        ret = (EOconstvector*) &s_eo_empty_constvector_entity;
//    }

//    return(ret);
//}





//extern const eOappEncReader_cfg_t encoder_reader_config_none;
//extern const eOappEncReader_cfg_t encoder_reader_config_eb1;
//extern const eOappEncReader_cfg_t encoder_reader_config_eb5;
//extern const eOappEncReader_cfg_t encoder_reader_config_eb7;

//extern const eOappEncReader_cfg_t * eoboardconfig_code2encoderconfig(uint32_t code)
//{
//    const eOappEncReader_cfg_t *ret = (eOappEncReader_cfg_t*) &encoder_reader_config_none;
//    
//    // so far the code is just an index equal to board number but starting from 0. eb1 is 0, etc....
//    switch(code)
//    {
//        case 0:    
//        case 2:
//        case 5:
//        case 7:            
//        {   // eb1 / eb3 / eb6 / eb8    
//            ret = &encoder_reader_config_eb1; 
//        } break;
//        
//        case 4:
//        {   // eb5       
//            ret = &encoder_reader_config_eb5;
//        } break;   
//         

//        case 6:
//        case 8:
//        {   // eb7 / eb9    
//            ret = &encoder_reader_config_eb7; 
//        } break;        
//        
//        case 1:
//        case 3: 
//        case 9:
//        case 10:
//        {   // no encoder in boards eb2 / eb4 / eb10 / eb11
//            ret = &encoder_reader_config_none; 
//        } break;        
//    
//        case 14:
//        {   // no encoder in boards eb15
//            ret = &encoder_reader_config_none; 
//        } break;  

//        case 20:
//        {   // no encoder is boards eb21
//            ret = &encoder_reader_config_none; 
//        } break;  
//        
//        default:    
//        {
//            ret = ret;
//        } break;
//    
//    }

//    return(ret);

//}


//const EOconstvector s_eo_empty_constvector_epdes = 
//{
//    .capacity       = 0,
//    .size           = 0,
//    .item_size      = sizeof(eOprot_EPcfg_t),
//    .dummy          = 0,
//    .stored_items   = NULL,
//    .functions      = NULL   
//};

//extern EOconstvector s_eo_vectorof_EPcfg_eb1eb3;
//extern EOconstvector s_eo_vectorof_EPcfg_eb2eb4;
//extern EOconstvector s_eo_vectorof_EPcfg_eb5;
//extern EOconstvector s_eo_vectorof_EPcfg_eb6eb8;
//extern EOconstvector s_eo_vectorof_EPcfg_eb7eb9;
//extern EOconstvector s_eo_vectorof_EPcfg_eb10eb11;
//extern EOconstvector s_eo_vectorof_EPcfg_eb15;
//extern EOconstvector s_eo_vectorof_EPcfg_eb21;

//extern EOconstvector * eoboardconfig_code2EPcfg(uint32_t code)
//{
//    EOconstvector *ret = (EOconstvector*) &s_eo_empty_constvector_epdes;
//    
//    // so far the code is just an index equal to board number but starting from 0. eb1 is 0, etc....
//    switch(code)
//    {
//        case 0:    
//        case 2:
//        {       
//            ret = (EOconstvector*)&s_eo_vectorof_EPcfg_eb1eb3; 
//        } break;
//        
//        case 1:
//        case 3: 
//        {   
//            ret = (EOconstvector*)&s_eo_vectorof_EPcfg_eb2eb4; 
//        } break;  

//        case 4:
//        {   
//            ret = (EOconstvector*)&s_eo_vectorof_EPcfg_eb5; 
//        } break;          

//        case 5:
//        case 7:    
//        {   
//            ret = (EOconstvector*)&s_eo_vectorof_EPcfg_eb6eb8;  
//        } break;

//        case 6:
//        case 8:    
//        {   
//            ret = (EOconstvector*)&s_eo_vectorof_EPcfg_eb7eb9;  
//        } break;

//        case 9:
//        case 10:    
//        {   
//            ret = (EOconstvector*)&s_eo_vectorof_EPcfg_eb10eb11; 
//        } break;
//        
//        case 14:    
//        {   
//            ret = (EOconstvector*)&s_eo_vectorof_EPcfg_eb15;  
//        } break;

//        case 20:    
//        {   
//            ret = (EOconstvector*)&s_eo_vectorof_EPcfg_eb21;  
//        } break;
//        
//        default:    
//        {
//            ret = ret;
//        } break;
//    
//    }

//    return(ret);
//}


////extern eOas_inertialidentifier_t eoboardconfig_code2inertialID(uint32_t code)
////{
////    eOas_inertialidentifier_t ret = eoas_inertial_id_none;
////    
////    switch(code)
////    {
////        case 1:
////        case 3: 
////        {   // board eb2 or eb4   
////            ret = eoas_inertial_id_hand_palm; 
////        } break;  

////        
////        default:    
////        {   // all the others
////            ret = eoas_inertial_id_none;
////        } break;
////    
////    }

////    return(ret);        
////}

//extern const eOas_inertial_serviceconfig_t * eoboardconfig_code2inertialCFG(uint32_t code)
//{
//    const eOas_inertial_serviceconfig_t *ret = NULL;
//    
//    switch(code)
//    {
//        case 1:
//        {
//            ret = &eo_inertials_cfg_eb2;
//        } break;
//        
//        case 3: 
//        {     
//            ret = &eo_inertials_cfg_eb4;
//        } break;  


//        case 9:
//        {
//            ret = &eo_inertials_cfg_eb10;
//        } break;
//        
//        case 10: 
//        {     
//            ret = &eo_inertials_cfg_eb11;
//        } break; 
//        
//        default:    
//        {   // all the others
//            ret = NULL;
//        } break;
//    
//    }

//    return(ret);   
//}

//#endif


extern const eOemsrunner_timing_t * eoboardconfig_code2ctrlooptiming(uint32_t code)
{
    static const eOemsrunner_timing_t normal = 
    {   // 400-300-300, but maybe better doing 400-250-350 or even 400-200-400
        .period         = 1000,
        .rxstartafter   = 0,
        .dostartafter   = 400,
        .txstartafter   = 700,
        .safetygap      = 50          
    };
    
    static const eOemsrunner_timing_t gateway = 
    {   // 450-050-500 .... or even we dont wait the can tx end in the tx phase.
        .period         = 1000,
        .rxstartafter   = 0,
        .dostartafter   = 450,
        .txstartafter   = 500,
        .safetygap      = 25          
    };
    
    const eOemsrunner_timing_t *ret = &normal;
 
    switch(code)
    {
        case 1:
        case 3:
        case 9:
        case 10:            
        {   // eb2, eb4, eb10, eb11
            ret = &gateway;
        } break;
         
        default:    
        {   // all the others
            ret = &normal;
        } break;
    
    }

    return(ret);   
}
    
const eOmn_serv_configuration_t serv_config_as_strain_eb1_eb3 = 
{   // eb1 or eb3
    .type       = eomn_serv_AS_strain,
    .filler     = {0},
    .data.as.strain = 
    {
        .version    =
        {
            .firmware   = {0, 0},
            .protocol   = {1, 0}
        },
        .canloc         =
        {
            .port           = eOcanport2,
            .addr           = 13,
            .insideindex    = eomn_serv_caninsideindex_none                   
        }
    }    
};

const eOmn_serv_configuration_t serv_config_as_strain_eb6_eb8 = 
{   // eb6 or eb8
    .type       = eomn_serv_AS_strain,
    .filler     = {0},
    .data.as.strain = 
    {
        .version    =
        {
            .firmware   = {0, 0},
            .protocol   = {1, 0}
        },
        .canloc         =
        {
            .port           = eOcanport2,
            .addr           = 13,
            .insideindex    = eomn_serv_caninsideindex_none                   
        }
    }    
};


const eOmn_serv_configuration_t serv_config_as_strain_eb7_eb9 =
{   // eb7 or eb9
    .type       = eomn_serv_AS_strain,
    .filler     = {0},
    .data.as.strain = 
    {
        .version    =
        {
            .firmware   = {0, 0},
            .protocol   = {1, 0}
        },
        .canloc         =
        {
            .port           = eOcanport2,
            .addr           = 1,
            .insideindex    = eomn_serv_caninsideindex_none                   
        }
    }    
};


const eOmn_serv_configuration_t serv_config_mc_eb1_eb3 =
{   // eb1 / eb3
    .type       = eomn_serv_MC_foc,
    .filler     = {0},
    .data.mc.foc_based = 
    {
        .boardtype4mccontroller = emscontroller_board_SHOULDER,
        .filler                 = {0},
        .version   =
        {
            .firmware   = {0, 0},
            .protocol   = {1, 3}
        },
        .arrayofjomodescriptors =
        {
            .head   = 
            {
                .capacity       = 4,
                .itemsize       = 3,
                .size           = 4,
                .internalmem    = 0                    
            },
            .data   =
            {
                { // joint 0
                    .actuator.foc.canloc    =
                    {
                        .port           = eOcanport1,
                        .addr           = 1,
                        .insideindex    = eomn_serv_caninsideindex_first                             
                    },
                    .sensor         =
                    {
                        .type   = eomn_serv_mc_sensor_encoder_aea,
                        .port   = eomn_serv_mc_port_ems_spiP6, // hal_encoder1   
                        .pos    = eomn_serv_mc_sensor_pos_atjoint
                    },
                    .extrasensor    =
                    {
                        .type   = eomn_serv_mc_sensor_none,
                        .port   = eomn_serv_mc_port_none,
                        .pos    = eomn_serv_mc_sensor_pos_none
                    }
                },
                { // joint 1
                    .actuator.foc.canloc    =
                    {
                        .port           = eOcanport1,
                        .addr           = 2,
                        .insideindex    = eomn_serv_caninsideindex_first                             
                    },
                    .sensor         =
                    {
                        .type   = eomn_serv_mc_sensor_encoder_aea,
                        .port   = eomn_serv_mc_port_ems_spiP7, // hal_encoder4
                        .pos    = eomn_serv_mc_sensor_pos_atjoint                            
                    },
                    .extrasensor    =
                    {
                        .type   = eomn_serv_mc_sensor_none,
                        .port   = eomn_serv_mc_port_none,
                        .pos    = eomn_serv_mc_sensor_pos_none
                    }
                },                    
                { // joint 2
                    .actuator.foc.canloc    =
                    {
                        .port           = eOcanport1,
                        .addr           = 3,
                        .insideindex    = eomn_serv_caninsideindex_first                             
                    },
                    .sensor         =
                    {
                        .type   = eomn_serv_mc_sensor_encoder_aea,
                        .port   = eomn_serv_mc_port_ems_spiP8, // hal_encoder2  
                        .pos    = eomn_serv_mc_sensor_pos_atjoint
                    },
                    .extrasensor    =
                    {
                        .type   = eomn_serv_mc_sensor_none,
                        .port   = eomn_serv_mc_port_none,
                        .pos    = eomn_serv_mc_sensor_pos_none
                    }
                },               
                { // joint 3
                    .actuator.foc.canloc    =
                    {
                        .port           = eOcanport1,
                        .addr           = 4,
                        .insideindex    = eomn_serv_caninsideindex_first                             
                    },
                    .sensor         =
                    {
                        .type   = eomn_serv_mc_sensor_encoder_aea,
                        .port   = eomn_serv_mc_port_ems_spiP9,    // hal_encoder5 
                        .pos    = eomn_serv_mc_sensor_pos_atjoint
                    },
                    .extrasensor    =
                    {
                        .type   = eomn_serv_mc_sensor_none,
                        .port   = eomn_serv_mc_port_none,
                        .pos    = eomn_serv_mc_sensor_pos_none
                    }
                }                    
            }   
        }
    }
};


const eOmn_serv_configuration_t serv_config_mc_eb2_eb4 =
{   // eb2 / eb4
    .type       = eomn_serv_MC_mc4,
    .filler     = {0},
    .data.mc.mc4_based  = 
    {
        .mc4version =
        {
            .firmware   = {0, 0},
            .protocol   = {1, 2}                 
        },
        .mc4shifts =
        {
            0  
        },
        .mc4joints =
        {
            {   // jomo 0   
                .port           = eOcanport1,
                .addr           = 3,
                .insideindex    = eocanmap_insideindex_first
            },      
            {   // jomo 1
                .port           = eOcanport1,
                .addr           = 3,
                .insideindex    = eocanmap_insideindex_second
            },
            {   // jomo 2
                .port           = eOcanport1,
                .addr           = 4,
                .insideindex    = eocanmap_insideindex_first
            },
            {   // jomo 3
                .port           = eOcanport1,
                .addr           = 4,
                .insideindex    = eocanmap_insideindex_second
            },
            {   // jomo 4   
                .port           = eOcanport1,
                .addr           = 5,
                .insideindex    = eocanmap_insideindex_first
            },
            {   // jomo 
                .port           = eOcanport1,
                .addr           = 5,
                .insideindex    = eocanmap_insideindex_second
            },
            {   // jomo 6
                .port           = eOcanport1,
                .addr           = 6,
                .insideindex    = eocanmap_insideindex_first
            },
            {   // jomo 7
                .port           = eOcanport1,
                .addr           = 6,
                .insideindex    = eocanmap_insideindex_second
            },
            {   // jomo 8   
                .port           = eOcanport1,
                .addr           = 7,
                .insideindex    = eocanmap_insideindex_first
            },
            {   // jomo 9
                .port           = eOcanport1,
                .addr           = 7,
                .insideindex    = eocanmap_insideindex_second
            },
            {   // jomo 10
                .port           = eOcanport1,
                .addr           = 8,
                .insideindex    = eocanmap_insideindex_first
            },
            {   // jomo 11
                .port           = eOcanport1,
                .addr           = 8,
                .insideindex    = eocanmap_insideindex_second
            }
        },
        .mais = 
        {
            .version    =
            {
                .firmware   = {0, 0},
                .protocol   = {1, 0}    
            },
            .canloc = 
            {
                .port           = eOcanport1,
                .addr           = 14,
                .insideindex    = eocanmap_insideindex_none                    
            }              
        }
    }    
};    

const eOmn_serv_configuration_t serv_config_mc_eb5 =
{   // eb5
    .type       = eomn_serv_MC_foc,
    .filler     = {0},
    .data.mc.foc_based = 
    {
        .boardtype4mccontroller = emscontroller_board_WAIST,
        .filler                 = {0},
        .version   =
        {
            .firmware   = {0, 0},
            .protocol   = {1, 3}
        },
        .arrayofjomodescriptors =
        {
            .head   = 
            {
                .capacity       = 4,
                .itemsize       = 3,
                .size           = 3,
                .internalmem    = 0                    
            },
            .data   =
            {
                { // joint 0
                    .actuator.foc.canloc    =
                    {
                        .port           = eOcanport1,
                        .addr           = 3,
                        .insideindex    = eomn_serv_caninsideindex_first                             
                    },
                    .sensor         =
                    {
                        .type   = eomn_serv_mc_sensor_encoder_aea,
                        .port   = eomn_serv_mc_port_ems_spiP6, // hal_encoder1   
                        .pos    = eomn_serv_mc_sensor_pos_atjoint
                    },
                    .extrasensor    =
                    {
                        .type   = eomn_serv_mc_sensor_none,
                        .port   = eomn_serv_mc_port_none,
                        .pos    = eomn_serv_mc_sensor_pos_none
                    }
                },
                { // joint 1
                    .actuator.foc.canloc    =
                    {
                        .port           = eOcanport1,
                        .addr           = 4,
                        .insideindex    = eomn_serv_caninsideindex_first                             
                    },
                    .sensor         =
                    {
                        .type   = eomn_serv_mc_sensor_encoder_aea,
                        .port   = eomn_serv_mc_port_ems_spiP7, // hal_encoder4
                        .pos    = eomn_serv_mc_sensor_pos_atjoint                            
                    },
                    .extrasensor    =
                    {
                        .type   = eomn_serv_mc_sensor_none,
                        .port   = eomn_serv_mc_port_none,
                        .pos    = eomn_serv_mc_sensor_pos_none
                    }
                },                    
                { // joint 2
                    .actuator.foc.canloc    =
                    {
                        .port           = eOcanport1,
                        .addr           = 1,
                        .insideindex    = eomn_serv_caninsideindex_first                             
                    },
                    .sensor         =
                    {
                        .type   = eomn_serv_mc_sensor_encoder_aea,
                        .port   = eomn_serv_mc_port_ems_spiP8, // hal_encoder2  
                        .pos    = eomn_serv_mc_sensor_pos_atjoint
                    },
                    .extrasensor    =
                    {
                        .type   = eomn_serv_mc_sensor_none,
                        .port   = eomn_serv_mc_port_none,
                        .pos    = eomn_serv_mc_sensor_pos_none
                    }
                },
                {   // there is not a joint 3 
                    0 
                }                   
            }  
        }
    }
};    

const eOmn_serv_configuration_t serv_config_mc_eb6_eb8 =
{   // eb6 / eb8
    .type       = eomn_serv_MC_foc,
    .filler     = {0},
    .data.mc.foc_based = 
    {
        .boardtype4mccontroller = emscontroller_board_UPPERLEG,
        .filler                 = {0},
        .version   =
        {
            .firmware   = {0, 0},
            .protocol   = {1, 3}
        },
        .arrayofjomodescriptors =
        {
            .head   = 
            {
                .capacity       = 4,
                .itemsize       = 3,
                .size           = 4,
                .internalmem    = 0                    
            },
            .data   =
            {
                { // joint 0
                    .actuator.foc.canloc    =
                    {
                        .port           = eOcanport1,
                        .addr           = 3,
                        .insideindex    = eomn_serv_caninsideindex_first                             
                    },
                    .sensor         =
                    {
                        .type   = eomn_serv_mc_sensor_encoder_aea,
                        .port   = eomn_serv_mc_port_ems_spiP6, // hal_encoder1   
                        .pos    = eomn_serv_mc_sensor_pos_atjoint
                    },
                    .extrasensor    =
                    {
                        .type   = eomn_serv_mc_sensor_none,
                        .port   = eomn_serv_mc_port_none,
                        .pos    = eomn_serv_mc_sensor_pos_none
                    }
                },
                { // joint 1
                    .actuator.foc.canloc    =
                    {
                        .port           = eOcanport1,
                        .addr           = 4,
                        .insideindex    = eomn_serv_caninsideindex_first                             
                    },
                    .sensor         =
                    {
                        .type   = eomn_serv_mc_sensor_encoder_aea,
                        .port   = eomn_serv_mc_port_ems_spiP7, // hal_encoder4
                        .pos    = eomn_serv_mc_sensor_pos_atjoint                            
                    },
                    .extrasensor    =
                    {
                        .type   = eomn_serv_mc_sensor_none,
                        .port   = eomn_serv_mc_port_none,
                        .pos    = eomn_serv_mc_sensor_pos_none
                    }
                },                    
                { // joint 2
                    .actuator.foc.canloc    =
                    {
                        .port           = eOcanport1,
                        .addr           = 1,
                        .insideindex    = eomn_serv_caninsideindex_first                             
                    },
                    .sensor         =
                    {
                        .type   = eomn_serv_mc_sensor_encoder_aea,
                        .port   = eomn_serv_mc_port_ems_spiP8, // hal_encoder2  
                        .pos    = eomn_serv_mc_sensor_pos_atjoint
                    },
                    .extrasensor    =
                    {
                        .type   = eomn_serv_mc_sensor_none,
                        .port   = eomn_serv_mc_port_none,
                        .pos    = eomn_serv_mc_sensor_pos_none
                    }
                },               
                { // joint 3
                    .actuator.foc.canloc    =
                    {
                        .port           = eOcanport1,
                        .addr           = 2,
                        .insideindex    = eomn_serv_caninsideindex_first                             
                    },
                    .sensor         =
                    {
                        .type   = eomn_serv_mc_sensor_encoder_aea,
                        .port   = eomn_serv_mc_port_ems_spiP9,    // hal_encoder5 
                        .pos    = eomn_serv_mc_sensor_pos_atjoint
                    },
                    .extrasensor    =
                    {
                        .type   = eomn_serv_mc_sensor_none,
                        .port   = eomn_serv_mc_port_none,
                        .pos    = eomn_serv_mc_sensor_pos_none
                    }
                }                    
            } 
        }
    }
};    

const eOmn_serv_configuration_t serv_config_mc_eb7_eb9 =
{   // eb7 / eb9
    .type       = eomn_serv_MC_foc,
    .filler     = {0},
    .data.mc.foc_based = 
    {
        .boardtype4mccontroller = emscontroller_board_ANKLE,
        .filler                 = {0},
        .version   =
        {
            .firmware   = {0, 0},
            .protocol   = {1, 3}
        },
        .arrayofjomodescriptors =
        {
            .head   = 
            {
                .capacity       = 4,
                .itemsize       = 3,
                .size           = 2,
                .internalmem    = 0                    
            },
            .data   =
            {
                { // joint 0
                    .actuator.foc.canloc    =
                    {
                        .port           = eOcanport1,
                        .addr           = 1,
                        .insideindex    = eomn_serv_caninsideindex_first                             
                    },
                    .sensor         =
                    {
                        .type   = eomn_serv_mc_sensor_encoder_aea,
                        .port   = eomn_serv_mc_port_ems_spiP6, // hal_encoder1   
                        .pos    = eomn_serv_mc_sensor_pos_atjoint
                    },
                    .extrasensor    =
                    {
                        .type   = eomn_serv_mc_sensor_none,
                        .port   = eomn_serv_mc_port_none,
                        .pos    = eomn_serv_mc_sensor_pos_none
                    }
                },
                { // joint 1
                    .actuator.foc.canloc    =
                    {
                        .port           = eOcanport1,
                        .addr           = 2,
                        .insideindex    = eomn_serv_caninsideindex_first                             
                    },
                    .sensor         =
                    {
                        .type   = eomn_serv_mc_sensor_encoder_aea,
                        .port   = eomn_serv_mc_port_ems_spiP7, // hal_encoder4
                        .pos    = eomn_serv_mc_sensor_pos_atjoint                            
                    },
                    .extrasensor    =
                    {
                        .type   = eomn_serv_mc_sensor_none,
                        .port   = eomn_serv_mc_port_none,
                        .pos    = eomn_serv_mc_sensor_pos_none
                    }
                },                    
                { // no joint 2
                    0
                },               
                { // no joint 3
                    0
                }                    
            }
        }
    }
};



const eOmn_serv_configuration_t serv_config_mc_eb15 =
{   // eb15
    .type       = eomn_serv_MC_foc,
    .filler     = {0},
    .data.mc.foc_based = 
    {
        .boardtype4mccontroller = emscontroller_board_CER_WAIST,
        .filler                 = {0},
        .version    =
        {
            .firmware   = {0, 0},
            .protocol   = {1, 3}
        },
        .arrayofjomodescriptors =
        {
            .head   = 
            {
                .capacity       = 4,
                .itemsize       = 3,
                .size           = 4,
                .internalmem    = 0                    
            },
            .data   =
            {
                { // joint 0
                    .actuator.foc.canloc    =
                    {
                        .port           = eOcanport1,
                        .addr           = 1,
                        .insideindex    = eomn_serv_caninsideindex_first                             
                    },
                    .sensor         =
                    {
                        .type   = eomn_serv_mc_sensor_none,
                        .port   = eomn_serv_mc_port_none,
                        .pos    = eomn_serv_mc_sensor_pos_none
                    },
                    .extrasensor    =
                    {
                        .type   = eomn_serv_mc_sensor_none,
                        .port   = eomn_serv_mc_port_none,
                        .pos    = eomn_serv_mc_sensor_pos_none
                    }
                },
                { // joint 1
                    .actuator.foc.canloc    =
                    {
                        .port           = eOcanport1,
                        .addr           = 2,
                        .insideindex    = eomn_serv_caninsideindex_first                             
                    },
                    .sensor         =
                    {
                        .type   = eomn_serv_mc_sensor_none,
                        .port   = eomn_serv_mc_port_none,
                        .pos    = eomn_serv_mc_sensor_pos_none                         
                    },
                    .extrasensor    =
                    {
                        .type   = eomn_serv_mc_sensor_none,
                        .port   = eomn_serv_mc_port_none,
                        .pos    = eomn_serv_mc_sensor_pos_none
                    }
                },                    
                { // joint 2
                    .actuator.foc.canloc    =
                    {
                        .port           = eOcanport1,
                        .addr           = 3,
                        .insideindex    = eomn_serv_caninsideindex_first                             
                    },
                    .sensor         =
                    {
                        .type   = eomn_serv_mc_sensor_none,
                        .port   = eomn_serv_mc_port_none,
                        .pos    = eomn_serv_mc_sensor_pos_none
                    },
                    .extrasensor    =
                    {
                        .type   = eomn_serv_mc_sensor_none,
                        .port   = eomn_serv_mc_port_none,
                        .pos    = eomn_serv_mc_sensor_pos_none
                    }
                },               
                { // joint 3
                    .actuator.foc.canloc    =
                    {
                        .port           = eOcanport1,
                        .addr           = 4,
                        .insideindex    = eomn_serv_caninsideindex_first                             
                    },
                    .sensor         =
                    {
                        .type   = eomn_serv_mc_sensor_none,
                        .port   = eomn_serv_mc_port_none,
                        .pos    = eomn_serv_mc_sensor_pos_none
                    },
                    .extrasensor    =
                    {
                        .type   = eomn_serv_mc_sensor_none,
                        .port   = eomn_serv_mc_port_none,
                        .pos    = eomn_serv_mc_sensor_pos_none
                    }
                }                    
            }
        }

    }
};


const eOmn_serv_configuration_t serv_config_mc_eb21 =
{   // eb21
    .type       = eomn_serv_MC_foc,
    .filler     = {0},
    .data.mc.foc_based = 
    {
        .boardtype4mccontroller = emscontroller_board_CER_BASE,
        .filler                 = {0},
        .version    =
        {
            .firmware   = {0, 0},
            .protocol   = {1, 3}
        },
        .arrayofjomodescriptors =
        {
            .head   = 
            {
                .capacity       = 4,
                .itemsize       = 3,
                .size           = 4,
                .internalmem    = 0                    
            },
            .data   =
            {
                { // joint 0
                    .actuator.foc.canloc    =
                    {
                        .port           = eOcanport1,
                        .addr           = 4,
                        .insideindex    = eomn_serv_caninsideindex_first                             
                    },
                    .sensor         =
                    {
                        .type   = eomn_serv_mc_sensor_none,
                        .port   = eomn_serv_mc_port_none,
                        .pos    = eomn_serv_mc_sensor_pos_none
                    },
                    .extrasensor    =
                    {
                        .type   = eomn_serv_mc_sensor_none,
                        .port   = eomn_serv_mc_port_none,
                        .pos    = eomn_serv_mc_sensor_pos_none
                    }
                },
                { // joint 1
                    .actuator.foc.canloc    =
                    {
                        .port           = eOcanport1,
                        .addr           = 2,
                        .insideindex    = eomn_serv_caninsideindex_first                             
                    },
                    .sensor         =
                    {
                        .type   = eomn_serv_mc_sensor_none,
                        .port   = eomn_serv_mc_port_none,
                        .pos    = eomn_serv_mc_sensor_pos_none                         
                    },
                    .extrasensor    =
                    {
                        .type   = eomn_serv_mc_sensor_none,
                        .port   = eomn_serv_mc_port_none,
                        .pos    = eomn_serv_mc_sensor_pos_none
                    }
                },                    
                { // joint 2
                    .actuator.foc.canloc    =
                    {
                        .port           = eOcanport1,
                        .addr           = 3,
                        .insideindex    = eomn_serv_caninsideindex_first                             
                    },
                    .sensor         =
                    {
                        .type   = eomn_serv_mc_sensor_none,
                        .port   = eomn_serv_mc_port_none,
                        .pos    = eomn_serv_mc_sensor_pos_none
                    },
                    .extrasensor    =
                    {
                        .type   = eomn_serv_mc_sensor_none,
                        .port   = eomn_serv_mc_port_none,
                        .pos    = eomn_serv_mc_sensor_pos_none
                    }
                },               
                { // joint 3
                    .actuator.foc.canloc    =
                    {
                        .port           = eOcanport1,
                        .addr           = 1,
                        .insideindex    = eomn_serv_caninsideindex_first                             
                    },
                    .sensor         =
                    {
                        .type   = eomn_serv_mc_sensor_none,
                        .port   = eomn_serv_mc_port_none,
                        .pos    = eomn_serv_mc_sensor_pos_none
                    },
                    .extrasensor    =
                    {
                        .type   = eomn_serv_mc_sensor_none,
                        .port   = eomn_serv_mc_port_none,
                        .pos    = eomn_serv_mc_sensor_pos_none
                    }
                }                    
            }
        }
    }
};


enum {maxboards_V2 = 11};
const eOmn_serv_configuration_t * const serv_config_mc_V2[maxboards_V2] =
{   // there are at most 11 ems boards. only board eb10 and eb11 (pos 9 and 10) dont have mc.
    &serv_config_mc_eb1_eb3,
    &serv_config_mc_eb2_eb4,
    &serv_config_mc_eb1_eb3,
    &serv_config_mc_eb2_eb4,    
    &serv_config_mc_eb5,
    &serv_config_mc_eb6_eb8,
    &serv_config_mc_eb7_eb9,    
    &serv_config_mc_eb6_eb8,
    &serv_config_mc_eb7_eb9,     
    NULL,
    NULL
};

enum {maxboards_CER = 21};
const eOmn_serv_configuration_t * const serv_config_mc_CER[maxboards_CER] =
{   // there are only eb15 and eb21 .   
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    &serv_config_mc_eb15,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    &serv_config_mc_eb21    
};



const eOmn_serv_configuration_t serv_config_as_mais_eb2_eb4 =  
{   // eb2/2b4
    .type       = eomn_serv_AS_mais,
    .filler     = {0},
    .data.as.mais = 
    {
        .version    =
        {
            .firmware   = {0, 0},
            .protocol   = {1, 0}    
        },
        .canloc = 
        {
            .port           = eOcanport1,
            .addr           = 14,
            .insideindex    = eocanmap_insideindex_none                    
        }
    }    
};


const eOmn_serv_configuration_t serv_config_sk_skin_eb2_eb4 =
{   // eb2 / eb4
    .type       = eomn_serv_SK_skin,
    .filler     = {0},
    .data.sk.skin = 
    {
        .version    =
        {
            .firmware   = {0, 0},
            .protocol   = {0, 0}  // in case of {0, 0} the can discovery is not done but the verify will be ok. for normal case use: {1, 0}    
        },
        .numofpatches   = 1,
        .canmapskin[0] = { 0x0000, 0x7f00 },
        .canmapskin[1] = {0},
        .canmapskin[2] = {0},
        .canmapskin[3] = {0}
    }    
};

const eOmn_serv_configuration_t serv_config_sk_skin_eb10_eb11 =   
{   // eb10 / eb11
    .type       = eomn_serv_SK_skin,
    .filler     = {0},
    .data.sk.skin = 
    {
        .version    =
        {
            .firmware   = {0, 0},
            .protocol   = {0, 0}  // in case of {0, 0} the can discovery is not done but the verify will be ok. for normal case use: {1, 0}   
        },
        .numofpatches   = 2,
        .canmapskin[0] = { 0x00fe, 0x0000 },
        .canmapskin[1] = { 0x0000, 0x3f00 },
        .canmapskin[2] = {0},
        .canmapskin[3] = {0}
    }    
};    




const eOmn_serv_configuration_t serv_config_as_inertial_eb2_eb4 =
{   // eb2 / eb4
    .type       = eomn_serv_AS_inertial,
    .filler     = {0},
    .data.as.inertial = 
    {
        .version    =
        {
            .firmware   = {0, 0},
            .protocol   = {0, 0}  // in case of {0, 0} the can discovery is not done but the verify will be ok. for normal case use: {1, 0}  
        },
        .canmap = { 0x0000, 0x7f00 }
    }    
};
    

const eOmn_serv_configuration_t serv_config_as_inertial_eb10_eb11 =    
{   // eb10 / eb11
    .type       = eomn_serv_AS_inertial,
    .filler     = {0},
    .data.as.inertial = 
    {
        .version    =
        {
            .firmware   = {0, 0},
            .protocol   = {0, 0}  // in case of {0, 0} the can discovery is not done but the verify will be ok. for normal case use: {1, 0}  
        },
        .canmap = { 0x00fe, 0x3f00 }
    }    
};  


// ok, verified by marco.accame on 07jan16
extern const eOmn_serv_configuration_t * eoboardconfig_code2motion_serv_configuration(uint32_t code)
{
    const eOmn_serv_configuration_t * ret = NULL;
    
    if(code < maxboards_V2)
    {   // boards from eb1 to eb11
        ret = serv_config_mc_V2[code]; 
    }
    else if(code < maxboards_CER)
    {
        ret= serv_config_mc_CER[code];
    }

    return(ret);        
}

// ok, verified by marco.accame on 30dec15
extern const eOmn_serv_configuration_t * eoboardconfig_code2strain_serv_configuration(uint32_t code)
{
    const eOmn_serv_configuration_t * ret = NULL;
    
    switch(code)
    {
        case 0:
        case 2:
        {   // board eb1 / eb3 / eb15  
            ret = &serv_config_as_strain_eb1_eb3; 
        } break;  
        
        case 5:
        case 7:
        {   // board eb6 / eb8
            ret = &serv_config_as_strain_eb6_eb8;           
        } break;        
 
#if     defined(ICUB_MEC_V2)        
        case 6:
        case 8:
        {   // board eb7 / eb9 ... but only in v2-mec
            ret = &serv_config_as_strain_eb7_eb9;           
        } break; 
#endif  

//#if     defined(CER)   
//#error -> if CER board 10.0.1.15 has a strain keep code. if not remove it. then remove error pragma, committ and push.     
//        case 14:
//        {   // CER board eb15: has a strain ... 
//            ret = &serv_config_as_strain_eb1_eb3; 
//        } break;          
//#endif
        
        default:    
        {   // all the others
            ret = NULL;
        } break;
    
    }

    return(ret);        
}


// ok, verified by marco.accame on 30dec15
extern const eOmn_serv_configuration_t * eoboardconfig_code2mais_serv_configuration(uint32_t code)
{
    const eOmn_serv_configuration_t * ret = NULL;
    
    switch(code)
    {
        case 1:
        case 3:
        {   // board eb2 / eb4   
            ret = &serv_config_as_mais_eb2_eb4; 
        } break;  

        default:    
        {   // all the others
            ret = NULL;
        } break;
    
    }

    return(ret);        
}

// ok, verified by marco.accame on 30dec15
extern const eOmn_serv_configuration_t * eoboardconfig_code2skin_serv_configuration(uint32_t code)
{
    const eOmn_serv_configuration_t * ret = NULL;
    
//    #warning --> rimuovo la skin per debug sul viola che ha problemi sul can2 della eb2
//    return(NULL);
    
    switch(code)
    {
        case 1:
        case 3:
        {   // board eb2 / eb4   
            ret = &serv_config_sk_skin_eb2_eb4; 
        } break;  

        case 9:
        case 10:
        {   // board eb10 / eb11   
            ret = &serv_config_sk_skin_eb10_eb11; 
        } break;         
        
        default:    
        {   // all the others
            ret = NULL;
        } break;
    
    }

    return(ret);        
}

// ok, verified by marco.accame on 07jan16
extern const eOmn_serv_configuration_t * eoboardconfig_code2inertials_serv_configuration(uint32_t code)
{
    const eOmn_serv_configuration_t * ret = NULL;

//    #warning --> rimuovo inerziali per debug sul viola che ha problemi sul can2 della eb2
//    return(NULL);
    
    switch(code)
    {
        case 1:
        case 3:
        {   // board eb2 / eb4   
            ret = &serv_config_as_inertial_eb2_eb4; 
        } break;  

        case 9:
        case 10:
        {   // board eb10 / eb11   
            ret = &serv_config_as_inertial_eb10_eb11; 
        } break;        
        
        default:    
        {   // all the others
            ret = NULL;
        } break;
    
    }

    return(ret);        
}


// --------------------------------------------------------------------------------------------------------------------
// - definition of extern hidden functions 
// --------------------------------------------------------------------------------------------------------------------
// empty-section

// --------------------------------------------------------------------------------------------------------------------
// - definition of static functions 
// --------------------------------------------------------------------------------------------------------------------
// empty-section


// --------------------------------------------------------------------------------------------------------------------
// - end-of-file (leave a blank line after)
// --------------------------------------------------------------------------------------------------------------------




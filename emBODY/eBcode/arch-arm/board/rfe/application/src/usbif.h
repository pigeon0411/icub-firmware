/*
 * Copyright (C) 2018 iCub Facility - Istituto Italiano di Tecnologia
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
#ifndef _USBIF_H_
#define _USBIF_H_

#ifdef __cplusplus
extern "C" {
#endif
    
    
// - doxy begin -------------------------------------------------------------------------------------------------------

/** @file       usbif.h
    @brief      This header file implements public interface to the stm32 hal library, when initialised by cube-mx.
    @author     marco.accame@iit.it
    @date       03/21/2017
**/

/** @defgroup d e 

    The cdcd is ..... 
    
    @{        
 **/


// - external dependencies --------------------------------------------------------------------------------------------  
    
#include "stdint.h"   
#include "stdbool.h" 




// - public #define  --------------------------------------------------------------------------------------------------
// empty-section
  

// - declaration of public user-defined types -------------------------------------------------------------------------    

extern void usbif_init(void);

extern void usbif_process(void);

// - declaration of extern public functions ---------------------------------------------------------------------------





/** @}            
    end of group stm32hal_lib_api  
 **/

#ifdef __cplusplus
}       // closing brace for extern "C"
#endif 

#endif  // include-guard


// - end-of-file (leave a blank line after)----------------------------------------------------------------------------

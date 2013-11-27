
// - include guard ----------------------------------------------------------------------------------------------------
#ifndef _EOPID_H_
#define _EOPID_H_

#ifdef __cplusplus
extern "C" {
#endif

/** @file       EOpid.h
    @brief      This header file implements public interface to PID controller.
    @author     alessandro.scalzo@iit.it
    @date       27/03/2012
**/

/** @defgroup eo_pid Object EOpid
    Does something.
     
    @{        
 **/


// - external dependencies --------------------------------------------------------------------------------------------

#include "EoCommon.h"


// - public #define  --------------------------------------------------------------------------------------------------



// - declaration of public user-defined types ------------------------------------------------------------------------- 

 

/** @typedef    typedef struct EOpid_hid EOpid
    @brief      EOpid is an opaque struct. It is used to implement data abstraction for the 
                object so that the user cannot see its private fields and he/she is forced to manipulate the
                object only with the proper public functions. 
 **/  
typedef struct EOpid_hid EOpid;

typedef enum { NO_FILTER = 0, CUT_FREQ_1_1_Hz = 11, CUT_FREQ_3_0_Hz = 30 } filter_cut_freq_t;

// - declaration of extern public variables, ... but better using use _get/_set instead -------------------------------
// empty-section


// - declaration of extern public functions ---------------------------------------------------------------------------
 
 
/** @fn         extern EOpid* eo_pid_New(void)
    @brief      Creates a new pid object 
    @return     The pointer to the required object.
 **/
extern EOpid* eo_pid_New(void);


/** @fn         extern void eo_pid_Init(EOpid *o, float Kp, float Kd, float Ki, float Ymax)
    @brief      Sets PID gain parameters and output limit.   
    @param      o     The pointer to the pid object.
    @param      Kp    The proportional gain.         
    @param      Kd    The derivative gain.
    @param      Ki    The integrative gain.
    @param      Ko    The constant offset.
    @param      Ymax  The output maximum value.
 **/

extern void eo_pid_SetPid(EOpid *o, float K, float Kd, float Ki, float Imax, int32_t pwm_max, int32_t pwm_offset);

extern void eo_pid_GetStatus(EOpid *o, int32_t *pwm, int32_t *err);

extern void eo_pid_Reset(EOpid *o);

/** @fn         extern float eo_pid_PWM(EOpid *o, float En)
    @brief      Executes a PID control step.
    @param      o  The pointer to the pid object.
    @param      En The error between measure and setpoint.
    @return     The actual PWM output value.
 **/

extern int32_t eo_pid_PWM_pi(EOpid *o, float Tr, float Tm);
extern int32_t eo_pid_PWM_pi_1_1Hz_1stLPF(EOpid *o, float Tr, float Tm);
extern int32_t eo_pid_PWM_pi_3_0Hz_1stLPF(EOpid *o, float Tr, float Tm);
extern int32_t eo_pid_PWM_pi_1_1Hz_2ndLPF(EOpid *o, float Tr, float Tm);
extern int32_t eo_pid_PWM_pi_3_0Hz_2ndLPF(EOpid *o, float Tr, float Tm);
extern int32_t eo_pid_PWM_piv(EOpid *o, float En, float Venc, float Vref, float Aref);
//extern int32_t eo_pid_PWM_pid(EOpid *o, float En);
extern int32_t eo_pid_PWM_pid(EOpid *o, float En, float Vref);

/** @}            
    end of group eo_pid  
 **/

#ifdef __cplusplus
}       // closing brace for extern "C"
#endif 

#endif  // include-guard


// - end-of-file (leave a blank line after)----------------------------------------------------------------------------

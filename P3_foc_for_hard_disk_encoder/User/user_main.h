#ifndef _USER_MAIN_H
#define _USER_MAIN_H

#ifdef __cplusplus
extern "C"
{
#endif
/*------------- C Scope -------------*/
#include "stdint.h"
#include "main.h"
#include "tim.h"
#include "spi.h"
#include "gpio.h"
#include "usart.h"
#include "adc.h"
#include "dma.h"
#include "vofa.h"

    void user_main(void);

    // 原始采集数据
    typedef struct
    {
        uint16_t ADC1_raw_data[2]; // ADC1采集原始数据
    } Raw_data_typedef;
    extern Raw_data_typedef Raw_data;

#ifdef __cplusplus
}
/*-------------- C++ Scope --------*/
/*cpp用的和带<cstdint>的放下面*/
#include <cstdio>
#include "math_utils.h"
#include <cmath>
#include "encoder.h"
// #include "encoder.h"
// #include "driver.h"
// #include "pid.h"
// #include "low_side_current_sense.h"
// #include "math_utils.h"
#include "motor.h"

#endif
#endif

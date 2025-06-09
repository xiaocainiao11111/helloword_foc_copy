#include "user_main.h"

// #include <stdio.h>
Raw_data_typedef Raw_data;

extern uint8_t cmd;
extern bool enabled;
extern float phaseResistance;
extern int polePairs; // 极对数
extern float voltageA, voltageB, voltageC;
extern float estimateAngle;
extern float electricalAngle;
extern float estimateVelocity;
extern float setPointCurrent;
extern float setPointVelocity;
extern float setPointAngle;
extern uint64_t openLoopTimestamp;

extern float deltaT;

extern float _angle;

extern float t0, t1, t2;
extern float dutyA;
extern float dutyB;
extern float dutyC;

extern float voltagePowerSupply;

extern uint16_t PERIOD_COUNT;

extern uint64_t t;

// uint32_t ADC1_raw_data[2];

float user_voltageQ = 4, user_angle = 0;

void user_main(void)
{
  __HAL_TIM_CLEAR_IT(&htim2, TIM_IT_UPDATE);
  HAL_TIM_Base_Start_IT(&htim2);
  HAL_ADCEx_Calibration_Start(&hadc1);
  HAL_ADC_Start_DMA(&hadc1, (uint32_t *)(Raw_data.ADC1_raw_data), 2);
  HAL_Delay(5);
  HAL_TIM_PWM_Start(&htim1, TIM_CHANNEL_1);
  HAL_TIMEx_PWMN_Start(&htim1, TIM_CHANNEL_1);
  HAL_TIM_PWM_Start(&htim1, TIM_CHANNEL_2);
  HAL_TIMEx_PWMN_Start(&htim1, TIM_CHANNEL_2);
  HAL_TIM_PWM_Start(&htim1, TIM_CHANNEL_3);
  HAL_TIMEx_PWMN_Start(&htim1, TIM_CHANNEL_3);

  // encoder.Init();

  // motor.AttachDriver(&driver);
  Encoder_Init();
  HAL_Delay(5);

  while (1)
  {
    VelocityOpenLoopTick(user_voltageQ, user_angle);
    // HAL_UART_Receive_IT(&huart1, &cmd, 1);
    // HAL_Delay(1);
  }
}

void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
  if (htim == &htim2)
  {

    if (Raw_data.ADC1_raw_data[1] > 0xFF0)
    {
      user_voltageQ = user_voltageQ + 0.01;
      if (user_voltageQ >= 12)
      {
        user_voltageQ = 12;
      }
    }
    if (Raw_data.ADC1_raw_data[1] < 0x00F)
    {
      user_voltageQ = user_voltageQ - 0.01;
      if (user_voltageQ <= 4)
      {
        user_voltageQ = 4;
      }
    }
    if (Raw_data.ADC1_raw_data[0] > 0xFF0)
    {
      user_angle = user_angle + 0.02;
    }
    if (Raw_data.ADC1_raw_data[0] < 0x00F)
    {
      user_angle = user_angle - 0.02;
    }
    _angle = GetRawAngle();
    // HAL_UART_Transmit_DMA(&huart1, &Tx_data[0], 4);

    // float ff[10] = {voltageA, voltageB, voltageC, estimateAngle, t0, t1, t2, (float)t, _angle,user_voltageQ};
    // Vofa_JustFloat(ff, 10);

    float ff[6] = {voltageA, voltageB, voltageC, estimateAngle, user_voltageQ, user_angle};
    Vofa_JustFloat(ff, 6);
  }
}

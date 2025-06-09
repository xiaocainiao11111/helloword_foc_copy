#ifndef _ENCODER_H_
#define _ENCODER_H_

#include "user_main.h"

float GetRawAngle();
void Encoder_Init();
float GetVelocity();
float GetFullAngle();
enum Direction
{
    CW = 1,
    CCW = -1,
    UNKNOWN = 0
};

extern Direction countDirection;

#endif

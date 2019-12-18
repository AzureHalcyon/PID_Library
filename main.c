/**
  ******************************************************************************
  * @file    main.c
  * @author  Hongxi Wong
  * @version V1.0.3
  * @date    2019/12/17
  * @brief   
  ******************************************************************************
  * @attention 
  *
  ******************************************************************************
  */
#include <stdio.h>
#include <stdint.h>
#include <windows.h>
#include "PID.h"

PID_TypeDef PID_Example;
uint16_t measure = 0;

int main()
{
    //pid��������
    PID_Init(&PID_Example);

    //pid������ʼ��
    PID_Example.PID_param_init(&PID_Example, 9600, 5000, 3, 1, 5, 0.3, 0.3, 100, 100, ErrorHandle | Integral_Limit | OutputFilter);

    //�޸�kp ki kd
    PID_Example.PID_reset(&PID_Example, 3, 1, 0);

    //���� measureΪ���ض������ֵ
    PID_Example.PID_Calc(&PID_Example, measure);

    system("pause");
    return 0;
}
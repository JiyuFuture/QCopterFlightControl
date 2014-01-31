/*=====================================================================================================*/
/*=====================================================================================================*/
#include "stm32f4_system.h"
#include "QCopterFC_param.h"
#include "module_sensor.h"
#include "algorithm_quaternion.h"
/*=====================================================================================================*/
/*=====================================================================================================*/
extern u8 Time_Min;
extern u8 Time_Sec;
extern u16 SysTick_Cnt;

PARAM_ST PARAM[PARAM_SIZE] = {0};
/*=====================================================================================================*/
/*=====================================================================================================*/
void Param_Init( PARAM_ST *PARAM_INIT )
{
  /* Time */
  PARAM_INIT[TIME_MIN].TYPE  = TYPE_U8;
  PARAM_INIT[TIME_MIN].NAME  = (u8*)"TIME.M";
  PARAM_INIT[TIME_MIN].ADDR  = (void*)(&Time_Min);
  PARAM_INIT[TIME_SEC].TYPE  = TYPE_U8;
  PARAM_INIT[TIME_SEC].NAME  = (u8*)"TIME.S";
  PARAM_INIT[TIME_SEC].ADDR  = (void*)(&Time_Sec);
  PARAM_INIT[TIME_MSEC].TYPE = TYPE_U16;
  PARAM_INIT[TIME_MSEC].NAME = (u8*)"TIME.CNT";
  PARAM_INIT[TIME_MSEC].ADDR = (void*)(&SysTick_Cnt);

PARAM_INIT[PID_KP].TYPE = TYPE_FP32;
PARAM_INIT[PID_KP].NAME = (u8*)"PID.KP";
PARAM_INIT[PID_KP].ADDR = NULL;
PARAM_INIT[PID_KI].TYPE = TYPE_FP32;
PARAM_INIT[PID_KI].NAME = (u8*)"PID.KI";
PARAM_INIT[PID_KI].ADDR = NULL;
PARAM_INIT[PID_KD].TYPE = TYPE_FP32;
PARAM_INIT[PID_KD].NAME = (u8*)"PID.KD";
PARAM_INIT[PID_KD].ADDR = NULL;

PARAM_INIT[THROTTLE_CH1].TYPE = TYPE_U16;
PARAM_INIT[THROTTLE_CH1].NAME = (u8*)"THR.CH1";
PARAM_INIT[THROTTLE_CH1].ADDR = NULL;
PARAM_INIT[THROTTLE_CH2].TYPE = TYPE_U16;
PARAM_INIT[THROTTLE_CH2].NAME = (u8*)"THR.CH2";
PARAM_INIT[THROTTLE_CH2].ADDR = NULL;
PARAM_INIT[THROTTLE_CH3].TYPE = TYPE_U16;
PARAM_INIT[THROTTLE_CH3].NAME = (u8*)"THR.CH3";
PARAM_INIT[THROTTLE_CH3].ADDR = NULL;
PARAM_INIT[THROTTLE_CH4].TYPE = TYPE_U16;
PARAM_INIT[THROTTLE_CH4].NAME = (u8*)"THR.CH4";
PARAM_INIT[THROTTLE_CH4].ADDR = NULL;
PARAM_INIT[THROTTLE_CH5].TYPE = TYPE_U16;
PARAM_INIT[THROTTLE_CH5].NAME = (u8*)"THR.CH5";
PARAM_INIT[THROTTLE_CH5].ADDR = NULL;
PARAM_INIT[THROTTLE_CH6].TYPE = TYPE_U16;
PARAM_INIT[THROTTLE_CH6].NAME = (u8*)"THR.CH6";
PARAM_INIT[THROTTLE_CH6].ADDR = NULL;

PARAM_INIT[BATTERY_VOL].TYPE = TYPE_FP32;
PARAM_INIT[BATTERY_VOL].NAME = (u8*)"BAT.VOL";
PARAM_INIT[BATTERY_VOL].ADDR = NULL;
PARAM_INIT[BATTERY_CUR].TYPE = TYPE_FP32;
PARAM_INIT[BATTERY_CUR].NAME = (u8*)"BAT.CUR";
PARAM_INIT[BATTERY_CUR].ADDR = NULL;
PARAM_INIT[BATTERY_CAP].TYPE = TYPE_FP32;
PARAM_INIT[BATTERY_CAP].NAME = (u8*)"BAT.CAP";
PARAM_INIT[BATTERY_CAP].ADDR = NULL;

  /* Accelerometer */
  PARAM_INIT[SENSOR_ACC_X].TYPE = TYPE_FP32;
  PARAM_INIT[SENSOR_ACC_X].NAME = (u8*)"ACC.X";
  PARAM_INIT[SENSOR_ACC_X].ADDR = (void*)(&Acc.TrueX);
  PARAM_INIT[SENSOR_ACC_Y].TYPE = TYPE_FP32;
  PARAM_INIT[SENSOR_ACC_Y].NAME = (u8*)"ACC.Y";
  PARAM_INIT[SENSOR_ACC_Y].ADDR = (void*)(&Acc.TrueY);
  PARAM_INIT[SENSOR_ACC_Z].TYPE = TYPE_FP32;
  PARAM_INIT[SENSOR_ACC_Z].NAME = (u8*)"ACC.Z";
  PARAM_INIT[SENSOR_ACC_Z].ADDR = (void*)(&Acc.TrueZ);

  /* Gyroscope */
  PARAM_INIT[SENSOR_GYR_X].TYPE = TYPE_FP32;
  PARAM_INIT[SENSOR_GYR_X].NAME = (u8*)"GYR.X";
  PARAM_INIT[SENSOR_GYR_X].ADDR = (void*)(&Gyr.TrueX);
  PARAM_INIT[SENSOR_GYR_Y].TYPE = TYPE_FP32;
  PARAM_INIT[SENSOR_GYR_Y].NAME = (u8*)"GYR.Y";
  PARAM_INIT[SENSOR_GYR_Y].ADDR = (void*)(&Gyr.TrueY);
  PARAM_INIT[SENSOR_GYR_Z].TYPE = TYPE_FP32;
  PARAM_INIT[SENSOR_GYR_Z].NAME = (u8*)"GYR.Z";
  PARAM_INIT[SENSOR_GYR_Z].ADDR = (void*)(&Gyr.TrueZ);

  /* Magnetometer */
  PARAM_INIT[SENSOR_MAG_X].TYPE = TYPE_FP32;
  PARAM_INIT[SENSOR_MAG_X].NAME = (u8*)"MAG.X";
  PARAM_INIT[SENSOR_MAG_X].ADDR = (void*)(&Mag.TrueX);
  PARAM_INIT[SENSOR_MAG_Y].TYPE = TYPE_FP32;
  PARAM_INIT[SENSOR_MAG_Y].NAME = (u8*)"MAG.Y";
  PARAM_INIT[SENSOR_MAG_Y].ADDR = (void*)(&Mag.TrueY);
  PARAM_INIT[SENSOR_MAG_Z].TYPE = TYPE_FP32;
  PARAM_INIT[SENSOR_MAG_Z].NAME = (u8*)"MAG.Z";
  PARAM_INIT[SENSOR_MAG_Z].ADDR = (void*)(&Mag.TrueZ);

  /* Barometer */
  PARAM_INIT[BARO_TEMP].TYPE   = TYPE_FP32;
  PARAM_INIT[BARO_TEMP].NAME   = (u8*)"BARO.T";
  PARAM_INIT[BARO_TEMP].ADDR   = (void*)(&Baro.Temp);
  PARAM_INIT[BARO_PRESS].TYPE  = TYPE_FP32;
  PARAM_INIT[BARO_PRESS].NAME  = (u8*)"BARO.P";
  PARAM_INIT[BARO_PRESS].ADDR  = (void*)(&Baro.Press);
  PARAM_INIT[BARO_HEIGHT].TYPE = TYPE_FP32;
  PARAM_INIT[BARO_HEIGHT].NAME = (u8*)"BARO.H";
  PARAM_INIT[BARO_HEIGHT].ADDR = (void*)(&Baro.Height);

  /* Attitude Angle */
  PARAM_INIT[MOTION_ANG_X].TYPE = TYPE_FP32;
  PARAM_INIT[MOTION_ANG_X].NAME = (u8*)"ANG.X";
  PARAM_INIT[MOTION_ANG_X].ADDR = (void*)(&AngE.Pitch);
  PARAM_INIT[MOTION_ANG_Y].TYPE = TYPE_FP32;
  PARAM_INIT[MOTION_ANG_Y].NAME = (u8*)"ANG.Y";
  PARAM_INIT[MOTION_ANG_Y].ADDR = (void*)(&AngE.Roll);
  PARAM_INIT[MOTION_ANG_Z].TYPE = TYPE_FP32;
  PARAM_INIT[MOTION_ANG_Z].NAME = (u8*)"ANG.Z";
  PARAM_INIT[MOTION_ANG_Z].ADDR = (void*)(&AngE.Yaw);

PARAM_INIT[MOTION_VEL_X].TYPE = TYPE_FP32;
PARAM_INIT[MOTION_VEL_X].NAME = (u8*)"VEL.X";
PARAM_INIT[MOTION_VEL_X].ADDR = NULL;
PARAM_INIT[MOTION_VEL_Y].TYPE = TYPE_FP32;
PARAM_INIT[MOTION_VEL_Y].NAME = (u8*)"VEL.Y";
PARAM_INIT[MOTION_VEL_Y].ADDR = NULL;
PARAM_INIT[MOTION_VEL_Z].TYPE = TYPE_FP32;
PARAM_INIT[MOTION_VEL_Z].NAME = (u8*)"VEL.Z";
PARAM_INIT[MOTION_VEL_Z].ADDR = NULL;

PARAM_INIT[MOTION_POS_X].TYPE = TYPE_FP32;
PARAM_INIT[MOTION_POS_X].NAME = (u8*)"POS.X";
PARAM_INIT[MOTION_POS_X].ADDR = NULL;
PARAM_INIT[MOTION_POS_Y].TYPE = TYPE_FP32;
PARAM_INIT[MOTION_POS_Y].NAME = (u8*)"POS.Y";
PARAM_INIT[MOTION_POS_Y].ADDR = NULL;
PARAM_INIT[MOTION_POS_Z].TYPE = TYPE_FP32;
PARAM_INIT[MOTION_POS_Z].NAME = (u8*)"POS.Z";
PARAM_INIT[MOTION_POS_Z].ADDR = NULL;

PARAM_INIT[GPS_LON].TYPE = TYPE_FP32;
PARAM_INIT[GPS_LON].NAME = (u8*)"GPS.LON";
PARAM_INIT[GPS_LON].ADDR = NULL;
PARAM_INIT[GPS_LAT].TYPE = TYPE_FP32;
PARAM_INIT[GPS_LAT].NAME = (u8*)"GPS.LAT";
PARAM_INIT[GPS_LAT].ADDR = NULL;
}
/*=====================================================================================================*/
/*=====================================================================================================*/
#include "mruby.h"
#include "mruby/data.h"
#include "mruby/array.h"
#include "mruby/variable.h"

#include "m5mruby.h"

#include "mrb_m5stack.h"

#include "M5Stack.h"
//#include "utility/MPU6886.h"
#include "utility/MPU9250.h"

#include <driver/i2c.h>
#include <esp_log.h>
#include <freertos/FreeRTOS.h>
#include <freertos/task.h>
#include <stdio.h>
#include "sdkconfig.h"

#define SDA_PIN 21
#define SCL_PIN 22

//https://github.com/nkolban/esp32-snippets/blob/master/i2c/scanner/i2cscanner.c
static void scan(){
	printf(">> i2cScanner\n");
	i2c_config_t conf;
	conf.mode = I2C_MODE_MASTER;
	conf.sda_io_num = (gpio_num_t)SDA_PIN;
	conf.scl_io_num = (gpio_num_t)SCL_PIN;
	conf.sda_pullup_en = GPIO_PULLUP_ENABLE;
	conf.scl_pullup_en = GPIO_PULLUP_ENABLE;
	conf.master.clk_speed = 100000;
	i2c_param_config(I2C_NUM_0, &conf);

	i2c_driver_install(I2C_NUM_0, I2C_MODE_MASTER, 0, 0, 0);

	int i;
	esp_err_t espRc;
	printf("     0  1  2  3  4  5  6  7  8  9  a  b  c  d  e  f\n");
	printf("00:         ");
	for (i=3; i< 0x78; i++) {
		i2c_cmd_handle_t cmd = i2c_cmd_link_create();
		i2c_master_start(cmd);
		i2c_master_write_byte(cmd, (i << 1) | I2C_MASTER_WRITE, 1 /* expect ack */);
		i2c_master_stop(cmd);

		espRc = i2c_master_cmd_begin(I2C_NUM_0, cmd, 10/portTICK_PERIOD_MS);
		if (i%16 == 0) {
			printf("\n%.2x:", i);
		}
		if (espRc == 0) {
			printf(" %.2x", i);
		} else {
			printf(" --");
		}
		//ESP_LOGD(tag, "i=%d, rc=%d (0x%x)", i, espRc, espRc);
		i2c_cmd_link_delete(cmd);
	}
	printf("\n");
}

static MPU9250 *mpu9250;

mrb_value mrb_m5stack_imu_init(mrb_state *mrb, mrb_value self)
{
  //scan();
  //M5.IMU.Init();
  mpu9250 = new MPU9250();
  mpu9250->calibrateMPU9250(mpu9250->gyroBias, mpu9250->accelBias);
  mpu9250->initMPU9250();
  mpu9250->initAK8963(mpu9250->magCalibration);
  return self;
}
mrb_value mrb_m5stack_imu_calibrate(mrb_state *mrb, mrb_value self)
{
  return self;
}
mrb_value mrb_m5stack_imu_read_byte(mrb_state *mrb, mrb_value self)
{
  return self;
}
mrb_value mrb_m5stack_imu_read_gyro(mrb_state *mrb, mrb_value self)
{  
  float ax=0,ay=0,az=0;
  //M5.IMU.getGyroData(&ax,&ay,&az);
  mrb_value v[3];
  v[0] = mrb_float_value(mrb,(mrb_float)ax);
  v[1] = mrb_float_value(mrb,(mrb_float)ay);
  v[2] = mrb_float_value(mrb,(mrb_float)az);
  return mrb_ary_new_from_values(mrb,3,v);
}
mrb_value mrb_m5stack_imu_read_accel(mrb_state *mrb, mrb_value self)
{
  float ax=0,ay=0,az=0;
  //M5.IMU.getAccelData(&ax,&ay,&az);
  if(mpu9250->readByte(MPU9250_ADDRESS, INT_STATUS) & 0x01){
  mpu9250->readAccelData(mpu9250->accelCount);
  mpu9250->getAres();
  mpu9250->ax = (float)mpu9250->accelCount[0] * mpu9250->aRes; // - accelBias[0];
  mpu9250->ay = (float)mpu9250->accelCount[1] * mpu9250->aRes; // - accelBias[1];
  mpu9250->az = (float)mpu9250->accelCount[2] * mpu9250->aRes; // - accelBias[2];

  ax = mpu9250->ax;
  ay = mpu9250->ay;
  az = mpu9250->az;
  //printf("%f,%f,%f\n",ax,ay,az);
  }else{
    //printf("mpu9250 not ready\n");
  }

  mrb_value v[3];
  v[0] = mrb_float_value(mrb,(mrb_float)ax);
  v[1] = mrb_float_value(mrb,(mrb_float)ay);
  v[2] = mrb_float_value(mrb,(mrb_float)az);
  mrb_ary_new_from_values(mrb,3,v);
  return mrb_ary_new_from_values(mrb,3,v);
}

/*
 * Copyright (c) 2006-2021, RT-Thread Development Team
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Change Logs:
 * Date           Author        Notes
 * 2021-10-10     Sherman       first version
 * 2021-11-03     Sherman       Add icu_sample
 */

#include <rtthread.h>
#include "hal_data.h"
#include <rtdevice.h>

#include "mpu6xxx.h"
#include "mpu6xxx_reg.h"

#include "drv_soft_i2c.h"

#include "sensor_inven_mpu6xxx.h"

//int rt_hw_mpu6xxx_port(void)
//{
//    struct rt_sensor_config cfg;
//
//    cfg.intf.dev_name = "i2c1";
//    cfg.intf.user_data = (void *)MPU6XXX_ADDR_DEFAULT;
//    cfg.irq_pin.pin = RT_PIN_NONE;
//
//    rt_hw_mpu6xxx_init("mpu", &cfg);
//
//
//    return 0;
//}

//INIT_APP_EXPORT(rt_hw_mpu6xxx_port);

#define LED3_PIN    BSP_IO_PORT_01_PIN_06
#define USER_INPUT  "P105"

#define ADC_DEV_NAME "adc0"
#define ADC_DEV_CHANNEL 4
#define REFER_VOLTAGE 330
#define CONVERT_BITS (1 << 12)

static void sensor_read_data(void)
{
    rt_adc_device_t adc_dev;
    rt_uint32_t value, vol;
    rt_err_t ret = RT_EOK;
    adc_dev = (rt_adc_device_t)rt_device_find(ADC_DEV_NAME);
    if (adc_dev == RT_NULL)
    {
        rt_kprintf("adc sample run failed! can't find %s device!\n",
                ADC_DEV_NAME);
        return RT_ERROR;
    }
    ret = rt_adc_enable(adc_dev, ADC_DEV_CHANNEL);
    value = rt_adc_read(adc_dev, ADC_DEV_CHANNEL);
    ret = rt_adc_disable(adc_dev, ADC_DEV_CHANNEL);
    vol = value * REFER_VOLTAGE / CONVERT_BITS;
    rt_kprintf("the voltage is :%d.%02d \n", vol / 100, vol % 100);
}

MSH_CMD_EXPORT(sensor_read_data, sensor_read_data);




void hal_entry(void)
{
    struct mpu6xxx_device* mpu6050_i2c_bus;
    struct mpu6xxx_3axes gyro,accel;
//    char str[20];

//    rt_kprintf("\nHello RT-Thread!\n");
//    mpu6050_i2c_bus = (struct mpu6xxx_device *)mpu6xxx_init("i2c1", MPU6XXX_ADDRESS_AD0_LOW);   //初始化MPU6050，测量单位为角速度，加速度    while(count++)
//    mpu6xxx_set_param(mpu6050_i2c_bus, MPU6XXX_ACCEL_RANGE, MPU6XXX_GYRO_RANGE_2000DPS);  //陀螺仪范围配置
//    mpu6xxx_set_param(mpu6050_i2c_bus, MPU6XXX_ACCEL_RANGE, MPU6XXX_ACCEL_RANGE_2G);     //加速度计，一般设置为±2G
//    mpu6xxx_set_param(mpu6050_i2c_bus, MPU6XXX_SAMPLE_RATE, 50);                       //采样频率
//    mpu6xxx_set_param(mpu6050_i2c_bus, MPU6XXX_DLPF_CONFIG, 25);                       //数字低通滤波器设置，一般为1/2采样率



    struct rt_sensor_config cfg;

    cfg.intf.dev_name = "i2c1";
    cfg.intf.user_data = (void *)MPU6XXX_ADDR_DEFAULT;
    cfg.irq_pin.pin = RT_PIN_NONE;
    rt_hw_mpu6xxx_init("mpu", &cfg);


    rt_pin_write(LED3_PIN, PIN_HIGH);
    while (1)
    {
//        rt_pin_write(LED3_PIN, PIN_HIGH);
//        rt_thread_mdelay(500);
//        rt_pin_write(LED3_PIN, PIN_LOW);
//        rt_thread_mdelay(500);


        mpu6xxx_get_gyro(mpu6050_i2c_bus, &gyro);

        rt_kprintf("gyro.x=%d,gyro.y=%d,gyro.z=%d\r\n",gyro.x,gyro.y,gyro.z);

//        sprintf(str,"gyro.x=%d\r\n",gyro.x);
//        rt_kprintf(str);
//
//        sprintf(str,"gyro.y=%d\r\n",gyro.y);
//        rt_kprintf(str);
//
//        sprintf(str,"gyro.z=%d\r\n",gyro.z);
//        rt_kprintf(str);


        mpu6xxx_get_accel(mpu6050_i2c_bus,&accel);

        rt_kprintf("gyro.x=%d,gyro.y=%d,gyro.z=%d\r\n",accel.x,accel.y,accel.z);

//        sprintf(str,"accel.x=%d\r\n",accel.x);
//        rt_kprintf(str);
//        sprintf(str,"accel.y=%d\r\n",accel.y);
//        rt_kprintf(str);
//        sprintf(str,"accel.z=%d\r\n",accel.z);
//        rt_kprintf(str);
        rt_thread_mdelay(1000);
    }
}

void irq_callback_test(void *args)
{
    rt_kprintf("\n IRQ00 triggered \n");
}

void icu_sample(void)
{
    /* init */
    rt_uint32_t pin = rt_pin_get(USER_INPUT);
    rt_kprintf("\n pin number : 0x%04X \n", pin);
    rt_err_t err = rt_pin_attach_irq(pin, PIN_IRQ_MODE_RISING, irq_callback_test, RT_NULL);
    if(RT_EOK != err)
    {
        rt_kprintf("\n attach irq failed. \n");
    }
    err = rt_pin_irq_enable(pin, PIN_IRQ_ENABLE);
    if(RT_EOK != err)
    {
        rt_kprintf("\n enable irq failed. \n");
    }
}
MSH_CMD_EXPORT(icu_sample, icu sample);

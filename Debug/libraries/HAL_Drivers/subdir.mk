################################################################################
# 自动生成的文件。不要编辑！
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../libraries/HAL_Drivers/drv_adc.c \
../libraries/HAL_Drivers/drv_common.c \
../libraries/HAL_Drivers/drv_gpio.c \
../libraries/HAL_Drivers/drv_soft_i2c.c \
../libraries/HAL_Drivers/drv_usart_v2.c 

OBJS += \
./libraries/HAL_Drivers/drv_adc.o \
./libraries/HAL_Drivers/drv_common.o \
./libraries/HAL_Drivers/drv_gpio.o \
./libraries/HAL_Drivers/drv_soft_i2c.o \
./libraries/HAL_Drivers/drv_usart_v2.o 

C_DEPS += \
./libraries/HAL_Drivers/drv_adc.d \
./libraries/HAL_Drivers/drv_common.d \
./libraries/HAL_Drivers/drv_gpio.d \
./libraries/HAL_Drivers/drv_soft_i2c.d \
./libraries/HAL_Drivers/drv_usart_v2.d 


# Each subdirectory must supply rules for building sources it contributes
libraries/HAL_Drivers/%.o: ../libraries/HAL_Drivers/%.c
	arm-none-eabi-gcc -I"D:\Embedded_Development\RT-ThreadStudio\workspace\RA6M4_2022_0714" -I"D:\Embedded_Development\RT-ThreadStudio\workspace\RA6M4_2022_0714\board\ports" -I"D:\Embedded_Development\RT-ThreadStudio\workspace\RA6M4_2022_0714\board" -I"D:\Embedded_Development\RT-ThreadStudio\workspace\RA6M4_2022_0714\libraries\HAL_Drivers\config" -I"D:\Embedded_Development\RT-ThreadStudio\workspace\RA6M4_2022_0714\libraries\HAL_Drivers" -I"D:\Embedded_Development\RT-ThreadStudio\workspace\RA6M4_2022_0714\packages\mpu6xxx-latest\inc" -I"D:\Embedded_Development\RT-ThreadStudio\workspace\RA6M4_2022_0714\ra\arm\CMSIS_5\CMSIS\Core\Include" -I"D:\Embedded_Development\RT-ThreadStudio\workspace\RA6M4_2022_0714\ra\fsp\inc\api" -I"D:\Embedded_Development\RT-ThreadStudio\workspace\RA6M4_2022_0714\ra\fsp\inc\instances" -I"D:\Embedded_Development\RT-ThreadStudio\workspace\RA6M4_2022_0714\ra\fsp\inc" -I"D:\Embedded_Development\RT-ThreadStudio\workspace\RA6M4_2022_0714\ra_cfg\fsp_cfg\bsp" -I"D:\Embedded_Development\RT-ThreadStudio\workspace\RA6M4_2022_0714\ra_cfg\fsp_cfg" -I"D:\Embedded_Development\RT-ThreadStudio\workspace\RA6M4_2022_0714\ra_gen" -I"D:\Embedded_Development\RT-ThreadStudio\workspace\RA6M4_2022_0714\rt-thread\components\drivers\include" -I"D:\Embedded_Development\RT-ThreadStudio\workspace\RA6M4_2022_0714\rt-thread\components\drivers\sensors" -I"D:\Embedded_Development\RT-ThreadStudio\workspace\RA6M4_2022_0714\rt-thread\components\finsh" -I"D:\Embedded_Development\RT-ThreadStudio\workspace\RA6M4_2022_0714\rt-thread\components\libc\compilers\common" -I"D:\Embedded_Development\RT-ThreadStudio\workspace\RA6M4_2022_0714\rt-thread\components\libc\compilers\newlib" -I"D:\Embedded_Development\RT-ThreadStudio\workspace\RA6M4_2022_0714\rt-thread\components\libc\posix\io\poll" -I"D:\Embedded_Development\RT-ThreadStudio\workspace\RA6M4_2022_0714\rt-thread\components\libc\posix\io\stdio" -I"D:\Embedded_Development\RT-ThreadStudio\workspace\RA6M4_2022_0714\rt-thread\components\libc\posix\ipc" -I"D:\Embedded_Development\RT-ThreadStudio\workspace\RA6M4_2022_0714\rt-thread\include" -I"D:\Embedded_Development\RT-ThreadStudio\workspace\RA6M4_2022_0714\rt-thread\libcpu\arm\common" -I"D:\Embedded_Development\RT-ThreadStudio\workspace\RA6M4_2022_0714\rt-thread\libcpu\arm\cortex-m4" -include"D:\Embedded_Development\RT-ThreadStudio\workspace\RA6M4_2022_0714\rtconfig_preinc.h" -std=gnu11 -mcpu=cortex-m33 -mthumb -mfpu=fpv5-sp-d16 -mfloat-abi=hard -ffunction-sections -fdata-sections -Dgcc -O0 -gdwarf-2 -g -Wall -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"


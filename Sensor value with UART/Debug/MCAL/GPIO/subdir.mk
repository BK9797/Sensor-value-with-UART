################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../MCAL/GPIO/gpio.c 

OBJS += \
./MCAL/GPIO/gpio.o 

C_DEPS += \
./MCAL/GPIO/gpio.d 


# Each subdirectory must supply rules for building sources it contributes
MCAL/GPIO/%.o: ../MCAL/GPIO/%.c MCAL/GPIO/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -I"/Users/bishoykamel/Documents/Study/Projects/Sensor value with UART/Libraries" -I"/Users/bishoykamel/Documents/Study/Projects/Sensor value with UART/HAL/LCD" -I"/Users/bishoykamel/Documents/Study/Projects/Sensor value with UART/MCAL/ADC" -I"/Users/bishoykamel/Documents/Study/Projects/Sensor value with UART/MCAL/GPIO" -I"/Users/bishoykamel/Documents/Study/Projects/Sensor value with UART/MCAL/UART" -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=16000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '



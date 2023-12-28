################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../MCAL/UART/uart.c 

OBJS += \
./MCAL/UART/uart.o 

C_DEPS += \
./MCAL/UART/uart.d 


# Each subdirectory must supply rules for building sources it contributes
MCAL/UART/%.o: ../MCAL/UART/%.c MCAL/UART/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -I"/Users/bishoykamel/Documents/Study/Projects/Sensor value with UART/Libraries" -I"/Users/bishoykamel/Documents/Study/Projects/Sensor value with UART/HAL/LCD" -I"/Users/bishoykamel/Documents/Study/Projects/Sensor value with UART/MCAL/ADC" -I"/Users/bishoykamel/Documents/Study/Projects/Sensor value with UART/MCAL/GPIO" -I"/Users/bishoykamel/Documents/Study/Projects/Sensor value with UART/MCAL/UART" -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=16000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '



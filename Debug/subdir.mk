################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../ADC.c \
../Buttons.c \
../Cool_Heat_Elements.c \
../EEPROM.c \
../GIE_Program.c \
../LED.c \
../SSD_disp.c \
../Timer.c \
../control.c \
../main.c 

OBJS += \
./ADC.o \
./Buttons.o \
./Cool_Heat_Elements.o \
./EEPROM.o \
./GIE_Program.o \
./LED.o \
./SSD_disp.o \
./Timer.o \
./control.o \
./main.o 

C_DEPS += \
./ADC.d \
./Buttons.d \
./Cool_Heat_Elements.d \
./EEPROM.d \
./GIE_Program.d \
./LED.d \
./SSD_disp.d \
./Timer.d \
./control.d \
./main.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega16 -DF_CPU=1000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '



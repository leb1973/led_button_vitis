################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/hw/button.c \
../src/hw/led.c 

OBJS += \
./src/hw/button.o \
./src/hw/led.o 

C_DEPS += \
./src/hw/button.d \
./src/hw/led.d 


# Each subdirectory must supply rules for building sources it contributes
src/hw/%.o: ../src/hw/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MicroBlaze gcc compiler'
	mb-gcc -Wall -O0 -g3 -c -fmessage-length=0 -MT"$@" -ID:/project/Verliog/led_button_GPIO/led_button_vitis/led_button_design_wrapper/export/led_button_design_wrapper/sw/led_button_design_wrapper/domain_microblaze_0/bspinclude/include -mlittle-endian -mcpu=v11.0 -mxl-soft-mul -Wl,--no-relax -ffunction-sections -fdata-sections -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '



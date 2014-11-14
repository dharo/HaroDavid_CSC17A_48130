################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Source/Inventory.cpp \
../Source/main.cpp 

OBJS += \
./Source/Inventory.o \
./Source/main.o 

CPP_DEPS += \
./Source/Inventory.d \
./Source/main.d 


# Each subdirectory must supply rules for building sources it contributes
Source/%.o: ../Source/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '



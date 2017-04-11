################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../solutions/mainTest.cpp 

OBJS += \
./solutions/mainTest.o 

CPP_DEPS += \
./solutions/mainTest.d 


# Each subdirectory must supply rules for building sources it contributes
solutions/%.o: ../solutions/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cygwin C++ Compiler'
	g++ -DCODE64 -I"D:\Pool\eclipse-workspace\leetcode\include" -I"C:\Users\13774\Desktop\bochs\devel\x2 system\include" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '



################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../solutions/354\ Russian\ Doll\ Envelops/mainTest.cpp 

OBJS += \
./solutions/354\ Russian\ Doll\ Envelops/mainTest.o 

CPP_DEPS += \
./solutions/354\ Russian\ Doll\ Envelops/mainTest.d 


# Each subdirectory must supply rules for building sources it contributes
solutions/354\ Russian\ Doll\ Envelops/mainTest.o: ../solutions/354\ Russian\ Doll\ Envelops/mainTest.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cygwin C++ Compiler'
	g++ -std=c++14 -DCODE64 -I"D:\Pool\eclipse-workspace\leetcode\include" -I"C:\Users\13774\Desktop\bochs\devel\x2 system\include" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"solutions/354 Russian Doll Envelops/mainTest.d" -MT"solutions/354\ Russian\ Doll\ Envelops/mainTest.d" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '



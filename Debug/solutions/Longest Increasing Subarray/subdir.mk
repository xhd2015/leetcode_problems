################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../solutions/Longest\ Increasing\ Subarray/mainTest.cpp 

OBJS += \
./solutions/Longest\ Increasing\ Subarray/mainTest.o 

CPP_DEPS += \
./solutions/Longest\ Increasing\ Subarray/mainTest.d 


# Each subdirectory must supply rules for building sources it contributes
solutions/Longest\ Increasing\ Subarray/mainTest.o: ../solutions/Longest\ Increasing\ Subarray/mainTest.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cygwin C++ Compiler'
	g++ -std=c++14 -DCODE64 -I"D:\Pool\eclipse-workspace\leetcode\include" -I"C:\Users\13774\Desktop\bochs\devel\x2 system\include" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"solutions/Longest Increasing Subarray/mainTest.d" -MT"solutions/Longest\ Increasing\ Subarray/mainTest.d" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '



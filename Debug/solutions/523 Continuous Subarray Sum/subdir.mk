################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../solutions/523\ Continuous\ Subarray\ Sum/mainTest_DP.cpp \
../solutions/523\ Continuous\ Subarray\ Sum/mainTest_slow.cpp 

OBJS += \
./solutions/523\ Continuous\ Subarray\ Sum/mainTest_DP.o \
./solutions/523\ Continuous\ Subarray\ Sum/mainTest_slow.o 

CPP_DEPS += \
./solutions/523\ Continuous\ Subarray\ Sum/mainTest_DP.d \
./solutions/523\ Continuous\ Subarray\ Sum/mainTest_slow.d 


# Each subdirectory must supply rules for building sources it contributes
solutions/523\ Continuous\ Subarray\ Sum/mainTest_DP.o: ../solutions/523\ Continuous\ Subarray\ Sum/mainTest_DP.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cygwin C++ Compiler'
	g++ -std=c++14 -DCODE64 -I"D:\Pool\eclipse-workspace\leetcode\include" -I"C:\Users\13774\Desktop\bochs\devel\x2 system\include" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"solutions/523 Continuous Subarray Sum/mainTest_DP.d" -MT"solutions/523\ Continuous\ Subarray\ Sum/mainTest_DP.d" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

solutions/523\ Continuous\ Subarray\ Sum/mainTest_slow.o: ../solutions/523\ Continuous\ Subarray\ Sum/mainTest_slow.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cygwin C++ Compiler'
	g++ -std=c++14 -DCODE64 -I"D:\Pool\eclipse-workspace\leetcode\include" -I"C:\Users\13774\Desktop\bochs\devel\x2 system\include" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"solutions/523 Continuous Subarray Sum/mainTest_slow.d" -MT"solutions/523\ Continuous\ Subarray\ Sum/mainTest_slow.d" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '



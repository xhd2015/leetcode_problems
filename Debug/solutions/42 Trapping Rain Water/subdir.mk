################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../solutions/42\ Trapping\ Rain\ Water/mainTest.cpp 

OBJS += \
./solutions/42\ Trapping\ Rain\ Water/mainTest.o 

CPP_DEPS += \
./solutions/42\ Trapping\ Rain\ Water/mainTest.d 


# Each subdirectory must supply rules for building sources it contributes
solutions/42\ Trapping\ Rain\ Water/mainTest.o: ../solutions/42\ Trapping\ Rain\ Water/mainTest.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cygwin C++ Compiler'
	g++ -std=c++14 -DCODE64 -I"D:\Pool\eclipse-workspace\leetcode\include" -I"C:\Users\13774\Desktop\bochs\devel\x2 system\include" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"solutions/42 Trapping Rain Water/mainTest.d" -MT"solutions/42\ Trapping\ Rain\ Water/mainTest.d" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '



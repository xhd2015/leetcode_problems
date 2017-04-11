################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../solutions/6\ ZigZag\ Conversion/Solution.cpp 

OBJS += \
./solutions/6\ ZigZag\ Conversion/Solution.o 

CPP_DEPS += \
./solutions/6\ ZigZag\ Conversion/Solution.d 


# Each subdirectory must supply rules for building sources it contributes
solutions/6\ ZigZag\ Conversion/Solution.o: ../solutions/6\ ZigZag\ Conversion/Solution.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cygwin C++ Compiler'
	g++ -DCODE64 -I"D:\Pool\eclipse-workspace\leetcode\include" -I"C:\Users\13774\Desktop\bochs\devel\x2 system\include" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"solutions/6 ZigZag Conversion/Solution.d" -MT"solutions/6\ ZigZag\ Conversion/Solution.d" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '



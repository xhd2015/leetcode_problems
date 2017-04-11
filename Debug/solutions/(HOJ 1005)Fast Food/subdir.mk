################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../solutions/(HOJ\ 1005)Fast\ Food/mainTest.cpp 

OBJS += \
./solutions/(HOJ\ 1005)Fast\ Food/mainTest.o 

CPP_DEPS += \
./solutions/(HOJ\ 1005)Fast\ Food/mainTest.d 


# Each subdirectory must supply rules for building sources it contributes
solutions/(HOJ\ 1005)Fast\ Food/mainTest.o: ../solutions/(HOJ\ 1005)Fast\ Food/mainTest.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cygwin C++ Compiler'
	g++ -DCODE64 -I"D:\Pool\eclipse-workspace\leetcode\include" -I"C:\Users\13774\Desktop\bochs\devel\x2 system\include" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"solutions/(HOJ 1005)Fast Food/mainTest.d" -MT"solutions/(HOJ\ 1005)Fast\ Food/mainTest.d" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '



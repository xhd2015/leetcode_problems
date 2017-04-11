################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../solutions/Algorithm\ X/ExactCover.cpp \
../solutions/Algorithm\ X/SudokuCrossList.cpp \
../solutions/Algorithm\ X/mainTest.cpp 

OBJS += \
./solutions/Algorithm\ X/ExactCover.o \
./solutions/Algorithm\ X/SudokuCrossList.o \
./solutions/Algorithm\ X/mainTest.o 

CPP_DEPS += \
./solutions/Algorithm\ X/ExactCover.d \
./solutions/Algorithm\ X/SudokuCrossList.d \
./solutions/Algorithm\ X/mainTest.d 


# Each subdirectory must supply rules for building sources it contributes
solutions/Algorithm\ X/ExactCover.o: ../solutions/Algorithm\ X/ExactCover.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cygwin C++ Compiler'
	g++ -DCODE64 -I"D:\Pool\eclipse-workspace\leetcode\include" -I"C:\Users\13774\Desktop\bochs\devel\x2 system\include" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"solutions/Algorithm X/ExactCover.d" -MT"solutions/Algorithm\ X/ExactCover.d" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

solutions/Algorithm\ X/SudokuCrossList.o: ../solutions/Algorithm\ X/SudokuCrossList.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cygwin C++ Compiler'
	g++ -DCODE64 -I"D:\Pool\eclipse-workspace\leetcode\include" -I"C:\Users\13774\Desktop\bochs\devel\x2 system\include" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"solutions/Algorithm X/SudokuCrossList.d" -MT"solutions/Algorithm\ X/SudokuCrossList.d" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

solutions/Algorithm\ X/mainTest.o: ../solutions/Algorithm\ X/mainTest.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cygwin C++ Compiler'
	g++ -DCODE64 -I"D:\Pool\eclipse-workspace\leetcode\include" -I"C:\Users\13774\Desktop\bochs\devel\x2 system\include" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"solutions/Algorithm X/mainTest.d" -MT"solutions/Algorithm\ X/mainTest.d" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '



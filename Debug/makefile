################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include solutions/[HOJ\ 1005]\ Fast\ Food\ DP/subdir.mk
-include solutions/Longest\ Increasing\ Subarray/subdir.mk
-include solutions/Algorithm\ X/subdir.mk
-include solutions/6\ ZigZag\ Conversion/subdir.mk
-include solutions/548\ Split\ Array\ With\ Equal\ Sum/subdir.mk
-include solutions/547\ Friend\ Circles/subdir.mk
-include solutions/546\ Remove\ Boxes\ DP/subdir.mk
-include solutions/523\ Continuous\ Subarray\ Sum/subdir.mk
-include solutions/522\ Longest\ Uncommon\ Subsequence\ II/subdir.mk
-include solutions/517\ Super\ Washing\ Machines/subdir.mk
-include solutions/44\ Wildcard\ Matching/subdir.mk
-include solutions/42\ Trapping\ Rain\ Water/subdir.mk
-include solutions/41\ Missing\ Positive/subdir.mk
-include solutions/37\ Sudoku\ Solver/subdir.mk
-include solutions/368\ Longest\ Divisiable\ Subset/subdir.mk
-include solutions/354\ Russian\ Doll\ Envelops/subdir.mk
-include solutions/10\ Regular\ Expression\ Matching/subdir.mk
-include solutions/subdir.mk
-include include/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(CC_DEPS)),)
-include $(CC_DEPS)
endif
ifneq ($(strip $(C++_DEPS)),)
-include $(C++_DEPS)
endif
ifneq ($(strip $(C_UPPER_DEPS)),)
-include $(C_UPPER_DEPS)
endif
ifneq ($(strip $(CXX_DEPS)),)
-include $(CXX_DEPS)
endif
ifneq ($(strip $(CPP_DEPS)),)
-include $(CPP_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 

# All Target
all: leetcode.exe

# Tool invocations
leetcode.exe: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: Cygwin C++ Linker'
	g++  -o "leetcode.exe"  $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(CC_DEPS)$(C++_DEPS)$(EXECUTABLES)$(OBJS)$(C_UPPER_DEPS)$(CXX_DEPS)$(CPP_DEPS)$(C_DEPS) leetcode.exe
	-@echo ' '

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets

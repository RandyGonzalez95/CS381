################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
ASM_SRCS += \
../material/programs/Example_FresnelPS.asm \
../material/programs/OffsetMapping_specular.asm 

OBJS += \
./material/programs/Example_FresnelPS.o \
./material/programs/OffsetMapping_specular.o 


# Each subdirectory must supply rules for building sources it contributes
material/programs/%.o: ../material/programs/%.asm
	@echo 'Building file: $<'
	@echo 'Invoking: GCC Assembler'
	as  -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '



################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/Aspect.cpp \
../src/BaseApplication.cpp \
../src/Entity381.cpp \
../src/EntityMgr.cpp \
../src/as2.cpp 

OBJS += \
./src/Aspect.o \
./src/BaseApplication.o \
./src/Entity381.o \
./src/EntityMgr.o \
./src/as2.o 

CPP_DEPS += \
./src/Aspect.d \
./src/BaseApplication.d \
./src/Entity381.d \
./src/EntityMgr.d \
./src/as2.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I"/home/randygonzalez/Desktop/CS381/PA2/include" -I/usr/local/include/OGRE/Terrain -I/usr/local/include/OGRE/Overlay -I/usr/include/ois -I/usr/local/include/OGRE -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '



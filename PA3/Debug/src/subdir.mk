################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/As3.cpp \
../src/Entity381.cpp \
../src/EntityMgr.cpp \
../src/GameMgr.cpp \
../src/InputMgr.cpp \
../src/aspect.cpp \
../src/engine.cpp \
../src/gfxMgr.cpp \
../src/mgr.cpp 

OBJS += \
./src/As3.o \
./src/Entity381.o \
./src/EntityMgr.o \
./src/GameMgr.o \
./src/InputMgr.o \
./src/aspect.o \
./src/engine.o \
./src/gfxMgr.o \
./src/mgr.o 

CPP_DEPS += \
./src/As3.d \
./src/Entity381.d \
./src/EntityMgr.d \
./src/GameMgr.d \
./src/InputMgr.d \
./src/aspect.d \
./src/engine.d \
./src/gfxMgr.d \
./src/mgr.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I"/home/randygonzalez/Desktop/CS381/PA3/include" -I/usr/local/include/OGRE/Terrain -I/home/randygonzalez/Desktop/381 -I/usr/local/include/OGRE/Overlay -I/usr/include/ois -I/usr/local/include/OGRE -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '



################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/Aspect.cpp \
../src/Command.cpp \
../src/Entity381.cpp \
../src/EntityMgr.cpp \
../src/GfxMgr.cpp \
../src/UnitAI.cpp \
../src/engine.cpp \
../src/gameMgr.cpp \
../src/inputMgr.cpp \
../src/mgr.cpp \
../src/pong.cpp 

OBJS += \
./src/Aspect.o \
./src/Command.o \
./src/Entity381.o \
./src/EntityMgr.o \
./src/GfxMgr.o \
./src/UnitAI.o \
./src/engine.o \
./src/gameMgr.o \
./src/inputMgr.o \
./src/mgr.o \
./src/pong.o 

CPP_DEPS += \
./src/Aspect.d \
./src/Command.d \
./src/Entity381.d \
./src/EntityMgr.d \
./src/GfxMgr.d \
./src/UnitAI.d \
./src/engine.d \
./src/gameMgr.d \
./src/inputMgr.d \
./src/mgr.d \
./src/pong.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -std=c++11 -I"/home/randy/workspace/Pong/include" -I/usr/local/include/OGRE/Overlay -I/usr/include/ois -I/usr/local/include/OGRE -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '



################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/Aspect.cpp \
../src/Entity381.cpp \
../src/EntityMgr.cpp \
../src/GfxMgr.cpp \
../src/Pong.cpp \
../src/UiMgr.cpp \
../src/engine.cpp \
../src/gameMgr.cpp \
../src/inputMgr.cpp \
../src/mgr.cpp 

OBJS += \
./src/Aspect.o \
./src/Entity381.o \
./src/EntityMgr.o \
./src/GfxMgr.o \
./src/Pong.o \
./src/UiMgr.o \
./src/engine.o \
./src/gameMgr.o \
./src/inputMgr.o \
./src/mgr.o 

CPP_DEPS += \
./src/Aspect.d \
./src/Entity381.d \
./src/EntityMgr.d \
./src/GfxMgr.d \
./src/Pong.d \
./src/UiMgr.d \
./src/engine.d \
./src/gameMgr.d \
./src/inputMgr.d \
./src/mgr.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I/usr/local/include/OGRE -I"/home/randy/Desktop/CS381/Pong/materials" -I"/home/randy/Desktop/CS381/Pong/inc" -I/usr/local/include/OGRE/Overlay -I/usr/include/ois -O0 -g3 -Wall -c -fmessage-length=0 -std=c++11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '



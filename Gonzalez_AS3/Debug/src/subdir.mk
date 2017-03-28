################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/Entity381.cpp \
../src/EntityMgr.cpp \
../src/GfxMgr.cpp \
../src/InputMgr.cpp \
../src/as3.cpp \
../src/aspect.cpp \
../src/engine.cpp \
../src/mgr.cpp 

OBJS += \
./src/Entity381.o \
./src/EntityMgr.o \
./src/GfxMgr.o \
./src/InputMgr.o \
./src/as3.o \
./src/aspect.o \
./src/engine.o \
./src/mgr.o 

CPP_DEPS += \
./src/Entity381.d \
./src/EntityMgr.d \
./src/GfxMgr.d \
./src/InputMgr.d \
./src/as3.d \
./src/aspect.d \
./src/engine.d \
./src/mgr.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I"/home/randygonzalez/Desktop/CS381/Gonzalez_AS3/include" -I"/home/randygonzalez/Desktop/CS381/Gonzalez_AS3/materials" -I/usr/local/include/OGRE/Terrain -I/usr/local/include/OGRE/Overlay -I/usr/include/ois -I/usr/local/include/OGRE -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '



################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/Aspects.cpp \
../src/BaseApplication.cpp \
../src/Entity381.cpp \
../src/EntityMgr.cpp \
../src/as2.cpp 

OBJS += \
./src/Aspects.o \
./src/BaseApplication.o \
./src/Entity381.o \
./src/EntityMgr.o \
./src/as2.o 

CPP_DEPS += \
./src/Aspects.d \
./src/BaseApplication.d \
./src/Entity381.d \
./src/EntityMgr.d \
./src/as2.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I"/home/randygonzalez/Desktop/CS381/Gonzalez_AS2/include" -I"/home/randygonzalez/Desktop/CS381/Gonzalez_AS2/materials" -I/usr/local/include/OGRE/Terrain -I/usr/local/include/OGRE/Overlay -I/usr/include/ois -I/usr/local/include/OGRE -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '



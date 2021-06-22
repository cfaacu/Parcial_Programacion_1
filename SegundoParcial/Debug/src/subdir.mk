################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/Aereo.c \
../src/Articulo.c \
../src/Controller.c \
../src/Dictionary.c \
../src/Informes.c \
../src/LinkedList.c \
../src/Main.c \
../src/Maritimo.c \
../src/Parser.c \
../src/PosArancelaria.c \
../src/utn.c 

OBJS += \
./src/Aereo.o \
./src/Articulo.o \
./src/Controller.o \
./src/Dictionary.o \
./src/Informes.o \
./src/LinkedList.o \
./src/Main.o \
./src/Maritimo.o \
./src/Parser.o \
./src/PosArancelaria.o \
./src/utn.o 

C_DEPS += \
./src/Aereo.d \
./src/Articulo.d \
./src/Controller.d \
./src/Dictionary.d \
./src/Informes.d \
./src/LinkedList.d \
./src/Main.d \
./src/Maritimo.d \
./src/Parser.d \
./src/PosArancelaria.d \
./src/utn.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c src/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '



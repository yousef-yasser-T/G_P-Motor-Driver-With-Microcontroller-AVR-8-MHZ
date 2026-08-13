################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include MCAL/Timer1/subdir.mk
-include MCAL/DIO/subdir.mk
-include HAL/Ultrasonic/subdir.mk
-include HAL/StateCar/subdir.mk
-include HAL/PB/subdir.mk
-include HAL/LCD/subdir.mk
-include HAL/DC_Motor/subdir.mk
-include HAL/Buzzer/subdir.mk
-include APP/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
LSS += \
Timer1_G6.lss \

FLASH_IMAGE += \
Timer1_G6.hex \

EEPROM_IMAGE += \
Timer1_G6.eep \

SIZEDUMMY += \
sizedummy \


# All Target
all: Timer1_G6.elf secondary-outputs

# Tool invocations
Timer1_G6.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,Timer1_G6.map -mmcu=atmega32 -o "Timer1_G6.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

Timer1_G6.lss: Timer1_G6.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S Timer1_G6.elf  >"Timer1_G6.lss"
	@echo 'Finished building: $@'
	@echo ' '

Timer1_G6.hex: Timer1_G6.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex Timer1_G6.elf  "Timer1_G6.hex"
	@echo 'Finished building: $@'
	@echo ' '

Timer1_G6.eep: Timer1_G6.elf
	@echo 'Create eeprom image (ihex format)'
	-avr-objcopy -j .eeprom --no-change-warnings --change-section-lma .eeprom=0 -O ihex Timer1_G6.elf  "Timer1_G6.eep"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: Timer1_G6.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 Timer1_G6.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(EEPROM_IMAGE)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) Timer1_G6.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(EEPROM_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets

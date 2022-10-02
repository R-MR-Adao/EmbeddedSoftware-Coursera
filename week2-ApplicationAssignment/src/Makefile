#******************************************************************************
# Copyright (C) 2017 by Alex Fosdick - University of Colorado
#
# Redistribution, modification or use of this software in source or binary
# forms is permitted as long as the files maintain this copyright. Users are
# permitted to modify this and use it to learn about the field of embedded
# software. Alex Fosdick and the University of Colorado are not liable for any
# misuse of this material.
#
#*****************************************************************************

#*****************************************************************************
# Compile Coursera m2 assignment project
#
# Use: make [TARGET] [PLATFORM-OVERRIDES]
#
# Build Targets:
#      Specify file names to build. Rules implemented for pre-processed (*.i),
# 		 assembly (*.asm), object (*.o) and executable (*.out) files
#
# Platform Overrides:
#      Specfiy intended compile platform.
#			 Options: HOST, MSP432
#			 Default: HOST
#
# author: Ricardo Adao
# date: 2022-10-01
#*****************************************************************************
include platform.mk
include sources.mk

# Architecture Independent Flags
TARGET = c1m2
ASMS = $(SOURCES:.c=.asm)
PPCS = $(SOURCES:.c=.i)
OBJS = $(SOURCES:.c=.o)
CFLAGS_COMMON = -std=c99 -Wall -Werror -g -O0
CPPFLAGs = -D$(PLATFORM)

ifeq ($(PLATFORM),HOST)
# Compiler Flags and Defines
	CC = gcc
	CFLAGS = $(CFLAGS_COMMON)
endif

ifeq ($(PLATFORM),MSP432)
	# Architectures Specific Flags
	LINKER_FILE = ../msp432p401r.lds
	CPU = cortex-m4
	ARCH = armv7e-m
	SPECS = nosys.specs
	FLOAT = hard
	FPU = fpv4-sp-d16

	# Compiler Flags and Defines
	CC = arm-none-eabi-gcc
	LD = arm-none-eabi-ld
	LDFLAGS = -Wl,-Map=$(TARGET).map -T $(LINKER_FILE)
	CFLAGS = $(CFLAGS_COMMON) -mcpu=$(CPU) -mthumb -march=$(ARCH) \
		-mfloat-abi=$(FLOAT) -mfpu=$(FPU) --specs=$(SPECS)
endif

# Generate the preprocessed output
%.i : %.c
		$(CC) -E $< $(INCLUDES) $(CPPFLAGs) $(CFLAGS) -o $@

# Generate assembly output
%.asm : %.c
		$(CC) -S $< $(INCLUDES) $(CPPFLAGs) $(CFLAGS) -o $@

# Generate object file
%.o : %.c
	$(CC) -c $< $(INCLUDES) $(CPPFLAGs) $(CFLAGS) -o $@

# Compile all object files, but DO NOT link.
.PHONY: compile-all
compile-all: $(TARGET).c

$(TARGET).c: $(OBJS)
	$(CC) $(INCLUDES) $(CPPFLAGs) $(CFLAGS) -c $(SOURCES)

# Compile all object files and link into a final executable
.PHONY: build
build: $(TARGET).out

$(TARGET).out: $(OBJS)
	$(CC) $(OBJS) $(INCLUDES) $(CPPFLAGs) $(CFLAGS) $(LDFLAGS) -o $@

.PHONY: clean
clean:
	rm -f $(OBJS) $(ASMS) $(PPCS) $(TARGET).out $(TARGET).map

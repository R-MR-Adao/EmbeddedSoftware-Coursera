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
# Compile Coursera m3 assignment project
#
# Use: make [TARGET]
#
# Build Targets:
#      Specify file names to build. Rules implemented for pre-processed (*.i),
# 		 assembly (*.asm), object (*.o), map (*.map) and executable (*.out) files
#
# author: Ricardo Adao
# date: 2022-10-02
#*****************************************************************************

include sources.mk

# Architecture Independent Flags
TARGET = c1m3
ASMS = $(SOURCES:.c=.asm)
PPCS = $(SOURCES:.c=.i)
OBJS = $(SOURCES:.c=.o)
MAPS = $(SOURCES:.c=.map)

# Architectures Specific Flags
LINKER_FILE = msp432p401r.lds
CPU = cortex-m4
ARCH = armv7e-m
SPECS = nosys.specs
FLOAT = hard
FPU = fpv4-sp-d16

# Compiler Flags and Defines
CC = arm-none-eabi-gcc
LD = arm-none-eabi-ld
LDFLAGS = -Wl,-Map=$(TARGET).map -T $(LINKER_FILE)
CFLAGS = -std=c99 -Wall -Werror -O0 -mcpu=$(CPU) -mthumb -march=$(ARCH) \
	-mfloat-abi=$(FLOAT) -mfpu=$(FPU) --specs=$(SPECS)

GENFLAGS = $< $(CFLAGS) -o $@

# Generate the preprocessed output
%.i : %.c
		$(CC) -E $(GENFLAGS)

# Generate assembly output
%.asm : %.c
		$(CC) -S $(GENFLAGS)

# Generate object file
%.o : %.c
	$(CC) -c $(GENFLAGS)

$(TARGET).map : $(TARGET).map
	$(CC) -o $(TARGET).out $(SOURCES) -Wl,-T $(LINKER_FILE) -Wl,-Map=$@ $(CFLAGS)

# Compile all object files, but DO NOT link.
.PHONY: compile-all
compile-all: $(TARGET).c

$(TARGET).c: $(OBJS)
	$(CC) $(CFLAGS) -c $(SOURCES)

# Compile all object files and link into a final executable
.PHONY: build
build: $(TARGET).out

$(TARGET).out: $(OBJS)
	$(CC) $(OBJS) $(CFLAGS) $(LDFLAGS) -o $@

.PHONY: clean
clean:
	rm -f $(OBJS) $(ASMS) $(PPCS) $(MAPS) $(TARGET).out $(TARGET).map

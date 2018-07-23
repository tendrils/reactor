# Set default configuration and resolve project paths
CONF=debug_arm-eabi-semihost

BASE=../..

CONF_DIR=$(BASE)/conf/$(CONF)
PLATFORM_DIR=$(BASE)/platform
OBJECTDIR=obj/$(CONF)
DISTDIR=dist/$(CONF)
SRCDIR=src

include $(CONF_DIR)/conf.mk

# Set hardware platform
BOARD_VENDOR=atmel
BOARD=same70-xpld

include $(PLATFORM_DIR)/platform.mk

CPU_FLAGS=$(THUMB) -mcpu=$(CPU_ARCH)
FPU_FLAGS=-mfloat-abi=hard -mfpu=$(FPU_ARCH)
ARCH_FLAGS=$(CPU_FLAGS) $(FPU_FLAGS)

# Use newlib-nano. To disable it, specify USE_NANO=
USE_NANO=--specs=nano.specs

# Use semihosting or not
USE_SEMIHOST=--specs=rdimon.specs
USE_NOHOST=--specs=nosys.specs

# Environment 
MKDIR=mkdir
CP=cp
RM=rm
CCADMIN=CCadmin

TARGET=arm-none-eabi

ifdef TARGET
    XC_PREFIX=${TARGET}-
endif

CC=${XC_PREFIX}gcc
CXX=${XC_PREFIX}g++
AS=${XC_PREFIX}as
LD=${XC_PREFIX}ld

# Linker configuration
LDCONF=sram
GC=-Wl,--gc-sections
MAP=-Wl,-Map=$(NAME).map
LD_SCRIPT=$(BOARD_DIR)/link_$(LDCONF).ld
LFLAGS=$(USE_NANO) $(USE_SEMIHOST) $(LD_SCRIPT) $(GC) $(MAP)

# C Compiler configuration
C_INCLUDES+=-Iinclude -I$(CONF_DIR) -I$(PLATFORM_DIR) $(CHIP_INCLUDES) $(KERNEL_INCLUDES)
CFLAGS+=-c -Os -flto -ffunction-sections -fdata-sections -nostdlib $(CHIP_FLAGS) $(ARCH_FLAGS) $(C_INCLUDES) 
CXXFLAGS=$(CFLAGS)

include $(CHIP_DIR)/chip_objects.mk

OBJECTFILES+=$(CHIP_OBJECTS)

STARTUP_C=$(BOARD_DIR)/startup.c
SYSTEM_C=$(BOARD_DIR)/system.c

$(OBJECTDIR)/startup.o: $(STARTUP_C)
	$(CC) $(CFLAGS) -o $@ $^
	
$(OBJECTDIR)/system.o: $(SYSTEM_C)
	$(CC) $(CFLAGS) -o $@ $^
	
$(OBJECTDIR):
	mkdir -p $(OBJECTDIR)/board
	mkdir -p $(OBJECTDIR)/chip
	mkdir -p $(OBJECTDIR)/core

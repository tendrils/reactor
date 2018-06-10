# Hardware architecture
CPU_ARCH=cortex-m7
FPU_ARCH=fpv5-d16

CPU_FLAGS=-mthumb -mcpu=$(CPU_ARCH)
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

XC_PREFIX=${TARGET}-

CC=${XC_PREFIX}gcc
CXX=${XC_PREFIX}g++
AS=${XC_PREFIX}as
LD=${XC_PREFIX}ld

# Startup code
STARTUP=$(BASE)/lib/chip/SAME70_DFP/2.2.91/same70b/gcc/gcc/startup_same70q21b.c

# -Os -flto -ffunction-sections -fdata-sections to compile for code size
CFLAGS=$(ARCH_FLAGS) $(STARTUP_DEFS) -Os -flto -ffunction-sections -fdata-sections
CXXFLAGS=$(CFLAGS)

# Link for code size
GC=-Wl,--gc-sections

# Create map file
MAP=-Wl,-Map=$(NAME).map


# Select Core
CORTEX_M=7
FPU_ARCH=-mfpu=fpv5-d16

FPU_FLAGS=-mfloat-abi=hard -mfpu=$(FPU_ARCH)

# Use newlib-nano. To disable it, specify USE_NANO=
USE_NANO=--specs=nano.specs

# Use semihosting or not
USE_SEMIHOST=--specs=rdimon.specs
USE_NOHOST=--specs=nosys.specs

CORE=CM$(CORTEX_M)

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

# Options for specific architecture
ARCH_FLAGS=-mthumb -mcpu=cortex-m$(CORTEX_M) $(FPU_FLAGS)

# Startup code
STARTUP=$(BASE)/startup/startup_ARM$(CORE).S

# -Os -flto -ffunction-sections -fdata-sections to compile for code size
CFLAGS=$(ARCH_FLAGS) $(STARTUP_DEFS) -Os -flto -ffunction-sections -fdata-sections
CXXFLAGS=$(CFLAGS)

# Link for code size
GC=-Wl,--gc-sections

# Create map file
MAP=-Wl,-Map=$(NAME).map


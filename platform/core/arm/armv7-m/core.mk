# Build settings for ARMv7 Profile M CPU core architecture
# Supported CPU cores:
# - Cortex M4
# - Cortex M7

ifndef REACTOR_PLATFORM_CORE
REACTOR_PLATFORM_CORE = 1

ifneq ($(CORE_FPU), '')
    CORE_FLOATABI=hard
else
    CORE_FLOATABI=soft
endif

CORE_INCLUDES=-I$(RESOURCE_BASE)/core/arm/cmsis-$(CMSIS_VERSION)

CORE_OBJECTS=

CORE_FLAGS=-mcpu=$(CORE_ID) -mfpu=$(CORE_FPU) -mfloat-abi=$(CORE_FLOATABI) -mthumb

endif

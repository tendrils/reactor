ifeq ($(CORE_ID), cortex-m7)
    K_CPUARCH=ARM_CM7
    K_CPUVER=r0p1
else
# bail out, no supported CPU detected (TODO)
    exit 1
endif

K_ROOT=$(BASE)/lib/kernel/$(KERNEL)/$(KERNEL_VERSION)

K_INCLUDE=$(K_ROOT)/include
K_PORT_INCLUDE=$(K_ROOT)/portable/GCC/$(K_CPUARCH)/$(K_CPUVER)

KERNEL_INCLUDES=-I$(K_INCLUDE) -I$(K_PORT_INCLUDE)

KERNEL_FLAGS=

# TODO add compilation rules and dependency lists
KERNEL_OBJECTS+=platform_freertos.o

ifeq ($(REACTOR_CPU_ARCH), cortex-m7)
    K_CPUARCH=ARM_CM7
    K_CPUVER=r0p1
else
# bail out, no supported CPU detected (TODO)
endif

K_ROOT=$(BASE)/lib/kernel/$(KERNEL)/$(KERNEL_VERSION)

K_INCLUDE=$(K_ROOT)/include
K_PORT_INCLUDE=$(K_ROOT)/portable/GCC/$(K_CPUARCH)/$(K_CPUVER)

KERNEL_INCLUDES=$(K_INCLUDE) $(K_PORT_INCLUDE)

# TODO add compilation rules and dependency lists

# Build settings for Atmel SAM-E70 MCU

ifndef REACTOR_PLATFORM_CHIP
REACTOR_PLATFORM_CHIP = 1

CHIP_FLAGS=-D__SAME70Q21B__

CHIP_LIB_DIR = $(RESOURCE_BASE)/chip/atmel/e70
DFP_DIR = $(CHIP_LIB_BASE)/dfp/$(DFP_VERSION)/$(CHIP_VERSION)
HAL_DIR = $(CHIP_LIB_BASE)/hal
HPL_DIR = $(CHIP_LIB_BASE)/hpl
HRI_DIR = $(CHIP_LIB_BASE)/hri

CHIP_INCLUDES=\
    -I$(DFP_DIR)/include \
    -I$(HRI_DIR) \
    -I$(HPL_DIR)/core \
    -I$(HPL_DIR)/pmc \
    -I$(HPL_DIR)/pio \
    -I$(HPL_DIR)/xdmac \
    -I$(HAL_DIR)/include \
    -I$(HAL_DIR)/utils/include

CORE_VENDOR=arm
CORE_ARCH=armv7-m
CORE_ID=cortex-m7
CORE_FPU=fpv5-d16

CHIP_OBJECTS=\
    $(CHIP_OBJ_DIR)/hal_atomic.o \
    $(CHIP_OBJ_DIR)/hal_delay.o \
    $(CHIP_OBJ_DIR)/hal_gpio.o \
    $(CHIP_OBJ_DIR)/hal_init.o \
    $(CHIP_OBJ_DIR)/hal_io.o \
    $(CHIP_OBJ_DIR)/hal_sleep.o \
    $(CHIP_OBJ_DIR)/utils_assert.o \
    $(CHIP_OBJ_DIR)/utils_event.o \
    $(CHIP_OBJ_DIR)/utils_list.o \
    $(CHIP_OBJ_DIR)/utils_syscalls.o \
    $(CHIP_OBJ_DIR)/hpl_init.o \
    $(CHIP_OBJ_DIR)/hpl_core_m7_base.o \
    $(CHIP_OBJ_DIR)/hpl_pmc.o \
    $(CHIP_OBJ_DIR)/hpl_sleep.o \
    $(CHIP_OBJ_DIR)/hpl_xdmac.o
    
$(CHIP_OBJ_DIR)/hal_%.o: $(HAL_DIR)/src/hal_%.c
	$(call f_action_compile_c, $^, $@)

$(CHIP_OBJ_DIR)/utils_%.o: $(HAL_DIR)/utils/src/utils_%.c
	$(call f_action_compile_c, $^, $@)

$(BUILDDIR)/hpl_init.o: $(HPL_DIR)/core/hpl_init.c
	$(call f_action_compile_c, $^, $@)

$(BUILDDIR)/hpl_core_m7_base.o: $(HPL_DIR)/core/hpl_core_m7_base.c
	$(call f_action_compile_c, $^, $@)

$(BUILDDIR)/hpl_pmc.o: $(HPL_DIR)/pmc/hpl_pmc.c
	$(call f_action_compile_c, $^, $@)

$(BUILDDIR)/hpl_sleep.o: $(HPL_DIR)/pmc/hpl_sleep.c
	$(call f_action_compile_c, $^, $@)

$(BUILDDIR)/hpl_xdmac.o: $(HPL_DIR)/xdmac/hpl_xdmac.c
	$(call f_action_compile_c, $^, $@)

endif

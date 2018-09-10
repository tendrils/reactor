# Build settings for Atmel SAM-E70 MCU

CHIP_FLAGS=-D__SAME70Q21B__

CHIP_SUPPT_DIR=$(BASE)/lib/chip/atmel/same70
DFP_DIR=$(CHIP_SUPPT_DIR)/dfp/$(DFP_VERSION)/$(CHIP_VERSION)
HAL_DIR=$(CHIP_SUPPT_DIR)/hal
HPL_DIR=$(CHIP_SUPPT_DIR)/hpl
HRI_DIR=$(CHIP_SUPPT_DIR)/hri

CHIP_INCLUDES=\
    -I$(DFP_DIR)/include \
    -I$(HRI_DIR) \
    -I$(HPL_DIR)/core \
    -I$(HPL_DIR)/pmc \
    -I$(HPL_DIR)/pio \
    -I$(HPL_DIR)/xdmac \
    -I$(HAL_DIR)/include \
    -I$(HAL_DIR)/utils/include \

CORE_VENDOR=arm
CORE_ARCH=armv7-m
CORE_ID=cortex-m7
CORE_FPU=fpv5-d16

CHIP_OBJECTS=\
    $(BUILDDIR)/hal_atomic.o \
    $(BUILDDIR)/hal_delay.o \
    $(BUILDDIR)/hal_gpio.o \
    $(BUILDDIR)/hal_init.o \
    $(BUILDDIR)/hal_io.o \
    $(BUILDDIR)/hal_sleep.o \
    $(BUILDDIR)/utils_assert.o \
    $(BUILDDIR)/utils_event.o \
    $(BUILDDIR)/utils_list.o \
    $(BUILDDIR)/utils_syscalls.o \
    $(BUILDDIR)/hpl_init.o \
    $(BUILDDIR)/hpl_core_m7_base.o \
    $(BUILDDIR)/hpl_pmc.o \
    $(BUILDDIR)/hpl_sleep.o \
    $(BUILDDIR)/hpl_xdmac.o
    
$(BUILDDIR)/hal_atomic.o: $(HAL_DIR)/src/hal_atomic.c
	${CC} $(CFLAGS) -o $@ $^

$(BUILDDIR)/hal_delay.o: $(HAL_DIR)/src/hal_delay.c
	$(CC) $(CFLAGS) -o $@ $^
	
$(BUILDDIR)/hal_gpio.o: $(HAL_DIR)/src/hal_gpio.c
	$(CC) $(CFLAGS) -o $@ $^
	
$(BUILDDIR)/hal_init.o: $(HAL_DIR)/src/hal_init.c
	$(CC) $(CFLAGS) -o $@ $^
	
$(BUILDDIR)/hal_io.o: $(HAL_DIR)/src/hal_io.c
	$(CC) $(CFLAGS) -o $@ $^
	
$(BUILDDIR)/hal_sleep.o: $(HAL_DIR)/src/hal_sleep.c
	$(CC) $(CFLAGS) -o $@ $^
	
$(BUILDDIR)/utils_assert.o: $(HAL_DIR)/utils/src/utils_assert.c
	$(CC) $(CFLAGS) -o $@ $^
	
$(BUILDDIR)/utils_event.o: $(HAL_DIR)/utils/src/utils_event.c
	$(CC) $(CFLAGS) -o $@ $^
	
$(BUILDDIR)/utils_list.o: $(HAL_DIR)/utils/src/utils_list.c
	$(CC) $(CFLAGS) -o $@ $^
	
$(BUILDDIR)/utils_syscalls.o: $(HAL_DIR)/utils/src/utils_syscalls.c
	$(CC) $(CFLAGS) -o $@ $^
	
$(BUILDDIR)/hpl_init.o: $(HPL_DIR)/core/hpl_init.c
	$(CC) $(CFLAGS) -o $@ $^
	
$(BUILDDIR)/hpl_core_m7_base.o: $(HPL_DIR)/core/hpl_core_m7_base.c
	$(CC) $(CFLAGS) -o $@ $^
	
$(BUILDDIR)/hpl_pmc.o: $(HPL_DIR)/pmc/hpl_pmc.c
	$(CC) $(CFLAGS) -o $@ $^
	
$(BUILDDIR)/hpl_sleep.o: $(HPL_DIR)/pmc/hpl_sleep.c
	$(CC) $(CFLAGS) -o $@ $^

$(BUILDDIR)/hpl_xdmac.o: $(HPL_DIR)/xdmac/hpl_xdmac.c
	$(CC) $(CFLAGS) -o $@ $^

CHIP_OBJECTS=\
    $(OBJECTDIR)/chip/hal_atomic.o \
    $(OBJECTDIR)/chip/hal_delay.o \
    $(OBJECTDIR)/chip/hal_gpio.o \
    $(OBJECTDIR)/chip/hal_init.o \
    $(OBJECTDIR)/chip/hal_io.o \
    $(OBJECTDIR)/chip/hal_sleep.o \
    $(OBJECTDIR)/chip/utils_assert.o \
    $(OBJECTDIR)/chip/utils_event.o \
    $(OBJECTDIR)/chip/utils_list.o \
    $(OBJECTDIR)/chip/utils_syscalls.o \
    $(OBJECTDIR)/chip/hpl_init.o \
    $(OBJECTDIR)/chip/hpl_core_m7_base.o \
    $(OBJECTDIR)/chip/hpl_pmc.o \
    $(OBJECTDIR)/chip/hpl_sleep.o \
    $(OBJECTDIR)/chip/hpl_xdmac.o
    
$(OBJECTDIR)/chip/hal_atomic.o: $(HAL_DIR)/src/hal_atomic.c
	${CC} $(CFLAGS) -o $@ $^

$(OBJECTDIR)/chip/hal_delay.o: $(HAL_DIR)/src/hal_delay.c
	$(CC) $(CFLAGS) -o $@ $^
	
$(OBJECTDIR)/chip/hal_gpio.o: $(HAL_DIR)/src/hal_gpio.c
	$(CC) $(CFLAGS) -o $@ $^
	
$(OBJECTDIR)/chip/hal_init.o: $(HAL_DIR)/src/hal_init.c
	$(CC) $(CFLAGS) -o $@ $^
	
$(OBJECTDIR)/chip/hal_io.o: $(HAL_DIR)/src/hal_io.c
	$(CC) $(CFLAGS) -o $@ $^
	
$(OBJECTDIR)/chip/hal_sleep.o: $(HAL_DIR)/src/hal_sleep.c
	$(CC) $(CFLAGS) -o $@ $^
	
$(OBJECTDIR)/chip/utils_assert.o: $(HAL_DIR)/utils/src/utils_assert.c
	$(CC) $(CFLAGS) -o $@ $^
	
$(OBJECTDIR)/chip/utils_event.o: $(HAL_DIR)/utils/src/utils_event.c
	$(CC) $(CFLAGS) -o $@ $^
	
$(OBJECTDIR)/chip/utils_list.o: $(HAL_DIR)/utils/src/utils_list.c
	$(CC) $(CFLAGS) -o $@ $^
	
$(OBJECTDIR)/chip/utils_syscalls.o: $(HAL_DIR)/utils/src/utils_syscalls.c
	$(CC) $(CFLAGS) -o $@ $^
	
$(OBJECTDIR)/chip/hpl_init.o: $(HPL_DIR)/core/hpl_init.c
	$(CC) $(CFLAGS) -o $@ $^
	
$(OBJECTDIR)/chip/hpl_core_m7_base.o: $(HPL_DIR)/core/hpl_core_m7_base.c
	$(CC) $(CFLAGS) -o $@ $^
	
$(OBJECTDIR)/chip/hpl_pmc.o: $(HPL_DIR)/pmc/hpl_pmc.c
	$(CC) $(CFLAGS) -o $@ $^
	
$(OBJECTDIR)/chip/hpl_sleep.o: $(HPL_DIR)/pmc/hpl_sleep.c
	$(CC) $(CFLAGS) -o $@ $^

$(OBJECTDIR)/chip/hpl_xdmac.o: $(HPL_DIR)/xdmac/hpl_xdmac.c
	$(CC) $(CFLAGS) -o $@ $^

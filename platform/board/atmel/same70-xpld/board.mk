ifndef REACTOR_PLATFORM_BOARD
REACTOR_PLATFORM_BOARD = 1

# This board always has the same MCU, so we define it here
CHIP_VENDOR=atmel
CHIP=same70
CHIP_VERSION=same70b

STARTUP_C=$(BOARD_DIR)/startup.c
SYSTEM_C=$(BOARD_DIR)/system.c

BOARD_OBJECTS=$(BUILDDIR)/startup.o $(BUILDDIR)/system.o

$(BUILDDIR)/startup.o: $(STARTUP_C)
	$(CC) $(CFLAGS) -o $@ $^
	
$(BUILDDIR)/system.o: $(SYSTEM_C)
	$(CC) $(CFLAGS) -o $@ $^

endif

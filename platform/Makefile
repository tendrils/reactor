NAME=reactor-platform
BASE:=..

default: build

OBJECTFILES+=\
    $(BUILDDIR)/reactor_core.o\
    $(BUILDDIR)/platform.o\
    $(BUILDDIR)/port_kernel_freertos.o\

include $(BASE)/script/project_mod.mk

# Build Targets
$(BUILDDIR)/reactor_core.o: src/reactor_core.c
	$(CC) $(CFLAGS) -o $@ $^

$(BUILDDIR)/platform.o: src/platform.c
	$(CC) $(CFLAGS) -o $@ $^
	
$(BUILDDIR)/port_kernel_freertos.o: src/port/port_kernel_freertos.c
	$(CC) $(CFLAGS) -o $@ $^

NAME=reactor-core
BASE:=../..

default: build

OBJECTFILES+=\
    $(BUILDDIR)/reactor_core.o\
    $(BUILDDIR)/platform.o\
    $(BUILDDIR)/platform_kernel.o\
    $(BUILDDIR)/firmware.o\
    $(BUILDDIR)/module.o\
    $(BUILDDIR)/component.o\
    $(BUILDDIR)/service.o\

include $(BASE)/script/project_mod.mk

# Build Targets
$(BUILDDIR)/reactor_core.o: src/reactor_core.c
	$(CC) $(CFLAGS) -o $@ $^

$(BUILDDIR)/platform.o: src/platform/platform.c
	$(CC) $(CFLAGS) -o $@ $^

ifeq ($(KERNEL), freertos)
$(BUILDDIR)/platform_kernel.o: src/platform/kernel_freertos.c
	$(CC) $(CFLAGS) -o $@ $^
endif

$(BUILDDIR)/firmware.o: src/firmware.c
	$(CC) $(CFLAGS) -o $@ $^

$(BUILDDIR)/module.o: src/module.c
	$(CC) $(CFLAGS) -o $@ $^

$(BUILDDIR)/component.o: src/component.c
	$(CC) $(CFLAGS) -o $@ $^

$(BUILDDIR)/service.o: src/service.c
	$(CC) $(CFLAGS) -o $@ $^

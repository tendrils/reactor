NAME=reactor-core
BASE:=../..

default: build

OBJECTFILES+=\
    $(BUILDDIR)/reactor_core.o\
    $(BUILDDIR)/platform.o\

include $(BASE)/script/project_mod.mk

# Build Targets
$(BUILDDIR)/reactor_core.o: src/reactor_core.c
	$(CC) $(CFLAGS) -o $@ $^

$(BUILDDIR)/platform.o: src/platform.c
	$(CC) $(CFLAGS) -o $@ $^

ifeq ($(KERNEL), freertos)
$(BUILDDIR)/platform_kernel.o: src/platform/kernel_freertos.c
	$(CC) $(CFLAGS) -o $@ $^
endif
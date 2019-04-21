ifndef REACTOR_PLATFORM_KERNEL
REACTOR_PLATFORM_KERNEL = 1

ifeq ($(CORE_ID), cortex-m7)
    K_CPUARCH=ARM_CM7
    K_CPUVER=r0p1
else
# bail out, no supported CPU detected (TODO)
    exit 1
endif

K_ROOT=$(RESOURCE_BASE)/kernel/$(KERNEL)/$(KERNEL_VERSION)

K_INCLUDE=$(K_ROOT)/include
KERNEL_PORTDIR=$(K_ROOT)/portable/GCC/$(K_CPUARCH)/$(K_CPUVER)

KERNEL_INCLUDES=-I$(K_INCLUDE) -I$(KERNEL_PORTDIR)

KERNEL_OBJECTS+=\
    $(BUILDDIR)/tasks.o\
    $(BUILDDIR)/queue.o\
    $(BUILDDIR)/list.o\
    $(BUILDDIR)/timers.o\
    $(BUILDDIR)/heap.o\
    $(BUILDDIR)/port.o\

KERNEL_FLAGS=

# TODO add compilation rules and dependency lists

$(BUILDDIR)/tasks.o: $(K_ROOT)/tasks.c
	$(CC) $(CFLAGS) -o $@ $^

$(BUILDDIR)/queue.o: $(K_ROOT)/queue.c
	$(CC) $(CFLAGS) -o $@ $^

$(BUILDDIR)/list.o: $(K_ROOT)/list.c
	$(CC) $(CFLAGS) -o $@ $^

$(BUILDDIR)/timers.o: $(K_ROOT)/timers.c
	$(CC) $(CFLAGS) -o $@ $^

$(BUILDDIR)/heap.o: $(K_ROOT)/portable/MemMang/heap_1.c
	$(CC) $(CFLAGS) -o $@ $^

$(BUILDDIR)/port.o: $(KERNEL_PORTDIR)/port.c
	$(CC) $(CFLAGS) -o $@ $^

endif

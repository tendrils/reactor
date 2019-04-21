NAME=reactor-core
BASE := $(realpath ../..)
CONF_DEFAULT := reference-hardware

default: build

include $(BASE)/project/project_mod.mk

OBJECTFILES+=\
    $(OBJ_DIR)/reactor_core.o\
    $(OBJ_DIR)/platform.o\
    $(OBJ_DIR)/platform_kernel.o\
    $(OBJ_DIR)/firmware.o\
    $(OBJ_DIR)/module.o\
    $(OBJ_DIR)/component.o\
    $(OBJ_DIR)/service.o

# Build Targets
$(OBJ_DIR)/reactor_core.o: src/reactor_core.c
	$(call f_action_compile)

$(OBJ_DIR)/firmware.o: src/firmware.c
	$(CC) $(CFLAGS) -o $@ $^

$(OBJ_DIR)/module.o: src/module.c
	$(CC) $(CFLAGS) -o $@ $^

$(OBJ_DIR)/component.o: src/component.c
	$(CC) $(CFLAGS) -o $@ $^

$(OBJ_DIR)/service.o: src/service.c
	$(CC) $(CFLAGS) -o $@ $^

# Components
$(OBJ_DIR)/lifecycle.o: src/component/lifecycle.c
	$(CC) $(CFLAGS) -o $@ $^

# Platform
$(OBJ_DIR)/platform.o: src/platform/platform.c
	$(CC) $(CFLAGS) -o $@ $^

ifeq ($(KERNEL), freertos)
$(OBJ_DIR)/platform_kernel.o: src/platform/kernel_freertos.c
	$(CC) $(CFLAGS) -o $@ $^
endif

BASE := $(realpath ../..)
include $(BASE)/rebuild/rebuild.mk

CONF_DEFAULT := reactor-base
default: build

OBJECTFILES+=\
    $(OBJ_DIR)/reactor_core.o\
    $(OBJ_DIR)/platform.o\
    $(OBJ_DIR)/platform/platform_kernel.o\
    $(OBJ_DIR)/firmware.o\
    $(OBJ_DIR)/module.o\
    $(OBJ_DIR)/component.o\
    $(OBJ_DIR)/service.o

# Build Targets
$(OBJ_DIR)/%.o: src/%.c
	$(call f_action_compile_c,$@,$^)

ifeq ($(KERNEL), freertos)
$(OBJ_DIR)/platform/platform_kernel.o: src/platform/kernel_freertos.c
	$(call f_action_compile_c,$@,$^)
endif

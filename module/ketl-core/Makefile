NAME=ketl-core
BASE := $(realpath ../..)
CONF_DEFAULT := ketl-base

default: build

include $(BASE)/project/project_mod.mk

OBJECTFILES+=\
    $(OBJ_DIR)/ketl_core.o

# Build Targets
$(OBJ_DIR)/ketl_core.o: src/ketl_core.c
	$(call f_action_compile)

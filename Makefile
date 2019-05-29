NAME=reactor
BASE:=.
SCRIPT_DIR=$(BASE)/reactor-build
SUBPROJECTS = $(MODDIRS) $(PLATFORM_DIR)

include $(SCRIPT_DIR)/project_aggregate.mk
include $(SCRIPT_DIR)/project_exe.mk

default: build

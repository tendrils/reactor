NAME=reactor
BASE:=.
SUBPROJECTS = $(MODDIRS) $(PLATFORM_DIR)

include project/project_aggregate.mk
include project/project_exe.mk

default: build

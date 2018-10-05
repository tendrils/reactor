NAME=reactor
BASE:=.

include $(BASE)/script/project_exe.mk

SUBPROJECTS = $(MODDIRS) $(PLATFORM_DIR)

default: build

clean: .clean_dist
	@echo "Cleaning modules..."
	for d in $(SUBPROJECTS); do make -C $$d $@; done
	@echo "Cleaning test-modules..."
	for d in $(testmodules); do make -C $$d $@; done

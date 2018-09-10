NAME=reactor
BASE:=.

include $(BASE)/script/project_exe.mk

modules=$(shell find ./module -mindepth 1 -maxdepth 1 -type d)
testmodules=$(shell find ./test-module -mindepth 1 -maxdepth 1 -type d)

default: build

all:
	@echo "Building modules..."
	for d in $(modules); do make -C $$d || exit 1; done
	@echo "Building test-modules..."
	for d in $(testmodules); do make -C $$d || exit 1; done

clean: .clean_dist
	@echo "Cleaning modules..."
	for d in $(modules); do make -C $$d $@; done
	@echo "Cleaning test-modules..."
	for d in $(testmodules); do make -C $$d $@; done

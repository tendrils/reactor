rebuild_base:=$(realpath .)
include $(rebuild_base)/rebuild/rebuild.mk

default: build

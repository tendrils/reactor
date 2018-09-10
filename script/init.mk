auto: default

# Set default configuration and resolve project paths
CONF?=debug_arm-eabi-semihost

PROJECT_BASE=.
CONF_DIR=$(BASE)/conf/$(CONF)
PLATFORM_DIR=$(BASE)/platform
MODULE_DIR=$(BASE)/module
SCRIPT_DIR=$(BASE)/script

BUILDDIR=$(PROJECT_BASE)/obj
DISTDIR=$(BASE)/dist
SRCDIR=$(PROJECT_BASE)/src

include $(CONF_DIR)/conf.mk

# Set hardware platform
BOARD_VENDOR=atmel
BOARD=same70-xpld

include $(PLATFORM_DIR)/platform.mk

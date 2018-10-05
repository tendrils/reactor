
include $(SCRIPT_DIR)/tasks.mk

include $(MODULE_DIR)/modules.mk

# Use newlib-nano. To disable it, specify USE_NANO=
USE_NANO=--specs=nano.specs

# Use semihosting or not
USE_SEMIHOST=--specs=rdimon.specs
USE_NOHOST=--specs=nosys.specs

# Environment 
MKDIR=mkdir
CP=cp
RM=rm
CCADMIN=CCadmin

TARGET?=arm-none-eabi

ifdef TARGET
    XC_PREFIX=$(TARGET)-
endif

CC=$(XC_PREFIX)gcc
CXX=$(XC_PREFIX)g++
AS=$(XC_PREFIX)as
LD=$(XC_PREFIX)gcc
OBJCOPY=$(XC_PREFIX)objcopy

LTOFLAG:=--plugin=$(shell $(CC) --print-file-name=liblto_plugin.so)
AR=$(XC_PREFIX)ar qc $(LTOFLAG)
RANLIB=$(XC_PREFIX)ranlib $(LTOFLAG)

# Linker configuration
LDCONF?=sram
GC=--gc-sections
MAP=-Map=$(DISTDIR)/$(PRODUCT_STRING).map
LD_SCRIPT=$(BOARD_DIR)/link_$(LDCONF).ld
LIBFLAGS=$(MODFLAGS) $(PLATFORM_LIBFLAGS)
LDFLAGS=$(USE_NANO) $(USE_SEMIHOST) $(PLATFORM_FLAGS) -L $(DISTDIR) -T $(LD_SCRIPT) -Wl,$(GC) -Wl,$(MAP) $(LIBFLAGS)

# C Compiler configuration
C_INCLUDES+=-Iinclude -I$(CONF_DIR) $(PLATFORM_INCLUDES)
CFLAGS+=-c -Os -flto -ffunction-sections -fdata-sections -ffreestanding $(USE_NANO) $(USE_SEMIHOST) $(PLATFORM_FLAGS) $(C_INCLUDES) 
CXXFLAGS=$(CFLAGS)

#
# build step implementations
#
.build-impl: .build-pre $(BUILDDIR) $(DISTDIR) $(PRODUCT)
	
.clean-impl: .clean-pre .clean_build .clean_dist
	
.clobber-impl: .clobber-pre clean

.all-impl: clean build test

.build-tests-impl:
	
.test-impl:
	
.help-impl:

.clean_build:
	rm -rf $(BUILDDIR)

.clean_dist:
	rm -rf $(DISTDIR)

$(BUILDDIR):
	mkdir -p $(BUILDDIR)

$(DISTDIR):
	mkdir -p $(DISTDIR)

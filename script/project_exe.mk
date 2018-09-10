# Common build rules and properties for executable firmware projects
include $(BASE)/script/init.mk

PRODUCT_STRING=$(NAME)_$(PLATFORM_STRING)

PRODUCT_ELF=$(DISTDIR)/$(PRODUCT_STRING).elf

PRODUCT_BIN=$(DISTDIR)/$(PRODUCT_STRING).bin

PRODUCT=$(PRODUCT_BIN)

include $(BASE)/script/project_common.mk

$(PRODUCT_ELF): $(OBJECTFILES) $(MODULES) $(PLATFORM_LIB)
	$(LD) -o $@ $(OBJECTFILES) $(LDFLAGS) $(ARCHFLAGS)

$(PRODUCT_BIN): $(PRODUCT_ELF)
	$(OBJCOPY) -I elf32-little -O binary $^ $@

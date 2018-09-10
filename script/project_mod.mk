# Common build rules and properties for reactor modules
include $(BASE)/script/init.mk

PRODUCT_STRING=mod$(NAME)--$(PLATFORM_STRING)

PRODUCT_MOD=$(DISTDIR)/$(PRODUCT_STRING).a

PRODUCT=$(PRODUCT_MOD)

$(PRODUCT_MOD): $(OBJECTFILES)
	$(AR) $@ $^
	$(RANLIB) $@

include $(BASE)/script/project_common.mk

# Common build rules and properties for reactor modules
include $(BASE)/script/init.mk

PRODUCT_STRING=lib$(NAME)_$(PLATFORM_STRING)

PRODUCT_LIB=$(DISTDIR)/$(PRODUCT_STRING).a

PRODUCT=$(PRODUCT_LIB)

$(PRODUCT_LIB): $(OBJECTFILES)
	$(AR) $@ $^
	$(RANLIB) $@

include $(BASE)/script/project_common.mk

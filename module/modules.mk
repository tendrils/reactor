# framework core module definitions

MOD_CORE_NAME=reactor-core
MOD_CORE_DIR=$(MODULE_DIR)/$(MOD_CORE_NAME)
MOD_CORE=mod$(MOD_CORE_NAME)--$(PLATFORM_STRING).a
MOD_CORE_FLAG=-l\:$(MOD_CORE)
MOD_CORE_FILE=$(DISTDIR)/$(MOD_CORE)

ifneq ($(NAME), $(MOD_CORE_NAME))
MODULES+=$(MOD_CORE_FILE)
MODDIRS+=$(MOD_CORE_DIR)
MODFLAGS+=$(MOD_CORE_FLAG)

$(MOD_CORE_FILE):
	$(MAKE) -C $(MOD_CORE_DIR)
endif

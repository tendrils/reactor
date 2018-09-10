BOARD_DIR=$(PLATFORM_DIR)/board/$(BOARD_VENDOR)/$(BOARD)

include $(BOARD_DIR)/board.mk

CHIP_DIR=$(PLATFORM_DIR)/chip/$(CHIP_VENDOR)/$(CHIP)

include $(CHIP_DIR)/chip.mk

CORE_DIR=$(PLATFORM_DIR)/core/$(CORE_VENDOR)/$(CORE_ARCH)

include $(CORE_DIR)/core.mk

KERNEL_DIR=$(PLATFORM_DIR)/kernel/$(KERNEL)/$(KERNEL_VERSION)

include $(KERNEL_DIR)/kernel.mk

PLATFORM_STRING=$(CORE_ID)_$(KERNEL)_$(BOARD)

PLATFORM_LIB_NAME=reactor-platform--$(PLATFORM_STRING)

PLATFORM_LIBFLAGS=-l$(PLATFORM_LIB_NAME)

PLATFORM_LIB=$(DISTDIR)/lib$(PLATFORM_LIB_NAME).a

PLATFORM_INCLUDES=-I$(PLATFORM_DIR) -I$(BOARD_DIR) -I$(CHIP_DIR) -I$(CORE_DIR) \
-I$(KERNEL_DIR) $(CORE_INCLUDES) $(CHIP_INCLUDES) $(BOARD_INCLUDES) $(KERNEL_INCLUDES)

PLATFORM_OBJECTS=$(CORE_OBJECTS) $(CHIP_OBJECTS) $(BOARD_OBJECTS) $(KERNEL_OBJECTS)

PLATFORM_FLAGS=$(CORE_FLAGS) $(CHIP_FLAGS) $(BOARD_FLAGS) $(KERNEL_FLAGS)

$(PLATFORM_LIB): $(DISTDIR)
$(PLATFORM_LIB): $(PLATFORM_OBJECTS)
	$(AR) $@ $(PLATFORM_OBJECTS)
	$(RANLIB) $@
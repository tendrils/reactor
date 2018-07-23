# Build settings for Atmel SAM-E70 MCU

CHIP_FLAGS=-D__SAME70Q21B__

CHIP_SUPPT_DIR=$(BASE)/lib/chip/atmel/same70
DFP_DIR=$(CHIP_SUPPT_DIR)/dfp/$(DFP_VERSION)/same70b
HAL_DIR=$(CHIP_SUPPT_DIR)/hal
HPL_DIR=$(CHIP_SUPPT_DIR)/hpl
HRI_DIR=$(CHIP_SUPPT_DIR)/hri

CHIP_INCLUDES=\
    -I$(BASE)/lib/core/arm/cmsis-$(CMSIS_VERSION) \
    -I$(DFP_DIR)/include \
    -I$(HRI_DIR) \
    -I$(HPL_DIR)/core \
    -I$(HPL_DIR)/pmc \
    -I$(HPL_DIR)/pio \
    -I$(HPL_DIR)/xdmac \
    -I$(HAL_DIR)/include \
    -I$(HAL_DIR)/utils/include \

REACTOR_CPU_ARCH=cortex-m7

# Core architecture
CPU_ARCH=$(REACTOR_CPU_ARCH)
FPU_ARCH=fpv5-d16
THUMB=-mthumb

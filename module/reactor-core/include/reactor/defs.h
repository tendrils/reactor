/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   reactor/defs.h
 * Author: Tendril
 *
 * Created on June 10, 2018, 10:33 AM
 */

#ifndef DEFS_H
#define DEFS_H


/* task scheduler values */
#define RPI_KERNEL_NONE                     0
#define RPI_KERNEL_FREERTOS                 1
#define RPI_KERNEL_EMBLINUX                 2
#define RPI_KERNEL_RTX5                     3

/* chip vendor values */
#define RPI_CHIP_VENDOR_ATMEL                   0

/* chip product line values */
#define RPI_CHIP_LINE_ATMEL_SAME70              0

/* chip product model values */
#define RPI_CHIP_MODEL_ATMEL_SAME70_Q21         0

/* system board values */
#define RPI_BOARD_SAME70_XPLD                   0

#define RPI_CORE_VENDOR_ARM                     0
#define RPI_CORE_VENDOR_RISCV                   1
#define RPI_CORE_VENDOR_INTEL                   2

/* CPU core values */
#define RPI_CORE_CORTEX_M0                      cortex-m0
#define RPI_CORE_CORTEX_M0P                     cortex-m0+
#define RPI_CORE_CORTEX_M1                      cortex-m1
#define RPI_CORE_CORTEX_M3                      cortex-m3
#define RPI_CORE_CORTEX_M4                      cortex-m4
#define RPI_CORE_CORTEX_M7                      cortex-m7

#endif /* DEFS_H */


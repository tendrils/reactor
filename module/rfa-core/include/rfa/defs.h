/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   defs.h
 * Author: Tendril
 *
 * Created on June 10, 2018, 10:33 AM
 */

#ifndef DEFS_H
#define DEFS_H

#ifdef __cplusplus
extern "C"
{
#endif

/* task scheduler values */
#define RFAPORT_KERNEL_NONE                     0
#define RFAPORT_KERNEL_FREERTOS                 1
#define RFAPORT_KERNEL_EMBLINUX                 2
#define RFAPORT_KERNEL_RTX5                     3

/* chip vendor values */
#define RFA_CHIP_VENDOR_ATMEL                   0

/* chip product line values */
#define RFA_CHIP_LINE_ATMEL_SAME70              0

/* chip product model values */
#define RFA_CHIP_MODEL_ATMEL_SAME70_Q21B        0

/* system board values */
#define RFA_BOARD_SAME70_XPLD                   0

#ifdef __cplusplus
}
#endif

#endif /* DEFS_H */


/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * 
 */

#ifndef RPI_CORE_H
#define RPI_CORE_H

// CMSIS headers for arm chips are included by their respective chip headers

#define RPI_CORE_IS_ARMV7
#define RPI_CORE_IS_ARMV7_M
#define RPI_CORE_IS_CORTEX_M

#define RPI_CORE_HAS_NVIC

#if(__CORTEX_M == 7U)
#   define RPI_CORE_IS_CORTEX_M7
#endif

#endif /* RPI_CORE_H */


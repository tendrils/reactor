/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   sam_e70.h
 * Author: Tendril
 *
 * Created on May 21, 2018, 8:02 AM
 */

#ifndef CHIP_SAME70_H
#define CHIP_SAME70_H

#ifdef __cplusplus
extern "C" {
#endif

#if (RFA_CHIP_MODEL == RFA_CHIP_MODEL_ATMEL_SAME70_Q21B)
#   define __SAME70Q21B__
#   include "sam.h"
#else
#   error "No supported chip line selected"
#endif

#ifdef __cplusplus
}
#endif

#endif /* CHIP_SAME70_H */


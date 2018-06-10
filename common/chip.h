/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   chip.h
 * Author: Tendril
 *
 * Created on April 5, 2018, 10:51 AM
 */

#ifndef CHIP_H
#define CHIP_H

#if (RFA_CHIP == RFA_CHIP_LINE_SAME70)
#   include "chip/atmel/same70.h"
#else
#   error "No supported chip line selected"
#endif

#endif /* CHIP_H */


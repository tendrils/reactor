/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   board.h
 * Author: Tendril
 *
 * Created on April 5, 2018, 11:00 AM
 */

#ifndef BOARD_H
#define BOARD_H

#if (RFA_BOARD == RFA_BOARD_SAME70_XPLD)
#   include "board/atmel/same70-xpld.h"
#else
#   error "No supported board model selected"
#endif

#endif /* BOARD_H */


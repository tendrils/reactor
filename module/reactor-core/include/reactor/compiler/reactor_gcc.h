/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   reactor/compiler/gcc.h
 * Author: Tendril
 * 
 */

#ifndef REACTOR_GCC_H
#define REACTOR_GCC_H

#define __preload __attribute ((constructor))

#define __module __attribute ((section(".static_modules")))

#endif /* REACTOR_GCC_H */

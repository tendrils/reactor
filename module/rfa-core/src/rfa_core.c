/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: tendril
 *
 * Created on March 16, 2018, 8:40 AM
 */

#include <stdio.h>
#include <stdlib.h>

#include <rfa.h>
#include <rfa/firmware.h>
#include <rfa/module.h>
#include <rfa/component.h>
#include <rfa/component/lifecycle_manager.h>

#include "module_internal.h"

const struct module _rfa_core =
    {
    2,
        {
        
        }
    };

extern int main(int argc, char** argv);

/*
 * 
 */
void rfa_core_init(int argc, char** argv)
    {
    
    rfa_firmware_module_define(rfa_firmware_root(), )
    return (EXIT_SUCCESS);
    }


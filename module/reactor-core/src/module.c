/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <reactor.h>
#include <reactor/firmware.h>
#include <reactor/module.h>
#include "module_internal.h"

size_t rfa_module_size(void) {
    return sizeof(struct module);
    }

extern void rfa_module_define(module_t *module) {
    rfa_firmware_module_define(rfa_firmware_root(), module);
    }

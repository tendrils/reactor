/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   reactor/firmware.h
 * Author: Tendril
 *
 * Created on March 26, 2018, 8:51 AM
 */

#ifndef REACTOR_FIRMWARE_H
#define REACTOR_FIRMWARE_H

#ifndef REACTOR_H
#   error "REACTOR_H must be included before" __FILE__
#endif

firmware_t* rfa_firmware_root();

size_t rfa_firmware_size(void);

rfa_result_t rfa_firmware_module_define(firmware_t *firmware, module_t const *module);

uint8_t rfa_firmware_module_count(firmware_t const *firmware);

module_t const* rfa_firmware_module_get(firmware_t const *firmware, uint8_t idx);

uint8_t rfa_firmware_service_count(firmware_t const *firmware);

service_t const* rfa_firmware_service_get(firmware_t const *firmware, uint8_t idx);

// initialize services + subsystems
rfa_result_t rfa_firmware_load(firmware_t const *firmware);

// start message queues, pass control to scheduler/runloop
rfa_result_t rfa_firmware_run(firmware_t const *firmware);

#endif /* REACTOR_FIRMWARE_H */


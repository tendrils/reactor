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

#ifndef RFA_FIRMWARE_H
#define RFA_FIRMWARE_H

#ifndef RFA_H
#   error "RFA_H must be included before" __FILE__
#endif

size_t rfa_firmware_size(void);

uint8_t rfa_firmware_module_count(firmware_t *firmware);

module_t** rfa_firmware_modules(firmware_t *firmware);

module_t* rfa_firmware_module_get(firmware_t *firmware, uint8_t idx);

service_t** rfa_firmware_services(firmware_t *firmware);

service_t* rfa_firmware_service_get(firmware_t *firmware, uint8_t idx);

#endif /* RFA_FIRMWARE_H */


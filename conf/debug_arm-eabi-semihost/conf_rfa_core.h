/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   conf_rfa_core.h
 * Author: Tendril
 *
 * Created on March 27, 2018, 11:24 PM
 */

#ifndef CONF_RFA_CORE_H
#define CONF_RFA_CORE_H

/* software platform configuration */

#define RFA_FIRMWARE_MODULES_MAX            4
#define RFA_FIRMWARE_COMPONENTS_MAX         16
#define RFA_FIRMWARE_SERVICES_MAX           16

#define RFA_MODULE_COMPONENTS_MAX           4

#define RFAPORT_KERNEL                      RFAPORT_KERNEL_FREERTOS

/* hardware platform configuration */

#define RFA_CHIP_VENDOR                     RFA_CHIP_VENDOR_ATMEL
#define RFA_CHIP_LINE                       RFA_CHIP_LINE_ATMEL_SAME70
#define RFA_CHIP_MODEL                      RFA_CHIP_MODEL_ATMEL_SAME70_Q21B

#define RFA_BOARD                           RFA_BOARD_SAME70_XPLD

#endif /* CONF_RFA_CORE_H */


/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   rfa/bus.h
 * Author: Tendril
 * 
 */

#ifndef RFA_MESSAGE_BUS_H
#define RFA_MESSAGE_BUS_H

#ifndef RFA_H
#   error "rfa.h must be included before" __FILE__
#endif

uint8_t rfa_message_bus_channel_count_get(message_bus_t *bus);

#endif /* RFA_MESSAGE_BUS_H */


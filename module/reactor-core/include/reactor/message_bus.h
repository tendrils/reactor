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

#ifndef REACTOR_MESSAGE_BUS_H
#define REACTOR_MESSAGE_BUS_H

#ifndef REACTOR_H
#   error "rfa.h must be included before" __FILE__
#endif

uint8_t rfa_message_bus_channel_count_get(message_bus_t *bus);

#endif /* REACTOR_MESSAGE_BUS_H */


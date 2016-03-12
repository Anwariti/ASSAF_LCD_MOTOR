/*
 * util.h
 *
 *  Created on: Mar 9, 2016
 *      Author: Anwar
 */

#ifndef UTIL_H_
#define UTIL_H_

#define GET_BIT(Reg , bit)           (Reg & (1<<bit))>> bit
#define CLR_BIT(Reg , bit )           Reg &=~(1<<bit)             // need it more optimized
#define TOGGLE_BIT(Reg , bit )        Reg ^=(1<<bit)
#define SET_REG(Reg)                  Reg =0xff
#define CLR_REG(Reg)                  Reg =0x00
#define TOGGLE_REG(Reg)               Reg ^=0xff
#define ASSIGN_REG(Reg,value)         Reg = value
#define GET_LOW_NIB(Reg)              Reg & 0x0f
#define CLR_LOW_NIB(Reg)              Reg &=0xf0;
#define SET_LOW_NIB(Reg)              Reg |=0x0f;
#define TOGGLE_LOW_NIB(Reg)           Reg ^= 0x0f
#define ASSIGN_LOW_NIB(Reg,value)     Reg= ((Reg &0xf0)|(value & 0x0f))    // need it more optimized
#define CLR_HIGH_NIB(Reg)             Reg &= 0x0f
#define SET_HIGH_NIB(Reg)             Reg |= 0xf0
#define TOGGLE_HIGH_NIB(Reg)          Reg ^= 0xf0
#define ASSIGN_HIGH_NIB(Reg,value)    Reg= ((Reg &0x0f)|( value << 4))

#define SET_REGFROM(Reg , value,bit )           Reg |=(value<<bit)

#endif /* UTIL_H_ */
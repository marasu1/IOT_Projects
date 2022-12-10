/**
 * @file Lib_CommonDefs.h
 * @author Sumant Marathe (iot.sumantmarathe@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2022-12-10
 * 
 * @copyright Copyright (c) 2022
 * 
 */


#ifndef LIB_COMMONDEFS_H
#define LIB_COMMONDEFS_H

#define FALSE   0u
#define TRUE    1u

#define BAUD_RATE  9600


enum Enum_LibState
{
    UNINIT = 0,
    INIT,
    DEINIT
};

enum Enum_ReturnState
{
    E_OK = 0,
    E_PENDING,
    E_NOT_OK
};


#endif
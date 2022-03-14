// Copyright 2022 atlaskef
/**
 * @file inputengine.h
 * @author atlaskef
 * @brief class-alike ООП декларация структур
 * @version 0.1
 * @date 2022-03-14
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#ifndef SRC_INPUTENGINE_H_
#define SRC_INPUTENGINE_H_

struct InputEngine;
typedef struct InputEngine* PInputEngine; 


/////////////////////////////////////////////////////////////////////
/**
 * !!! Объявлять функции тута !!!
 */

// ...
PInputEngine InputEngine__new();
/*void InputEngine__func_test(PInputEngine instance);*/
/////////////////////////////////////////////////////////////////////

#include "inputengine.class.h"

/////////////////////////////////////////////////////////////////////
/**
 * @brief Декларация класса InputEngine
 */
typedef struct InputEngine {
    __inputengine_vtable__ * call;
    
    /// !!!! Объявлять переменные тута !!!!
} InputEngine;
/////////////////////////////////////////////////////////////////////

#endif  // SRC_INPUTENGINE_H_

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
#ifndef SRC_INPUTENGINE_CLASS_H_
#define SRC_INPUTENGINE_CLASS_H_

#include "./inputengine.h"

/////////////////////////////////////////////////////////////////////
/**
 * Декларация Virtual Table класса InputEngine
 */
typedef struct {
    /*void (*func_test)(PInputEngine);*/
    /// !!! Декларация функций... !!!
} __inputengine_vtable__;

extern __inputengine_vtable__ __inputengine_vtable___defaults__;
/////////////////////////////////////////////////////////////////////


/////////////////////////////////////////////////////////////////////
/**
 * Декларация макроса для базовой инициализации InputEngine
 */
#define INPUTENGINE(...) {\
.call = &__inputengine_vtable___defaults__,\
__VA_ARGS__}

#define NEW_INPUTENGINE() InputEngine__new()
/////////////////////////////////////////////////////////////////////


#endif  // SRC_INPUTENGINE_CLASS_H_

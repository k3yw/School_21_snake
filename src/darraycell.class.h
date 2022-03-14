// Copyright 2022 atlaskef
/**
 * @file darraycell.h
 * @author atlaskef
 * @brief class-alike ООП декларация структур
 * @version 0.1
 * @date 2022-03-14
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#ifndef SRC_DARRAYCELL_CLASS_H_
#define SRC_DARRAYCELL_CLASS_H_

#include "./darraycell.h"

/////////////////////////////////////////////////////////////////////
/**
 * Декларация Virtual Table класса DArrayCell
 */
typedef struct {
    /*void (*func_test)(PDArrayCell);*/
    /// !!! Декларация функций... !!!
} __darraycell_vtable__;

extern __darraycell_vtable__ __darraycell_vtable___defaults__;
/////////////////////////////////////////////////////////////////////


/////////////////////////////////////////////////////////////////////
/**
 * Декларация макроса для базовой инициализации DArrayCell
 */
#define DARRAYCELL(...) {\
.call = &__darraycell_vtable___defaults__,\
__VA_ARGS__}

#define NEW_DARRAYCELL(cur_cell, data, page_size, has_data) \
DArrayCell__new(cur_cell, data, page_size, has_data)
/////////////////////////////////////////////////////////////////////


#endif  // SRC_DARRAYCELL_CLASS_H_

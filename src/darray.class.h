// Copyright 2022 atlaskef
/**
 * @file darray.h
 * @author atlaskef
 * @brief class-alike ООП декларация структур
 * @version 0.1
 * @date 2022-03-14
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#ifndef SRC_DARRAY_CLASS_H_
#define SRC_DARRAY_CLASS_H_

#include "./darray.h"

/////////////////////////////////////////////////////////////////////
/**
 * Декларация Virtual Table класса DArray
 */
typedef struct {
    /*void (*func_test)(PDArray);*/
    /// !!! Декларация функций... !!!
    PDArrayCell (*get)(PDArray, int );
    PDArrayCell (*add)(PDArray, void *);
    void (*free)(PDArray);
} __darray_vtable__;

extern __darray_vtable__ __darray_vtable___defaults__;
/////////////////////////////////////////////////////////////////////


/////////////////////////////////////////////////////////////////////
/**
 * Декларация макроса для базовой инициализации DArray
 */

// Закомментированно из-за важной логики в DArray__new()
/* #define DARRAY(...) {\
.call = &__darray_vtable___defaults__,\
__VA_ARGS__} */

#define NEW_DARRAY() DArray__new()
/* #define DARRAY_GET(array, type, index) */
/////////////////////////////////////////////////////////////////////


#endif  // SRC_DARRAY_CLASS_H_

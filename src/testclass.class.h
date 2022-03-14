// Copyright 2022 atlaskef
/**
 * @file testclass.h
 * @author atlaskef
 * @brief class-alike ООП декларация структур
 * @version 0.1
 * @date 2022-03-14
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#ifndef SRC_TESTCLASS_CLASS_H_
#define SRC_TESTCLASS_CLASS_H_

/* #include "./testclass.h" */

/////////////////////////////////////////////////////////////////////
/**
 * Декларация Virtual Table класса TestClass
 */
typedef struct {
    /*void (*func_test)(PTestClass);*/
    /// !!! Декларация функций... !!!
    void (*Render)(PTestClass);
} __testclass_vtable__;

extern __testclass_vtable__ __testclass_vtable___defaults__;
/////////////////////////////////////////////////////////////////////


/////////////////////////////////////////////////////////////////////
/**
 * Декларация макроса для базовой инициализации TestClass
 */
#define TESTCLASS(...) {\
.call = &__testclass_vtable___defaults__,\
__VA_ARGS__}
/////////////////////////////////////////////////////////////////////



#endif  // TESTCLASS_CLASS_H_

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
#ifndef SRC_TESTCLASS_H_
#define SRC_TESTCLASS_H_

struct TestClass;
typedef struct TestClass* PTestClass; 


/////////////////////////////////////////////////////////////////////
/**
 * !!! Объявлять функции тута !!!
 */

// ...
/*void func_test(PTestClass instance);*/
void TestClass__Render(PTestClass instance);
/////////////////////////////////////////////////////////////////////

#include "testclass.class.h"

/////////////////////////////////////////////////////////////////////
/**
 * @brief Декларация класса TestClass
 */
typedef struct TestClass {
    __testclass_vtable__ * call;
    /// !!!! Объявлять переменные тута !!!!
} TestClass;
/////////////////////////////////////////////////////////////////////

#endif  // SRC_TESTCLASS_H_

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
#ifndef SRC_DARRAY_H_
#define SRC_DARRAY_H_

struct DArrayCell;
typedef struct DArrayCell* PDArrayCell;
#define DARRAY_PAGE_LIMIT 16
struct DArray;
typedef struct DArray* PDArray; 


/////////////////////////////////////////////////////////////////////
/**
 * !!! Объявлять функции тута !!!
 */

// ...
PDArray DArray__new();
PDArrayCell DArray__get(PDArray instance, int index);
PDArrayCell DArray__add(PDArray instance, void * data);
void DArray__free(PDArray instance);
/*void DArray__func_test(PDArray instance);*/
/////////////////////////////////////////////////////////////////////

#include "darray.class.h"

/////////////////////////////////////////////////////////////////////
/**
 * @brief Декларация класса DArray
 */
typedef struct DArray {
    __darray_vtable__ * call;
    int size;
    PDArray last_page;
    PDArray next_page;
    PDArrayCell last_element;
    PDArrayCell data[DARRAY_PAGE_LIMIT];
    /// !!!! Объявлять переменные тута !!!!
} DArray;
/////////////////////////////////////////////////////////////////////

#endif  // SRC_DARRAY_H_

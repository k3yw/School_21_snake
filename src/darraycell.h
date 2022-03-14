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
#ifndef SRC_DARRAYCELL_H_
#define SRC_DARRAYCELL_H_

#include "./darray.h"
struct DArrayCell;
typedef struct DArrayCell* PDArrayCell; 


/////////////////////////////////////////////////////////////////////
/**
 * !!! Объявлять функции тута !!!
 */

// ...
PDArrayCell DArrayCell__new(PDArrayCell cur_cell, void * data, int page_size, int has_data);
/*void DArrayCell__func_test(PDArrayCell instance);*/
/////////////////////////////////////////////////////////////////////

#include "darraycell.class.h"

/////////////////////////////////////////////////////////////////////
/**
 * @brief Декларация класса DArrayCell
 */
typedef struct DArrayCell {
    __darraycell_vtable__ * call;
    int id;
    int page_end;
    int has_value;
    PDArray next_page;
    void * data;
    /// !!!! Объявлять переменные тута !!!!
} DArrayCell;
/////////////////////////////////////////////////////////////////////

#endif  // SRC_DARRAYCELL_H_

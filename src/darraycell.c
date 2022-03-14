#include <stdlib.h>
#include "./darraycell.h"
#include "./darray.h"

/////////////////////////////////////////////////////////////////////
/**
 * @brief Инициализация VTable класса DArrayCell
 */
__darraycell_vtable__
    __darraycell_vtable___defaults__ = {
    /*.func_test = DArrayCell__func_test,*/
    // !!! Инициализация функций... !!!
};
/////////////////////////////////////////////////////////////////////

PDArrayCell DArrayCell__new(PDArrayCell cur_cell, void * data, int page_size, int has_data) {
    PDArrayCell ret = cur_cell;
    if (ret == NULL) {
        ret = (PDArrayCell)malloc(sizeof(DArrayCell));
       /*  page_size--; */
    }

    ret->next_page = NULL;

    ret->call = &__darraycell_vtable___defaults__;
    ret->data = data;
    ret->has_value = has_data;
    ret->page_end = page_size >= DARRAY_PAGE_LIMIT;
    ret->id = page_size;

    /* if (ret->page_end) {
        ret->next_page = NEW_DARRAY();
    } */
    return ret;
}

/*
void DArrayCell__func_test(PDArrayCell instance) {
    PTextureMap test = DARRAYCELL();
    test->call.func_test(&test);
} 
*/

/* код */

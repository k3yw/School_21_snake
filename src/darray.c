#include <stdlib.h>
#include "./darray.h"
#include "./darraycell.h"

/////////////////////////////////////////////////////////////////////
/**
 * @brief Инициализация VTable класса DArray
 */
__darray_vtable__
    __darray_vtable___defaults__ = {
    /*.func_test = DArray__func_test,*/
    .add = DArray__add,
    .get = DArray__get,
    .free = DArray__free
    // !!! Инициализация функций... !!!
};
/////////////////////////////////////////////////////////////////////

PDArray DArray__new() {
    PDArray ret = (PDArray)malloc(sizeof(DArray));
    ret->call = &__darray_vtable___defaults__;
    ret->next_page = NULL;
    ret->size = 0;
    ret->last_element = NULL;
    
    ret->last_page = ret;

    for (int i = 0; i < DARRAY_PAGE_LIMIT; i++)
    {
        ret->data[i] = NEW_DARRAYCELL(NULL, NULL, i, 0);
    }

    ret->last_element = ret->data[0];

    return ret;
}

PDArrayCell DArray__add(PDArray instance, void * data) {
    PDArrayCell cell = NULL;
    if (instance == instance->last_page) {
        int is_page_limit = instance->size >= DARRAY_PAGE_LIMIT;
        cell = is_page_limit ? NULL : instance->data[instance->size];

        if (is_page_limit) {
            // костылииииииииииии дедлаааааайныыыыыы
            instance->last_page = NEW_DARRAY();
            instance->next_page = instance->last_page;
            cell = instance->last_page->last_element;
            instance->last_element->next_page = instance->last_page;
            instance->next_page->size += 1;
        } else {
            instance->last_element = cell;
        }

        cell = NEW_DARRAYCELL(cell, data, is_page_limit ? 0 : instance->size, 1);

        if (is_page_limit == 0) {
            instance->size += 1;
        }
        
    } else {
        PDArray next_instance = instance->last_page;
        cell = next_instance->call->add(next_instance, data);
        if (next_instance->last_page != NULL) {
            instance->last_page = next_instance->last_page;
        }
    }
    
    return cell;
}

PDArrayCell DArray__get(PDArray instance, int index) {
    PDArrayCell ret = NULL;
    if (index < instance->size) {
        PDArray current_page = instance;
        PDArrayCell cell = NULL;
        while (index >= DARRAY_PAGE_LIMIT 
            && current_page != NULL) {
            cell = current_page->
                call->get(current_page, index % DARRAY_PAGE_LIMIT); // Может быть баг, добавь -1
            index -= DARRAY_PAGE_LIMIT;
            
            if (cell == NULL) {
                break;
            }
            current_page = cell->next_page;
        }
        
        if (current_page != NULL) {
            cell = current_page->data[index];

            if (cell->has_value == 0) {
                cell = NULL;
            }
            
            ret = cell;
        }
    }
    return ret;
}

void DArray__free(PDArray instance) {
    while (instance != NULL) {
        for (int i = 0; i < DARRAY_PAGE_LIMIT; i++)
        {
            PDArrayCell cell = instance->data[i];
            if (cell != NULL) {
                free(cell);
            }
        }

        PDArray next = instance->data[DARRAY_PAGE_LIMIT]->next_page;
        free(instance);
        instance = next;
    }
}

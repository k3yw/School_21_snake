#include <stdio.h>
#include <stdlib.h>
#include "./../darray.h"
#include "./../darraycell.h"
#include "./tests.h"

int main() {
    system("clear");
    printf("START\n");
    PDArray d = NEW_DARRAY();
    
    test("Size is 0", d->size, 0, 1);

    for (int i = 0; i < DARRAY_PAGE_LIMIT; i++)
    {
        printf("%d, data: %ld\n", d->data[i]->id, (long)d->data[i]->data);
    }

    d->call->add(d, "test");
    

    test("Size is 1 after new element is added", d->size, 1, 1);

    for (int i = 0; i < DARRAY_PAGE_LIMIT; i++)
    {
        printf("%d, data: %ld\n", d->data[i]->id, (long)d->data[i]->data);
    }

    test("ID of last cell is 0", d->last_element->id, 0, 1);


    for (long i = 0; i < DARRAY_PAGE_LIMIT; i++)
    {
        d->call->add(d, (void*) i);
    }

    for (int i = 0; i < DARRAY_PAGE_LIMIT; i++)
    {
        printf("%d, data: %ld\n", d->data[i]->id, (long)d->data[i]->data);
    }
    

    test("ID of last cell is 15", d->data[DARRAY_PAGE_LIMIT - 1]->id, 15, 1);
    
    test("Size is 16", d->size, 16, 1);

    PDArrayCell last = d->next_page->data[0];

    for (int i = 0; i < DARRAY_PAGE_LIMIT; i++)
    {
        printf("%d, data: %ld\n", d->next_page->data[i]->id, (long)d->next_page->data[i]->data);
    }

    test("Last element of a first page is not null", (long)last, TNULL, 0);
    test("New page is created", (long)d->last_page, (long)d, 0);
    test("New page equals next_page", (long)d->last_page, (long)d->next_page, 1);
    test("New page goes after the first page", (long)d->data[DARRAY_PAGE_LIMIT - 1]->next_page, TNULL, 0);
    test("ID of last cell is in new page is 0", d->next_page->last_element->id, 0, 1);
    test("First element of next page equals to DArray->last_element", (long)d->next_page->data[0], (long)last, 1);

    PDArrayCell get_result = d->call->get(d, 5);
    test("Get call returns proper cell", (long)get_result, TNULL, 0);
    test("Get call returns cell with id of 5", get_result->id, 5, 1);
    test("Get call returns NULL cell for index > size (16)", (long)d->call->get(d, 16), TNULL, 1);
    test("Get call returns NULL cell for index > size (5) (next_page)", (long)d->call->get(d->next_page, 15), TNULL, 1);
    return 0;
}

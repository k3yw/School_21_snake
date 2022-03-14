#include <ncurses.h>
#include "./testclass.h"

/////////////////////////////////////////////////////////////////////
/**
 * @brief Инициализация VTable класса TestClass
 */
__testclass_vtable__
    __testclass_vtable___defaults__ = {
    .Render = TestClass__Render
    /*.func_test = func_test,*/
    // !!! Инициализация функций... !!!
};
/////////////////////////////////////////////////////////////////////

/*
void func_test(PTestClass instance) {
    PTextureMap test = TESTCLASS();
} 
*/

void TestClass__Render(PTestClass instance) {
    printw("test\n");
    printf("%ld", (long)instance);
}

/* код */

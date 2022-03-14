#include <stdio.h>
#include <stdlib.h>
#include "./tests.h"

void terminate() {
    printf("%sTerminating...", KCYN);
    exit(0);
}

void test(char* name, long value, long assert, int equals) {
    int status = 0;

    if (equals) {
        status = value == assert;
    } else {
        status = value != assert;
    }

    if (status == 0) {
        printf(" -- %s%s: %s%s%s %s\t\tGiven value: [%ld], Expected: %s [%ld]\n", 
        KYEL,
        name,
        status == 0 ? KRED : KGRN,
        status == 0 ? "FAIL" : "SUCCESS", KNRM,
        KMAG,
        value,
        equals ? "equals" : "not equals",
        assert);
    } else {
        printf(" -- %s%s: %s%s%s\n", 
        KYEL,
        name,
        status == 0 ? KRED : KGRN,
        status == 0 ? "FAIL" : "SUCCESS", KNRM);
    }
    

    if (status == 0) {
        terminate();
    }
}
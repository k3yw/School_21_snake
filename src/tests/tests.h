#ifndef SRC_TESTS_TESTS_H_
#define SRC_TESTS_TESTS_H_

#define TNULL 0

#define KNRM  "\x1B[0m"
#define KRED  "\x1B[31m"
#define KGRN  "\x1B[32m"
#define KYEL  "\x1B[33m"
#define KBLU  "\x1B[34m"
#define KMAG  "\x1B[35m"
#define KCYN  "\x1B[36m"
#define KWHT  "\x1B[37m"

void test(char* name, long value, long assert, int equals);
void terminate();

#endif  // SRC_TESTS_TESTS_H_
#include "acutest.h"


int add_function(int a, int b);
int mult_function(int a, int b);


void test_add_function(void){
    TEST_CHECK(add_function(4,6) == 10);
    TEST_MSG("Expected '4+6 = 10'");
}


TEST_LIST = {
    {"Add function",test_add_function},
    {NULL, NULL}
};



int add_function(int a , int b){
    int result = a + b;
    return result;
}

int mult_function(int a, int b){
    int result = a* b;
    return result;
}
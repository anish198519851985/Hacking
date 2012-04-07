#include <stddef.h>
 
int main(void) {
    char a[3][4] = { { 0 } };
    size_t sz;
    void * ptr;
    char c;
 
    /*
     * "Array decay"
     *
     * 'a' has type 'char[3][4]', as seen on line 4.
     * 'a[0]' has type 'char[4]'.
     * 'a[0][0]' has type 'char'.
     *
     * But when an expression with an array type appears
     * outside of use as the immediate operand of the
     * 'sizeof' operator or the unary '&' address operator,
     * then the expressions are converted to yield a pointer
     * value that points to the array's element type
     *
     * 'a' goes from 'char[3][4]' to 'char (*)[4]'
     * 'a[0]' goes from 'char[4]' to 'char *'
     */
 
    /* Below, 'a' has type 'char[3][4]' */
    sz = sizeof a;
 
    /* Below, 'a[0]' has type 'char[4]' */
    sz = sizeof a[0];
 
    /* Below, 'a[0][0]' has type 'char' */
    sz = sizeof a[0][0];
 
    /* Below, 'a' yields a value with type 'char(*)[4]' */
    ptr = a;
 
    /* Below, 'a[0]' yields a value with type 'char *' */
    ptr = a[0];
 
    /* Below, 'a[0][0]' yields a value with type 'char' */
    c = a[0][0];
 
    /* Below, '&a' yields a value with type 'char(*)[3][4]' */
    ptr = &a;
 
    /* Below, '&a[0]' yields a value with type 'char(*)[4]' */
    ptr = &a[0];
 
    /* Below, '&a[0][0]' yields a value with type 'char *' */
    ptr = &a[0][0];
 
    /* Below, '*a' has type 'char[4]' */
    sz = sizeof *a;
 
    /* Below, '*a[0]' has type 'char' */
    sz = sizeof *a[0];
 
    /* Below, '*a' yields a value with type 'char *' */
    ptr = *a;
 
    /* Below, '*a[0]' yields a value with type 'char' */
    c = *a[0];
 
    return 0;
  }

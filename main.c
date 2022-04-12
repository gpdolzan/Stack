#include "stack.h"

int main(int argc, char const *argv[])
{
    stack stk;
    createStack(&stk);
    push(&stk, 17);
    push(&stk, 12);
    push(&stk, 1);
    push(&stk, 8);
    push(&stk, 19);
    int size = stk.stackSize;
    for(int i = 0; i < size; i++)
        popLog(&stk);
    return 0;
}

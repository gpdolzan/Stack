#include <stdio.h>
#include <stdlib.h>

typedef struct t_node
{
    int data;
    struct t_node *prev;
}t_node;

typedef struct stack
{
    int stackSize;
    struct t_node *top;
}stack;

void createStack(stack *stk);
void destroyStack(stack* stk);

t_node* createNode();
void destroyNode(t_node* node);

void push(stack* stk, int data);
t_node* pop(stack* stk);

/* Extra Functions */
void popLog(stack* stk);
#include "stack.h"

void createStack(stack *stk)
{
    stk->stackSize = 0;
    stk->top = NULL;
}

void destroyStack(stack* stk)
{
    t_node* nodeDestroyer = NULL;

    while(stk->top != NULL)
    {
        nodeDestroyer = stk->top;
        stk->top = stk->top->prev;
        stk->stackSize--;
        free(nodeDestroyer);
    }
}

t_node* createNode()
{
    t_node* node = (t_node*)malloc(sizeof(struct t_node));
    node->data = -1;
    node->prev = NULL;
    return node;
}

void destroyNode(t_node* node)
{
    free(node);
}

void push(stack* stk, int data)
{
    t_node* node = createNode();
    node->data = data;

    if(stk->top == NULL)
    {
        node->prev = NULL;
        stk->top = node;
        stk->stackSize++;
    }
    else
    {
        node->prev = stk->top;
        stk->top = node;
        stk->stackSize++;
    }
}

t_node* pop(stack* stk)
{
    t_node* nodeSaver = NULL;

    if(stk->top == NULL)
        return NULL;
    else
    {
        nodeSaver = stk->top;
        stk->top = stk->top->prev;
        stk->stackSize--;
        return nodeSaver;
    }
    return NULL;
}

void popLog(stack* stk)
{
    t_node* node = pop(stk);
    if(node == NULL)
        return;
    else if(node->prev == NULL)
        printf("Data: %d - Prev: None\n", node->data);
    else
        printf("Data: %d - Prev: %d\n", node->data, node->prev->data);
    destroyNode(node);
}
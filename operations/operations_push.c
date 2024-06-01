#include "./../pushswap.h"

void push_b(t_list_stack *stack_a, t_list_stack *stack_b, int printable)
{
    t_list *top_a;
    t_list *tmp;

    if (!stack_a || !stack_a->stack)
        return;

    top_a = stack_a->stack;
    stack_a->stack = stack_a->stack->next;
    top_a->next = stack_b->stack;
    stack_b->stack = top_a;

    stack_a->size--;
    stack_b->size++;

    if (printable == PRINT)
        printf("pb\n");

    printf("stack_a size: %d, stack_b size: %d\n", stack_a->size, stack_b->size);
    printf("stack_a head: %p, stack_b head: %p\n", (void*)stack_a->stack, (void*)stack_b->stack);

    tmp = stack_a->stack;
    if (tmp)
        index_list(&tmp);

    tmp = stack_b->stack;
    if (tmp)
        index_list(&tmp);

    printf("indices updated\n");
}

void push_a(t_list_stack *stack_a, t_list_stack *stack_b, int printable)
{
    t_list *tmp;

    while(stack_b->stack->next->next)
    {
        stack_b->stack = stack_b->stack->next;
    }
    while (stack_a->stack->next)
    {
        stack_a->stack = stack_a->stack->next;
    }
    stack_a->stack->next = stack_b->stack->next;
    stack_b->stack->next = NULL;
    stack_b->size--;
    stack_a->size++;
    if(printable == PRINT)
        printf("pa\n");

    tmp = stack_a->stack;
    if (tmp)
        index_list(&tmp);

    tmp = stack_b->stack;
    if (tmp)
        index_list(&tmp);
}
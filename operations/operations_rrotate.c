#include "./../pushswap.h"

void reverse_rotate_a(t_list_stack *stack, int printable)
{
    if (!stack || !stack->stack || !stack->stack->next)
        return;

    t_list *tmp = stack->stack;
    t_list *prev = NULL;

    while (tmp->next)
    {
        prev = tmp;
        tmp = tmp->next;
    }

    if (prev)
        prev->next = NULL;

    tmp->next = stack->stack;
    stack->stack = tmp;

    if (printable == PRINT)
        printf("rra\n");

    index_list(&(stack->stack));
}


void reverse_rotate_b(t_list_stack *stack, int printable)
{
    if (!stack || !stack->stack || !stack->stack->next)
        return;

    t_list *tmp = stack->stack;
    t_list *prev = NULL;

    while (tmp->next)
    {
        prev = tmp;
        tmp = tmp->next;
    }

    if (prev)
        prev->next = NULL;

    tmp->next = stack->stack;
    stack->stack = tmp;

    if (printable == PRINT)
        printf("rra\n");

    index_list(&(stack->stack));
}



void	reverse_rotate_ab(t_list_stack *stack_a, t_list_stack *stack_b, int printable)
{
	reverse_rotate_a(stack_a, DONT_PRINT);
	reverse_rotate_b(stack_b, DONT_PRINT);
	if (printable)
		printf("rrr\n");
	index_list(&(stack_a->stack));
	index_list(&(stack_b->stack));
}
#include "./../pushswap.h"

void rotate_a(t_list_stack *stack, int printable)
{
    if (!stack || !stack->stack || !stack->stack->next)
        return;

    t_list *first = stack->stack;
    t_list *tmp = stack->stack;

    while (tmp->next->next)
    {
        tmp = tmp->next;
    }

    t_list *last = tmp->next;
    tmp->next = NULL;
    last->next = first;
    stack->stack = last;

    if (printable == PRINT)
        printf("ra\n");

    index_list(&(stack->stack), INDEX_ON_STACK);
}



void	rotate_b(t_list_stack *stack, int printable)
{
    if (!stack || !stack->stack || !stack->stack->next)
        return;

    t_list *first = stack->stack;
    t_list *tmp = stack->stack;

    while (tmp->next->next)
    {
        tmp = tmp->next;
    }

    t_list *last = tmp->next;
    tmp->next = NULL;
    last->next = first;
    stack->stack = last;

    if (printable == PRINT)
        printf("ra\n");

    index_list(&(stack->stack), INDEX_ON_STACK);

}
void	rotate_ab(t_list_stack *stack_a, t_list_stack *stack_b, int printable)
{
	rotate_a(stack_a, DONT_PRINT);
	rotate_b(stack_b, DONT_PRINT);
	if (printable)
		printf("rr\n");
}

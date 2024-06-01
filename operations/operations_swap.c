#include "./../pushswap.h"

void swap_a(t_list_stack *stack, int printable)
{
    t_list *first;
    t_list *second;

    if (!stack || !stack->stack || !stack->stack->next)
        return;

    first = stack->stack;
    second = stack->stack->next;
    first->next = second->next;
    second->next = first;
    stack->stack = second;

    // Swap indices
    int temp = first->index_in_stack;
    first->index_in_stack = second->index_in_stack;
    second->index_in_stack = temp;

    if (printable == PRINT)
        printf("sa\n");
	index_list(&(stack->stack));
}
void	swap_b(t_list_stack *stack, int printable)
{
	t_list *second_last;

	while (stack->stack->next->next->next)
	{
		stack->stack = stack->stack->next;
	}
	second_last = stack->stack->next;
	stack->stack->next = stack->stack->next->next;
	stack->stack->next->next = second_last;
	if (printable == PRINT)
		printf("sb\n");
	index_list(&(stack->stack));

}
void	swap_ab(t_list_stack *stack_a, t_list_stack *stack_b, int printable)
{
	swap_a(stack_a, DONT_PRINT);
	swap_b(stack_b, DONT_PRINT);
	if (printable == PRINT)
		printf("ss\n");
	index_list(&(stack_a->stack));
	index_list(&(stack_b->stack));
}

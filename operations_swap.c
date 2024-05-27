#include "pushswap.h"

void	swap_a(t_list_stack *stack, int printable)
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
		printf("sa\n");
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
}
void	swap_ab(t_list_stack *stack_a, t_list_stack *stack_b)
{
	swap_a(stack_a, DONT_PRINT);
	swap_b(stack_b, DONT_PRINT);
	printf("ss\n");
}

#include "./../pushswap.h"

void	reverse_rotate_a(t_list_stack *stack, int printable)
{
	t_list *first;

	first = stack->stack;
	stack->stack = stack->stack->next;
	first->next = NULL;
	while(stack->stack->next)
	{
		stack->stack = stack->stack->next;
	}
	stack->stack->next = first;
	if (printable)
		printf("rra\n");
}

void	reverse_rotate_b(t_list_stack *stack, int printable)
{
	t_list *first;

	first = stack->stack;
	stack->stack = stack->stack->next;
	first->next = NULL;
	while(stack->stack->next)
	{
		stack->stack = stack->stack->next;
	}
	stack->stack->next = first;
	if (printable == PRINT)
		printf("rrb\n");
}

void	reverse_rotate_ab(t_list_stack *stack_a, t_list_stack *stack_b, int printable)
{
	reverse_rotate_a(stack_a, DONT_PRINT);
	reverse_rotate_b(stack_b, DONT_PRINT);
	if (printable)
		printf("rrr\n");
}
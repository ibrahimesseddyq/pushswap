#include "./../pushswap.h"

void	push_a(t_list_stack *stack_a, t_list_stack *stack_b, int printable)
{
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
}

void	push_b(t_list_stack *stack_a, t_list_stack *stack_b, int printable)
{
	while(stack_a->stack->next->next)
	{
		stack_a->stack = stack_a->stack->next;
	}
	while (stack_b->stack->next)
	{
		stack_b->stack = stack_b->stack->next;
	}
	stack_b->stack->next = stack_a->stack->next;
	stack_a->stack->next = NULL;
	stack_a->size--;
	stack_b->size++;
	if(printable == PRINT)
		printf("pb\n");
}
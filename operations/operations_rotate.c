#include "./../pushswap.h"

void	rotate_a(t_list_stack *stack, int printable)
{
	t_list *first;
	t_list *tmp;

	first = stack->stack;
	while(stack->stack->next->next)
	{
		stack->stack = stack->stack->next;
	}
	tmp = stack->stack->next;
	stack->stack->next = NULL;
	tmp->next = first;
	stack->stack = tmp;
	if (printable == PRINT)
		printf("ra\n");
}
void	rotate_b(t_list_stack *stack, int printable)
{
	t_list *first;
	t_list *tmp;

	first = stack->stack;
	while(stack->stack->next->next)
	{
		stack->stack = stack->stack->next;
	}
	tmp = stack->stack->next;
	stack->stack->next = NULL;
	tmp->next = first;
	stack->stack = tmp;
	if(printable == PRINT)
		printf("rb\n");
}
void	rotate_ab(t_list_stack *stack_a, t_list_stack *stack_b, int printable)
{
	rotate_a(stack_a, DONT_PRINT);
	rotate_b(stack_b, DONT_PRINT);
	if (printable)
		printf("rr\n");
}

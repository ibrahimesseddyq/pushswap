#include "./../pushswap.h"

void solve_3(t_list_stack *stack_a, t_list_stack *stack_b)
{
	t_list *tmp;
	int	tab[3];
	int i;

	tmp = stack_a->stack;
	i = 0;
	while (tmp)
	{
		tab[i] = tmp->content;
		i++;
		tmp = tmp->next;
	}
	if(tab[0] < tab[1] && tab[1] < tab[2])
		return ;
	if(tab[0] > tab[1] && tab[1] > tab[2])
	{
		swap_a(stack_a,PRINT);
		reverse_rotate_a(stack_a, PRINT);
	}
	else if(tab[0] > tab[1] && tab[2] > tab[0])
	{
		swap_a(stack_a,PRINT);
	}
	else if(tab[0] > tab[2] && tab[2] > tab[1])
	{
		rotate_a(stack_a, PRINT);
	}
	else if(tab[1] > tab[2] && tab[2] > tab[0])
	{
		swap_a(stack_a, PRINT);
		rotate_a(stack_a, PRINT);
	}
	else if(tab[1] > tab[0] && tab[0] > tab[2])
	{
		reverse_rotate_a(stack_a, PRINT);
	}
}
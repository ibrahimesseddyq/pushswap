#include "./../pushswap.h"

void solve_4(t_list_stack *stack_a, t_list_stack *stack_b)
{
	t_list *tmp;
	int	tab[4];
	int small;
	int small_index;
	int i;

	tmp = stack_a->stack;
	i = 0;
	small = tmp->content;
	while (tmp)
	{

		tab[i] = tmp->content;
		i++;
		if(tab[i] < small)
			small = tab[i];
		tmp = tmp->next;
	}
	i = 0;
	// if not sorted
	while (i < 4)
	{
		if (tab[i] == small)
			small_index = i;
		i++;
	}
	while(i-- && i < 2)
	{
		reverse_rotate_a(stack_a, PRINT);
	}

	while(i-- && i >= 2)
	{
		rotate_a(stack_a, PRINT);
	}
	push_b(stack_a, stack_b, PRINT);
	tmp = stack_a->stack;
	small = tmp->content;
	while (tmp)
	{

		tab[i] = tmp->content;
		i++;
		if(tab[i] < small)
			small = tab[i];
		tmp = tmp->next;
	}
	i = 0;
	// if not sorted
	while (i < 4)
	{
		if (tab[i] == small)
			small_index = i;
		i++;
	}
	while(i-- && i < 2)
	{
		reverse_rotate_a(stack_a, PRINT);
	}

	while(i-- && i >= 2)
	{
		rotate_a(stack_a, PRINT);
	}
	solve_3(stack_a, stack_b);
	push_a(stack_a, stack_b, PRINT);
	push_a(stack_a, stack_b, PRINT);

}
#include  "./../pushswap.h"

t_list_stack *fill_stack(t_strings *strings)
{
	int i;
	t_list_stack *stack;
	t_list		*node;

	stack = malloc(sizeof(t_list_stack));
	if ( !stack)
		return (NULL);
	i = 0;
	while (i < strings->size)
	{
		node = ft_lstnew(ft_atoi(strings->strs[i]));
		ft_lstadd_back(&stack->stack, node);
		i++;
	}
	stack->size = strings->size;
	return (stack);
}
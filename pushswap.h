#ifndef PUSHSWAP_H
# define PUSHSWAP_H

# define PRINT 1337
# define DONT_PRINT 42
#include <stdlib.h>
typedef struct s_list
{
	int				content;
	struct s_list	*next;
}	t_list;
typedef struct s_stack
{
	t_list	*stack;
	int		size;
}	t_list_stack;
#endif
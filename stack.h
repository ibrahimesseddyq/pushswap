#ifndef STACK_H
# define STACK_H
#include <stdlib.h>
typedef struct s_element
{
	int value;
	int index;
}  t_element;

typedef struct  s_stack
{
	t_element		*lst;
	size_t 	size;
} t_stack;

#endif
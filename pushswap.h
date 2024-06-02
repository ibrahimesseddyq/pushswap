#ifndef PUSHSWAP_H
# define PUSHSWAP_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <string.h>
# include <limits.h>
# define NL '\n'
# define BUFFER_SIZE 2147483646
# define PRINT 1337
# define DONT_PRINT 42
# define INVALID_CHAR -42
# define NOT_ANUMBER -1
# define SUCCESS		 1
# define ERROR		 -1337
# define SWAP_A		 1
# define SWAP_B		 2
# define SWAP_AB	 3
# define PUSH_A		 4
# define PUSH_B		 5
# define PUSH_AB	 6
# define ROTATE_A	 7
# define ROTATE_B	 8
# define ROTATE_AB	 9
# define RROTATE_B	 10
# define RROTATE_A	 11
# define RROTATE_AB	 12

typedef struct s_strings
	{
		char **strs;
		int size;
	} t_strings;

	
typedef struct s_list
{
	int				index_in_stack;
	int				index;
	int				content;
	struct s_list	*next;
}	t_list;
typedef struct s_stack
{
	t_list	*stack;
	int		size;
}	t_list_stack;

//Operations on stack
t_list_stack *fill_stack(t_strings *strings);
void	swap_a(t_list_stack *stack, int printable);
void	swap_b(t_list_stack *stack, int printable);
void	swap_ab(t_list_stack *stack_a, t_list_stack *stack_b, int printable);
void	rotate_a(t_list_stack *stack, int printable);
void	rotate_b(t_list_stack *stack, int printable);
void	rotate_ab(t_list_stack *stack_a, t_list_stack *stack_b, int printable);
void	reverse_rotate_a(t_list_stack *stack, int printable);
void	reverse_rotate_b(t_list_stack *stack, int printable);
void	reverse_rotate_ab(t_list_stack *stack_a, t_list_stack *stack_b, int printable);
void	swap_a(t_list_stack *stack, int printable);
void	swap_b(t_list_stack *stack, int printable);
void	swap_ab(t_list_stack *stack_a, t_list_stack *stack_b, int printable);
void	push_a(t_list_stack *stack_a, t_list_stack *stack_b, int printable);
void	push_b(t_list_stack *stack_a, t_list_stack *stack_b, int printable);
// other
t_list	*ft_lstnew(int content);
void	ft_lstadd_back(t_list **lst, t_list *new);
t_list_stack *process_parse(int ac, char **av);
char *get_next_line(int fd);
int	ft_atoi(const char *str);
size_t	ft_strlen(const char *str);
void solve_more_than_5(t_list_stack *stack_a, t_list_stack *stack_b);
void index_list(t_list **head);
void print_list(t_list **head);
#endif
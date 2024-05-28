#include "pushswap.h"
// int	check_operation(char *line)
// {
// 	if(line[0] == 's' && line[1] == 'a')
// 		return (SWAP_A);
// 	else if (line[0] == 's' && line[1] == 'b')
// 		return (SWAP_B);
// 	else if (line[0] == 's' && line[1] == 's')
// 		return (SWAP_AB);
// 	else if (line[0] == 'p' && line[1] == 'a')
// 		return (PUSH_A);
// 	else if (line[0] == 'p' && line[1] == 'b')
// 		return (PUSH_B);
// 	else if(line[0] == 'r' && line[1] == 'r' && line[2] == 'r')
// 		return (RROTATE_AB);
// 	else if(line[0] == 'r' && line[1] == 'r' && line[2] == 'a')
// 		return (RROTATE_A);
// 	else if(line[0] == 'r' && line[1] == 'r' && line[2] == 'b')
// 		return (RROTATE_B);
// 	else if (line[0] == 'r' && line[1] == 'r')
// 		return (ROTATE_AB);
// 	else if (line[0] == 'r' && line[1] == 'a')
// 		return (ROTATE_A);
// 	else if (line[0] == 'r' && line[1] == 'b')
// 		return (ROTATE_B);
// 	else 
// 		return (ERROR);
// }
// void operate_swap(int operation, t_list_stack *stack_a, t_list_stack *stack_b)
// {
// 	if (operation == SWAP_A)
// 	{
// 		swap_a(stack_a, DONT_PRINT);
// 	}
// 	else if (operation == SWAP_B)
// 	{
// 		swap_b(stack_b, DONT_PRINT);
// 	}
// 	else if (operation == SWAP_AB)
// 	{
// 		swap_ab(stack_a, stack_b, DONT_PRINT);
// 	}
// }
// void operate_push(int operation, t_list_stack *stack_a, t_list_stack *stack_b)
// {
// 	if (operation == PUSH_A)
// 	{
// 		push_a(stack_a, stack_b, DONT_PRINT);
// 	}
// 	else if (operation == PUSH_B)
// 	{
// 		push_b(stack_b, stack_b, DONT_PRINT);
// 	}
// }
// void operate_rotate(int operation, t_list_stack *stack_a, t_list_stack *stack_b)
// {
// 	if (operation == ROTATE_A)
// 	{
// 		rotate_a(stack_a, DONT_PRINT);
// 	}
// 	else if (operation == ROTATE_B)
// 	{
// 		rotate_b( stack_b, DONT_PRINT);
// 	}
// 	else if (operation == ROTATE_AB)
// 	{
// 		rotate_ab(stack_b, stack_b, DONT_PRINT);
// 	}
// }
// void operate_rrotate(int operation, t_list_stack *stack_a, t_list_stack *stack_b)
// {
// 	if (operation == ROTATE_A)
// 	{
// 		reverse_rotate_a(stack_a, DONT_PRINT);
// 	}
// 	else if (operation == ROTATE_B)
// 	{
// 		reverse_rotate_b( stack_b, DONT_PRINT);
// 	}
// 	else if (operation == ROTATE_AB)
// 	{
// 		reverse_rotate_ab(stack_b, stack_b, DONT_PRINT);
// 	}
// }
// int operate(char *line, t_list_stack *stack_a, t_list_stack *stack_b)
// {
// 	int operation;

// 	operation = check_operation(line);
// 	if (ERROR)
// 		return (ERROR);
// 	if (operation == SWAP_A || operation == SWAP_B || operation == SWAP_AB)
// 		operate_swap(operation, stack_a, stack_b);
// 	else if (operation == PUSH_A || operation == PUSH_B)
// 		operate_push(operation, stack_a, stack_b);
// 	else if (operation == ROTATE_A || operation == ROTATE_B || operation == ROTATE_AB)
// 		operate_rotate(operation, stack_a, stack_b);
// 	else if (operation == RROTATE_A || operation == RROTATE_B || operation == RROTATE_AB)
// 		operate_rotate(operation, stack_a, stack_b);
// 	return (1);
// }
// int process_check(t_list_stack *stack_a, t_list_stack *stack_b)
// {
//     char *line;
// 	int i;

// 	i = 0;
//     while ((line = get_next_line(0)) != NULL)
//     {
//         if (*line == '\n')
//         {
//             free(line);
//             break;
//         }
//         if (operate(line, stack_a, stack_b) == ERROR)
//         {
//             free(line);
//             return (ERROR);
//         }	
// 		if(line[0] == '!')
// 			break;
//         free(line);
// 		i++;
//     }
//     return (1);
// }
// void check_if_sorted(t_list_stack *stack)
// {
// 	int x;
// 	int y;

// 	x = 0;
// 	while(stack->stack->next)
// 	{
// 		y = (int)stack->stack->content;
// 		if (x > y)
// 		{
// 			printf("KO\n");
// 			exit(0);
// 		}
// 		x = y;
// 		stack->stack = stack->stack->next;
// 	}
// 	printf("OK\n");

// }
// int main(int ac, char **av) {
//     t_list_stack *stack_a;
//     t_list_stack *stack_b;


//     stack_a = process_parse(ac, av);
//     stack_b = malloc(sizeof(t_list_stack));
//     if (!stack_b)
// 	{
//         free(stack_a);
//         return (ERROR);
//     }
//     // process_check(stack_a, stack_b);
//     // check_if_sorted(stack_a);
//     // free(stack_a);
//     // free(stack_b);
//     // return (0);
// }
#include "pushswap.h"
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int check_operation(char *line) {
    if (line[0] == 's' && line[1] == 'a')
        return SWAP_A;
    else if (line[0] == 's' && line[1] == 'b')
        return SWAP_B;
    else if (line[0] == 's' && line[1] == 's')
        return SWAP_AB;
    else if (line[0] == 'p' && line[1] == 'a')
        return PUSH_A;
    else if (line[0] == 'p' && line[1] == 'b')
        return PUSH_B;
    else if (line[0] == 'r' && line[1] == 'r' && line[2] == 'r')
        return RROTATE_AB;
    else if (line[0] == 'r' && line[1] == 'r' && line[2] == 'a')
        return RROTATE_A;
    else if (line[0] == 'r' && line[1] == 'r' && line[2] == 'b')
        return RROTATE_B;
    else if (line[0] == 'r' && line[1] == 'r')
        return ROTATE_AB;
    else if (line[0] == 'r' && line[1] == 'a')
        return ROTATE_A;
    else if (line[0] == 'r' && line[1] == 'b')
        return ROTATE_B;
    else
        return ERROR;
}

void operate_swap(int operation, t_list_stack *stack_a, t_list_stack *stack_b) {
    if (operation == SWAP_A) {
        swap_a(stack_a, DONT_PRINT);
    } else if (operation == SWAP_B) {
        swap_b(stack_b, DONT_PRINT);
    } else if (operation == SWAP_AB) {
        swap_ab(stack_a, stack_b, DONT_PRINT);
    }
}

void operate_push(int operation, t_list_stack *stack_a, t_list_stack *stack_b) {
    if (operation == PUSH_A) {
        push_a(stack_a, stack_b, DONT_PRINT);
    } else if (operation == PUSH_B) {
        push_b(stack_a, stack_b, DONT_PRINT);
    }
}

void operate_rotate(int operation, t_list_stack *stack_a, t_list_stack *stack_b) {
    if (operation == ROTATE_A) {
        rotate_a(stack_a, DONT_PRINT);
    } else if (operation == ROTATE_B) {
        rotate_b(stack_b, DONT_PRINT);
    } else if (operation == ROTATE_AB) {
        rotate_ab(stack_a, stack_b, DONT_PRINT);
    }
}

void operate_rrotate(int operation, t_list_stack *stack_a, t_list_stack *stack_b) {
    if (operation == RROTATE_A) {
        reverse_rotate_a(stack_a, DONT_PRINT);
    } else if (operation == RROTATE_B) {
        reverse_rotate_b(stack_b, DONT_PRINT);
    } else if (operation == RROTATE_AB) {
        reverse_rotate_ab(stack_a, stack_b, DONT_PRINT);
    }
}

int operate(char *line, t_list_stack *stack_a, t_list_stack *stack_b) {
    int operation = check_operation(line);
    if (operation == ERROR)
        return ERROR;
    if (operation == SWAP_A || operation == SWAP_B || operation == SWAP_AB) {
        operate_swap(operation, stack_a, stack_b);
    } else if (operation == PUSH_A || operation == PUSH_B) {
        operate_push(operation, stack_a, stack_b);
    } else if (operation == ROTATE_A || operation == ROTATE_B || operation == ROTATE_AB) {
        operate_rotate(operation, stack_a, stack_b);
    } else if (operation == RROTATE_A || operation == RROTATE_B || operation == RROTATE_AB) {
        operate_rrotate(operation, stack_a, stack_b);
    }
    return 1;
}

int process_check(t_list_stack *stack_a, t_list_stack *stack_b) {
    char *line;
    int i = 0;

    while ((line = get_next_line(0)) != NULL) {
        if (*line == '\n') {
            free(line);
            break;
        }
        if (operate(line, stack_a, stack_b) == ERROR) {
            free(line);
            return ERROR;
        }
        free(line);
        i++;
    }
    return 1;
}

void check_if_sorted(t_list_stack *stack) {
    int x;
    int y;

    x = 0;
    while (stack->stack->next) {
        y = (int)stack->stack->content;
        if (x > y) {
            printf("KO\n");
            exit(0);
        }
        x = y;
        stack->stack = stack->stack->next;
    }
    printf("OK\n");
}

int main(int ac, char **av) {
    t_list_stack *stack_a;
    t_list_stack *stack_b;

    stack_a = process_parse(ac, av);
    stack_b = malloc(sizeof(t_list_stack));
    if (!stack_b) {
        free(stack_a);
        return ERROR;
    }
    process_check(stack_a, stack_b);
    check_if_sorted(stack_a);
    free(stack_a);
    free(stack_b);
    return 0;
}

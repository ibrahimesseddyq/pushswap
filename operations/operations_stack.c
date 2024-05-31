#include  "./../pushswap.h"

t_list_stack *fill_stack(t_strings *strings) {
    int i;
    t_list_stack *stack;
    t_list *node;
    t_list *temp_node;

    stack = malloc(sizeof(t_list_stack));
    if (!stack)
        return NULL;
    stack->stack = NULL; // Initialize stack pointer to NULL
    i = 0;
    while (i < strings->size) {
        node = ft_lstnew(ft_atoi(strings->strs[i]));
        if (!node) {
            // Free any previously allocated nodes and the stack in case of an error
            while (stack->stack) {
                temp_node = stack->stack->next;
                free(stack->stack);
                stack->stack = temp_node;
            }
            free(stack);
            return NULL;
        }
        ft_lstadd_back(&stack->stack, node);
        i++;
    }
    stack->size = strings->size;

    // Print stack contents for debugging without altering the original stack pointer
    temp_node = stack->stack;
    while (temp_node) {
        printf("nbr in stack %d\n", temp_node->content);
        temp_node = temp_node->next;
    }

    return stack;
}

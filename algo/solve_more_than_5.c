#include "./../pushswap.h"
void print_list(t_list **head) {
    t_list *current = *head;
    while (current) {
        printf("Index: %d, Content: %d\n", current->index, current->content);
        current = current->next;
    }
}

int compare(const void *a, const void *b) {
    return (*(t_list **)a)->content - (*(t_list **)b)->content;
}

void index_list(t_list **head){
    int size = 0;
    t_list *temp = *head;
    while (temp) {
        size++;
        temp = temp->next;
    }

    t_list **array = (t_list **)malloc(size * sizeof(t_list *));
    if (!array) {
        perror("Failed to allocate array");
        exit(EXIT_FAILURE);
    }

    temp = *head;
    for (int i = 0; i < size; i++) {
        array[i] = temp;
        temp = temp->next;
    }

    qsort(array, size, sizeof(t_list *), compare);

    for (int i = 0; i < size; i++) {
        array[i]->index = i + 1;
    }

    free(array);
}
void solve_more_than_5(t_list_stack *stack_a, t_list_stack *stack_b)
{
    t_list *tmp_ptr;
    int factor_15;
    int factor_30;
    int i = 0;

    // Factor calculations
    factor_15 = stack_a->size / 6;
    factor_30 = stack_a->size / 3;

    // Update index_in_stack for each element in the list
    index_list(&(stack_a->stack));
    tmp_ptr = stack_a->stack;

    // Debugging output
    // printf("i = %d and size = %d\n", i, stack_a->size);
    if (!tmp_ptr)
    {
        printf("tmp_ptr is null\n");
        return;
    }

    while (i < stack_a->size && tmp_ptr != NULL)
    {
        // printf("entered\n");

        if (tmp_ptr->index < factor_30)
        {
            if (tmp_ptr->index_in_stack > 0 && tmp_ptr->index_in_stack < stack_a->size / 2)
            {
                while (tmp_ptr->index_in_stack > 0)
                {
                    rotate_a(stack_a, PRINT);
                    printf("i is %d\n", i);
                    // Update the list indices
                    index_list(&(stack_a->stack));
                    tmp_ptr = stack_a->stack;  // Re-evaluate tmp_ptr after rotation
                    if (tmp_ptr == NULL) break;
                }
            }
            else if (tmp_ptr->index_in_stack >= stack_a->size / 2)
            {
                while (tmp_ptr->index_in_stack > 0)
                {
                    reverse_rotate_a(stack_a, PRINT);
                    index_list(&(stack_a->stack));
                    tmp_ptr = stack_a->stack;  // Re-evaluate tmp_ptr after reverse rotation
                    if (tmp_ptr == NULL) break;
                }
            }
            push_b(stack_a, stack_b, PRINT);
			
            // index_list(&(stack_b->stack));  // Update indices for stack_b
            // if (tmp_ptr->index < factor_15)
            //     reverse_rotate_b(stack_b, PRINT);
        }
        tmp_ptr = tmp_ptr->next;
        i++;
    }
}
#include "./../pushswap.h"
void print_list(t_list *head) {
    while (head) {
        printf("Index: %d, Content: %d\n", head->index, head->content);
        head = head->next;
    }
}

// Comparator function for qsort
int compare(const void *a, const void *b) {
    return (*(t_list **)a)->content - (*(t_list **)b)->content;
}

// Function to index the list
void index_list(t_list *head) {
    int size = 0;
    t_list *temp = head;
    while (temp) {
        size++;
        temp = temp->next;
    }

    t_list **array = (t_list **)malloc(size * sizeof(t_list *));
    if (!array) {
        perror("Failed to allocate array");
        exit(EXIT_FAILURE);
    }

    temp = head;
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
	t_list **tmp;
	int factor_15;
	int factor_30;

	tmp = &(stack_a->stack);
	factor_15 = stack_a->size / 6;
	factor_30 = stack_a->size / 3;

	index_list(tmp);
	while(stack_a->stack)
	{

	}

}
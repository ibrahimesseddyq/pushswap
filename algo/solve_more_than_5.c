#include "./../pushswap.h"
void print_list(t_list **head)
{
    t_list *current = *head;
    while (current) {
        printf("Index: %d, Content: %d, Index in stack: %d\n", current->index, current->content, current->index_in_stack);
        current = current->next;
    }
}

int compare(const void *a, const void *b) {
    return (*(t_list **)a)->content - (*(t_list **)b)->content;
}

void index_list(t_list **head, int operation)
{
    int size = 0;
    t_list *temp = *head;
	int j = 0;
    while (temp) {
        size++;
		temp->index_in_stack = j;
        temp = temp->next;
		j++;
    }
	if (operation == INDEX_ON_STACK)
		return ;
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
        array[i]->index = i ;
    }

    free(array);
}
// void solve_more_than_5(t_list_stack *stack_a, t_list_stack *stack_b)
// {
//     t_list *tmp_ptr;
//     int factor_15;
//     int factor_30;

//     while (stack_a->size > 3)
//     {
//         // Factor calculations
//         factor_15 = stack_a->size / 6;
//         factor_30 = stack_a->size / 3;

//         // Update index_in_stack for each element in the list
//         index_list(&(stack_a->stack));
//         tmp_ptr = stack_a->stack;

//         if (!tmp_ptr)
//         {
//             printf("tmp_ptr is null\n");
//             return;
//         }

//         while (tmp_ptr && stack_a->size > 3)
//         {
//             if (tmp_ptr->index < factor_30)
//             {
//                 // printf("entered content : %d index : %d, index in stack: %d\n", tmp_ptr->content, tmp_ptr->index, tmp_ptr->index_in_stack);
//                 // printf("index in stack %d and pivot %d\n", tmp_ptr->index_in_stack, stack_a->size / 2);

//                 // Rotate or reverse rotate until the element is at the top
//                 while (tmp_ptr->index_in_stack > 0)
//                 {
//                     if (tmp_ptr->index_in_stack > stack_a->size / 2)
//                     {
//                         rotate_a(stack_a, PRINT);
//                     }
//                     else
//                     {
//                         reverse_rotate_a(stack_a, PRINT);
//                     }

//                     index_list(&(stack_a->stack));
//                     tmp_ptr = stack_a->stack;  // Re-evaluate tmp_ptr after each rotation
//                 }

//                 // Push the element to stack_b
//                 push_b(stack_a, stack_b, PRINT);
//                 index_list(&(stack_b->stack));  // Update indices for stack_b
//                 printf("\n----a---\n");
//                 print_list(&(stack_a->stack));
//                 printf("\n----b---\n");
//                 print_list(&(stack_b->stack));
//                 printf("\n----end---\n");

//                 // If the pushed element's index is less than factor_15, reverse rotate stack_b
//                 if (stack_b->stack && stack_b->stack->index < factor_15)
//                 {
//                     reverse_rotate_b(stack_b, PRINT);
//                 }
                
//                 // Recalculate factors and update indices
//                 factor_15 = stack_a->size / 6;
//                 factor_30 = stack_a->size / 3;
//                 index_list(&(stack_a->stack));
//                 index_list(&(stack_b->stack));

//                 // Start from the beginning of the stack_a after each push
//                 tmp_ptr = stack_a->stack;
//             }
//             else
//             {
//                 tmp_ptr = tmp_ptr->next;
//             }

//             if (!tmp_ptr)
//             {
//                 printf("tmp_ptr is null\n");
//                 break;
//             }
//         }
//     }
// }
int check_if_there_isnolessthanfactor30(t_list *tmp_ptr,int factor_30)
{
	while (tmp_ptr)
	{
		if(tmp_ptr->index < factor_30)
			return (1);
		tmp_ptr = tmp_ptr->next;
	}
	return (0);
}
// void solve_more_than_5(t_list_stack *stack_a, t_list_stack *stack_b)
// {
//     t_list *tmp_ptr;
//     int factor_15;
//     int factor_30;

//     while (stack_a->size > 3)
//     {
//         // Factor calculations
//         factor_15 = stack_a->size / 6;
//         factor_30 = stack_a->size / 3;

//         // Print factor values for debugging
//         printf("Factor 15: %d, Factor 30: %d\n", factor_15, factor_30);

//         // Update index_in_stack for each element in the list
//         index_list(&(stack_a->stack), INDEX_ORDER);
//         tmp_ptr = stack_a->stack;

//         if (!tmp_ptr)
//         {
//             printf("tmp_ptr is null\n");
//             return;
//         }

//         while ( tmp_ptr && check_if_there_isnolessthanfactor30(stack_a,factor_30) && stack_a->size > 3)
//         {
//             printf("Checking element with index: %d, content: %d\n", tmp_ptr->index, tmp_ptr->content);

//             if (tmp_ptr->index < factor_30)
//             {
//                 printf("Element to move: content: %d, index: %d, index in stack: %d\n", tmp_ptr->content, tmp_ptr->index, tmp_ptr->index_in_stack);
//                 printf("Index in stack: %d and pivot: %d\n", tmp_ptr->index_in_stack, stack_a->size / 2);

//                 // Rotate or reverse rotate until the element is at the top
//                 while (tmp_ptr->index_in_stack > 0)
//                 {
//                     if (tmp_ptr->index_in_stack > stack_a->size / 2)
//                     {
//                         rotate_a(stack_a, PRINT);
//                     }
//                     else
//                     {
//                         reverse_rotate_a(stack_a, PRINT);
//                     }
//                 }

//                 // Push the element to stack_b
//                 push_b(stack_a, stack_b, PRINT);
//                 index_list(&(stack_b->stack), INDEX_ON_STACK);  // Update indices for stack_b
//                 printf("\n----a---\n");
//                 print_list(&(stack_a->stack));
//                 printf("\n----b---\n");
//                 print_list(&(stack_b->stack));
//                 printf("\n----end---\n");

//                 // If the pushed element's index is less than factor_15, reverse rotate stack_b
//                 if (stack_b->stack && stack_b->stack->index < factor_15)
//                 {
//                     rotate_b(stack_b, PRINT);
//                 }
                
// 				printf("Factor 15: %d, Factor 30: %d\n", factor_15, factor_30);

//                 index_list(&(stack_a->stack), INDEX_ON_STACK);
//                 index_list(&(stack_b->stack), INDEX_ON_STACK);

//                 // Start from the beginning of the stack_a after each push
//                 tmp_ptr = stack_a->stack;
//             }
//             else
//             {
//                 tmp_ptr = tmp_ptr->next;
//             }

//             if (!tmp_ptr)
//             {
//                 printf("tmp_ptr is null\n");
//                 break;
//             }
//         }
//     }
// }
// void solve_more_than_5(t_list_stack *stack_a, t_list_stack *stack_b)
// {
// 	t_list *tmp_ptr;
//     int factor_15;
//     int factor_30;
// 	int lessthan15;

// 	lessthan15 = 0;
// 	while(stack_a->size > 3)
// 	{
// 		factor_15 = stack_a->size / 6;
//         factor_30 = stack_a->size / 3;
// 		index_list(&(stack_b->stack), INDEX_ORDER);
// 		while(tmp_ptr && check_if_there_isnolessthanfactor30(stack_a->stack,factor_30))
// 		{
// 			    while (tmp_ptr->index_in_stack > 0)
//                 {
//                     if (tmp_ptr->index_in_stack > stack_a->size / 2)
//                         rotate_a(stack_a, PRINT);
//                     else
//                         reverse_rotate_a(stack_a, PRINT);
// 					index_list(&(stack_b->stack), INDEX_ON_STACK);
//                 }
// 			if (tmp_ptr->index < factor_15)
// 				lessthan15 = 1;
// 			if (tmp_ptr->index < factor_30)
// 			{
// 				push_b(stack_a, stack_b, PRINT);
// 				index_list(&(stack_b->stack), INDEX_ON_STACK);
// 			}
// 			if (lessthan15)
// 				rotate_b(stack_b, PRINT);
// 			if(tmp_ptr->next)
// 				tmp_ptr = tmp_ptr->next;
// 			else
// 				tmp_ptr = stack_a->stack;
// 		}
// 	}
// }
void solve_more_than_5(t_list_stack *stack_a, t_list_stack *stack_b)
{
    t_list *tmp_ptr;
    int factor_15;
    int factor_30;

    while (stack_a->size > 3) {
        factor_15 = stack_a->size / 6;
        factor_30 = stack_a->size / 3;
        index_list(&(stack_b->stack), INDEX_ORDER);  // Update order-based indices in stack_b

        tmp_ptr = stack_a->stack;

        while (tmp_ptr && check_if_there_isnolessthanfactor30(tmp_ptr, factor_30)) {
            while (tmp_ptr->index_in_stack > 0) {
                if (tmp_ptr->index_in_stack > stack_a->size / 2)
                    rotate_a(stack_a, PRINT);
                else
                    reverse_rotate_a(stack_a, PRINT);

                index_list(&(stack_a->stack), INDEX_ON_STACK);  // Update indices after rotate
                tmp_ptr = stack_a->stack;  // Reset tmp_ptr to the new head
            }

            if (tmp_ptr->index < factor_15) {
                // Move element based on index < factor_15 logic here (potentially rotate_b)
            }

            if (tmp_ptr->index < factor_30) {
                push_b(stack_a, stack_b, PRINT);
                index_list(&(stack_b->stack), INDEX_ON_STACK); // Update indices after push
                index_list(&(stack_a->stack), INDEX_ON_STACK); // Update indices after push
            }

            tmp_ptr = stack_a->stack;  // Reset tmp_ptr to the new head after each operation
        }
    }
}
PUSHSWAP = push_swap
CHECKER = checker
SRC = 
OPS_SRC = operations/operations_stack.c operations/operations_push.c operations/operations_rotate.c operations/operations_rrotate.c operations/operations_swap.c
ALGO_SRC =  algo/solve_more_than_5.c

UTILS_SRC = utils/ft_lstadd_back.c utils/ft_lstnew.c
LIBFT_SRC = ft_strlen.c ft_atoi.c get_next_line.c
SRC_BONUS = checker.c parser.c $(OPS_SRC) $(ALGO_SRC)
SRC = pushswap.c parser.c $(OPS_SRC) $(ALGO_SRC)
OBJ = $(SRC:.c=.o)

FLAGS = 
OBJ_BONUS = $(SRC_BONUS:.c=.o)
all: $(PUSHSWAP)

$(PUSHSWAP): $(OBJ)
	gcc $(FLAGS) $(LIBFT_SRC) $(UTILS_SRC) $(OBJ) -o $(PUSHSWAP)
bonus: $(CHECKER)

$(CHECKER): $(OBJ_BONUS)
	gcc $(FLAGS) $(LIBFT_SRC) $(UTILS_SRC) $(OBJ_BONUS) -o $(CHECKER)

%.o: %.c
	gcc $(FLAGS) -c $< -o $@

clean:
	rm -f $(OBJ_BONUS)

fclean: clean
	rm -f $(CHECKER)

re: fclean bonus

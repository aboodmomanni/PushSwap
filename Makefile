CC = cc
CFLAGS = -Wall -Wextra -Werror

SRC = ft_lstadd_back_bonus.c \
      ft_lstnew_bonus.c \
      ft_lstsize_bonus.c \
      ft_lstclear.c \
      generateIndeces.c \
      main.c \
      makestack.c \
      push.c \
      radix.c \
      reverseRotate.c \
      rotate.c \
      sort3-5.c \
      sortType.c \
      ft_atoi.c \
      ft_isdigit.c \
      swap.c

OBJ = $(SRC:.c=.o)
NAME = push_swap

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
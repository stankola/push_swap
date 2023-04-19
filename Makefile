# TODO: 42 header

NAME = push_swap

CC = cc

CFLAGS = -Wall -Wextra -Werror

SRCDIR = src

LIBDIR = lib

OBJDIR = obj

INCDIR = include

LIB_INCDIR = $(LIBDIR)/$(INCDIR)

_SRC =	stack.c stack_functions.c push_swap.c push_swap_operations.c \
		push_swap_main.c isinteger.c chkoverflow.c insertion_sort.c \
		ft_graph.c ft_max.c ft_min.c ft_queue.c
SRC = $(patsubst %, $(SRCDIR)/%, $(_SRC))

_OBJ = $(patsubst %.c, %.o, $(_SRC))
OBJ = $(patsubst %, $(OBJDIR)/%, $(_OBJ))

_LIB =	libft.a
LIB = $(patsubst %, $(LIBDIR)/%, $(_LIB))

_INC = push_swap.h sorting_algorithms.h stack.h
INC = $(patsubst %, $(INCDIR)/%, $(_INC))

_LIB_INC = libft.h
LIB_INC = $(patsubst %, $(LIB_INCDIR)/%, $(_LIB_INC))

.PHONY: all

all: $(NAME)

$(LIB):
	$(MAKE) -C $(LIBDIR)

$(OBJDIR)/%.o: $(SRCDIR)/%.c $(INC) $(LIB)
	$(CC) $(CFLAGS) -c $< -I$(INCDIR) -I$(LIB_INCDIR)  -o $@

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -L$(LIBDIR) -l:$(_LIB) -o $@

clean:
	rm -f $(OBJ)
	$(MAKE) -C $(LIBDIR) clean
	rm -f $(LIB)

fclean: clean
	rm -f $(NAME)

re: fclean all
# TODO: 42 header

NAME = push_swap

CC = cc

CFLAGS = -Wall -Wextra -Werror

SFLAGS = -fsanitize=address -g3

SRCDIR = src

LIBDIR = lib

OBJDIR = obj

INCDIR = include

LIB_INCDIR = $(LIBDIR)/$(INCDIR)

_SRC =	ft_math.c ft_queue.c isinteger.c push_swap.c push_swap_main.c \
		push_swap_operations.c push_swap_operator.c \
		ring.c ring_functions.c stack.c stack_functions.c
#_SRC +=	merge_sort.c radix_sort.c insertion_sort.c ring_merge_sort.c \
#		ring_radix_sort.c 
_SRC +=	radix_sort.c
_SRC +=	test_utils.c
SRC = $(patsubst %, $(SRCDIR)/%, $(_SRC))

_OBJ = $(patsubst %.c, %.o, $(_SRC))
OBJ = $(patsubst %, $(OBJDIR)/%, $(_OBJ))

_LIB =	libft.a
LIB = $(patsubst %, $(LIBDIR)/%, $(_LIB))
LIB_COMPILER_NAME = $(patsubst lib%.a, %, $(_LIB))

_INC =	ft_math.h push_swap.h push_swap_operations.h ring.h \
		sorting_algorithms.h stack.h
INC = $(patsubst %, $(INCDIR)/%, $(_INC))

_LIB_INC = libft.h
LIB_INC = $(patsubst %, $(LIB_INCDIR)/%, $(_LIB_INC))

.PHONY: all

all: $(NAME)

sanitizer: $(OBJ)
	$(CC) $(CFLAGS) $(SFLAGS) $(OBJ) -L$(LIBDIR) -l$(LIB_COMPILER_NAME) -o $(NAME)

$(OBJDIR):
	mkdir -p $(OBJDIR)

$(LIB):
	$(MAKE) -C $(LIBDIR)

$(OBJDIR)/%.o: $(SRCDIR)/%.c $(INC) $(LIB) $(OBJDIR)
	$(CC) $(CFLAGS) -c $< -I$(INCDIR) -I$(LIB_INCDIR) -o $@

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -L$(LIBDIR) -l$(LIB_COMPILER_NAME) -o $@

clean:
	rm -f $(OBJ)
	$(MAKE) -C $(LIBDIR) clean
	rm -f $(LIB)
	rm -f $(patsubst %, %~, $(SRC))
	rm -f $(patsubst %, %~, $(INC))

fclean: clean
	rm -f $(NAME)

re: fclean all
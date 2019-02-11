CC = clang

NAME = minishell

CFLAGS = -Werror -Wall -Wextra

LDLIBS = -lft

LDFLAGS = -L libft

LDSANI = -lsani

LDINST = -linst

DEP = \
	libft/libft.a

CPPFLAGS = -I includes -I libft/includes

SRC_PATH = srcs

OBJ_PATH = obj

HDR_PATH = includes

SRC_NAME = 	env_class.c \
	env_method2.c \
	lexer_class.c \
	env_method3.c \
	env_method.c \
	parser_class.c \
	lexer_method.c \
	parser_method.c \
	get_next_line.c \
	main.c \
	parser_method3.c \
	parser_method2.c \
	parser_method4.c

HDR_NAME = 	env_class.h \
	get_next_line.h \
	lexer_class.h \
	minishell.h \
	env_method.h \
	parser_method2.h \
	lexer_method.h \
	parser_class.h \
	parser_method.h

OBJ_NAME = $(SRC_NAME:.c=.o)

SRC = $(addprefix $(SRC_PATH)/,$(SRC_NAME))

OBJ = $(addprefix $(OBJ_PATH)/,$(OBJ_NAME))

HDR = $(addprefix $(HDR_PATH)/,$(HDR_NAME))

all: $(NAME)

$(DEP):
	make -C $(dir $@)

$(NAME): libft/libft.a $(OBJ) $(HDR)
	$(CC) $(CFLAGS) -I includes -I libft -o $@ $(OBJ) -L libft -lft

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c
	@mkdir $(OBJ_PATH) 2> /dev/null || true
	$(CC) $(CFLAGS) $(CPPFLAGS) -o $@ -c $<

clean:
	rm -fv $(OBJ)
	rm -rf $(OBJ_PATH) 2> /dev/null || true
	make clean -C libft

fclean: clean
	rm -fv $(NAME)
	rm -fv libft/libft.a
	rm -fv libft/smax/libsmax.a

re: fclean all

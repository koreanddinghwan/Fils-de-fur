# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: myukang <myukang@student.42.kr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/27 18:01:47 by myukang           #+#    #+#              #
#    Updated: 2022/04/27 22:07:38 by myukang          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf
CFLAGS = -Wall -Wextra -Werror -c -g -fsanitize=address
GFLAGS = -I /usr/local/include -L /usr/local/lib -lmlx -framework OpenGL -framework Appkit
GCC = gcc

LIBFT_DIR = ./libft/
LIBFT = libft.a
MLX_DIR = ./minilibx/
MLX = libmlx.a

GNL_DIR = ./gnl/
GNL_SRCS = get_next_line.c get_next_line_utils.c
GNL_OBJS_O = $(GNL_SRCS:.c=.o)
GNL_OBJS = $(addprefix $(GNL_DIR), $(GNL_OBJS_O))

FDF_DIR = ./fdf_srcs/
FDF_SRCS = main.c fils_de_fer.c
FDF_OBJS_O = $(FDF_SRCS:.c=.o)
FDF_OBJS = $(addprefix $(FDF_DIR), $(FDF_OBJS_O))

TOOLS_DIR = ./fdf_srcs/tools/
TOOLS_SRCS = call_error.c validate_file_name.c free_split.c
TOOLS_OBJS_O = $(TOOLS_SRCS:.c=.o)
TOOLS_OBJS = $(addprefix $(TOOLS_DIR), $(TOOLS_OBJS_O))

OBJ_FILES = $(FDF_OBJS) $(GNL_OBJS) $(TOOLS_OBJS)

all : $(NAME)

$(NAME) : $(OBJ_FILES)
	make all -C $(LIBFT_DIR)
	make all -C $(MLX_DIR)
	mv $(LIBFT_DIR)$(LIBFT) $(LIBFT)
	mv $(MLX_DIR)$(MLX) $(MLX)
	$(GCC) -Wall -Wextra -Werror -g -fsanitize=address -o $@ $^ $(MLX) $(LIBFT) $(GFLAGS)

%.o : %.c
	$(GCC) $(CFLAGS) $< -o $@

fclean : clean
	rm -f $(NAME)

clean :
	make fclean -C $(LIBFT_DIR)
	make clean -C $(MLX_DIR)
	rm -f $(OBJS_FILES) $(LIBFT)

re : fclean all

.PHONY: all clean fclean re 



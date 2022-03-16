# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rdanyell <rdanyell@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/16 12:33:05 by rdanyell          #+#    #+#              #
#    Updated: 2022/02/18 16:00:56 by rdanyell         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME_SL		= so_long

NAME_SLB	= so_long_bonus

LIB_DIR		= libft/

LIBFT		= $(LIB_DIR)/libft.a

INCLUDES_SL	= includes/

HEADER_SL	= includes/so_long.h

HEADER_SLB	= includes/so_long_bonus.h

DIR_SL		= srcs/

DIR_SLB		= bonus/

FILES_SL	= main.c parse.c init.c play.c check.c 			

FILES_SLB	= main_bonus.c parse_bonus.c init_bonus.c \
			play_bonus.c check_bonus.c animation_bonus.c \
			enemy_bonus.c score_bonus.c

SRCS_SL		= $(addprefix $(DIR_SL), $(FILES_SL))

SRCS_SLB	= $(addprefix $(DIR_SLB), $(FILES_SLB))

OBJS_SL		= $(SRCS_SL:%.c=%.o)

OBJS_SLB	= $(SRCS_SLB:%.c=%.o)

CC 			= cc

CFLAGS		= -Wall -Wextra -Werror

MLX_FLAGS = -l mlx -framework OpenGL -framework AppKit

.PHONY: 	all libft mlx clean fclean re bonus

all:		libft $(NAME_SL)

libft:
			make -C $(LIB_DIR)

bonus:
			@make NAME_SL="$(NAME_SLB)" \
			OBJS_SL="$(OBJS_SLB)" \
			HEADER_SL="$(HEADER_SLB)" all

$(NAME_SL):	$(OBJS_SL)
			$(CC) $(CFLAGS) $(MLX_FLAGS) $(OBJS_SL) $(LIBFT) -o $@

%.o:		%.c $(LIBFT) $(HEADER_SL) 
			$(CC) $(CFLAGS) -I $(INCLUDES_SL) -I mlx -c $< -o $@

clean	:
			$(RM) $(OBJS_SL) $(OBJS_SLB)
			make -C $(LIB_DIR) clean
				
fclean	:	clean
			rm -r $(NAME_SL) $(NAME_SLB)
			make -C $(LIB_DIR) fclean

re		:	fclean all
	

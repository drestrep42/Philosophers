# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: drestrep <drestrep@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/17 19:54:56 by drestrep          #+#    #+#              #
#    Updated: 2024/03/12 15:42:07 by drestrep         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 			= 		philo

CC 				= 		gcc
CFLAGS 			= 		-g3 -Wall -Wextra -Werror -fsanitize=address #-O3

SRC_DIR			=		src
SRCS			=		$(wildcard	src/*.c)

OBJ_DIR			=		obj
OBJS 			= 		$(addprefix obj/, $(notdir $(SRCS:%.c=%.o)))

all:					$(NAME)
	
$(NAME):				$(OBJS) | $(OBJ_DIR)
						@$(CC) $(CFLAGS) $(OBJS) -o philo
						@echo " "
						@echo "💭💭   💭  💭  💭  💭     💭💭    💭💭    💭💭    💭💭   💭  💭  💭💭💭  💭💭    💭💭"
						@echo "💭  💭 💭  💭  💭  💭   💭    💭 💭     💭    💭  💭  💭 💭  💭  💭      💭  💭 💭"
						@echo "💭💭   💭💭💭  💭  💭   💭    💭  💭💭  💭    💭  💭💭   💭💭💭  💭💭💭  💭💭    💭💭"
						@echo "💭     💭  💭  💭  💭   💭    💭     💭 💭    💭  💭     💭  💭  💭      💭  💭     💭"
						@echo "💭     💭  💭  💭  💭💭   💭💭    💭💭    💭💭    💭     💭  💭  💭💭💭  💭  💭  💭💭"
						@echo " "

	
$(OBJ_DIR)/%.o:			$(SRC_DIR)/%.c | $(OBJ_DIR)
						@$(CC) $(CFLAGS) -c $< -o $@
	
$(OBJ_DIR):	
						@mkdir -p $(OBJ_DIR)
	
clean:
						@rm -rf $(OBJ_DIR)
	
fclean: clean	
						@rm -rf $(NAME)

re: fclean all
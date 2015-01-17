# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hades <hades@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/01/07 11:47:18 by alex              #+#    #+#              #
#    Updated: 2015/01/17 21:49:10 by hades            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= ft_gkrellm
CC			= g++
CFLAGS		= -Wall -Werror -Wextra -g
LIBS 		= -lncurses
RM			= rm -rf

SRC			=	sources/IMonitorDisplay.class.cpp \
				sources/IMonitorModule.class.cpp \
				sources/Ncurses.class.cpp \
				sources/CPUmodule.class.cpp \
				sources/DTmodule.class.cpp \
				sources/HSmodule.class.cpp \
				sources/OSmodule.class.cpp \
				sources/Rmodule.class.cpp \
				sources/main.cpp 

OBJ			= $(SRC:.cpp=.o)

all:		$(NAME)

$(NAME):	$(OBJ)
			$(CC) -o $(NAME) $(OBJ) $(LIBS)

clean:
			$(RM) $(OBJ)

fclean:		clean
			$(RM) $(NAME)

re:			fclean all

%.o:		%.cpp
			$(CC) $(CFLAGS) -c $< -o $@

.PHONY:		all clean re fclean
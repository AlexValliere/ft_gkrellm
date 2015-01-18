# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alex <alex@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/01/07 11:47:18 by alex              #+#    #+#              #
#    Updated: 2015/01/18 17:51:20 by alex             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= ft_gkrellm
CC			= g++
CFLAGS		= -Wall -Werror -Wextra `pkg-config --cflags gtk+-3.0`
LIBS 		= -lncurses `pkg-config --libs gtk+-3.0`
RM			= rm -rf

SRC			=	sources/IMonitorDisplay.class.cpp \
				sources/IMonitorModule.class.cpp \
				sources/GtkDisplay.class.cpp \
				sources/Ncurses.class.cpp \
				sources/CPUmodule.class.cpp \
				sources/DTmodule.class.cpp \
				sources/HSmodule.class.cpp \
				sources/OSmodule.class.cpp \
				sources/Rmodule.class.cpp \
				sources/Refresh.class.cpp \
				sources/usual_functions.cpp \
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
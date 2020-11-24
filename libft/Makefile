# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    Makefile                                         .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: yalabidi <marvin@le-101.fr>                +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2018/10/03 11:06:26 by yalabidi     #+#   ##    ##    #+#        #
#    Updated: 2018/10/13 18:55:56 by matheme     ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #

NAME=libft.a

HEADER=libft.h

OBJ= 	ft_memcpy.o\
		ft_strncat.o\
		ft_memmove.o\
		ft_memset.o\
		ft_strcpy.o\
		ft_strncpy.o\
		ft_bzero.o\
		ft_memccpy.o\
		ft_strdup.o\
		ft_memchr.o\
		ft_strlcat.o\
		ft_memcmp.o\
		ft_strcat.o\
		ft_strlen.o\
		ft_strchr.o\
		ft_strrchr.o\
		ft_strstr.o\
		ft_strnstr.o\
		ft_strcmp.o\
		ft_strncmp.o\
		ft_atoi.o\
		ft_isalpha.o\
		ft_isalnum.o\
		ft_isascii.o\
		ft_isdigit.o\
		ft_isprint.o\
		ft_toupper.o\
		ft_tolower.o\
		ft_putchar.o\
		ft_putstr.o\
		ft_putendl.o\
		ft_putnbr.o\
		ft_putchar_fd.o\
		ft_putstr_fd.o\
		ft_putendl_fd.o\
		ft_putnbr_fd.o\
		ft_memalloc.o\
		ft_memdel.o\
		ft_strnew.o\
		ft_strdel.o\
		ft_strclr.o\
		ft_striter.o\
		ft_striteri.o\
		ft_strmap.o\
		ft_strmapi.o\
		ft_strequ.o\
		ft_strnequ.o\
		ft_strsub.o\
		ft_strjoin.o\
		ft_strtrim.o\
		ft_strsplit.o\
		ft_itoa.o\
		ft_lstnew.o\
		ft_lstdelone.o\
		ft_lstdel.o\
		ft_lstadd.o\
		ft_lstiter.o\
		ft_lstmap.o\
		ft_lstaddback.o\
		ft_power.o\
		ft_putadresse.o\
		ft_putdoubletab.o\

CC=-Wall -Werror -Wextra

all : $(NAME)

$(NAME) : $(OBJ)

%.o : %.c
	gcc -I$(HEADER) $(CC) -c $^ -o $@
	ar rs $(NAME) $@

clean :
	rm -f $(OBJ)

fclean : clean
	rm -f $(NAME)

re : fclean all


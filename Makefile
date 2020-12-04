# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: matheme <matheme@student.42lyon.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/24 13:54:31 by matheme           #+#    #+#              #
#    Updated: 2020/12/04 17:37:56 by matheme          ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

# nom de l'executable
NM_NAME = ft_nm
OTOOL_NAME = ft_otool

#sources
SRC_GPATH		= srcs
NM_SRC_PATH		= $(SRC_GPATH)/nm
OTOOL_SRC_PATH	= $(SRC_GPATH)/otool

#objects
NM_OBJ_PATH		= nm_obj
OTOOL_OBJ_PATH	= otool_obj

#includes
INC_PATH		= includes
HEADER			= $(INC_PATH)/nm.h $(INC_PATH)/otool.h

NM_NAME_SRC		=	main.c handle_64.c handle_32.c nm.c sort.c swap.c symbol.c handle_fat.c handle_ar.c g_file.c get_cpu_type.c
OTOOL_NAME_SRC	=	main.c


# les objects
NM_OBJ				= $(addprefix $(NM_OBJ_PATH)/,$(NM_NAME_SRC:.c=.o))
OTOOL_OBJ			= $(addprefix $(OTOOL_OBJ_PATH)/,$(OTOOL_NAME_SRC:.c=.o))

#compilateur + flags
CC			=	gcc #-g3 -fsanitize=address -g3
CFLAGS		=  -Wall -Wextra -Werror

#librairies
LIBFT				= libft
LIBFT_INC			= libft
LIBFT.A				= $(LIBFT)/libft.a


all : lib $(NM_NAME) $(OTOOL_NAME)

$(NM_NAME) : $(NM_OBJ) $(LIBFT.A)
	@$(CC) -I $(LIBFT_INC) -L $(LIBFT) $^ -o $@ && printf "\n\n${B}[EXECUTABLE \"$(NM_NAME)\" COMPILED]${N}\n\n"

$(OTOOL_NAME) : $(OTOOL_OBJ) $(LIBFT.A)
	@$(CC) -I $(LIBFT_INC) -L $(LIBFT) $^ -o $@ && printf "\n\n${B}[EXECUTABLE \"$(OTOOL_NAME)\" COMPILED]${N}\n\n"

$(NM_OBJ_PATH)/%.o : $(NM_SRC_PATH)/%.c $(INC_PATH)/nm.h
	@mkdir $(NM_OBJ_PATH) 2> /dev/null || true
	@$(CC) -I $(LIBFT_INC) -I $(INC_PATH) -c $< -o $@
	@printf "\033[2K\r${G} >>Compiling ${N}$<\033[36m \033[0m"


$(OTOOL_OBJ_PATH)/%.o : $(OTOOL_SRC_PATH)/%.c $(INC_PATH)/otool.h
	@mkdir $(OTOOL_OBJ_PATH) 2> /dev/null || true
	@$(CC) -I $(LIBFT_INC) -I $(INC_PATH) -c $< -o $@
	@printf "\033[2K\r${G} >>Compiling ${N}$<\033[36m \033[0m"

lib:
	@make -C $(LIBFT)

clean:
	@rm -f $(NM_OBJ)
	@rm -f $(OTOOL_OBJ)
	@make -C $(LIBFT) clean
	@rmdir $(NM_OBJ_PATH) 2> /dev/null || true
	@rmdir $(OTOOL_OBJ_PATH) 2> /dev/null || true
	@printf "${R}[CLEANING $(NM_NAME) BINARIES]${N}\n\n"
	@printf "${R}[CLEANING $(OTOOL_NAME) BINARIES]${N}\n\n"

fclean: clean
	@make -C $(LIBFT) fclean
	@rm -f $(NM_NAME)
	@rm -f $(OTOOL_NAME)
	@printf "${R}[REMOVING $(NM_NAME) BINARIES]${N}\n\n"
	@printf "${R}[REMOVING $(OTOOL_NAME) BINARIES]${N}\n\n"

re: fclean all

nor :
	@printf "\n${B}[NORMINETTE $(NAME)]${N}\n\n"
	@norminette $(NM_SRC_PATH)/*.c $(OTOOL_SRC_PATH)/*.c $(INC_PATH)/*.h



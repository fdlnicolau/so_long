# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    MAKEFILE                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lnicolau <lnicolau@student.42malaga.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/26 02:59:59 by lnicolau          #+#    #+#              #
#    Updated: 2024/05/26 02:59:59 by lnicolau         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME        =   so_long

#------------------------------------------------------------------------------#
#---------------------------------INSTRUCTIONS---------------------------------#
#------------------------------------------------------------------------------#
CC          =   cc -I ${INCLUDE} -I ${LIBFT_SRC} -I ${MLX_SRC}/include -Wall -Wextra -Werror -MMD -g
RM          =   rm -rf
USER        =   lnicolau
#------------------------------------------------------------------------------#
#------------------------------------INIT--------------------------------------#
#------------------------------------------------------------------------------#
SRC_DIR            =   src

OBJ_DIR            =   obj
LIBS               =   ./libs/
INCLUDE            =   ./include/
#------------------------------------------------------------------------------#
#-----------------------------------FILES--------------------------------------#
#------------------------------------------------------------------------------#


SRC_FILES          =   ${SRC_DIR}/main.c \
                        ${SRC_DIR}/free.c \
                        ${SRC_DIR}/check_map.c \
                        ${SRC_DIR}/utils.c \
                        #${SRC_DIR}/parsing.c \

OBJ                =   $(patsubst %.c, $(OBJ_DIR)/%.o, $(SRC_FILES))
DEP                =   $(addsuffix .d, $(basename $(SRC_FILES)))

#------------------------------------------------------------------------------#
#---------------------------------DEPENDENCIES---------------------------------#
#------------------------------------------------------------------------------#
LIBFT_SRC   =   libft
MLX_SRC     =   /sgoinfre/shared/MLX42/builds
FT_LNK      =   -L$(LIBFT_SRC) -lft
MLX_LNK     =   -L$(MLX_SRC) -lmlx42 -ldl -lglfw -pthread -lm
#------------------------------------------------------------------------------#
#-----------------------------------RULES--------------------------------------#
#------------------------------------------------------------------------------#

all: 
	@$(MAKE) -C $(LIBFT_SRC)
	@$(MAKE) $(NAME)

$(OBJ_DIR)/%.o: %.c Makefile
	@mkdir -p $(dir $@)
	@echo  "${WHITE}+---------------------------------------+${DEF_COLOR}"
	@echo  "${WHITE}|${BLUE} File Name: ${BROWN}$(notdir $<)"
	@echo  "${WHITE}|${CYAN} Path:      ${YELLOW}$(dir $<)"
	@echo  "${WHITE}+---------------------------------------+${DEF_COLOR}"
	@$(CC) -c $< -o $@

-include $(DEP)

$(NAME):    $(OBJ)
	@echo
	@echo "${ITALIC}${BOLD}${MAGENTA}+---------------------------------------------+${DEF_COLOR}"
	@echo "${ITALIC}${BOLD}${MAGENTA}|${BLUE} Compiling ${NAME}...${MAGENTA}                        |${DEF_COLOR}"
	@echo "${ITALIC}${BOLD}${MAGENTA}+---------------------------------------------+${DEF_COLOR}"
	@$(CC) $(OBJ) $(FT_LNK) $(MLX_LNK) -o $(NAME) 
	@echo "\n${BLUE} ◎ $(GREEN)$(NAME) compiled successfully ${BLUE}◎$(DEF_COLOR)\n"

clean:
	@${RM} ${OBJ} ${DEP}
	@$(RM) ./$(OBJ_DIR)
	@$(MAKE) -C $(LIBFT_SRC) clean
	@echo "\n${BLUE} ◎ $(RED)All objects cleaned successfully ${BLUE}◎$(DEF_COLOR)\n"

fclean: clean
	@$(RM) $(NAME)
	@$(MAKE) -C $(LIBFT_SRC) fclean
	@echo "\n${BLUE} ◎ $(RED)All objects and executable cleaned successfully${BLUE} ◎$(DEF_COLOR)\n"

re: fclean all

.PHONY: all clean fclean re


# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cpoulain <cpoulain@student.42lehavre.fr>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/18 16:33:26 by cpoulain          #+#    #+#              #
#    Updated: 2024/11/28 13:00:39 by cpoulain         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Commands

RM				=	/usr/bin/rm -f
ECHO			=	/usr/bin/echo

# Includes

include			Files.mk
include			Files_Test.mk

# Directories

SRC_DIR			:=	src
INC_DIR			:=	include
OBJ_DIR			:=	build
TEST_DIR		:=	tests
TEST_INC_DIR	:=	tests/include

# Third party

THIRD_PARTY_LIB	:=	third_party
LIBFT_DIR		:=	42_libft_full
LIBFT_PATH		:=	$(THIRD_PARTY_LIB)/$(LIBFT_DIR)
LIBFT_INC_H		:=	libft.h
LIBFT_TARGET	:=	libftfull.a
LIBFT_GIT		:=	https://github.com/CodeWithCharles/42_libft_full.git

# Targets

TARGET			:=	pipex
TEST_TARGET		:=	tester

# Compiler

CC				:=	cc
CFLAGS			:=	-Wall -Wextra -Werror

# Files definition

MAIN_FILE		:=	$(SRC_DIR)/pipex
CORE_FILES		:=	$(filter-out $(MAIN_FILE), $(FILES))

# Objs formatter

CORE_SRCS		=	$(addprefix $(SRC_DIR)/, $(addsuffix .c, $(CORE_FILES)))
CORE_OBJS		=	$(addprefix $(OBJ_DIR)/, $(addsuffix .o, $(CORE_FILES)))
TEST_SRCS		=	$(addprefix $(TEST_DIR)/$(SRC_DIR)/, $(addsuffix .c, $(TEST_FILES)))
TEST_OBJS		=	$(addprefix $(OBJ_DIR)/$(TEST_DIR)/, $(addsuffix .o, $(TEST_FILES)))
SRCS			=	$(addprefix $(SRC_DIR)/, $(addsuffix .c, $(FILES)))
OBJS			=	$(addprefix $(OBJ_DIR)/, $(addsuffix .o, $(FILES)))

# Terminal colors

TERM_RESET		:=	\033[0m
TERM_BLACK		:=	\033[30m
TERM_RED		:=	\033[31m
TERM_GREEN		:=	\033[32m
TERM_YELLOW		:=	\033[33m
TERM_BLUE		:=	\033[34m
TERM_MAGENTA	:=	\033[35m
TERM_CYAN		:=	\033[36m
TERM_WHITE		:=	\033[37m

TERM_UP			:=	\033[1A
TERM_CLEAR_LINE	:=	\033[2K\r

# Phony rules

.PHONY: all clean fclean re norminette _header _obj_footer _obj_header tests cleanlibs fcleanlibs tests

all: $(TARGET)

clean:
	@if [ -e $(OBJ_DIR) ]; then \
		printf "$(TERM_YELLOW)Removing %d objects from \"%s\" folder...\n$(TERM_RESET)" $(words $(OBJS)) $(OBJ_DIR);\
		$(RM) -r $(OBJ_DIR);\
	fi

fclean: clean
	@if [ -e $(TARGET) ]; then \
		printf "$(TERM_YELLOW)Removing \"%s\"...\n$(TERM_RESET)" $(TARGET);\
		$(RM) $(TARGET);\
		$(RM) libft.h;\
	fi
	@if [ -e $(TEST_TARGET) ]; then \
		printf "$(TERM_YELLOW)Removing \"%s\"...\n$(TERM_RESET)" $(TEST_TARGET); \
		$(RM) $(TEST_TARGET);\
	fi

cleanlibs:
	@$(MAKE) clean -C $(LIBFT_PATH)

tests: $(TEST_TARGET)

fcleanlibs:
	@$(MAKE) fclean -C $(LIBFT_PATH)
	@$(RM) $(LIBFT_TARGET)
	@$(RM) $(INC_DIR)/$(LIBFT_INC_H)

re: fclean all

norminette:
	@norminette $(SRC_DIR) $(INC_DIR) | grep -Ev '^Notice|OK!$$'	\
	&& $(ECHO) -e '\033[1;31mNorminette KO!'						\
	|| $(ECHO) -e '\033[1;32mNorminette OK!'

_header:
	@printf "$(TERM_GREEN)Welcome to $(TERM_BLUE) \"%s\"$(TERM_GREEN) builder !\n$(TERM_RESET)" $(TARGET)

_obj_header:
	@printf "$(TERM_MAGENTA)Building objects into \"%s\" folder...\n$(TERM_RESET)" $(OBJ_DIR)

_obj_footer:
	@printf "$(TERM_UP)$(TERM_CLEAR_LINE)$(TERM_GREEN)Done building $(TERM_BLUE)%d$(TERM_GREEN) object(s) !\n$(TERM_RESET)" $(words $(OBJS))

tests: all
	@printf "$(TERM_UP)$(TERM_GREEN)Building test file into \"%s\".\n$(TERM_RESET)" $(TEST_FILE)
	@sh -c "$(CC) $(OBJS) $(CFLAGS) $(NAME) $(TEST_FILE) -o $(TEST_TARGET) && ./$(TEST_TARGET)"

# Binary / Lib generation

$(TARGET): $(LIBFT_TARGET) _header _obj_header $(OBJS) _obj_footer
	@printf "$(TERM_MAGENTA)Making executable $(TERM_BLUE)\"%s\"$(TERM_MAGENTA)...$(TERM_RESET)" $@
	@$(CC) $(OBJS) -I$(INC_DIR) $(LIBFT_TARGET) -o $@ $(CFLAGS)
	@printf "$(TERM_CLEAR_LINE)$(TERM_GREEN)Done building executable $(TERM_BLUE)\"%s\"$(TERM_GREEN) !\n$(TERM_RESET)" $@

$(TEST_TARGET): $(LIBFT_TARGET) _header _obj_header $(CORE_OBJS) $(TEST_OBJS) _obj_footer
	@printf "$(TERM_YELLOW)Making executable $(TERM_BLUE)\"%s\"$(TERM_MAGENTA)...$(TERM_RESET)" $@
	@$(CC) $(CORE_OBJS) $(TEST_OBJS) -I$(INC_DIR) -I$(TEST_INC_DIR) $(LIBFT_TARGET) -o $@ $(CFLAGS)
	@printf "$(TERM_CLEAR_LINE)$(TERM_GREEN)Done building executable $(TERM_BLUE)\"%s\"$(TERM_GREEN) !\n$(TERM_RESET)" $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@printf "$(TERM_CLEAR_LINE)$(TERM_MAGENTA)Compiling $(TERM_BLUE)\"%s\"$(TERM_MAGENTA)...\n$(TERM_RESET)" $@
	@mkdir -p $(@D)
	@$(CC) -c $< -o $@ -I$(INC_DIR) $(CFLAGS)
	@printf "$(TERM_UP)"

$(OBJ_DIR)/$(TEST_DIR)/%.o: $(TEST_DIR)/%.c
	@printf "$(TERM_CLEAR_LINE)$(TERM_YELLOW)Compiling $(TERM_BLUE)\"%s\"$(TERM_YELLOW)...\n$(TERM_RESET)" $@
	@mkdir -p $(@D)
	@$(CC) -c $< -o $@ -I$(INC_DIR) $(CFLAGS)
	@printf "$(TERM_UP)"

# Third party compilation

$(LIBFT_TARGET):
	@if [ ! -d "$(LIBFT_PATH)/.git" ]; then \
		printf "$(TERM_YELLOW)Cloning third party library \"%s\" in \"%s\"...\n$(TERM_RESET)" $(LIBFT_GIT) $(LIBFT_PATH);\
		git clone $(LIBFT_GIT) $(LIBFT_PATH);\
	fi
	@printf "$(TERM_MAGENTA)Making archive $(TERM_BLUE)\"%s\"$(TERM_MAGENTA)...$(TERM_RESET)" $@
	@$(MAKE) -C $(LIBFT_PATH)
	@mv $(LIBFT_PATH)/$(LIBFT_INC_H) $(INC_DIR)
	@mv $(LIBFT_PATH)/$(LIBFT_TARGET) ./ 
	@printf "$(TERM_CLEAR_LINE)$(TERM_GREEN)Done building archive $(TERM_BLUE)\"%s\"$(TERM_GREEN) !\n$(TERM_RESET)" $@

define MSG
# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile for libft                                 :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: arsciand <arsciand@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/10/14 19:23:44 by arsciand          #+#    #+#              #
#                                                     ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
endef

# Progress bar

ifneq ($(words $(MAKECMDGOALS)),1)
.DEFAULT_GOAL   =   make
%:
	@$(MAKE) $@ --no-print-directory -rRf $(firstword $(MAKEFILE_LIST))
else
ifndef ECHO
T               :=  $(shell $(MAKE) $(MAKECMDGOALS) --no-print-directory \
                    -nrRf $(firstword $(MAKEFILE_LIST)) \
                    ECHO="OutputPrintable" | grep -c "OutputPrintable")
N               :=  x
C               =   $(words $N)$(eval N := x $N)
V               =   "`expr "   [\`expr $C '*' 100 / $T\`" : '.*\(....\)$$'`%]"
ECHO            =   printf "\e[1A\r%s %s %s                                      \n" $V
endif

# Color

RESET_C         =   \033[m
B_C             =   \033[0;34m
Y_C             =   \033[0;33m
G_C             =   \033[0;32m
R_C             =   \033[0;31m
M_C             =   \033[0;35m
C_C             =   \033[0;36

# Programms names

NAME            =   libft.a

# Dir/Files Path

S_PATH          =   srcs/
H_PATH          =   includes/
B_PATH          =   build/
O_PATH          =   build/objs/
PATHS           +=  $(B_PATH)
PATHS           +=  $(O_PATH)

# Files

SRC             += $(S_PATH)ft_atoi.c
SRC             += $(S_PATH)ft_atol.c
SRC             += $(S_PATH)ft_isdigit.c
SRC             += $(S_PATH)ft_isnum.c
SRC             += $(S_PATH)ft_itoa.c
SRC             += $(S_PATH)ft_lstfind.c
SRC             += $(S_PATH)ft_lstappend.c
SRC             += $(S_PATH)ft_lstdel.c
SRC             += $(S_PATH)ft_lstdelone.c
SRC             += $(S_PATH)ft_lstiter.c
SRC             += $(S_PATH)ft_lstiter_ctx.c
SRC             += $(S_PATH)ft_lstlen.c
SRC             += $(S_PATH)ft_lstnew.c
SRC             += $(S_PATH)ft_memalloc.c
SRC             += $(S_PATH)ft_memcpy.c
SRC             += $(S_PATH)ft_memdel.c
SRC             += $(S_PATH)ft_memset.c
SRC             += $(S_PATH)ft_get_opts_and_args.c
SRC             += $(S_PATH)ft_strchr.c
SRC             += $(S_PATH)ft_strcmp.c
SRC             += $(S_PATH)ft_strcpy.c
SRC             += $(S_PATH)ft_strdel.c
SRC             += $(S_PATH)ft_strdup.c
SRC             += $(S_PATH)ft_strequ.c
SRC             += $(S_PATH)ft_strlen.c
SRC             += $(S_PATH)ft_tabcopy.c
SRC             += $(S_PATH)ft_tabdel.c
SRC             += $(S_PATH)ft_tablen.c


# Objects and Headers

HDR             +=  libft.h

# STD             +=  gnu17

OBJ             =   $(patsubst $(S_PATH)%.c, $(O_PATH)%.o, $(SRC))
vpath %.h $(H_PATH)

# Variables

DEBUG           =
CFLAGS          =   -Wall -Wextra -Werror# -std=$(STD)
ifeq ($(DEBUG), g)
    CFLAGS      =   -g
else ifeq ($(DEBUG), fsanitize)
    CFLAGS      =   -fsanitize=address
else ifeq ($(DEBUG), hard)
    CFLAGS      +=  -Weverything -fsanitize=address,undefined #-Wno-cast-qual -Wno-missing-noreturn -Wno-disabled-macro-expansion -Wno-reserved-id-macro
else ifeq ($(DEBUG), dev)
    CFLAGS      =
endif
CC              =   clang $(CFLAGS)
COMPL           =   $(CC) -c -I$(H_PATH)
BUILD           =   $(PATHS)
AR_RC           =   ar rc
RANLI           =   ranlib
CFLAG           =   -Wall -Wextra -Werror -g
RM_RF           =   /bin/rm -rf
MKDIR           =   mkdir -p
NORME           =   norminette
SLEEP           =   sleep 0.01
GCFIL           =   "- > Compiling  -"
GCLAR           =   "- } Archiving  -"
RMSHW           =   "- - Removing   -"
MKSHW           =   "- + Creating   -"
GCRUN           =   echo ">\n$(G_C)----->     Compiling$(RESET_C)\n"
CLRUN           =   echo ">\n$(R_C)----->     Cleaning$(RESET_C)\n"
NORMR           =   echo ">\n$(Y_C)----->     Norminette$(RESET_C)\n"

.PHONY: all norme clean fclean re test

# Rules

make:
	$(MSG)
	$(MAKE) --no-print-directory all

all: $(BUILD) $(NAME)

$(NAME): $(OBJ)
	$(SLEEP)
	$(AR_RC) $(NAME) $^
	$(ECHO) $(GCLAR) $@
	$(RANLI) $(NAME)

$(OBJ): $(O_PATH)%.o: $(S_PATH)%.c $(HDR)
	$(COMPL) $< -o $@
	$(ECHO) $(GCFIL) $<

$(PATHS):
	$(SLEEP)
	$(GCRUN)
	$(MKDIR) $(PATHS)
	$(foreach var,$(PATHS), $(ECHO) $(MKSHW) $(var);)

norme:
	$(NORMR)
	$(NORME) $(SRC) $(H_PATH)$(HNAME)
	$(NORMD)

clean:
	$(CLRUN)
	for i in $(OBJ); do $(RM_RF) $$i; $(ECHO) $(RMSHW) $$i; done

fclean:
	$(CLRUN)
	for i in $(OBJ); do $(RM_RF) $$i; $(ECHO) $(RMSHW) $$i; done
	for i in $(PATHS); do $(RM_RF) $$i; $(ECHO) $(RMSHW) $$i; done
	$(RM_RF) $(NAME)
	$(ECHO) $(RMSHW) $(NAME)

re:
	$(MAKE) --no-print-directory fclean all

ifndef VERBOSE
.SILENT:
endif

endif

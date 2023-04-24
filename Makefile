#################################################################################
## PROJECT			                                               ##
#################################################################################

 NAME    =       iam

#################################################################################
## BUILDING DETAILS                                                            ##
#################################################################################

GCC 		= 	gcc
ECHO 		= 	/bin/echo -e
INCLUDE 	= 	-I./include
FLAGS 		= 	-Wextra -Wall -Werror -g3 -std=c11
LIBSPATH	=	-L$(HOME)/.froot/lib/
LIBRARIES	=	-llapin -lsfml-graphics -lsfml-audio -lsfml-window	\
			-lsfml-system -lstdc++ -lm -ldl -lpthread -lgcc_s -lavcall

DEFLT	=	"\033[00m"
PINK	=	"\033[0;36m"
GREEN	=	"\033[1;32m"
TEAL	=	"\033[1;36m"
RED	=	"\033[0;31m"
BLINK 	= 	"\033[1;92m"
SBLINK	= 	"\033[0m"

#################################################################################
## SOURCE                                                                      ##
#################################################################################

SRC     =       $(shell find ./ -name "*.c")
OBJ     =       $(SRC:.c=.o)
MAIN    =       $(wildcard main/*.c)
MOBJ    =       $(MAIN:.c=.o)

#################################################################################
## RULES                                                                       ##
#################################################################################

all:$(NAME)

build :		$(ECHO) $(BLINK) "[SUCCESS]" $(DEFLT)

%.o : %.c
	@ $(GCC) -o $@ -c $< $(INCLUDE) $(FLAGS) && \
	$(ECHO) $(BLINK) "[OK]"$(SBLINK) $(PINK) $< $(DEFLT) || \
	$(ECHO) $(RED) "[KO]" $(PINK) $< $(DEFLT)

$(NAME):$(OBJ) $(MOBJ)
	@ $(GCC) -o $@ $^ $(INCLUDE) $(FLAGS) $(LIBSPATH) $(LIBRARIES) && \
	$(ECHO) $(BLINK) "[OK]"$(SBLINK) $(PINK) $(NAME) $(DEFLT) || \
	$(ECHO) $(RED) "[KO]" $(TEAL) $(NAME) $(DEFLT)

clean:
	@ find -name "*.o" -delete && find -name "*~" -delete && \
	$(ECHO) $(BLINK) "[CLEAN SUCCESS]" $(DEFLT)

fclean:
	@find . -name "*.so" -delete -or -name "*.exe" -delete \
        -or -name "*.a" -delete -or -name "*.o" -delete    \
        -or -name "*~" -delete -or -name "vgcore*" -delete
	@$(ECHO) $(GREEN) "All useless files deleted!" $(DEFLT)
	@find -name $(NAME) -delete
	@$(ECHO) $(GREEN) "Binary deleted!" $(DEFLT)

re: 		fclean all


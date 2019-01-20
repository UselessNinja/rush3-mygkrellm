##
## EPITECH PROJECT, 2019
## my_convert_temp
## File description:
## Compile the program
##

NAME    =       MyGKrellm

CCPP    =       g++

SRC     =       main.cpp					\
				modules/Memory.cpp			\
				modules/Network.cpp			\
				modules/Os.cpp				\
				modules/Processor.cpp		\
				modules/Time.cpp			\
				modules/User.cpp			\
				core/core.cpp				\
				core/MonitorDisplay.cpp     \
				sfml/sfmlMain.cpp           \
				sfml/display_mod.cpp        \
				sfml/mySFML.cpp             \
				sfml/dispRam.cpp			\
				ncurses/ncurseMain.cpp		\
				ncurses/ncursePrint.cpp


OBJ     =       $(SRC:.cpp=.o)

CPPFLAGS =      -Wextra -Wall -I.

RED     =       \033[31;1m

GRE     =       \033[32;1m

YEL     =       \033[33;1m

ORA     =       \033[33;5m

BLU     =       \033[34;1m

CYAN    =       \033[36;1m

PUR     =       \033[35;1m

END     =       \033[0m

RM      =       rm -f

all:            $(NAME)

$(NAME):        $(OBJ)
		@$(CCPP) -o $(NAME) $(OBJ) -lncurses -lsfml-graphics -lsfml-window -lsfml-system
		@echo

clean:
		@echo -e "Cleaning the folder !"
		@$(foreach var, $(OBJ), if [ -e $(var) ] ; then                         \
		        printf "{$(RED)\xe2\x9c\x98$(END)} $(var)\n"        \
		        && $(RM) $(var) ; fi ;)
		@$(RM) vgcore.*
		@echo -e "Folder cleaned !"

fclean:         clean
		@echo -e "Deleting the binary !"
		@if [ -e $(NAME) ] ; then                                               \
		        printf "{$(RED)\xe2\x9c\x98$(END)} $(NAME)\n"       \
		        && rm -f $(NAME) ; fi
		@echo -e "Binary gone !"

re:             fclean all

%.o:            %.cpp
		@echo -e "{$(GRE)\xe2\x9c\x93$(END)} $<$(END) $(RED)\xe2\x9f\xb6$(END) $@)"
		@$(CC) $(CPPFLAGS) -o $@ -c $<

.PHONY:         all clean fclean re
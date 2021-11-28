#SHELL = /usr/bin/env bash

NAME = ea
COMPILER = gcc
FLAGS = -o

clean :
	@rm $(NAME)

all:
	@$(COMPILER) $(FLAGS) $(NAME) $(NAME).c

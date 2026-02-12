CC			:= gcc
CFLAGS	:= -std=c11 -pedantic -Wall -Wextra -Werror

NAME 		:= print_decimal
SRC 		:= ./src/$(NAME).c
OBJ 		:= ./obj/$(NAME).o

LIB_NAME	:= libprint_decimal.a

DEMO_EXEC	:= demo
DEMO_SRC 	:= demo.c

all: $(LIB_NAME)

$(LIB_NAME): $(OBJ)
	ar rcs $@ $<

$(OBJ): $(SRC)
	mkdir -p obj
	$(CC) $(CFLAGS) -c $< -o $@

demo: $(DEMO_SRC) $(LIB_NAME)
	$(CC) $^ -o $@
	./$@

clean:
	rm -rf $(DEMO_EXEC) $(LIB_NAME) obj/ 

.PHONY: all demo clean

CC			  := gcc
CFLAGS	  := -std=c11 -pedantic -Wall -Wextra -Werror

NAME 	  	:= print_decimal
SRC 	  	:= ./src/$(NAME).c
OBJ 	  	:= ./obj/$(NAME).o

LIB_NAME	:= libprint_decimal.a

DEMO_EXEC	:= demo
DEMO_SRC 	:= demo.c

TEST_EXEC := test
TEST_SRC  := tests/test.c
TESTFLAGS := -lcheck
OS        := $(shell uname)
ifeq ($(OS), Linux)
  TESTFLAGS += -lpthread -lrt -lm -lsubunit
endif

all: $(LIB_NAME)

$(LIB_NAME): $(OBJ)
	ar rcs $@ $<

$(OBJ): $(SRC)
	mkdir -p obj
	$(CC) $(CFLAGS) -c $< -o $@

demo: $(DEMO_SRC) $(LIB_NAME)
	$(CC) $^ -o $@
	./$@

test: $(LIB_NAME) $(TEST_SRC)
	$(CC) $(CFLAGS) $(TEST_SRC) $(LIB_NAME) -o $(TEST_EXEC) $(TESTFLAGS)
	./$(TEST_EXEC)

clean:
	rm -rf \
	$(DEMO_EXEC) \
	$(TEST_EXEC) \
	$(LIB_NAME) \
	obj/ 

.PHONY: all demo clean

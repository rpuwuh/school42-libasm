NAME = libasm.a

ASM = nasm
ASMFLAGS = -f elf64 -g -F dwarf

SRC = \
	  ./src/ft_read.s \
	  ./src/ft_write.s \
      ./src/ft_strlen.s \
	  ./src/ft_strcmp.s\
	  ./src/ft_strcpy.s \
	  ./src/ft_strdup.s

OBJ = $(SRC:.s=.o)

# CFLAGS = -Wall -Wextra -Werror
# CFLAGS = ""

CC = gcc

all: $(NAME)

%.o: %.s
	$(ASM) $(ASMFLAGS) $< -o $@

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)
 
test: all
	$(CC) -no-pie -g3 -m64 testmains/main.c $(NAME) -o test

test_run: test
	./test

clean:
	rm -f $(OBJ)
fclean: clean
	rm -f $(NAME)

re: fclean $(NAME)

.PHONY: all clean fclean re

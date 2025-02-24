CC = gcc
CFLAGS = -Wall -g

# Source files
SRC = maincache.c memoization.c convert.c
OBJ = $(SRC:.c=.o)
EXEC = maincache

t
all: $(EXEC)

$(EXEC): $(OBJ)
	$(CC) $(CFLAGS) -o $(EXEC) $(OBJ)

%.o: %.c
	$(CC) $(CFLAGS) -c $<


clean:
	rm -f $(OBJ) $(EXEC)


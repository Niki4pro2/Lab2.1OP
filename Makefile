CC = gcc

CFLAGS = -Wall -Wextra -g -std=c11 -DDEBUG

OBJ = src/main.o src/bitset/bitset.o src/output/output.o src/handlers/errors.o

TARGET = bitsetMain

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(TARGET)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

cleanf:
	rm -f $(OBJ) $(TARGET)

rebuild: cleanf $(TARGET)

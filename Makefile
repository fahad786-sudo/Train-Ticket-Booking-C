CC = gcc
CFLAGS = -Wall -Wextra -std=c11 -Iinclude

SRC = $(wildcard src/*.c)
OBJ = $(patsubst src/%.c,build/obj/%.o,$(SRC))

TARGET = build/bin/train_booking

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(OBJ) -o $(TARGET)

build/obj/%.o: src/%.c
	@mkdir -p build/obj
	@mkdir -p build/bin
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf build/obj/*.o build/bin/train_booking

run: all
	./$(TARGET)
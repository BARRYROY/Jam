CC = gcc
CFLAGS = -Wall -Wextra -std=c99 -pedantic -I/opt/homebrew/Cellar/sdl2/2.30.8/include
LDFLAGS = -L/opt/homebrew/Cellar/sdl2/2.30.8/lib -lSDL2
SRC_DIR = src
SRC_FILES = $(wildcard $(SRC_DIR)/*.c)
OBJ_FILES = $(SRC_FILES:.c=.o)
OUT_FILE = game

# Rule to link object files into the final executable with SDL2
$(OUT_FILE): $(OBJ_FILES)
	$(CC) $(OBJ_FILES) -o $(OUT_FILE) $(LDFLAGS)

# Rule for compiling .c files into .o files
$(SRC_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

# Clean rule: remove object files and the executable
clean:
	rm -f $(OBJ_FILES) $(OUT_FILE)

# Run the game executable
run: $(OUT_FILE)
	./game

# Compiler settings
CC = gcc
CFLAGS = -O3 -Wall
OUTPUT_BIN_DIR = bin

# Create output directory if not found
$(shell mkdir -p $(OUTPUT_BIN_DIR))

# Source files
SRCS = main.c des.c feistel.c keygen.c permutation.c utils.c
OBJS = $(SRCS:.c=.o)

# Targets
all: des

des: $(SRCS)
	$(CC) $(CFLAGS) $(SRCS) -o $(OUTPUT_BIN_DIR)/des

# Run
run_encrypt:
	./$(OUTPUT_BIN_DIR)/des e key.txt plaintext.txt ciphertext.txt

run_decrypt:
	./$(OUTPUT_BIN_DIR)/des d key.txt ciphertext.txt decrypted.txt

# Clean up
clean:
	rm -rf $(OUTPUT_BIN_DIR) *.o

# Help
help:
	@echo "Available targets:"
	@echo "  all           - Build the DES executable"
	@echo "  run_encrypt   - Run encryption using example files"
	@echo "  run_decrypt   - Run decryption using example files"
	@echo "  clean         - Remove binaries and object files"
	@echo "  help          - Show this help message"

.PHONY: all run_encrypt run_decrypt clean help

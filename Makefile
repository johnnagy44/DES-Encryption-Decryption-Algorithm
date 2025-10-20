# Compiler settings
CC = gcc
CFLAGS = -O3 -Wall -Iinc
OUTPUT_BIN_DIR = bin
SRC_DIR = src

# Create output directory if not found
$(shell mkdir -p $(OUTPUT_BIN_DIR))

# Automatically detect all .c files inside src/
SRCS = $(wildcard $(SRC_DIR)/*.c)

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
	rm -rf $(OUTPUT_BIN_DIR)

# Help
help:
	@echo "Available targets:"
	@echo "  all           - Build the DES executable"
	@echo "  run_encrypt   - Run encryption using example files"
	@echo "  run_decrypt   - Run decryption using example files"
	@echo "  clean         - Remove binaries"
	@echo "  help          - Show this help message"

.PHONY: all run_encrypt run_decrypt clean help

CFLAG=-Wall
BUILD_DIR=build

all: build_dir stack_vm

build_dir:
	mkdir -p $(BUILD_DIR)

stack_vm: main.o run.o stack.o
	$(CC) $(BUILD_DIR)/main.o $(BUILD_DIR)/run.o $(BUILD_DIR)/stack.o -o $(BUILD_DIR)/$@

main.o:
	$(CC) -c main.c $(CFLAG) -o $(BUILD_DIR)/$@

run.o:
	$(CC) -c run.c $(CFLAG) -o $(BUILD_DIR)/$@

stack.o:
	$(CC) -c stack.c $(CFLAG) -o $(BUILD_DIR)/$@

clear:
	rm -rf $(BUILD_DIR)

.PHONY: all clear
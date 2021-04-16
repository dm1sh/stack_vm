CFLAG=-Wall -ggdb3
BUILD_DIR=build

all: build_dir stack_vm

build_dir:
	mkdir -p $(BUILD_DIR)

stack_vm: main.o run.o stack.o command.o
	$(CC) $(BUILD_DIR)/main.o $(BUILD_DIR)/run.o $(BUILD_DIR)/stack.o $(BUILD_DIR)/command.o -o $(BUILD_DIR)/$@

main.o:
	$(CC) -c main.c $(CFLAG) -o $(BUILD_DIR)/$@

run.o:
	$(CC) -c run.c $(CFLAG) -o $(BUILD_DIR)/$@

stack.o:
	$(CC) -c stack.c $(CFLAG) -o $(BUILD_DIR)/$@

command.o:
	$(CC) -c command.c $(CFLAG) -o $(BUILD_DIR)/$@

clean:
	rm -rf $(BUILD_DIR)

.PHONY: all clean
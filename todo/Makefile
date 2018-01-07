CC=gcc
CFLAGS=-O2
APP=todo
INSTALL_DIR=/usr/local/bin

all: todo_queue.o todo.o
	$(CC) -o $(APP) $^

.PHONY: install clean
install: todo_queue.o todo.o
	gcc -o $(APP) $^
	rm -f $^
	sudo mv $(APP) $(INSTALL_DIR)
	@echo install done!

%.o: %.c
	gcc -c $^

clean:
	rm -f *.o
	sudo rm -f $(INSTALL_DIR)/$(APP)
	@echo "Cleaned!"

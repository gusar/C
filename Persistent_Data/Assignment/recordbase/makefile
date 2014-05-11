CC = gcc
CFLAGS = -I.
DEPS = main.h
OBJS = main.o read_write.o operations.o compact.o

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

recordbase: $(OBJS)
	$(CC) -o $@ $^ $(CFLAGS)
	@echo -----------------------
	@echo To launch: ./recordbase
	@echo -----------------------

.PHONY: clean

clean:
	-rm $(OBJS)
	@echo --------------
	@echo Nice and Clean
	@echo --------------
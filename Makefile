CC = gcc
CFLAGS = -Wall -Wextra 
TARGET = mercado
BINFOLDER = bin/
OBJFOLDER = obj/
SRCFOLDER = src/
INCLUD = -I ./inc

SRCFILES := $(wildcard $(SRCFOLDER)*.c)

all: $(SRCFILES:$(SRCFOLDER)%.c=$(OBJFOLDER)%.o) | $(BINFOLDER) 
	$(CC) $(CFLAGS) $(OBJFOLDER)*.o -o $(BINFOLDER)$(TARGET) -I ./inc

obj/%.o: $(SRCFOLDER)%.c | $(OBJFOLDER)
	$(CC) $(CFLAGS) -c $< $(INCLUD) -o $@ 

$(BINFOLDER):
	mkdir -p $@

$(OBJFOLDER):
	mkdir -p $@

.PHONY: test

run:
	$(BINFOLDER)$(TARGET)

clean:
	rm -f $(BINFOLDER)*
	rm -f $(OBJFOLDER)*
	make -C test clean;

test: 
	make -C test 
	@echo "\n\n\n\n=========================TESTE==========================\n"
	make -C test run
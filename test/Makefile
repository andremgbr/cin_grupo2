CC = gcc
CFLAGS = -Wall -Wextra -I ../inc
TARGET = teste
BINFOLDER = bin/
OBJFOLDER = obj/
SRCFOLDER = ../src/
INCLUD = -I ../inc -lcheck -pthread -lrt -lm -lsubunit 


SRCFILES := $(wildcard $(SRCFOLDER)*.c) 
SRCFILES := $(filter-out $(SRCFOLDER)run.c, $(SRCFILES))

SRCFILES_TEST := $(wildcard *.c)

# Converte os arquivos .c para .o dentro do obj/
OBJFILES := $(patsubst $(SRCFOLDER)%.c, $(OBJFOLDER)%.o, $(SRCFILES))
OBJFILES += $(patsubst %.c, $(OBJFOLDER)%.o, $(SRCFILES_TEST)) 

all: $(OBJFILES) | $(BINFOLDER) 
	@echo "OJFILES: $(OBJFILES)"
	$(CC) $(CFLAGS) $(OBJFOLDER)*.o -o $(BINFOLDER)$(TARGET) $(INCLUD)
	
obj/%.o: $(SRCFOLDER)%.c | $(OBJFOLDER)
	$(CC) $(CFLAGS) -c $< $(INCLUD) -o $@ 

obj/%.o: %.c | $(OBJFOLDER)
	$(CC) $(CFLAGS) -c $< $(INCLUD) -o $@ 

$(BINFOLDER):
	mkdir -p $@

$(OBJFOLDER):
	mkdir -p $@

run:
	$(BINFOLDER)$(TARGET)

clean:
	rm -f $(BINFOLDER)*
	rm -f $(OBJFOLDER)*

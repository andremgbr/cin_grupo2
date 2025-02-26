CC = gcc
CFLAGS = -Wall -Wextra 
TARGET = mercado
BINFOLDER = bin/
OBJFOLDER = obj/
SRCFOLDER = src/

SRCFILES := $(wildcard $(SRCFOLDER)*.c)

all: $(SRCFILES:$(SRCFOLDER)%.c=$(OBJFOLDER)%.o) | $(BINFOLDER) 
	$(CC) $(CFLAGS) $(OBJFOLDER)*.o -o $(BINFOLDER)$(TARGET)

obj/%.o: $(SRCFOLDER)%.c | $(OBJFOLDER)
	$(CC) $(CFLAGS) -c $< -I ./inc -o $@ 

$(BINFOLDER):
	mkdir -p $@

$(OBJFOLDER):
	mkdir -p $@

run:
	$(BINFOLDER)$(TARGET)

clean:
	rm -f $(BINFOLDER)*
	rm -f $(OBJFOLDER)*

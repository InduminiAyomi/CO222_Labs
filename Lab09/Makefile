#CO222-lab 9
#Makefile

#user defined variables
CC = gcc
CFLAGS = -Wall
CSRC = cipher.c vigenere.c 
HSRC = vigenere.h 
OBJ =  cipher.o vigenere.o
EX = $(CSRC:.c=.exe)



cipher: $(OBJ)    
	$(CC) -o $@ $(OBJ) 
	

%.o: %.c %.h
	$(CC) $(CFLAGS) -c $<
	
	
%.o: %.c $(HSRC)
	$(CC) $(CFLAGS) -c $<
	

.PHONY: clobber
cobbler: clean
cobbler:
	rm -f $(EX) 
	
	
.PHONY: clean
clean:
	rm -f $(OBJ) 


.PHONY: test
test: cipher
	./cipher < test.dat

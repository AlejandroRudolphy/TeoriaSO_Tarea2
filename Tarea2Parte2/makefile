 
#
# Seccion 1
#
# Esta seccion se puede modificar segun
# los requerimientos de su proyecto

CC=gcc
SRC=Hora.c
OBJ=$(SRC:.c=.o)
BIN=$(SRC:.c= )
CFLAGS=-Wall -W -std=c99
#
# Seccion 2 (NO MODIFICAR!!!)
#
default: $(BIN)

$(BIN): $(OBJ)
	$(CC) $^ -o $(BIN)
	
%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	@rm -f $(OBJ)
	@rm -f *~
	@rm -f $(BIN)

run:
	@echo "Salida---------"
	@./$(BIN)

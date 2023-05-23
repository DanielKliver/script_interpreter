TARGET = ./bin/MyProject
CC = gcc

CFLAGS = -Wall

PATH_INCLUDE = -Isrc

PREF_SRC = ./src/
PREF_OBJ = ./obj/src/

SRC = $(wildcard $(PREF_SRC)*.c)
OBJ = $(patsubst $(PREF_SRC)%.c, $(PREF_OBJ)%.o, $(SRC))

all: $(TARGET)

$(PREF_OBJ)%.o : $(PREF_SRC)%.c
	                        $(CC) -c $(CFLAGS) $(PATH_INCLUDE) -o $@ $<

$(TARGET) : $(OBJ)
	                        $(CC) $(CFLAGS) -o $(TARGET) $(OBJ)

clean :
	                        rm $(TARGET) $(PREF_OBJ)*.o

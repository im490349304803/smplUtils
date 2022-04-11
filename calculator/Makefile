include ../config.mk
SRC = $(wildcard main.c)
OBJ = $(patsubst %.c, obj/%.o, $(SRC))
LIBS= -L calc/obj -lcalc -lncurses
RANLIB = ranlib
prog: $(OBJ) calcl
	$(CC) $(OBJ) $(CFLAGS) $(LDFLAGS) $(LIBS)  -o obj/prog

obj/%.o: %.c obj
	$(CC) $(CFLAGS) -c $< -o $@
calcl:
	$(MAKE) -C calc
obj: 
	-mkdir -p obj
clean:
	-rm -r obj
	$(MAKE) -C calc clean

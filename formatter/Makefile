include ../config.mk
SRC = $(wildcard *.c)
OBJ = $(patsubst %.c, obj/%.o, $(SRC))
LIBS=  -lconvert -lncurses
RANLIB = ranlib
prog: $(OBJ) convl
	$(CC) obj/low.o $(CFLAGS) $(LDFLAGS) $(LIBS)  -o obj/low
	$(CC) obj/uper.o $(CFLAGS) $(LDFLAGS) $(LIBS)  -o obj/uper

obj/%.o: %.c obj
	$(CC) $(CFLAGS) -c $< -o $@
convl:
	$(MAKE) -C convert
obj: 
	-mkdir -p obj
clean:
	-rm -r obj
	$(MAKE) -C convert clean

include ../../config.mk
SRC = $(wildcard *.c)
OBJ = $(patsubst %.c, obj/%.o, $(SRC))
RANLIB = ranlib
lib: $(OBJ) 
	$(AR) -rc obj/libcalc.a $(OBJ)
	$(RANLIB) obj/libcalc.a

prog: $(OBJ)
	$(CC) $(CFLAGS) $(LDFLAGS) $(LIBS) $(OBJ) -o prog

obj/%.o: %.c obj
	$(CC) $(CFLAGS) -c $< -o $@

obj: 
	-mkdir obj
clean:
	-rm -r obj

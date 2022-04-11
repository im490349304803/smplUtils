include ../../config.mk
CFLAGS += -fpic
LDFLAGS += -shared
SRC = $(wildcard *.c)
OBJ = $(patsubst %.c, obj/%.o, $(SRC))
RANLIB = ranlib
lib: $(OBJ) 
	$(CC) -shared  $(OBJ) -o obj/libconvert.so
	sudo cp obj/libconvert.so /usr/lib
	sudo chmod 0755 /usr/lib/libconvert.so
	sudo ldconfig
prog: $(OBJ)
	$(CC) $(CFLAGS) $(LDFLAGS) $(LIBS) $(OBJ) -o prog

obj/%.o: %.c  obj
	$(CC) $(CFLAGS) -c $< -o $@

obj: 
	-mkdir obj
clean:
	-rm -r obj

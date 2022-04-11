include ../config.mk
SRC = $(wildcard *.c)
OBJ = $(patsubst %.c, obj/%.o, $(SRC))
LIBS=  -lconvert -lncurses
RANLIB = ranlib
RESULT_PATH=

prog: $(OBJ) convl
	$(CC) obj/low.o $(CFLAGS) $(LDFLAGS) $(LIBS)  -o obj/low
	$(CC) obj/uper.o $(CFLAGS) $(LDFLAGS) $(LIBS)  -o obj/uper
ifeq ($(FORMATTER),LOW)
	$(COPY) obj/low obj/prog
else ifeq ($(FORMATTER),UPER)
	$(COPY) obj/uper obj/prog
else
        $(error bad FORMATTER config.. please add this opt to config.mk)
endif


obj/%.o: %.c obj
	$(CC) $(CFLAGS) -c $< -o $@
convl:
	$(MAKE) -C convert
obj: 
	-mkdir -p obj
clean:
	-rm -r obj
	$(MAKE) -C convert clean

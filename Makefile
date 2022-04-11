include config.mk
all:
	$(MAKE) -C calculator
	$(MAKE) -C formatter
	$(SIZE) calculator/obj/prog
	$(SIZE) formatter/obj/uper
	$(SIZE) formatter/obj/low
	$(SIZE) formatter/obj/prog
clean:
	$(MAKE) -C calculator clean
	$(MAKE) -C formatter clean

calc: all
	calculator/obj/prog
formatter: all
	formatter/obj/prog



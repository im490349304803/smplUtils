include config.mk
all:
	$(MAKE) -C calculator
	$(MAKE) -C formatter
	$(SIZE) calculator/obj/prog
	$(SIZE) formatter/obj/uper
	$(SIZE) formatter/obj/low
clean:
	$(MAKE) -C calculator clean
	$(MAKE) -C formatter clean

calc: all
	calculator/obj/prog
formatter_uper: all
	formatter/obj/uper
formatter_low: all
	formatter/obj/low



all:
	$(MAKE) -C calculator
	$(MAKE) -C formatter
clean:
	$(MAKE) -C calculator clean
	$(MAKE) -C formatter clean

TARGET =main
DEPS =tree_sort
DEPS:=$(addsuffix .o, $(DEPS))

CC=gcc
ARRAYS = 27

.PHONY: compile clean run draw help

compile:	$(TARGET)

$(TARGET):$(DEPS)
	$(CC) -Os $(addsuffix .c,$(TARGET)) $(DEPS) -o Os 
	$(CC) -O0 $(addsuffix .c,$(TARGET)) $(DEPS) -o O0 
	$(CC) -O1 $(addsuffix .c,$(TARGET)) $(DEPS) -o O1 
	$(CC) -O2 $(addsuffix .c,$(TARGET)) $(DEPS) -o O2 
	$(CC) -O3 $(addsuffix .c,$(TARGET)) $(DEPS) -o O3 
%.o: %.c		
	$(CC) $(CFLAGS) -c $< 	 
clean:
	@echo Tidying things up...
	rm -f $(TARGET)
	-rm -f $(DEPS)
	-rm -f *.o $(TARGET)
	-rm -f Os
	-rm -f O0
	-rm -f O1
	-rm -f O2
	-rm -f O3

run:
	./Os -Os $(ARRAYS)
	./O0 -O0 $(ARRAYS)
	./O1 -O1 $(ARRAYS)
	./O2 -O2 $(ARRAYS)
	./O3 -O3 $(ARRAYS)
draw:
	gnuplot gnuplot.sh
	
help:
	@echo "Usage : "
	@echo "make compile - compiles with different flags"
	@echo "make run - starts the sorting"
	@echo "make draw - outputs the plots(gnuplot is needed)"
	@echo "make clean - removes *.o files"
	




TARGET =main
DEPS =tree_sort
DEPS:=$(addsuffix .o, $(DEPS))


CC=gcc
FLAGS = Os O0 O1 O2 O3
CMDSEP = &
ARRAYS = 27

.PHONY: compile clean run draw help

compile:$(TARGET)

$(TARGET):$(DEPS)
	$(foreach var,$(FLAGS),$(CC) -$(var) $(addsuffix .c,$(TARGET)) $(DEPS) -o $(var) ;) # compiling with different flags
%.o: %.c		
	$(CC) $(CFLAGS) -c $< 	 
clean:
	@echo Tidying things up...
	rm -f $(TARGET)
	-rm -f $(DEPS)
	-rm -f *.o $(TARGET)
	$(foreach var,$(FLAGS),rm -f $(var) ;) # deletes the .* o files.
	$(foreach var,$(FLAGS),rm -f ./-$(var) ;) # deletes the output data files.
run:
	$(foreach var,$(FLAGS),./$(var) -$(var) $(ARRAYS) ;) 
	
draw:
	gnuplot gnuplot.sh # draws the curves
	
help:
	@echo "Usage : "
	@echo "make compile - compiles with different flags"
	@echo "make run - starts the sorting"
	@echo "make draw - outputs the plots(gnuplot is needed)"
	@echo "make clean - removes *.o files"
	




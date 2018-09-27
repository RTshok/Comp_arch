# Testing speed of tree_sort
- I've used different gcc optimization flags to compile (Os,O0..).
- Wrote a makefile which compiles C files, then runs them and draws a plot (using gnuplot)
- Spoiler : As we can see from the 'tree_sort_out.pdf', the algorithm slightly depends on the optimization flags :(

## Running the program
 - Use `sudo pacman -Sy gnuplot` (if you don't have gnuplot installed) for Arch Linux.
 - Or `sudo apt-get gnuplot` for Ubuntu
 Then open terminal, use Makefile to compile.
 - `make compile` -> compiles with different flags
 - `make run` -> starts the sorting
 - `make draw` -> outputs the plots(gnuplot is needed)
 - `make clean` -> removes *.o files"

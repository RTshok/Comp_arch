set term qt
set output "tree_sort.png"
set xlabel "Number of elements"
set ylabel "Time of execution,ms"
set title "Tree sort speed-test"

set grid
set linestyle 1 lt 2 lw 2
set key box linestyle 1

set xtics 250000
set ytics 500
plot "-O0" using 1:2 with lines ,\
"-O1" using 1:2 with lines lc rgb "green" ,\
"-O2" using 1:2 with lines lc rgb "red" ,\
"-O3" using 1:2 with lines lc rgb "blue" ,\
"-Os" using 1:2 with lines lc rgb "brown"
pause -1 "Hit any key to continue"
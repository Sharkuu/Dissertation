set datafile separator ";"
set yrange [0:1]
set xlabel 'Time (log(t/2days))'
set ylabel 'Remaining electrons fraction'

plot  "example.txt" using 1:2  notitle with lines 
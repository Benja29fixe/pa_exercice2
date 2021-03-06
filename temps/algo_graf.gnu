set terminal pngcairo size 1000, 600
set output 'algo_graf.png'
set xlabel "nombre de colonnes (nombre de lignes = 1)"
set ylabel "temps (s)"
set title "5/ Algorithme de Graf"

set style line 10 linetype 1 \
    	       	  linecolor rgb "#1536FF" \
    	       	  linewidth 3

f(x)=a*x**2+b*x+c
set key on inside top left
fit f(x) "algo_graf.temps" using 2:4 via a, b, c
plot "algo_graf.temps" using 2:4 with dots, f(x) title "Algorithme de Graf" linestyle 10

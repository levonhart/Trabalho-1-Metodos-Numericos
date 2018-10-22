reset
  set terminal png size 700,200
  set output '/var/www/graf/grafico.png'
  set size 1,1
  set boxwidth 0.7 relative
  set style fill solid 1.0 border lt -1
  set grid
  set xdata time
  set format x "%d"
  set xrange ["31/05/2010":"21/06/2010"]
  set xlabel "Dias"
  set ylabel "Total"
  plot '/var/www/graf/lista.dat' using 1:2 with boxes t''
  exit
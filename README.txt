COMPILATION STEPS:
1.install gsl library:
	sudo apt-get install libgsl-dev

2.install gnuplot:
	sudo apt-get install gnuplot-x11

3.compile multiple files to make program "writetimings.exe" which produces dat files for each sorting algorithm:
	gcc csequence.c sorts.c timeit.c writetimings.c -o writetimings

4.compile multiple files to make program "fitdata.exe" which fits graphs into linear line by using polynomial fitting (linked with gsl library):
	gcc polifitgsl.c fitdata.c -o fitdata `gsl-config --cflags --libs`

RUNNING STEPS:
5.produce dat files by running writetimings.exe 
	./writetimings

6. file permissions if necessary: 
	sudo chmod -R a+rwx .

7.produce fd files from dat files by using shell script:
	for el in *.dat ; do ./fitdata <$el >${el%.dat}.fd ; done

8. type gnuplot and copy/paste this for single graph(example is quicksort-shuffled case):
	f(x) = C0 + C1*x
	set logscale xy	
	load 'data_quick_shf.fd'
	set xrange [100:100000]
	set key left
	plot 10**f(log10(x)), 'data_quick_shf.dat'

9. or type gnuplot and copy/paste this example (all sorting algorithms for constantelement case) for multigraph:
	set logscale xy	
	set xrange [100:100000]
	set key left
	set pointsize 2
	i(x) = -4.060523 + 0.788952*x
	m(x) = -3.764798 + 1.041230*x
	q(x) = -4.260254 + 1.063257*x
	h(x) = -3.823527 + 1.078122*x
	c(x) = -4.573432 + 0.933107*x
	load 'data_heap_shf.fd'
	plot 10**i(log10(x)), 'data_insertion_c1.dat', 10**m(log10(x)), 'data_merge_c1.dat', 10**q(log10(x)), 'data_quick_c1.dat',  10**h(log10(x)), 'data_heap_c1.dat', 10**c(log10(x)), 'data_counting_c1.dat'
	set term png small size 750,350 uncrop
	set output "c1.png"
	replot
	set term x11

	
	
 

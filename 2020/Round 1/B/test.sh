for ((i=1;i<20;i++)) do
	echo $i
	./gen $i > in
	./correctsoln < in > out
	diff -w <(./a < in) out
done
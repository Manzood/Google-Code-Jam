for ((i=1;;i++)) do
	echo $i
	./gen $i > in
	diff -w <(./A < in) <(./correct < in) || break
done

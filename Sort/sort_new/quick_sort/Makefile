TARGET=quick_sort

target: quick_sort

quick_sort:
	gcc -c quick_sort.c -o quick_sort.o
	ar -cvr libquick_sort.a quick_sort.o
	gcc -shared -fPIC quick_sort.o -o libquick_sort.so

lib:
	gcc -c quick_sort.c -o quick_sort.o
	ar -cvr libquick_sort.a quick_sort.o

so:
	gcc -c quick_sort.c -o quick_sort.o
	gcc -shared -fPIC quick_sort.o -o libquick_sort.so	

clean:
	rm -f libquick_sort.a
	rm  -f *.o *.a *.so
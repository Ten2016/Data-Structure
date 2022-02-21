TARGET=quick_sort



quick_sort: quick_sort_test.o quick_sort.o 
	gcc -o quick_sort_test.o quick_sort.o -o $(TARGET)

quick_sort_test.o:
	gcc -c quick_sort_test.c

quick_sort.o:
	gcc -c quick_sort.c



clean:
	rm -f $(TARGET)
	rm  -rf ./*.o

test:
	quick_sort
	./$(TARGET)
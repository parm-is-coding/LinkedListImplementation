all:
	gcc -Wall -Werror -g -o  output test.c list.c


clean:
	rm output a.out

runVal:
	valgrind --leak-check=yes ./output

run:
	./output

CFLAGS=-WALL -pedantic -g
output:$*.o
	$(CC) $(CFLAGS) -o $@

$*.o:
	$^ -c

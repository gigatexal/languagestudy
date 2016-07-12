CC = g++
CPPFLAGS = -Wall -g -std=c++11
app:	app.o list.o

app.o: 	list.h

list.o:	list.h

.PHONY: clean
clean:	
	$(info -- cleaning the direcotry --)
	rm -f *.o
	rm -f app


#Reed Posehn
CC = g++
CFLAGS = -Wall -Wextra -g

CaveCrawler: CaveCrawler.o Actions.o Events.o Init.o Intro.o
	$(CC) -o CaveCrawler CaveCrawler.o Actions.o Events.o Init.o Intro.o

CaveCrawler.o: CaveCrawler.cpp
	$(CC) $(CFLAGS) -c CaveCrawler.cpp

Actions.o: Actions.cpp
	$(CC) $(CFLAGS) -c Actions.cpp

Events.o: Events.cpp
	$(CC) $(CFLAGS) -c Events.cpp

Init.o: Init.cpp
	$(CC) $(CFLAGS) -c Init.cpp

Intro.o: Intro.cpp
	$(CC) $(CFLAGS) -c Intro.cpp

clean:
	rm CaveCrawler *.o

#Reed Posehn
CC = g++
CFLAGS = -Wall -Wextra -g

CaveCrawler: CaveCrawler.o Init.o Intro.o
	$(CC) -o CaveCrawler CaveCrawler.o Init.o Intro.o

CaveCrawler.o: CaveCrawler.cpp
	$(CC) $(CFLAGS) -c CaveCrawler.cpp

Init.o: Init.cpp
	$(CC) $(CFLAGS) -c Init.cpp

Intro.o: Intro.cpp
	$(CC) $(CFLAGS) -c Intro.cpp

clean:
	rm CaveCrawler *.o

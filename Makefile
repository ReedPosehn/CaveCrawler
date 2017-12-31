#Reed Posehn
CC = g++
CFLAGS = -Wall -Wextra -g

CaveCrawler: CaveCrawler.o
	$(CC) -o CaveCrawler CaveCrawler.o

CaveCrawler.o: CaveCrawler.cpp
	$(CC) $(CFLAGS) -c CaveCrawler.cpp

clean:
	rm CaveCrawler *.o

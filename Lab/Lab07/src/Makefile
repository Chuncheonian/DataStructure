CC = clang++
TARGET = a.out
OBJS += MultimediaContent.o MusicContent.o PhotoContent.o VideoContent.o 
OBJS += DoublyIterator.o SortedDoublyLinkedList.o
OBJS += Application.o main.o

CXXFLAGS = -g -std=c++17 -Wall
LDFLAGS = -lc

all : $(TARGET)

$(TARGET) : $(OBJS)
	$(CC) $(LDFLAGS) -o $@ $^

.c.o :
	$(CC) $(LDFLAGS) -c -o $@ @<

clean :
	rm -rf $(TARGET) $(OBJS)
CC = g++
TARGET = a.out
OBJS += MultimediaContent.o FavoritePhotoContent.o FavoriteVideoContent.o 
OBJS += CharacterContent.o LocationContent.o EventContent.o
OBJS += UnsortedList.o SortedList.o SortedSinglyLinkedList.o DoublyIterator.o SortedDoublyLinkedList.o
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
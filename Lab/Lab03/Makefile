CC = g++
TARGET = a.out
OBJS += MultimediaContent.o FavoriteContent.o Event.o
OBJS += UnsortedList.o CircularQue.o
OBJS += Application.o Lab03.o

CXXFLAGS = -g -std=c++17 -Wall
LDFLAGS = -lc

all : $(TARGET)

$(TARGET) : $(OBJS)
	$(CC) $(LDFLAGS) -o $@ $^

.c.o :
	$(CC) $(LDFLAGS) -c -o $@ @<

clean :
	rm -rf $(TARGET) $(OBJS)
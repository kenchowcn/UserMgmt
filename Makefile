CC = g++
CFLAGS = -c -fPIC -Wall -I./
LIBS = -lIce -lIceUtil -lpthread

all: ice server client

ice:
	slice2cpp UserMgmt.ice

server: Server.o UserMgmt.o UserMgmtI.o
	$(CC) $^ -o $@ $(LIBS)

UserMgmt.o: UserMgmt.cpp
	$(CC) $(CFLAGS) $^

UserMgmtI.o: UserMgmtI.cpp
	$(CC) $(CFLAGS) $^

Server.o: Server.cpp
	$(CC) $(CFLAGS) $^

client: Client.o UserMgmt.o UserMgmtI.o
	$(CC) $^ -o $@ $(LIBS)

Client.o: Client.cpp
	$(CC) $(CFLAGS) $^

clean:
	rm -rf *.o server client UserMgmt.h UserMgmt.cpp

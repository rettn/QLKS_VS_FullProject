#ifndef ROOM_H
#define ROOM_H

typedef struct {
    char roomNo[20];
    char roomName[50];
    int floor;
    int numMax;
    int price;
} Room;

void inputRoom(Room *r);
void displayRoom(const Room *r);

#endif

#include <stdio.h>
#include <string.h>
#include "room.h"

void inputRoom(Room* r) {
    printf("Nhap ma phong: ");
    readLine(r->roomNo, sizeof(r->roomNo));

    printf("Nhap ten phong: ");
    readLine(r->roomName, sizeof(r->roomName));

    printf("Nhap tang: ");
    scanf("%d", &r->floor);
    getchar(); 

    printf("Nhap so nguoi toi da: ");
    scanf("%d", &r->numMax);
    getchar();

    printf("Nhap gia: ");
    scanf("%d", &r->price);
    getchar();
}

void displayRoom(const Room* r) {
    printf("Ma phong: %s, Ten phong: %s, Tang: %d, So nguoi toi da: %d, Gia tien: %d\n",
        r->roomNo, r->roomName, r->floor, r->numMax, r->price);
}

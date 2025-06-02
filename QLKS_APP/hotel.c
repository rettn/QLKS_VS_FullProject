#include <stdio.h>
#include <string.h>
#include "hotel.h"

void inputHotel(Hotel* h) {
    printf("Nhap ma khach san: ");
    readLine(h->hotelNo, sizeof(h->hotelNo));

    printf("Nhap ten khach san: ");
    readLine(h->name, sizeof(h->name));

    printf("Nhap dia chi: ");
    readLine(h->address, sizeof(h->address));

    printf("Nhap loai: ");
    readLine(h->type, sizeof(h->type));

    char temp[10];
    printf("Nhap so phong: ");
    readLine(temp, sizeof(temp));
    h->roomCount = atoi(temp);

    for (int i = 0; i < h->roomCount; i++) {
        printf("--- Phong %d ---\n", i + 1);
        inputRoom(&h->roomList[i]);
    }
}


void displayHotel(const Hotel *h) {
    printf("Ten KS: %s, Ma KS: %s, Dia chi: %s, Loai: %s\n",
        h->name, h->hotelNo, h->address, h->type);
}

void displayAllHotel(const Hotel *h) {
    displayHotel(h);
    printf("Danh sach phong:\n");
    for (int i = 0; i < h->roomCount; i++) {
        displayRoom(&h->roomList[i]);
    }
}

int calculateProfit(const Hotel *h, const Booking *bookings, int bookingCount) {
    int profit = 0;
    for (int i = 0; i < bookingCount; i++) {
        if (strcmp(bookings[i].hotelNo, h->hotelNo) == 0) {
            for (int j = 0; j < h->roomCount; j++) {
                if (strcmp(bookings[i].roomNo, h->roomList[j].roomNo) == 0) {
                    profit += h->roomList[j].price;
                    break;
                }
            }
        }
    }
    return profit;
}

int isRoomAvailable(const Hotel *h, const Booking *bookings, int bookingCount, const Room *room) {
    for (int i = 0; i < bookingCount; i++) {
        if (strcmp(bookings[i].hotelNo, h->hotelNo) == 0 &&
            strcmp(bookings[i].roomNo, room->roomNo) == 0) {
            return 0;
        }
    }
    return 1;
}

void showRoomAvailable(const Hotel *h, const Booking *bookings, int bookingCount) {
    displayHotel(h);
    printf("Danh sach phong trong:\n");
    for (int i = 0; i < h->roomCount; i++) {
        if (isRoomAvailable(h, bookings, bookingCount, &h->roomList[i])) {
            displayRoom(&h->roomList[i]);
        }
    }
}

#ifndef HOTEL_H
#define HOTEL_H
#include "room.h"
#include "booking.h"
#define MAX_ROOMS 50
typedef struct {
    char hotelNo[20];
    char name[50];
    char address[100];
    char type[30];
    Room roomList[MAX_ROOMS];
    int roomCount;
} Hotel;
void inputHotel(Hotel *h);
void showRoomAvailable(const Hotel *h, const Booking *bookings, int bookingCount);
#endif

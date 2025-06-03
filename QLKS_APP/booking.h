#ifndef BOOKING_H
#define BOOKING_H
typedef struct {
    char hotelNo[20];
    char roomNo[20];
    char cmtnd[20];
    char checkIn[20];
    char checkOut[20];
} Booking;
void inputBooking(Booking *booking);
void displayBooking(const Booking *booking);
#endif

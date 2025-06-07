#include <stdio.h>
#include <string.h>
#include "booking.h"
#include "datacontroller.h"
#include "customer.h"
#include "color_utils.h"

int isRoomBooked(const char* hotelNo, const char* roomNo) {
    for (int i = 0; i < dataController.bookingCount; i++) {
        if (strcmp(dataController.bookingList[i].hotelNo, hotelNo) == 0 &&
            strcmp(dataController.bookingList[i].roomNo, roomNo) == 0) {
            return 1; // Da co nguoi dat
        }
    }
    return 0;
}

void inputBooking(Booking *booking) {
    printf("Nhap ma khach san: ");
    fgets(booking->hotelNo, sizeof(booking->hotelNo), stdin);
    booking->hotelNo[strcspn(booking->hotelNo, "\n")] = 0;

    while (findHotel(booking->hotelNo) == NULL) {
        printError("Khach san khong ton tai. Nhap lai: ");
        fgets(booking->hotelNo, sizeof(booking->hotelNo), stdin);
        booking->hotelNo[strcspn(booking->hotelNo, "\n")] = 0;
    }

    printf("Nhap ma phong: ");
    fgets(booking->roomNo, sizeof(booking->roomNo), stdin);
    booking->roomNo[strcspn(booking->roomNo, "\n")] = 0;

    if (isRoomBooked(booking->hotelNo, booking->roomNo)) {
        printError("Phong nay da co nguoi dat. Vui long chon phong khac.");
        booking->roomNo[0] = '\0'; // Đánh dấu thất bại để main biết
        return;
    }

    printf("Nhap CMTND: ");
    fgets(booking->cmtnd, sizeof(booking->cmtnd), stdin);
    booking->cmtnd[strcspn(booking->cmtnd, "\n")] = 0;

    int found = 0;
    for (int i = 0; i < dataController.customerCount; i++) {
        if (strcmp(dataController.customerList[i].cmtnd, booking->cmtnd) == 0) {
            found = 1;
            break;
        }
    }

    if (!found && dataController.customerCount < MAX_CUSTOMERS) {
        Customer *newC = &dataController.customerList[dataController.customerCount++];
        strcpy(newC->cmtnd, booking->cmtnd);
        inputCustomerWithoutCMTND(newC);
        printSuccess("Them khach hang moi thanh cong.");
    }

    printf("Nhap ngay nhan (yyyy-MM-dd HH:mm:ss): ");
    fgets(booking->checkIn, sizeof(booking->checkIn), stdin);
    booking->checkIn[strcspn(booking->checkIn, "\n")] = 0;

    printf("Nhap ngay tra (yyyy-MM-dd HH:mm:ss): ");
    fgets(booking->checkOut, sizeof(booking->checkOut), stdin);
    booking->checkOut[strcspn(booking->checkOut, "\n")] = 0;
}

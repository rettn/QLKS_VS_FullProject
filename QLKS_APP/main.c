#include <stdio.h>
#include <stdlib.h>
#include "hotel.h"
#include "customer.h"
#include "booking.h"
#include "datacontroller.h"

#define MAX_HOTELS 10
#define MAX_CUSTOMERS 50
#define MAX_BOOKINGS 100

void menu() {
    printf("\n----- QUAN LY KHACH SAN -----\n");
    printf("1. Nhap thong tin khach san\n");
    printf("2. Hien thi phong trong\n");
    printf("3. Dat phong\n");
    printf("4. Hien thi danh sach dat phong\n");
    printf("0. Thoat\n");
    printf("------------------------------\n");
    printf("Chon: ");
}

int main() {
    int choice;
    do {
        menu();
        scanf("%d", &choice);
        getchar();
        switch (choice) {
            case 1:
                if (dataController.hotelCount < MAX_HOTELS) {
                    inputHotel(&dataController.hotelList[dataController.hotelCount]);
                    dataController.hotelCount++;
                } else {
                    printf("Danh sach khach san day!\n");
                }
                break;
            case 2:
                for (int i = 0; i < dataController.hotelCount; i++) {
                    showRoomAvailable(&dataController.hotelList[i], dataController.bookingList, dataController.bookingCount);
                }
                break;
            case 3:
                if (dataController.bookingCount < MAX_BOOKINGS) {
                    inputBooking(&dataController.bookingList[dataController.bookingCount]);
                    dataController.bookingCount++;
                } else {
                    printf("Danh sach dat phong day!\n");
                }
                break;
            case 4:
                for (int i = 0; i < dataController.bookingCount; i++) {
                    displayBooking(&dataController.bookingList[i]);
                }
                break;
            case 0:
                printf("Tam biet!\n");
                break;
            default:
                printf("Lua chon khong hop le!\n");
        }
    } while (choice != 0);

    return 0;
}

#include <stdio.h>
#include <string.h>
#include "booking.h"
#include "datacontroller.h"
#include "customer.h"

void inputBooking(Booking *booking) {
    printf("Nhap ma khach san: ");
    readLine(booking->hotelNo, sizeof(booking->hotelNo));

    // Kiểm tra khách sạn tồn tại
    while (findHotel(booking->hotelNo) == NULL) {
        printf("Khach san khong ton tai. Nhap lai: ");
        readLine(booking->hotelNo, sizeof(booking->hotelNo));
        
    }

    printf("Nhap ma phong: ");
	readLine(booking->roomNo, sizeof(booking->roomNo));
	

    //Không kiểm tra chi tiết phòng, giả sử hợp lệ

    printf("Nhap CMTND: ");
    readLine(booking->cmtnd, sizeof(booking->cmtnd));
	

    // Nếu khách hàng chưa tồn tại, thêm mới
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
    }

    printf("Nhap ngay nhan (yyyy-MM-dd HH:mm:ss): ");
    readLine(booking->checkIn, sizeof(booking->checkIn));
	

    printf("Nhap ngay tra (yyyy-MM-dd HH:mm:ss): ");
    readLine(booking->checkOut, sizeof(booking->checkOut));
	
}

void displayBooking(const Booking *booking) {
    printf("Ma KS: %s, Ma phong: %s, CMTND: %s, Ngay nhan: %s, Ngay tra: %s\n",
           booking->hotelNo, booking->roomNo, booking->cmtnd,
           booking->checkIn, booking->checkOut);
}

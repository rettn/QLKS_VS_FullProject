#include <stdio.h>
#include <stdlib.h>
#include "hotel.h"
#include "customer.h"
#include "booking.h"
#include "datacontroller.h"
#include "color_utils.h"

#define MAX_HOTELS 10
#define MAX_BOOKINGS 100
void resetColor();

void printTitle(const char* title) {
   resetColor();
   setColor(11);

   printf("============================================\n");
   printf("      %s\n", title);
   printf("============================================\n");
}

void menu() {
   printTitle("QUAN LY KHACH SAN");
   printf("  [1] Nhap thong tin khach san\n");
   printf("  [2] Hien thi phong trong\n");
   printf("  [3] Dat phong\n");
   printf("  [4] Hien thi danh sach dat phong\n");
   printf("  [0] Thoat\n");
   printf("------------------------------\n");
   printf("Chon: ");
}

int main() {
   int choice;
   do {
       menu();
       if (scanf("%d", &choice) != 1) {
           printError("Lua chon khong hop le!");
           while (getchar() != '\n');
           continue;
       }
       while (getchar() != '\n'); 
       switch (choice) {
           case 1:
               if (dataController.hotelCount < MAX_HOTELS) {
                   inputHotel(&dataController.hotelList[dataController.hotelCount]);
                   dataController.hotelCount++;
                   printSuccess("Da them khach san thanh cong.");
               } else {
                   printError("Danh sach khach san da day!");
               }
               break;
           case 2:
               for (int i = 0; i < dataController.hotelCount; i++) {
                   showRoomAvailable(&dataController.hotelList[i], dataController.bookingList, dataController.bookingCount);
               }
               break;
           case 3:
               if (dataController.bookingCount < MAX_BOOKINGS) {
                   int index = dataController.bookingCount;
                   inputBooking(&dataController.bookingList[index]);

                   // Chi tang va in thanh cong neu booking hop le (roomNo != "")
                   if (dataController.bookingList[index].roomNo[0] != '\0') {
                       dataController.bookingCount++;
                       printSuccess("Dat phong thanh cong.");
                   }
               } else {
				   printError("Danh sach dat phong da day!");
			   }
               break;
           case 4:
               printf("|  %-10s  |  %-10s  |  %-12s  |  %-19s  |  %-19s  |\n",
                      "Ma KS", "Ma phong", "CCCD", "Ngay nhan", "Ngay tra");
               printf("----------------------------------------------------------------------------------------------\n");
               for (int i = 0; i < dataController.bookingCount; i++) {
                   displayBooking(&dataController.bookingList[i]);
               }
               break;
           case 0:
               printSuccess("Cam on ban. Tam biet!");
               break;
           default:
               printError("Lua chon khong hop le!");
       }
       printf("\nNhan Enter de tiep tuc...");
       getchar();
   } while (choice != 0);
   return 0;
}

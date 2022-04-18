#include <stdio.h>
int ticketType, ticketTime, manAge, price, priceSpecialOffer, specialOffer, totalPrice = 0;
int index, repCount, newOrExit, continueOrNot, ridesOrNot = 0;
int ageYear, birthDay = 0;
const int QTY = 1;
const int THIS_YEAR = 2022, TODAY = 416;
const int ALL_ADULT_1DAY = 62000, ALL_YOUTH_1DAY = 54000, ALL_CHILD_1DAY = 47000, ALL_ADULT_AFTER4 = 50000, ALL_YOUTH_AFTER4 = 43000, ALL_CHILD_AFTER4 = 36000,   
     PARK_ADULT_1DAY = 59000, PARK_YOUTH_1DAY = 52000, PARK_CHILD_1DAY = 46000, PARK_ADULT_AFTER4 = 47000, PARK_YOUTH_AFTER4 = 41000, PARK_CHILD_AFTER4 = 35000,
     BABY = 15000, FREE_OF_CHARGE = 0;
const float DISABLED_DC_RATE = 0.5f, VETERAN_DC_RATE = 0.5f, MILITARY_DC_RATE = 0.51f, PREGNANT_DC_RATE = 0.5f, MULTICHILD_DC_RATE = 0.7f;
const int TICKET_TYPE_INDEX = 0, TICKET_TIME_INDEX = 1, MANAGE_INDEX = 2, PRICE_INDEX = 3, SPECIAL_OFFER_INDEX = 4;
int idNum[13];
int ticketInfo[10][5] = {0};
//function declaration
int TicketType();
int TicketTime();
int ManAge();
int TicketPrice(int, int, int);
void TicketQTY();
int SpecialOfferQuestion();
int SpecialOffer(int, int, int);
int TicketType(int);
int TicketTime(int);    
int ManAge(int);    
int PriceSpecialOffer(int);     
int SpecialOfferIndex(int);
int ContinueOrNot();
void PrintOut(int);
int NewOrExit();

int main() {   
   do {
      do {    
         TicketType();
         TicketTime();
         ManAge();
         TicketPrice(manAge, ticketType, ticketTime);
         TicketQTY();
         SpecialOfferQuestion();
         SpecialOffer(manAge, specialOffer, price);
         TicketType(ticketType);
         TicketTime(ticketTime);    
         ManAge(manAge);    
         PriceSpecialOffer(priceSpecialOffer);     
         SpecialOfferIndex(specialOffer);
         repCount++;
         ContinueOrNot();
      } while(continueOrNot != 2);

      PrintOut(repCount);
      NewOrExit();
   
   } while(newOrExit != 2);
   return 0;
}

int TicketType() {
      printf("Select Type of Tickets\n1.All\n2.Park\n");
      scanf("%d", &ticketType);
      return ticketType;
   }

int TicketTime() {
   printf("Select Time of Tickets\n1.Day\n2.After4\n");
   scanf("%d", &ticketTime);
   return ticketTime;
}

int ManAge() {
   printf("Input your social security number\n"); 
   for(index = 0; index < 13; index++) {
   scanf("%1d", &idNum[index]);
   }
   ageYear = idNum[0]*10 + idNum[1];
   
   if (ageYear <= 22) {
      ageYear += 2000;
   } else {
      ageYear += 1900;
   }
   
   birthDay = idNum[2]*1000+idNum[3]*100+idNum[4]*10+idNum[5];
   manAge = THIS_YEAR - ageYear;
   if(birthDay >= TODAY) {
      manAge;
   } else {
      manAge -= 1;
   }
   return manAge;
}

int TicketPrice(int manAge, int ticketType, int ticketTime) {
   if(manAge < 1) {
      price = FREE_OF_CHARGE;   
   } else if (manAge >= 1  && manAge < 3) {
      printf("baby rides? 1.yes 2.no\n");
      scanf("%d", &ridesOrNot);
      if(ridesOrNot == 1) {
         price = BABY;
      } else if(ridesOrNot == 2) {
         price = FREE_OF_CHARGE;
      }
   } else if (ticketType == 1 && ticketTime == 1 && manAge >= 3 && manAge < 12) {
      price = ALL_CHILD_1DAY;   
   } else if (ticketType == 1 && ticketTime == 1 && manAge >= 12 && manAge < 18) {
      price = ALL_YOUTH_1DAY;
   } else if (ticketType == 1 && ticketTime == 1 && manAge >= 18 && manAge < 65) {
      price = ALL_ADULT_1DAY;
   } else if (ticketType == 1 && ticketTime == 1 && manAge >= 65) {
      price = ALL_CHILD_1DAY;
   
   } else if (ticketType == 1 && ticketTime == 2 && manAge >= 3 && manAge < 12) {
      price = ALL_CHILD_AFTER4;
   } else if (ticketType == 1 && ticketTime == 2 && manAge >= 12 && manAge < 18) {
      price = ALL_YOUTH_AFTER4;
   } else if (ticketType == 1 && ticketTime == 2 && manAge >= 18 && manAge < 65) {
      price = ALL_ADULT_AFTER4;
   } else if (ticketType == 1 && ticketTime == 2 && manAge >= 65) {
      price = ALL_CHILD_AFTER4;
       
   } else if (ticketType == 2 && ticketTime == 1 && manAge >= 3 && manAge < 12) {
      price = PARK_CHILD_1DAY;
   } else if (ticketType == 2 && ticketTime == 1 && manAge >= 12 && manAge < 18) {
      price = PARK_YOUTH_1DAY;
   } else if (ticketType == 2 && ticketTime == 1 && manAge >= 18 && manAge < 65) {
      price = PARK_ADULT_1DAY;
   } else if (ticketType == 2 && ticketTime == 1 && manAge >= 65) {
      price = PARK_CHILD_1DAY;
      
   } else if (ticketType == 2 && ticketTime == 2 && manAge >= 3 && manAge < 12) {
      price = PARK_CHILD_AFTER4;
   } else if (ticketType == 2 && ticketTime == 2 && manAge >= 12 && manAge < 18) {
      price = PARK_YOUTH_AFTER4;
   } else if (ticketType == 2 && ticketTime == 2 && manAge >= 18 && manAge < 65) {
      price = PARK_ADULT_AFTER4;
   } else if (ticketType == 2 && ticketTime == 2 && manAge >= 65) {
      price = PARK_CHILD_AFTER4;
   }
   return price;
}

void TicketQTY() {    //Tickets QTY(fixed)
   printf("How many tickets? (max 10)\n");
   printf("1\n");   
}

int SpecialOfferQuestion() {
   printf("Special Offer\n1.None\n2.Disabled\n3.Veteran\n4.Military\n5.Pregnant\n6.MultiChild\n");
   scanf("%d", &specialOffer);   
   return specialOffer;
}

int SpecialOffer(int manAge, int specialOffer, int price) {
   if(manAge >= 65) {
      specialOffer = 1;
   }
   if(specialOffer == 1) {
      priceSpecialOffer = price;
   } else if(specialOffer == 2) {
      priceSpecialOffer = (int)(price * DISABLED_DC_RATE);      // if DC_RATE is changed, price might need to be round-up
   } else if (specialOffer == 3) {
      priceSpecialOffer = (int)(price * VETERAN_DC_RATE);
   } else if (ticketType == 1 && specialOffer == 4) {
      priceSpecialOffer = (int)(price * MILITARY_DC_RATE); 
   } else if (ticketType == 1 && specialOffer == 5) {
      priceSpecialOffer = (int)(price * PREGNANT_DC_RATE); 
   } else if (ticketType == 1 && specialOffer == 6) {
      priceSpecialOffer = (int)(price * MULTICHILD_DC_RATE);
   }
   
   printf("The ticket price is : %d\n", priceSpecialOffer);
   printf("Thank you\n");   
   return priceSpecialOffer;
}

int TicketType(int ticketType) {
   ticketInfo[repCount][TICKET_TYPE_INDEX]= ticketType;
   return ticketInfo[repCount][TICKET_TYPE_INDEX];
}

int TicketTime(int ticketTime) {
   ticketInfo[repCount][TICKET_TIME_INDEX] = ticketTime;
   return ticketInfo[repCount][TICKET_TIME_INDEX];
}

int ManAge(int manAge) {
   ticketInfo[repCount][MANAGE_INDEX] = manAge;
   return ticketInfo[repCount][MANAGE_INDEX];
}

int PriceSpecialOffer(int priceSpecialOffer) {
   ticketInfo[repCount][PRICE_INDEX] = priceSpecialOffer;
   return ticketInfo[repCount][PRICE_INDEX];
}

int SpecialOfferIndex(int specialOffer) {
   ticketInfo[repCount][SPECIAL_OFFER_INDEX] = specialOffer;
   return ticketInfo[repCount][SPECIAL_OFFER_INDEX];   
}

int ContinueOrNot() {
   printf("Continue to buy or not?\n1.More tickets\n2.Terminate\n");
   scanf("%d", &continueOrNot);
   return continueOrNot;   
}

void PrintOut(int repCount) {
   printf("Stop ticketing. Thank you\n");
   printf("===================== LOTTE WORLD =====================\n");   
   for(index = 0; index < repCount; index++) {   
      if(ticketInfo[index][TICKET_TYPE_INDEX] == 1) {
         printf("All\t");   
      } else if(ticketInfo[index][TICKET_TYPE_INDEX]    == 2) {
         printf("Park\t");   
      }
      if(ticketInfo[index][TICKET_TIME_INDEX] == 1) {
         printf("1Day\t");
      } else if(ticketInfo[index][TICKET_TIME_INDEX] == 2) {
         printf("After4\t");
      }
      
      if(ticketInfo[index][MANAGE_INDEX] < 3) {
         printf("Baby\t");
      } else if(ticketInfo[index][MANAGE_INDEX] >= 3 && ticketInfo[index][MANAGE_INDEX] < 12) {
         printf("Child\t");
      } else if(ticketInfo[index][MANAGE_INDEX] >= 12 && ticketInfo[index][MANAGE_INDEX] < 18) {
         printf("Youth\t");
      } else if(ticketInfo[index][MANAGE_INDEX] >= 18 && ticketInfo[index][MANAGE_INDEX] < 65) {
         printf("Adult\t");
      } else if(ticketInfo[index][MANAGE_INDEX] >= 65) {
         printf("Senior\t");
      }
      
      printf(" X\t%d\t", QTY);

      if(ticketInfo[index][SPECIAL_OFFER_INDEX] == 1) { 
         printf("None\n");
      } else if(ticketInfo[index][SPECIAL_OFFER_INDEX] == 2) {
         printf("Disabled\n");
      } else if(ticketInfo[index][SPECIAL_OFFER_INDEX] == 3) {
         printf("Veteran\n");
      } else if(ticketInfo[index][SPECIAL_OFFER_INDEX] == 4) {
         printf("Military\n");
      } else if(ticketInfo[index][SPECIAL_OFFER_INDEX] == 5) {
         printf("Pregnant\n");
      } else if(ticketInfo[index][SPECIAL_OFFER_INDEX] == 6) {
         printf("MultiChild\n");
      } 
      
      totalPrice += ticketInfo[index][PRICE_INDEX];
   }
   
   printf("The total price is %d\n",totalPrice);
      totalPrice = 0;
   printf("=======================================================\n");
   printf("\n");
}

int NewOrExit() {
   printf("To continue or not(1.New Order, 2.Exit)\n");
   scanf("%d", &newOrExit);
   return newOrExit;
}

#include <stdio.h>

int main(void) {
	int ticketType, ticketTime, manAge, price, specialOffer, totalPrice = 0;
	int index, repCount, NewOrExit, continueOrNot, ridesOrNot = 0;
	int ageYear, birthDay = 0;
	const int QTY = 1;
	const int THIS_YEAR = 2022, TODAY = 416;
	const int ALL_ADULT_1DAY = 62000, ALL_YOUTH_1DAY = 54000, ALL_CHILD_1DAY = 47000, ALL_ADULT_AFTER4 = 50000, ALL_YOUTH_AFTER4 = 43000, ALL_CHILD_AFTER4 = 36000,	
		  PARK_ADULT_1DAY = 59000, PARK_YOUTH_1DAY = 52000, PARK_CHILD_1DAY = 46000, PARK_ADULT_AFTER4 = 47000, PARK_YOUTH_AFTER4 = 41000, PARK_CHILD_AFTER4 = 35000,
		  BABY = 15000, FREE_OF_CHARGE = 0;
	const float DISABLED_DC_RATE = 0.5f, VETERAN_DC_RATE = 0.5f, MILITARY_DC_RATE = 0.51f, PREGNANT_DC_RATE = 0.5f, MULTICHILD_DC_RATE = 0.7f;
	const int TICKET_TYPE_INDEX = 0, TICKET_TIME_INDEX = 1, MANAGE_INDEX = 2, PRICE_INDEX = 3, SPCIAL_OFFER_INDEX = 4;
	int idNum[13];
	int ticketInfo[10][5] = {0};

	while(true) {
	do {	 
	printf("Select Type of Tickets\n1.All\n2.Park\n");
	scanf("%d", &ticketType);
	printf("Select Time of Tickets\n1.Day\n2.After4\n");
	scanf("%d", &ticketTime);
	printf("Input your social security number\n"); 
	for(index = 0; index < 13; index++) {
		scanf("%1d", &idNum[index]);
	}
	//manAge calculation
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
	// price setting
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
	//Tickets QTY(fixed)
	printf("How many tickets? (max 10)\n");
	printf("1\n");
	//Special Offer
	printf("Special Offer\n1.None\n2.Disabled\n3.Veteran\n4.Military\n5.Pregnant\n6.MultiChild\n");
	scanf("%d", &specialOffer);
	
	if(manAge >= 65) {
		specialOffer = 1;
	}
	if(specialOffer == 1) {
		price;
	} else if(specialOffer == 2) {
		price = (int)(price * DISABLED_DC_RATE);      // if DC_RATE is changed, price might need to be round-up
	} else if (specialOffer == 3) {
		price = (int)(price * VETERAN_DC_RATE);
	} else if (ticketType == 1 && specialOffer == 4) {
		price = (int)(price * MILITARY_DC_RATE); 
	} else if (ticketType == 1 && specialOffer == 5) {
		price = (int)(price * PREGNANT_DC_RATE); 
	} else if (ticketType == 1 && specialOffer == 6) {
		price = (int)(price * MULTICHILD_DC_RATE);
	}
	printf("The ticket price is : %d\n", price);
	printf("Thank you\n");	
	//2D array 
	ticketInfo[repCount][TICKET_TYPE_INDEX] = ticketType;
	ticketInfo[repCount][TICKET_TIME_INDEX] = ticketTime;
	ticketInfo[repCount][MANAGE_INDEX] = manAge;
	ticketInfo[repCount][PRICE_INDEX] = price;
	ticketInfo[repCount][SPCIAL_OFFER_INDEX] = specialOffer;	
		
	repCount++;
	
	printf("Continue to buy or not?\n1.More tickets\n2.Terminate\n");
	scanf("%d", &continueOrNot);
	if(continueOrNot == 1) {
		continue;
	} else if(continueOrNot == 2) {
		break;
	}
	printf("\n\n");
	} while(repCount < 10); //do while loop ends
	
	printf("Stop ticketing. Thank you\n");
	printf("===================== LOTTE WORLD =====================\n");	
	for(index = 0; index < repCount; index++) {	
		if(ticketInfo[index][TICKET_TYPE_INDEX] == 1) {
			printf("All\t");	
		} else if(ticketInfo[index][TICKET_TYPE_INDEX] 	== 2) {
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
		printf("%d\t",ticketInfo[index][PRICE_INDEX]);
		
		if(ticketInfo[index][SPCIAL_OFFER_INDEX] == 1) {
			printf("None\n");
		} else if(ticketInfo[index][SPCIAL_OFFER_INDEX] == 2) {
			printf("Disabled\n");
		} else if(ticketInfo[index][SPCIAL_OFFER_INDEX] == 3) {
			printf("Veteran\n");
		} else if(ticketInfo[index][SPCIAL_OFFER_INDEX] == 4) {
			printf("Military\n");
		} else if(ticketInfo[index][SPCIAL_OFFER_INDEX] == 5) {
			printf("Pregnant\n");
		} else if(ticketInfo[index][SPCIAL_OFFER_INDEX] == 6) {
			printf("MultiChild\n");
		}		
		
		totalPrice += ticketInfo[index][PRICE_INDEX];
	}
	printf("The total price is %d\n",totalPrice);
		totalPrice = 0;
	printf("=======================================================\n");
	printf("\n");

	printf("To continue or not(1.New Order, 2.Exit)\n");
	scanf("%d", &NewOrExit);
	if(NewOrExit == 1) {
		continue;
	} else if(NewOrExit == 2) {
		break;
	}
	}
	return 0;
}

#include <stdio.h>
//const int naming will be updated
int main(void) {
	int ticketType = 0;
	int ticketTime = 0;
	int repCount = 0;
	int index;
	int NewOrExit;
	int ageYear;
	int birthDay;
	int manAge;
	int idNum[13];
	int ticketPrice = 0;
	int ticketNum = 1; // fixed
	int ridesOrNot;
	int specialOffer = 0;
	int totalPrice = 0;
	int continueOrNot;
	const int THISYEAR = 2022;
	const int TODAY = 416;
	const int ALLADULT1DAY = 62000;
	const int ALLYOUTH1DAY = 54000;
	const int ALLCHILD1DAY = 47000;	
	const int ALLADULTAFTER4 = 50000;
	const int ALLYOUTHAFTER4 = 43000;
	const int ALLCHILDAFTER4 = 36000;	
	const int PARKADULT1DAY = 59000;
	const int PARKYOUTH1DAY = 52000;
	const int PARKCHILD1DAY = 46000;	
	const int PARKADULTAFTER4 = 47000;
	const int PARKYOUTHAFTER4 = 41000;
	const int PARKCHILDAFTER4 = 35000;	
	const int BABY = 15000;
	const int FREEOFCHARGE = 0;	
	//2D Array
	int ticketInfo[10][5] = {0};
	const int ticketTypeIndex = 0;
	const int ticketTimeIndex = 1;
	const int manAgeIndex = 2;
	const int ticketPriceIndex = 3;
	const int specialOfferIndex = 4;

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
	manAge = THISYEAR - ageYear;
	if(birthDay >= TODAY) {
		manAge;
	} else {
		manAge -= 1;
	}
	// price setting
	if(manAge < 1) {
		ticketPrice = FREEOFCHARGE;	
	} else if (manAge >= 1  && manAge < 3) {
		printf("baby rides? 1.yes 2.no\n");
		scanf("%d", &ridesOrNot);
		if(ridesOrNot == 1) {
			ticketPrice = BABY;
		} else if(ridesOrNot == 2) {
			ticketPrice = FREEOFCHARGE;
		}
	} else if (ticketType == 1 && ticketTime == 1 && manAge >= 3 && manAge < 12) {
		ticketPrice = ALLCHILD1DAY;	
	} else if (ticketType == 1 && ticketTime == 1 && manAge >= 12 && manAge < 18) {
		ticketPrice = ALLYOUTH1DAY;
	} else if (ticketType == 1 && ticketTime == 1 && manAge >= 18 && manAge < 65) {
		ticketPrice = ALLADULT1DAY;
	} else if (ticketType == 1 && ticketTime == 1 && manAge >= 65) {
		ticketPrice = ALLCHILD1DAY;
	
	} else if (ticketType == 1 && ticketTime == 2 && manAge >= 3 && manAge < 12) {
		ticketPrice = ALLCHILDAFTER4;
	} else if (ticketType == 1 && ticketTime == 2 && manAge >= 12 && manAge < 18) {
		ticketPrice = ALLYOUTHAFTER4;
	} else if (ticketType == 1 && ticketTime == 2 && manAge >= 18 && manAge < 65) {
		ticketPrice = ALLADULTAFTER4;
	} else if (ticketType == 1 && ticketTime == 2 && manAge >= 65) {
		ticketPrice = ALLCHILDAFTER4;
		 
	} else if (ticketType == 2 && ticketTime == 1 && manAge >= 3 && manAge < 12) {
		ticketPrice = PARKCHILD1DAY;
	} else if (ticketType == 2 && ticketTime == 1 && manAge >= 12 && manAge < 18) {
		ticketPrice = PARKYOUTH1DAY;
	} else if (ticketType == 2 && ticketTime == 1 && manAge >= 18 && manAge < 65) {
		ticketPrice = PARKADULT1DAY;
	} else if (ticketType == 2 && ticketTime == 1 && manAge >= 65) {
		ticketPrice = PARKCHILD1DAY;
		
	} else if (ticketType == 2 && ticketTime == 2 && manAge >= 3 && manAge < 12) {
		ticketPrice = PARKCHILDAFTER4;
	} else if (ticketType == 2 && ticketTime == 2 && manAge >= 12 && manAge < 18) {
		ticketPrice = PARKYOUTHAFTER4;
	} else if (ticketType == 2 && ticketTime == 2 && manAge >= 18 && manAge < 65) {
		ticketPrice = PARKADULTAFTER4;
	} else if (ticketType == 2 && ticketTime == 2 && manAge >= 65) {
		ticketPrice = PARKCHILDAFTER4;
	}
	//the number of Tickets(fixed)
	printf("How many tickets? (max 10)\n");
	printf("1\n");
	//Special Offer
	printf("Special Offer\n1.None\n2.Disabled\n3.Veteran\n4.Military\n5.Pregnant\n6.Multiple\n");
	scanf("%d", &specialOffer);
	
	if(manAge >= 65) {
		specialOffer = 1;
	}
	if(specialOffer == 1) {
		ticketPrice;
	} else if(specialOffer == 2) {
		ticketPrice*=0.5; 
	} else if (specialOffer == 3) {
		ticketPrice*=0.5; 
	} else if (ticketType == 1 && specialOffer == 4) {
		ticketPrice*=0.49; 
	} else if (ticketType == 1 && specialOffer == 5) {
		ticketPrice*=0.5; 
	} else if (ticketType == 1 && specialOffer == 6) {
		ticketPrice*=0.3;
	}
	printf("The ticket price is : %d\n", ticketPrice);
	printf("Thank you\n");
	//2D array 
	ticketInfo[repCount][ticketTypeIndex] = ticketType;
	ticketInfo[repCount][ticketTimeIndex] = ticketTime;
	ticketInfo[repCount][manAgeIndex] = manAge;
	ticketInfo[repCount][ticketPriceIndex] = ticketPrice;
	ticketInfo[repCount][specialOfferIndex] = specialOffer;	
		
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
		if(ticketInfo[index][ticketTypeIndex] == 1) {
			printf("All\t");	
		} else if(ticketInfo[index][ticketTypeIndex] == 2) {
			printf("Park\t");	
		}
		if(	ticketInfo[index][ticketTimeIndex] == 1) {
			printf("1Day\t");
		} else if(	ticketInfo[index][ticketTimeIndex] == 2) {
			printf("After4\t");
		}
		
		if(ticketInfo[index][manAgeIndex] < 3) {
			printf("Baby\t");
		} else if(ticketInfo[index][manAgeIndex] >= 3 && ticketInfo[index][manAgeIndex] < 12) {
			printf("Child\t");
		} else if(ticketInfo[index][manAgeIndex] >= 12 && ticketInfo[index][manAgeIndex] < 18) {
			printf("Youth\t");
		} else if(ticketInfo[index][manAgeIndex] >= 18 && ticketInfo[index][manAgeIndex] < 65) {
			printf("Adult\t");
		} else if(ticketInfo[index][manAgeIndex] >= 65) {
			printf("Senior\t");
		}
		
		printf(" X\t%d\t", ticketNum);
		printf("%d\t",ticketInfo[index][ticketPriceIndex]);
		
		if(ticketInfo[index][specialOfferIndex] == 1) {
			printf("None\n");
		} else if(ticketInfo[index][specialOfferIndex] == 2) {
			printf("Disabled\n");
		} else if(ticketInfo[index][specialOfferIndex] == 3) {
			printf("Veteran\n");
		} else if(ticketInfo[index][specialOfferIndex] == 4) {
			printf("Military\n");
		} else if(ticketInfo[index][specialOfferIndex] == 5) {
			printf("Pregnant\n");
		} else if(ticketInfo[index][specialOfferIndex] == 6) {
			printf("Multiple\n");
		}		
		
		totalPrice += ticketInfo[index][ticketPriceIndex];
	}
	printf("The total price is %d\n",totalPrice);
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
}

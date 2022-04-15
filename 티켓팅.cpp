#include <stdio.h>
// 2차원 배열로 수정예정
// 동반 1인 할인은 중복 적용이 가능한가? (고려되지 않음) 
int main(void) {
	int ticketType[10];
	int ticketTime[10];
	int idNum[13];
	int i;	//i means index
	int ageYear;
	int birthDay;
	int manAge[10];
	const int THISYEAR = 2022;
	const int TODAY = 414;
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
	int ticketPrice[10];
	int ticketNum = 1; // fixed
	int ridesOrNot;
	int specialOffer[10];
	int sumPrice;
	int continueOrNot;
	int ticket[10];
	int index = 0;
	const char* TICKETTYPE1 = "All";
	const char* TICKETTYPE2 = "Park";
	const char* TICKETTIME1 = "1Day";
	const char* TICKETTIME2 = "After4";
	const char* SPECIALOFFER1 = "None";
	const char* SPECIALOFFER2 = "Disabled";
	const char* SPECIALOFFER3 = "Veteran";
	const char* SPECIALOFFER4 = "Military";
	const char* SPECIALOFFER5 = "Pregnant";
	const char* SPECIALOFFER6 = "Multiple";
	const char* MANAGE1 = "Baby";
	const char* MANAGE2 = "Child";
	const char* MANAGE3 = "Youth";
	const char* MANAGE4 = "Adult";
	const char* MANAGE5 = "Senior";
	int NewOrExit;
	
	while(true) {
	for(int index = 0; index < 10; index++) { // the max number of repetition is 10 
	printf("Select Type of Tickets\n1.All\n2.Park\n");
	scanf("%d", &ticketType[i]);
	
	printf("Select Time of Tickets\n1.Day\n2.After4\n");
	scanf("%d", &ticketTime[i]);
	
	printf("Input your social security number\n"); 
	for(int index = 0; index < 13; index++) {
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
	manAge[i] = THISYEAR - ageYear;
	if(birthDay >= TODAY) {
		manAge[i];
	} else {
		manAge[i] -= 1;
	}
	// price setting
	if(manAge[i] < 1) {
		ticketPrice[i] = FREEOFCHARGE;	
	} else if (manAge[i] >= 1  && manAge[i] < 3) {
		printf("baby rides? 1.yes 2.no\n");
		scanf("%d", &ridesOrNot);
		if(ridesOrNot == 1) {
			ticketPrice[i] = BABY;
		} else if(ridesOrNot == 2) {
			ticketPrice[i] = FREEOFCHARGE;
		}
	} else if (ticketType[i] == 1 && ticketTime[i] == 1 && manAge[i] >= 3 && manAge[i] < 12) {
		ticketPrice[i] = ALLCHILD1DAY;	
	} else if (ticketType[i] == 1 && ticketTime[i] == 1 && manAge[i] >= 12 && manAge[i] < 18) {
		ticketPrice[i] = ALLYOUTH1DAY;
	} else if (ticketType[i] == 1 && ticketTime[i] == 1 && manAge[i] >= 18 && manAge[i] < 65) {
		ticketPrice[i] = ALLADULT1DAY;
	} else if (ticketType[i] == 1 && ticketTime[i] == 1 && manAge[i] >= 65) {
		ticketPrice[i] = ALLCHILD1DAY;
		
	} else if (ticketType[i] == 1 && ticketTime[i] == 2 && manAge[i] >= 3 && manAge[i] < 12) {
		ticketPrice[i] = ALLCHILDAFTER4;
	} else if (ticketType[i] == 1 && ticketTime[i] == 2 && manAge[i] >= 12 && manAge[i] < 18) {
		ticketPrice[i] = ALLYOUTHAFTER4;
	} else if (ticketType[i] == 1 && ticketTime[i] == 2 && manAge[i] >= 18 && manAge[i] < 65) {
		ticketPrice[i] = ALLADULTAFTER4;
	} else if (ticketType[i] == 1 && ticketTime[i] == 2 && manAge[i] >= 65) {
		ticketPrice[i] = ALLCHILDAFTER4;
		 
	} else if (ticketType[i] == 2 && ticketTime[i] == 1 && manAge[i] >= 3 && manAge[i] < 12) {
		ticketPrice[i] = PARKCHILD1DAY;
	} else if (ticketType[i] == 2 && ticketTime[i] == 1 && manAge[i] >= 12 && manAge[i] < 18) {
		ticketPrice[i] = PARKYOUTH1DAY;
	} else if (ticketType[i] == 2 && ticketTime[i] == 1 && manAge[i] >= 18 && manAge[i] < 65) {
		ticketPrice[i] = PARKADULT1DAY;
	} else if (ticketType[i] == 2 && ticketTime[i] == 1 && manAge[i] >= 65) {
		ticketPrice[i] = PARKCHILD1DAY;
		
	} else if (ticketType[i] == 2 && ticketTime[i] == 2 && manAge[i] >= 3 && manAge[i] < 12) {
		ticketPrice[i] = PARKCHILDAFTER4;
	} else if (ticketType[i] == 2 && ticketTime[i] == 2 && manAge[i] >= 12 && manAge[i] < 18) {
		ticketPrice[i] = PARKYOUTHAFTER4;
	} else if (ticketType[i] == 2 && ticketTime[i] == 2 && manAge[i] >= 18 && manAge[i] < 65) {
		ticketPrice[i] = PARKADULTAFTER4;
	} else if (ticketType[i] == 2 && ticketTime[i] == 2 && manAge[i] >= 65) {
		ticketPrice[i] = PARKCHILDAFTER4;
	}
	//the number of Tickets(fixed)
	printf("How many tickets? (max 10)\n");
	printf("1\n");
	
	//Special Offer
	printf("Special Offer\n1.None\n2.Disabled\n3.Veteran\n4.Military\n5.Pregnant\n6.Multiple\n");
	scanf("%d", &specialOffer[i]);
		
	if(manAge[i] >= 65) {
		specialOffer[i] = 1;
	}
	if(specialOffer[i] == 1) {
		ticketPrice[i];
	} else if(specialOffer[i] == 2) {
		ticketPrice[i]*=0.5; 
	} else if (specialOffer[i] == 3) {
		ticketPrice[i]*=0.5; 
	} else if (ticketType[i] == 1 && specialOffer[i] == 4) {
		ticketPrice[i]*=0.49; 
	} else if (ticketType[i] == 1 && specialOffer[i] == 5) {
		ticketPrice[i]*=0.5; 
	} else if (ticketType[i] == 1 && specialOffer[i] == 6) {
		ticketPrice[i]*=0.3;
	}
	sumPrice += ticketPrice[i]*ticketNum;
	printf("The ticket price is : %d\n", ticketPrice[i]*ticketNum);
	printf("Thank you");
	
	i++;
	
	printf("Continue to buy or not?\n1.More tickets\n2.Terminate\n");
	scanf("%d", &continueOrNot);
	if(continueOrNot == 1) {
		continue;
	} else if(continueOrNot == 2) {
		break;
	}
	printf("\n\n");
	} // for statement ends. 
	printf("Stop ticketing. Thank you\n");
	printf("===================== LOTTE WORLD =====================\n");
	for(index = 0; index < i; index++) {
		if(ticketType[index] == 1) {
			printf("%s\t", TICKETTYPE1);	
		} else if(ticketType[index] == 2) {
			printf("%s\t", TICKETTYPE2);	
		}
		if(ticketTime[index] == 1) {
			printf("%s\t", TICKETTIME1);
		} else if(ticketTime[index] == 2) {
			printf("%s\t", TICKETTIME2);
		}
		
		if(manAge[i] < 3) {
			printf("%s\t", MANAGE1);
		} else if(manAge[i] >= 3 && manAge[i] < 12) {
			printf("%s\t", MANAGE2);
		} else if(manAge[i] >= 12 && manAge[i] < 18) {
			printf("%s\t", MANAGE3);
		} else if(manAge[i] >= 18 && manAge[i] < 65) {
			printf("%s\t", MANAGE4);
		} else if(manAge[i] >= 65) {
			printf("%s\t", MANAGE5);
		}

		printf(" X\t%d\t", ticketNum);
		printf("%d\t",ticketPrice[index]);
		
		if(specialOffer[index] == 1) {
			printf("%s\n", SPECIALOFFER1);
		} else if(specialOffer[index] == 2) {
			printf("%s\n", SPECIALOFFER2);
		} else if(specialOffer[index] == 3) {
			printf("%s\n", SPECIALOFFER3);
		} else if(specialOffer[index] == 4) {
			printf("%s\n", SPECIALOFFER4);
		} else if(specialOffer[index] == 5) {
			printf("%s\n", SPECIALOFFER5);
		} else if(specialOffer[index] == 6) {
			printf("%s\n", SPECIALOFFER6);
		}	
	}
	printf("The total price is %d \n",sumPrice);
	printf("====================================================\n");
	printf("\n");

	printf("To Continue or Not(1.New Order, 2.Exit)\n");
	scanf("%d", &NewOrExit);
	if(NewOrExit == 1) {
		continue;
	}
	if(NewOrExit == 2) {
		break;
	}
	}		
}

#include <stdio.h>
// the number of tickets could be const variables? 
int main(void) {
	int ticketTime[10];
	int ticketNumFinal;
	int i;
	
	do {
	printf("How many tickets? (max 10)\n");
	scanf("%d", &ticketTime[i]);
	
	ticketNumFinal = ticketTime[0];
	
	i++;
	} while(i < ticketNumFinal);
	
}

/*
Name:Lennis Bahati
Reg no:PA106/G/28806/25
Description :CAT 2
Date:Week 
*/
#include<stdio.h> 
int main(){
	int Totaltax,overtime,normalhours=40,netpay,overtimepay,overtimerate,
	hoursworked, hourwage, grosspay, normalpay;
	
	//Input
	printf("Enter hours worked in a week please:");
	scanf("%d",&hoursworked);
	
	printf("Enter hourly wage please:");
	scanf("%d",&hourwage);
	
	//gross pay calculation
	if(hoursworked <=40){
		//NOrmal pay 
		grosspay=hoursworked*hourwage;
	}else{
		//overtime 
		 overtime=hoursworked-normalhours;
		 overtimerate=1.5 * hourwage;
		 normalpay=normalhours * hourwage;
		 overtimepay=overtime * overtimerate;
		 
		 grosspay=normalpay+overtimepay;
	}
	
	//tax
	const int Fbr=600;//first bracket limit $600
	const float onerate=0.15; //first bracket rate
	const float tworate=0.20;//secon bracket rate
	
	if(grosspay<=Fbr){
		int tax=grosspay*onerate;
	}else{
		int tax1b=Fbr*onerate,
		Rincome=grosspay-onerate,//remaining income
		taxR=Rincome*tworate;//tax on remaining income
		
		int Totaltax=onerate+taxR;
		
	}
	//netpay calculations
	netpay=grosspay-Totaltax;
	
	//Payment summarry

	printf("______Payment summarry_______\n \n");
	printf("\nGross pay:.....$%d",grosspay);
	printf("\nTaxes Deducted:.....$%d",Totaltax);
	printf("\nNet pay:.....$%d",netpay);
	
	return 0;
}
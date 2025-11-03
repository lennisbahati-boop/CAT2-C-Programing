/*
Name:Lennis Bahati
Reg no:PA106/G/28806/25
Description :CAT 2
Date:Week 
*/#include<stdio.h>
int main(){
	int i,j;
	
	int scores1[2][2]={
	{65,92},
	{84,72}
	};
	
	int scores2[2][2]={
	{35,70},
	{59,67}
	};
	
	for(i=0;i<2;i++){
		for(j=0;j<2;j++){
			printf("%d\t",scores1[i][j]);
		}
		printf("\n");
	}
		for(i=0;i<2;i++){
		for(j=0;j<2;j++){
			printf("%d\t",scores2[i][j]);
		}
		printf("\n");
	}
	return 0;
}
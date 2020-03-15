#include <stdio.h>
#include "myBank.h"
#define LENGTH 50
#define OPEN 1
#define CLOSE 0

double accounts [LENGTH][2]={0};

//Function that returns a real number with two-digits number after the decimal point.
double decimalPlace(double x){
    x *= 100;
    x = (int)x;
    x /= 100.0;
    return x;
}

//Function that opening an account, saving the initial deposit amount
//and prints the new account number.
void open(double a){
	
	for(int i = 0; i < LENGTH; i++){
		if(accounts[i][0] == CLOSE){
			accounts[i][0] = OPEN;
			accounts[i][1] = a;

			printf("Your account number is: %d \n",i+901);
			return;
		}
    }
	    printf("You can't open a new account \n");
			
}

//Function that prints the balance.
//This action is only allowed if the account is open.
void balance(int account){
	if(accounts[account-901][0] == OPEN){
	    double balance = accounts[account-901][1];
		printf("Yours balance is: %0.2lf \n", balance);
	}
	else
	printf("You can't see the balance, The account number doesn't exist! \n");
}
//Function that accepts a deposit receives and account number and prints the new balance.
//This action is only allowed if the account is open.
void deposite(int account, double d){
	if((accounts[account-901][0] == OPEN)&&(d>0)){
		accounts[account-901][1] += d;
		printf("Yours new balance is: %0.2lf \n",accounts[account-901][1]);
	}
	else
	printf("You don't have an account! \n");
}

//Function that accepts a withdrawal amount and account number and print the new balance. 
//This action is only allowed if the account is open and there is enough cash to withdraw.
void withdrawal(int account, double w){
	if((accounts[account-901][0]==OPEN)&&(accounts[account-901][1] >= w)&&(w>0)){
		accounts[account-901][1] -= w;
		printf("Yours new balance is: %0.2lf \n",accounts[account-901][1]);
	}
	else
	printf("You can't see the new balance \n");
}
//Function that closing an account.
//Only allowed if the account is open.
void closeAccount(int account){
	if(accounts[account-901][0]==OPEN){
		accounts[account-901][0]=CLOSE;
		accounts[account-901][1]=0;
		printf("Yours account is closed!\n");
	}
	else
	printf("You don't have an account \n");
}

//Add interest at a given percentage rate to all open accounts.
void interest(double in){
	for(int i = 0; i <= LENGTH; i++){
		if(accounts[i][0]==OPEN){
			accounts[i][1] += ((accounts[i][1])*(in/100));
		}
	}
    printf("The interest has been added to all accounts \n");
}
//Print all open accounts and there balance.
void printAll(){
	for(int i = 0; i <= LENGTH; i++){
		if(accounts[i][0]==OPEN){
			printf("Account number: %d , balance: %0.2lf \n",i+901, accounts[i][1]);
		}
	}
}
//Close all accounts and exit the program.
void closeAll(){
	for(int i = 0; i <= LENGTH; i++){
		if(accounts[i][0]==OPEN){
			accounts[i][0]=CLOSE;
			accounts[i][1]=0;
	    }
     }
    printf("All the accounts are closed!\n");
}

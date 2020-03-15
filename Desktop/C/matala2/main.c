#include <stdio.h>
#include "myBank.h"

enum Boolean {False = 0, True = 1};

int main(){
while(True){

    char type;
    printf("Menu- \n\nO: Open new account \nB: Print balance \nD: Deposite  \nW: Withrawal \nC: Close account \n");
    printf("I: Add interest to all accounts \nP: Print all open accounts and balance \nE: Close all accounts and exit \n");
    scanf(" %c", &type);
    switch(type)
    {
        case 'O':
            printf("Initial deposit? \n");
            double amount = 0;
            while((scanf(" %lf", &amount)==False)&&(amount <= 0)){
            printf("Enter a positive real number! \n");
            while(getchar() != '\n');
            }
            
            double newAmount= decimalPlace(amount);

            open(newAmount);
            
        break;

        case 'B':
            printf("‫‪Account‬‬ ‫‪number?:‬‬ \n");
            int account_number= 0;
            while(scanf(" %d", &account_number)==False&&((account_number<901)||(account_number>950))){
            printf("This account doesn't exist! Enter your account number \n");
            while(getchar() != '\n');
            }
            balance(account_number);

        break;

        case 'D':
            printf("‫‪Account‬‬ ‫‪number? \n");
            int account1=0;
            while(scanf(" %d", &account1)==False&&((account1<901)||(account1>950))){
            printf("This account doesn't exist! Enter your account number \n");
            while(getchar() != '\n');
            }
            printf("Amount? \n");
            double amount1=0; 
            while((scanf(" %lf", &amount1)==False)&&(amount1 <= 0)){
            printf("Enter a positive real number! \n");
            while(getchar() != '\n');
            }
            
            double newAmount1 = decimalPlace(amount1);

            deposite(account1, newAmount1);
            
        break;

        case 'W':
            printf("‫‪Account‬‬ ‫‪number? \n");
            int account2=0;
            while(scanf(" %d", &account2)==False&&((account2<901)||(account2>950))){
            printf("This account doesn't exist! Enter your account number \n");
            while(getchar() != '\n');
            }
            printf("Amount? \n");
            double amount2 = 0;
            while((scanf(" %lf", &amount2)==False)&&(amount2 <= 0)){
            printf("Enter a positive real number! \n");
            while(getchar() != '\n');
            }
            
            double newAmount2 = decimalPlace(amount2);

            withdrawal(account2, newAmount2);
            
        break;

        case 'C':
            printf("‫‪Account‬‬ ‫‪number? \n");
            int account3 = 0;
            while(scanf(" %d", &account3)==False&&((account3<901)||(account3>950))){
            printf("This account doesn't exist! Enter your account number \n");
            while(getchar() != '\n');
            }

            closeAccount(account3);
        break;

        case 'I':
            printf("‫‪‫‪Interest rate‬‬? \n");
            double inter=0;
            while((scanf(" %lf", &inter)==False)&&(inter <= 0)){
            printf("Enter a positive real number! \n");
            while(getchar() != '\n');
            }
            double newInter = decimalPlace(inter);

            interest(newInter);
        break;

        case 'P':
           printAll();
        break;

        case 'E':
            closeAll();

            return False;
            break;

        default:
        printf("Error! type isn't correct! \n");
    }
}

return 0;
}

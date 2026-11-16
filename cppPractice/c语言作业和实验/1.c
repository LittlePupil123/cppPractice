#include<stdio.h>

int main(){
    double rate=5/100.0;
    double amount;
    printf("Enter an amount:");
    scanf("%lf",&amount);
    
    amount+=amount*rate;
    printf("with tax added:$%lf",amount);
    
    return 0;
}
// Enter a dollar amount: 93
// $20 bills: 4
// $10 bills: 1
// $5 bills: 0
// $1 bills: 3
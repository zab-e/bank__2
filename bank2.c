#include <stdio.h>
#include <string.h>
int withdraw_balance(int x,int y) {
    return x - y;
}
int deposit_balance(int x,int y) {
    return x + y;
}
struct account {
    double balance;
    char name[25];
    char op;
    double new_balance;
    double amount;

};


void run_code() {

    struct account account1;

    printf("Enter account holder name:\n");
    fgets(account1.name, sizeof(account1.name), stdin);
    account1.name[strcspn(account1.name, "\n")] = 0;
    

    printf("Welcome %s\n", account1.name);

    printf("Enter account balance:\n");
    scanf("%lf", &account1.balance);
    

    printf("Choose operation type:(D,W)\n");
    scanf(" %c", &account1.op);
    if (account1.op == 'D' || account1.op == 'd') {
        printf("Enter amount u wish to deposit:\n");
        scanf("%lf", &account1.amount);
        account1.new_balance = deposit_balance(account1.balance,account1.amount);
        
        
    }
    else if (account1.op == 'w' || account1.op == 'W') {
        printf("Enter amount u wish to withdraw:\n");
        scanf("%lf", &account1.amount);
        if (account1.balance < account1.amount) {
            printf("Insufficient Funds\n");
            return;
            
        }
        account1.new_balance = withdraw_balance(account1.balance,account1.amount);
        
        printf("$%.2lf",  account1.new_balance);

    }
    else {
        return;
    }

    printf("Summary:\nAccount holdername:%s\nAmount:$%.2lf\nStatus:Success\nFinal balance:$%.2lf\n", account1.name,account1.amount,account1.new_balance);
    return;


    
    
    
}


int main () {
    run_code();
    return 0;
}

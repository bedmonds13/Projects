#include "Account.h"

Account::Account(){
    account_number = 0;
    pin = 0;
    balance =0;
}
Account::Account(int acno, int pin){
    account_number =acno;
    this->pin = pin;
    balance =0;
}
Account::Account(int acno, int pin, int balance){
    account_number = acno;
    this-> pin = pin;
    this->balance = balance;
}
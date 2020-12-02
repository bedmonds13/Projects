#include <string>
using namespace std;
class Account{
    
    public:
        Account();
        Account(int acno, int pin);
        Account(int acno, int pin, int balance);
        

        int get_acno() { return account_number;}
        int get_password(){return pin;}
        
        double get_balance(){return balance;}

        void deposit();
        void withdraw();
        void create_account();

    private:
        int account_number;
        int pin;
        int balance;
        
        

};
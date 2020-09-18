#include <string>
using namespace std;
class Account{
    int account_number;
    int pin;
    double account_balance = 0;
    
    public:
        double get_balance(){return account_balance;}
        void deposit();
        void withdraw();
        int get_acno() { return account_number;}
        int get_password(){return pin;}

        void create_account();
        //Account find_account(char passsword);
       

};
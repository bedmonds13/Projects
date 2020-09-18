#include <fstream>
#include <iostream>
#include "Account.h"
using namespace std;

//ceate new instance of account to be saved
void Account::create_account(){
    cout << "What is your new account number? " ;
    cin >>account_number;
    cout << endl;

    cout << "Password: ";
    cin >> pin;
    cout << endl;

     cout << "What is your starting balance?" ;
     cin >> account_balance;
     cout << endl;
}

void Account::deposit()
{
    //Prompt user and receive for deposit input
    double new_deposit;
    cout << "How much would you like to deposit into your account? " << endl;
    cin >> new_deposit;
    account_balance += new_deposit;
    cout << "You added $" << new_deposit << ". Your new balance is: $" << account_balance;


}
void Account::withdraw()
{
    double new_withdrawal;
    cout << "How much would you like to withdraw from your account? ";
    cin >> new_withdrawal;
    cout << endl;

    

    account_balance -= new_withdrawal;
    cout <<"You withdrew $" << new_withdrawal << ". Your new balance is $" <<account_balance;
    cout << endl;
}
//Functions to navigate/ mannipuilate files
void write_account(){
    //create account instance
    Account new_account;
    new_account.create_account();
    
    ofstream stream;
    stream.open("DataBase.dat", ios::out| ios::binary | ios::app);
    if(!stream.is_open())
    {
        cout << "File does not exist"; 
    }
    stream.write(reinterpret_cast<char*> (&new_account), sizeof(Account));

    //Print credentials for user
    cout << "Account Number: "<< new_account.get_acno() << "Account Password: "<< new_account.get_password() <<" Balance: " << new_account.get_balance() << endl;
    stream.close();
}

    






int find_account(int acno ,int password, Account &account)
{
    ifstream stream;
    Account new_account;
    stream.open("DataBase.dat",  ios::binary);
    if(!stream)
    {
        cout << "File does not exist." << endl; 
    }
  
    bool found_account = false;
 
        while(stream.read((char*)&new_account, sizeof(Account))){
               
            if(new_account.get_acno() == acno && new_account.get_password() == password)
            {
               cout << "Balance:" <<new_account.get_balance() << endl;
                cout << "Found account " << new_account.get_acno() << endl;
                account = new_account;
                stream.close();
                found_account = true;
                return 1;
                }
               
        }
        cout << "Account doesnt exist" << endl;
        stream.close();
        return -1;
    
}

int main(){


    //create user verification. Password and account number

    cout << "Hello. In order to access your account you must confirm your credentials" << endl;


    int account_number, number_check, password;
    bool logged_in = false;
    Account current_account;    
    bool intro_passed = false, login = false, signup = false;
    do
    {
        cout  << "/*/*/*/*/ 1: Log in   /*/*/*/*/" << endl;
        cout  << "/*/*/*/*/ 2: Sign up  /*/*/*/*/" << endl;

        int input;
        cin >> input;
        switch (input)
        {
        case 1:
            //Login
            login = true;
            intro_passed =true;
            break;
        case 2:
            //Sign up
            signup = true;
            intro_passed =true;
            break;
        default:
            break;
        }
    } while (!intro_passed);

    if(signup)
    {
        
        write_account();
    }

    if(login){
        do{
            cout << "What is your account number?" << endl;
            cin >> account_number;  
    
            cout << "Password: " << endl;
        
            cin >> password;

            // Search for stored user 
            if(find_account(account_number, password, current_account) == 1)
            {
                    cout << "Logged in!" << endl;
                    logged_in = true;
            }
            else{
                cout << "Not logged in." << endl;
            }
        }while(!logged_in);
    }

    if(logged_in){
        do{
            cout << "What would you like to do with your account?" << endl;

            cout << "/*/*/*/*/ 1: Balance               /*/*/*/*/ " << endl;
            cout << "/*/*/*/*/ 2: Make Deposit          /*/*/*/*/ " << endl;
            cout << "/*/*/*/*/ 3: Make Withdrawal       /*/*/*/*/ " << endl;
            cout << "/*/*/*/*/ ESC: Log out             /*/*/*/*/ " << endl;
            
            
            int input;
            cin >> input;
            switch (input)
            {
            case 1:
                cout << current_account.get_balance();
                //Check balance
                //cout << "Your currrent balance is: $" << current_account.get_balance() << endl;
                break;
            case 2:
                cout << 2;
                current_account.deposit();
                break;
                
            case 3:
                cout << 3;
                current_account.withdraw();
                break;
            case 4:
            cout << "Good bye!" << endl;
            logged_in = false;
            
            break;
            default:
                cout << "Not a valid input" << endl;
                break;
            }
        }while(logged_in);
    }
   
    return 0;
}



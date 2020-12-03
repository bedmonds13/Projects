#include <fstream>
#include <iostream>
#include <sstream>
#include <iomanip>
#include "Account.h"

using namespace std;  

const int ACCOUNT_NUMBER_SIZE = 10;
const int PIN_SIZE = 5;
const int ACCOUNT_BALANCE_SIZE = 10;
const int NEW_LINE_SIZE = 2;
const int RECORD_SIZE =  ACCOUNT_NUMBER_SIZE + PIN_SIZE + ACCOUNT_BALANCE_SIZE+NEW_LINE_SIZE;

bool find_account(int acno ,int password,int account_size, istream& stream)
{
    Account new_account;
    
    if(stream.fail())
    {
        cout << "File does not exist. \n"; 
        exit(1);
    }
    else
    {
        stream.seekg(0, ios::end);
        int nrecords = stream.tellg() / RECORD_SIZE;
        int current_record = 0;
        cout << "There are currently " << nrecords<< " many records \n";    
        stream.seekg(RECORD_SIZE * current_record, ios::beg);
        while(current_record < nrecords + 1)
        {
            string line = "";
            if( getline(stream,line) )
            {
                string current_acno = line.substr(0, 9);
                string current_pin = line.substr(10,14);

                int x,y;

                stringstream account_string(current_acno);
                stringstream pin_string(current_pin);
                
                account_string >> x;
                pin_string >> y;
            
                if(acno == x && password == y)
                {
                    return true;
                }
            }

            current_record++;
        }
        return false;
    }
}
void write_account(int acno, int password, int balance, ostream& stream)
{
    stream.seekp(0, ios::end);  

    stream <<left  << setw(ACCOUNT_NUMBER_SIZE) <<acno 
                << setw(PIN_SIZE)
                << password 
                << setw(ACCOUNT_BALANCE_SIZE) << balance << "\n";
    
}

Account get_account(int acno, istream& stream)
{
    Account account;
    if(stream.fail())
    {
        exit(1);   
    }
    else 
    {
        stream.seekg(0 , ios::end);
        int current_record = 0;
        int nrecords =  stream.tellg()/RECORD_SIZE;

        stream.seekg(0, ios::beg);
        while(current_record < nrecords + 1)
        {
            stream.seekg(current_record * RECORD_SIZE, ios::beg);

            string line;
            getline(stream, line);
            
            string account_string = line.substr(0,9);
            stringstream next_account(account_string);
            
            int nextaccount;
            next_account >> nextaccount;
          
            if(acno == nextaccount)
            {
                string pin_string = line.substr(10, 14); 
                string balance_string = line.substr(14,24);
                
                stringstream pin_convert(pin_string);
                stringstream balance_convert(balance_string);
                int password = 0;
                int balance = 0;

                pin_convert >> password;
                balance_convert >>  balance;
                return  Account(acno, password, balance); 
            }
            current_record++;
        }
        cout << "Account not found. \n";
        exit(1);
    } 
}
void deposit(Account& account)
{
    cout << "How much would you like to deposit? \n";
    int deposit;
    cin >> deposit;
    account.deposit(deposit);
    cout << "New balance : $" << account.get_balance() << "\n";
}
void withdraw(Account& account)
{
    cout << "How much would you like to withdraw? \n";
    int withdrawal;
    cin >> withdrawal;
    account.withdraw(withdrawal);
    cout << "New balance : $" << account.get_balance() << "\n";
}
void overwrite_account(Account account)
{
    ifstream fileIn;
    ofstream fileOut;
    fileIn.open("data.txt");

    fileOut.open("temp.txt");

    fileIn.seekg(0, ios::end);

    int current_record = 0;
    int nrecords = fileIn.tellg() / RECORD_SIZE;

   fileIn.seekg(0, ios::beg);
   string line;

    while (current_record < nrecords )
    {
        fileIn.seekg(RECORD_SIZE * current_record, ios::beg);
        getline(fileIn, line);

        string account_string = line.substr(0, 9);
        stringstream next_account(account_string);

        int nextaccount;
        next_account >> nextaccount;

        if (account.get_acno() == nextaccount)
        {
            cout << "Found account. Now writing to database";
            fileOut << left << setw(ACCOUNT_NUMBER_SIZE) << account.get_acno()
                << setw(PIN_SIZE)
                << account.get_password()
                << setw(ACCOUNT_BALANCE_SIZE) << account.get_balance() << "\n";
        }
        else
        {
            fileOut << line << "\n";
        }
        current_record++;
    }
    
    fileIn.close();
    fileOut.close();

    fileIn.open("temp.txt");
    fileOut.open("data.txt");
    fileIn.seekg(0, ios::end);
    current_record = 0;
    nrecords = fileIn.tellg() / RECORD_SIZE;
    fileIn.seekg(0, ios::beg);
    while (current_record < nrecords )
    {
        getline(fileIn, line);
        fileOut << line << "\n";
        current_record++;
    }
    
}
int main(){

    cout << "Hello. In order to access your account you must confirm your credentials" << endl;

    int account_number;
    int password;

    Account current_account;   
    fstream stream; 
    bool login = false, signup = false;
  
    cout  << "/*/*/*/*/ 1: Log in   /*/*/*/*/" << endl;
    cout  << "/*/*/*/*/ 2: Sign up  /*/*/*/*/" << endl;
        
        int input = 0;
        while(input != 1 && input != 2)
        {
            cin >> input;
            switch(input)
            {
                case 1:
                    login = true;
                    break;
                case 2:
                    signup = true;
                    break;
                default:
                    break;
            }
        }
        
       if(login == true)
       {
            cout << "You selected login. \n";
            cout << "Enter your account number. \n";
            int acno;
            cin >> acno;

            cout << "Enter your pin. \n";
            int pin;
            cin >> pin;

            fstream stream;      
            stream.open("data.txt",  ios::in );
            if(find_account(acno, pin, RECORD_SIZE, stream))
            {
                cout << "Acount found.\n";
                current_account = get_account(acno, stream);
                cout << "Account No: " << current_account.get_acno() 
                    << ". Current Balance is: " 
                    << current_account.get_balance() << "\n";
                stream.close();
                while (input != 0) 
                {
                    cout << "What you you like to do to with your account? \n" 
                        << "1 - Deposit \n" << "2 - Withdraw \n" << "3 - Delete Account \n"
                        << "0 - Exit \n";
                
                    cin >> input;
                    switch (input) {
                        case 1:
                            deposit(current_account);
                            overwrite_account(current_account);
                            break;
                        case 2:
                            withdraw(current_account);
                            overwrite_account(current_account);
                            break;
                        case 3:
                            break;
                        case 0:
                            break;
                        default:
                            break;

                    }
                }
            }
            else
            {
                cout << "Account not found. \n";
                stream.close();
            }
            
       }
       else if(signup == true)
       {
            cout << "You selected signup. \n";
            cout << "Enter new account number. \n";
            int acno;
            cin >> acno;

            cout << "Enter new pin. \n";
            int pin;
            cin >> pin;

            
            stream.open("data.txt", ios::out | ios::app);
            if(stream.fail())
            {
                cout << "File not found";
                exit(1);
            }
            else
            {
                cout << "What is your starting balance? :";
                int balance;
                cin >> balance;


                write_account( acno, pin, balance, stream);
            }

            stream.close();
       }
}
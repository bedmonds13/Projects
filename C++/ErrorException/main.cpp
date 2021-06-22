#include <string>
#include <iostream>
using namespace std;
class MyApplicationError
{
    string reason;
    public:
        MyApplicationError( const string& r) : reason(r) {}
        const string& what()
        {
            return reason;
        }
        
};
int main()
{
   
    try
    {
        throw MyApplicationError("Illegal value");
    }   
    catch(MyApplicationError& e)
    {
        cout << "Caught exception" << e.what() << '\n';
    } 

}
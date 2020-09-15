
using namespace std;
#include <string>
class Player{
   char mark;
    string name;
    public:
        void add_mark(char new_mark)
        {
           
            mark = new_mark;
        }

        char get_mark()
        {
            return mark;
        }
        void add_name(string new_name)
        {
            name = new_name;
        }
        string get_name()
        {
            return name; 
        }
};
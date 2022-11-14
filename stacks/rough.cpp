#include<iostream>
#include<stack>
using namespace std;


void say_hi()
{
    cout<<"hi\n";
}
class nor{
    public:
    void envoke()
    {
        say_hi();
    }
};

int main()
{
    nor n;
    n.envoke();
}

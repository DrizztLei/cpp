#include <iostream>

using namespace std;

template<typename A, typename B>
void print(const A& a,const B& b)
{
    cout << a << endl;
    cout << b << endl;
}

template<typename A>
auto reture_type(A parameter) -> decltype A
{
    return A;
}


int main(int argc, char ** argv)
{
    auto str = "auto type test";
    print(str, str);
    cout << str << endl;
}

#include<iostream>

using namespace std;

#define sp ' '

std::ostream& nl(std::ostream& os)
{
    os << '\n';
    return os;
}



int main()
{
    cout << 1 << sp << 2 << nl;
    cout << 3 << sp << 4 << sp;
    cin.get();
    cout << 5 << sp << 6 << nl;
    cin.get();
    cout << 7 << sp << 8;

    return 0;
}
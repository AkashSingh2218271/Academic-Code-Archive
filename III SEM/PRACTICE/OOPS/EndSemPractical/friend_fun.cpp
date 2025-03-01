#include <iostream>
#include <string>
using namespace std;

class OnePiece
{
    string zoro, luffy, law;

public:
    void get_data();
    void put_data();
    friend void Alliance(OnePiece obj);
};

void OnePiece::get_data()
{
    cout << "Enter the name of captian of Straw Hat priate :" << endl;
    getline(cin, luffy);
    // fflush(stdin);
    cout << "Enter the name of vice captian of Straw Hat priate :" << endl;
    getline(cin, zoro);
    // fflush(stdin);
    cout << "Enter the name of captian of Hearts priate :" << endl;
    getline(cin, law);
}

void OnePiece::put_data()
{
    cout << "Captian of Straw Hat priate is " << luffy << endl;
    cout << "Vice captian of Straw Hat priate is " << zoro << endl;
    cout << "Captian of Hearts priate is " << law << endl;
}

void Alliance(OnePiece op)
{
    cout << "Alliance between captian of Hearts priate " << op.law << " and captian of Straw Hat priate " << op.luffy << " against one of the warlord of see the DD (Joker)." << endl;
}

int main()
{
    OnePiece priate;
    priate.get_data();
    priate.put_data();
    Alliance(priate);

    return 0;
}
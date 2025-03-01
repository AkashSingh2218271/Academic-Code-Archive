#include <iostream>
using namespace std;
#include <string>
class chageWithUpcomingLetter{
    string s;
    public:
    void getdata(string str){
        s = str;
    }
    void putdata(){
        cout << "string is " << s << endl;
    }
    void changeletter(){
        for (int i = 0; i < s.length(); i++)
        {
            if(s[i] == ' ')
            continue;
            if(s[i] >= 'a' && s[i] <= 'y' || s[i] >= 'A' && s[i] <= 'Y') {
                s[i] = s[i] + 1;
            }else if(s[i] == 'z'){
                s[i] = 'a';
            }else if (s[i] == 'Z')
            {
               s[i] = 'A';
            }
        }
        
    }
};
int main(){
    string str;
    chageWithUpcomingLetter obj;
    getline(cin,str);
    obj.getdata(str);
    obj.putdata();
    obj.changeletter();
    cout << "string after change " << endl;
    obj.putdata();
    return 0;
}

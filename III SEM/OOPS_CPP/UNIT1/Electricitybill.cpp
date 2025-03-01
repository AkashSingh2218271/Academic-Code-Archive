#include <iostream>
using namespace std;
    struct Electricitybill
    {
      char name[10];
      float unit[10];
      float bill_cost[10];
    };
    struct Electricitybill n;
int main() {
    int s = 3;
    cout << "Enter names\n";
    for (int i = 0; i < s; i++)
    {
        cin >> n.name[i];
        fflush(stdin);
    }
    cout << "Enter units\n";
    for (int i = 0; i < s; i++)
    {
        cin >> n.unit[i];
        fflush(stdin);
    }
    
    for(int i = 0; i < s; i++)
    if (n.unit[i] <= 100 )
    {
        n.bill_cost[i] = n.unit[i] * (0.6) + 50;
    } else if ( n.unit[i] > 100 && n.unit[i] <= 300)
    {
        n.bill_cost[i] = n.unit[i] * (0.8) + 50;
    }else
    {
        n.bill_cost[i] = n.unit[i] * (0.9) + 50;
        n.bill_cost[i] += n.bill_cost[i] * (0.15);
    }
    
    for (int i = 0; i < s; i++)
    {
        cout << "bill of " << n.name[i] << endl;
        cout << "cost of bill is  " << n.bill_cost[i] << endl;
    }

    return 0;
}
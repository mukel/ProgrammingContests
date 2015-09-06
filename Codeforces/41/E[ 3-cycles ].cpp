#include<iostream>
using namespace std;
int main()
{
    int n, t = 0;
    cin >> n;
    
    for(int i = 1; i <= n; i++)
          t += ((i) / 2);
          
    cout << t << endl;
    
    for(int i = 1; i <= n; i++)
          for(int j = i + 1; j <= n; j += 2)
                cout << i << " " << j << endl;
//  system("pause");
    
    return 0;
}

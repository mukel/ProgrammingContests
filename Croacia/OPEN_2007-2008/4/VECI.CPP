/*
Alfonso Alfonso Peterssen
TASK: VECI
*/
#include <iostream>

using namespace std;

string st;

int main() {

    cin >> st;
    
    if ( next_permutation( st.begin(), st.end() ) )
         cout << st << endl;
    else cout << "0" << endl;

    return 0;
}

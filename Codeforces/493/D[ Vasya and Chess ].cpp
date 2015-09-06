#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int N;
    cin >> N;
    if (N % 2 == 0) cout << "white" << endl << "1 2" << endl;
    else
    cout << "black" << endl;
    return 0;
}
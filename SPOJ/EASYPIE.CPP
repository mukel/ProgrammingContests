/*
Alfonso Alfonso Peterssen
11 - 1 - 2008
SPOJ #82 "Easy Problem"
*/
#include <iostream>
#include <map>

using namespace std;

const int MAXP = 9;

int T, N, i;
int time_;
int attemps[MAXP];
int accepted[MAXP];
int total_time[MAXP];
char problem, answer;
string team;

int main() {

    for ( cin >> T; T; T-- ) {

        /* Init */
        fill( attemps, attemps + MAXP, 0 );
        fill( accepted, accepted + MAXP, 0 );
        fill( total_time, total_time + MAXP, 0 );
        map< string, map< char, int > > submissions;

        cin >> N;
        for ( i = 0; i < N; i++ ) {
            cin >> time_ >> team >> problem >> answer;
            problem -= 'A';
            if ( submissions[team][problem] == -1 ) continue;
            else submissions[team][problem]++;
            if ( answer == 'A' ) {
                /* Accepted */
                attemps[problem] += submissions[team][problem];
                total_time[problem] += time_;
                accepted[problem]++;
                submissions[team][problem] = -1;
            }
        }

        for ( i = 0; i < MAXP; i++ ) {
            cout << ( char )( i + 'A' ) << " " << accepted[i];
            if ( accepted[i] > 0 ) {
                cout.precision( 2 );
                cout << fixed << " "
                     << ( double )attemps[i] / accepted[i] << " "
                     << ( double )total_time[i] / accepted[i];
            }
            cout << endl;
        }
    }

    return 0;
}

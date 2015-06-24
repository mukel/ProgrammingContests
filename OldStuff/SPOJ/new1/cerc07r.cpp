/*
Alfonso2 Peterssen
SPOJ #2058 "Reaux! Sham! Beaux!"
5 - 9 - 2008
*/
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <map>

using namespace std;

#define REP( i, n ) \
	for ( int i = 0; i < (n); i++ )

int T;
int win[3][3];
map< string, int > kind;
string name1, name2;
string lang1, lang2;
string play1, play2;

int main() {

	kind["Nuzky"] = 1;
	kind["Scissors"] = 1;
	kind["Ciseaux"] = 1;
	kind["Schere"] = 1;
	kind["Ollo"] = 1;
	kind["Olloo"] = 1;
	kind["Forbice"] = 1;
	kind["Choki"] = 1;
	kind["Nozyce"] = 1;
	kind["Tijera"] = 1;
	
	kind["Papir"] = 2;
	kind["Paper"] = 2;
	kind["Feuille"] = 2;
	kind["Papier"] = 2;
	kind["Papir"] = 2;
	kind["Carta"] = 2;
	kind["Rete"] = 2;
	kind["Paa"] = 2;
	kind["Papier"] = 2;
	kind["Papel"] = 2;
	
	/*
	0 rock
	1 scissors
	2 paper
	*/
	win[0][1] = 1;
	win[1][2] = 1;
	win[2][0] = 1;

	while ( ++T ) {

		cin >> lang1 >> name1;
		cin >> lang2 >> name2;

		int score1 = 0, score2 = 0;
		for (;;) {
			cin >> play1;
			if ( play1 == "-" ) break;
			if ( play1 == "." ) break;
			cin >> play2;
			
			score1 += win[ kind[ play1 ] ][ kind[ play2 ] ];
			score2 += win[ kind[ play2 ] ][ kind[ play1 ] ];
		}
		
		cout << "Game #" << T << ":" << endl;
		
		cout << name1 << ": " << score1 << " point";
		if ( score1 != 1 ) cout << "s";
		cout << endl;

		cout << name2 << ": " << score2 << " point";
		if ( score2 != 1 ) cout << "s";
		cout << endl;
		
		if ( score1 > score2 )
		      cout << "WINNER: " << name1 << endl;
		else
		if ( score2 > score1 )
		      cout << "WINNER: " << name2 << endl;
		else
			cout << "TIED GAME" << endl;
			
		if ( play1 == "." ) break;
	}
	
	return 0;
}

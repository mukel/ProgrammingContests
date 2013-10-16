/*
Alfonso2 Peterssen(mukel)
acm.mipt.ru
MIPT #103 "Nim Game - Give Away!"
Play as you would in normal Nim, making the Nim-sum of the heap-sizes
zero, unless your move would leave only heaps of size one, {discounting
empty heaps). In this case, move so as to leave either one more or one fewer
one-heaps than the normal play move.
On other words a position with some heap of size two or more is a second
player win if and only if its Nim-sum is zero, but one in which all the heaps
are zero or one is a second player win only if its Nim-sum is one (i.e. it has
an odd number of one-heaps).
ON NUMBERS AND GAMES
J. H. CONWAY
*/
#include <cstdio>
#include <iostream>

using namespace std;

#define REP(i, n) for (int i = 0; i < (int)(n); ++i)

int nimSum;
bool anyAbove1;

int main()
{
	REP(i, 4)
	{
		int x; cin >> x;
		nimSum ^= x;
		anyAbove1 |= (x > 1);
	}
	
	bool secondWin = (anyAbove1 && !nimSum) || (!anyAbove1 && nimSum == 1);
	
	if (secondWin) printf( "Second" );
	else printf( "First" );
	
	printf( " wins.\n" );

	return 0;
}

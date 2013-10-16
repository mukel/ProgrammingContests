/*
Alfonso Alfonso Peterssen
29 - 8 - 2007
USACO 2005 JAN Bronze "Bank Balance"
*/
#include <fstream>
#include <map>
using namespace std;

#define problem "d"
#define traverse( x, it ) \
  for ( typeof( x.begin() ) it = x.begin(); it != x.end(); it++ )

int N, i, amount;
char sign;
string bitch;
map< string, int > money;

string bitches[] =
  { "Alice", "Betsy", "Corinne", "Debra" };

ifstream fin ( problem ".in" );
ofstream fout ( problem ".out" );

int main() {

  for ( i = 0; i < 4; i++ )
    money[ bitches[i] ] = 0;

  fin >> N;
  for ( i = 0; i < N; i++ ) {

    fin >> bitch >> sign >> amount;

    if ( sign == '+' )
         money[ bitch ] += amount;
    else money[ bitch ] -= amount;
  }

  traverse( money, it )
    fout << it->first << ' ' << it->second << endl;

  return 0;
}

/*
Problem 12: Bank Balance [Rob Kolstad, 2004]

Alice, Betsy, Corinne, and Debra have opened bank accounts. The
bank has kept a central ledger of their deposits (money into the
bank) and withdrawals (money out of the bank). They are good financial
citizens and never withdraw more money than they have.

Given the ledger (see format below), print the amount of money each
has in the bank after the ledger's transactions are completed. The
initial balance for each is, of course, 0. All numbers fit into 32 bit
integers.

PROBLEM NAME: bankbal

INPUT FORMAT:

* Line 1: A single integer N, the number of transactions

* Lines 2..N+1: Each line contains a single transaction with two
        fields. The first field is    the name of the person
        performing the transaction. The second field is a number: if
        positive, the number is a deposit; if negative, the number is
        a withdrawal.

SAMPLE INPUT (file bankbal.in):

6
Alice +100
Corinne +100
Betsy +200
Alice -10
Debra +10
Betsy -100

INPUT DETAILS:

Alice deposits 100; so does Corrinne. Betsy deposits 200.  Alice takes out
10; Debra puts in 10.  Betsy takes out 100. The input never contains names
other than 'Alice', 'Betsy', 'Corinne', and 'Debra'.

OUTPUT FORMAT:

* Lines 1..4: Each line tells the name and balance of one of the
        depositors. The depositors are listed in alphabetical order.

SAMPLE OUTPUT (file bankbal.out):

Alice 90
Betsy 100
Corinne 100
Debra 10
*/

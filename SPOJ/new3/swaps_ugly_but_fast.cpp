/*
Alfonso2 Peterssen
SPOJ #861 "Counting inversions"
16 - 9 - 2008
*/
#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

#define REP( i, n ) \
	for ( int i = 0; i < (n); i++ )

extern unsigned int _stklen = 20000000;

typedef long long int64;
typedef pair< int, int > par;

const int
	MAXN = 250000,
	MAXC = 50001,
	MAXNODES = 5000000,
	oo = (int)1e9;

int N, Q;
int idx[MAXN];
int value[MAXN];
int64 inversions;
int size;
struct node {
	int val, L, R, size, cant;
} T[MAXNODES];
int tree[4 * MAXN];

// for merge
par seq1[MAXC]; int cant1;
par seq2[MAXC]; int cant2;
par seq3[MAXC]; int cant3;

inline void FixSize( int x ) {
	if ( x != 0 )
		T[x].size =
			T[ T[x].L ].size +
			T[ T[x].R ].size +
			T[x].cant;
}

void Splay( int &x, int val ) {
	if ( x == 0 ) return ;
	if ( val < T[x].val ) {
		if ( T[x].L != 0 ) {
			Splay( T[x].L, val );
			int y = T[x].L;
			T[x].L = T[y].R;
			T[y].R = x;
			FixSize( x );
			FixSize( y );
			x = y;
		}
	} else
	if ( val > T[x].val ) {
		if ( T[x].R != 0 ) {
			Splay( T[x].R, val );
			int y = T[x].R;
			T[x].R = T[y].L;
			T[y].L = x;
			FixSize( x );
			FixSize( y );
			x = y;
		}
	}
}

void Insert( int& x, int val, int cant = 1 ) {

	Splay( x, val );

	if ( val != T[x].val ) {
		if ( val < T[x].val ) {
			T[size++] = (node){ val, T[x].L, x, 0, cant };
			T[x].L = 0;
		} else
		if ( val > T[x].val ) {
			T[size++] = (node){ val, x, T[x].R, 0, cant };
			T[x].R = 0;
		}
		FixSize( x );
		FixSize( size - 1 );
		x = size - 1;
	} else {
		T[x].cant += cant;
		FixSize( x );
	}
}

void Delete( int& x, int val ) {
	if ( x == 0 ) return ;
	Splay( x, val );
	if ( T[x].val == val )
		if ( T[x].cant == 1 ) {
			if ( T[x].L != 0 ) {
				int y = T[x].L;
				Splay( y, +oo );
				T[y].R = T[x].R;
				x = y;
			}
			else
			if ( T[x].R != 0 ) {
				int y = T[x].R;
				Splay( y, -oo );
				T[y].L = T[x].L;
				x = y;
			}
			else
				x = 0; // NULL
		} else
			T[x].cant--;
	FixSize( x );
}

void Delete1( int& x, int val ) {
	if ( x == 0 ) return ;
	Splay( x, val );
	if ( T[x].val == val )
		if ( T[x].cant == 1 ) {
			int y;
			if ( T[x].L == 0 )
				y = T[x].R;
			else {
				y = T[x].L;
				Splay( val, y );
				T[y].R = T[x].R;
			}
			x = y;
		} else
			T[x].cant--;
	FixSize( x );
}

int BuildTree( par seq[], int lo, int hi ) {
	if ( lo > hi ) return 0;
	int mid = ( lo + hi ) / 2;
	int id = size++;
	T[id] = (node){ seq[mid].first,
		BuildTree( seq, lo, mid - 1 ),
		BuildTree( seq, mid + 1, hi ),
		0, seq[mid].second };
	FixSize( id );
	return id;
}

void Traverse( int x, par seq[], int& cant ) {
	if ( x == 0 ) return ;
	Traverse( T[x].L, seq, cant );
	seq[cant++] = make_pair( T[x].val, T[x].cant );
	Traverse( T[x].R, seq, cant );
}

// merge a and b into x
void Merge( int& x, int a, int b ) {
	cant1 = cant2 = cant3 = 0;
	Traverse( a, seq1, cant1 );
	Traverse( b, seq2, cant2 );
	
	/*printf( "merge -> " );
	REP( i, cant1 ) printf( "%d ", seq1[i].first );
	printf( " -> ");
	REP( i, cant2 ) printf( "%d ", seq2[i].first );
	printf( "\n" );*/
	
	int lo1 = 0, lo2 = 0;
	
	int sum = 0;
	REP( i, cant1 )
		sum += seq1[i].second;
	
	while ( lo1 < cant1 || lo2 < cant2 ) {
		if ( lo1 < cant1 && lo2 < cant2 ) {
			if ( seq1[lo1].first < seq2[lo2].first ) {
      			sum -= seq1[lo1].second;
			      seq3[cant3++] = seq1[lo1], lo1++;
			}
			else
			if ( seq2[lo2].first < seq1[lo1].first ) {
				inversions += (int64)sum * seq2[lo2].second;
			      seq3[cant3++] = seq2[lo2], lo2++;
			}
			else {
      			sum -= seq1[lo1].second;
				inversions += (int64)sum * seq2[lo2].second;
			      seq3[cant3++] =
					make_pair( seq1[lo1].first, seq1[lo1].second + seq2[lo2].second );
				lo1++;
				lo2++;
			}
		}
		else
		if ( lo1 == cant1 ) {
		      seq3[cant3++] = seq2[lo2];
		      lo2++;
		} else
		if ( lo2 == cant2 ) {
     			sum -= seq1[lo1].second;
		      seq3[cant3++] = seq1[lo1];
		      lo1++;
		}
	}

	x = BuildTree( seq3, 0, cant3 - 1 );
}

int CountLessThan( int& x, int val ) {
	if ( x == 0 ) return 0;
	Splay( x, val );
	if ( T[x].val < val )
		return T[ T[x].L ].size + T[x].cant; // <
	return T[ T[x].L ].size;
}

int CountInv( int x, int val ) {
	if ( x & 1 ) {
		int cant = T[ tree[x^1] ].size;
	      return cant - CountLessThan( tree[x^1], val + 1 );
	}
	else
	      return CountLessThan( tree[x^1], val );
}

void Build( int x, int lo, int hi ) {
	if ( lo == hi ) {
		idx[lo] = x;
	      Insert( tree[x], value[lo] );
	      return ;
	}
	
	int mid = ( lo + hi ) / 2;
	Build( 2 * x, lo, mid );
	Build( 2 * x + 1, mid + 1, hi );

/*	printf( "merge %d %d\n", 2 * x, 2 * x + 1 );
	fflush( stdout );
*/
	Merge( tree[x], tree[2 * x], tree[2 * x + 1] );
}

void Update( int pos, int val ) {
	if ( value[pos] == val )
		return ;
	for ( int x = idx[pos]; x != 1; x /= 2 ) {
		inversions -= CountInv( x, value[pos] );
		inversions += CountInv( x, val );
		Delete( tree[x], value[pos] );
		Insert( tree[x], val );
	}
	value[pos] = val;
}

int main() {

	scanf( "%d", &N );
	REP( i, N )
		  scanf( "%d", &value[i] );

	T[size++] = (node){ 0, 0, 0, 0, 0 }; // Nil Node
	Build( 1, 0, N - 1 );
	
	for ( scanf( "%d", &Q ); Q--; ) {
		int pos, val;
		scanf( "%d %d", &pos, &val );
		Update( pos - 1, val );
		printf( "%lld\n", inversions );
	}

	return 0;
}

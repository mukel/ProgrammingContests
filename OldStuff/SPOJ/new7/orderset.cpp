/*
Alfonso2 Peterssen (mukel)
*/
#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <ctime>

using namespace std;

#define REP( i, n ) \
	for ( int i = 0; i < (n); i++ )

const int MAXNODES = 200000;

struct Treap {

	int root, nodes;
	struct node {
		int size, key, prior, child[2]; // 0 left, 1 right
		node() {}
		node( int key ) : size( 1 ), key( key ), prior( rand() * rand() + rand() ) {
			child[0] = 0;
			child[1] = 0;
		}
	} buff[MAXNODES];

	int size( int root ) { return buff[root].size; }
	bool empty( int root ) { return size( root ) == 0; }

	inline void update_size( int root ) {
		buff[root].size =
			buff[ buff[root].child[0] ].size +
			buff[ buff[root].child[1] ].size +
			1;
	}

	inline void rotate( int& root, int dir ) {
		int tmp = buff[root].child[dir];
		buff[root].child[dir] = buff[tmp].child[1 - dir];
		buff[tmp].child[1 - dir] = root;
		update_size( root );
		update_size( tmp );
		root = tmp;
	}

	void insert( int& root, int val ) {
		if ( root == 0 ) {
			buff[root = ++nodes] = node( val );
			return ;
		}

		if ( val != buff[root].key ) {
			bool dir = !( val < buff[root].key );
			insert( buff[root].child[dir], val );
			if ( buff[root].prior > buff[ buff[root].child[dir] ].prior )
			      rotate( root, dir );
		} else
		      return ;

		update_size( root );
	}

	void erase( int& root, int val ) {
		if ( root == 0 )
			return ;

		if ( val != buff[root].key ) {
			bool dir = !( val < buff[root].key );
			erase( buff[root].child[dir], val );
		} else {
			int L = buff[root].child[0];
			int R = buff[root].child[1];
			if ( L && R ) rotate( root, buff[L].prior > buff[R].prior );
			else if ( L ) rotate( root, 0 );
			else if ( R ) rotate( root, 1 );
			else { root = 0; return ; }
			erase( root, val );
		}

		update_size( root );
	}

	inline int countLessThan( int root, int val ) {
		int rank = 0;
		while ( root != 0 ) {
			bool dir = !( val < buff[root].key );
			if ( dir ) { // go right
			      rank += buff[ buff[root].child[0] ].size;
				if ( val <= buff[root].key )
				      return rank;
			      rank++;
			}
			root = buff[root].child[dir];
		}
		return rank;
	}

	// 0-based
	int findKth( int root, int kth ) {
		// assert( kth >= 0 && kth < size( root ) );
		while ( root != 0 ) {
			int val = buff[root].child[0];
			if ( kth < buff[val].size )
			      root = val;
			else {
				kth -= buff[val].size + 1;
				if ( kth < 0 )
					return buff[root].key;
				root = buff[root].child[1];
			}
		}
	}

} S;

int N;

/* Fast IO */
inline int next_int() {
	register int res = 0;
	register char ch;
	while ( ( ch = getc_unlocked( stdin ) ) == '\n' || ch == ' ' );
	if ( ch == '-' ) {
		while ( ( ch = getc_unlocked( stdin ) ) >= '0' ) {
			res *= 10;
			res += ( ch - '0' );
		}
		return -res;
	} else {
		do {
			res *= 10;
			res += ( ch - '0' );
		} while ( ( ch = getc_unlocked( stdin ) ) >= '0' );
		return res;
	}
}

inline char next_char() {
	register char ch;
	while ( ( ch = getc_unlocked( stdin ) ) < 'A' );
	return ch;
}

#define FAST_IO 1

int main() {

	srand( time( 0 ) );
	
	#ifdef FAST_IO
		scanf( "%d", &N );
	#else
		N = next_int();
	#endif
	REP( i, N ) {
		char op[3]; int val;
		#ifdef FAST_IO
			op[0] = next_char();
			val = next_int();
		#else
			scanf( "%s %d", &op, &val );
		#endif
		if ( op[0] == 'I' ) S.insert( S.root, val ); else
		if ( op[0] == 'D' ) S.erase( S.root, val ); else
		if ( op[0] == 'C' ) printf( "%d\n", S.countLessThan( S.root, val ) ); else
		if ( op[0] == 'K' ) {
			if ( val > S.size( S.root ) ) printf( "invalid\n" );
			else
			      printf( "%d\n", S.findKth( S.root, val - 1 ) );
		}
	}

	return 0;
}

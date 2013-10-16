/*
Alfonso2 Peterssen(mukel)
Team: UH++
Timus Online Judge
1220. Stacks
*/
#include <cstdio>
#include <stack>

const int
	MAXS = 1000,
	MAXQ = 100001;

int Q;
int ptr;
int val[MAXQ];
unsigned short int prev[MAXQ];
int top[MAXS];

int main()
{
	scanf( "%d", &Q );
	while (Q--)
	{
		char op[10]; int id;
		scanf( "%s %d", &op, &id );
		id--;
		
		if (op[1] == 'U' ) // PUSH
		{
			int x;
			scanf( "%d", &x );

			val[ptr] = x;
			prev[ptr] = ptr - top[id];
			top[id] = ptr;
			ptr++;
		}
		else
		{
			printf( "%d\n", val[ top[id] ] );
			top[id] -= prev[ top[id] ];
		}
	}

	return 0;
}

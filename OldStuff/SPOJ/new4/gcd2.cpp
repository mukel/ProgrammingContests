#import<cstdio>
#import<cstring>
int T, A, B;
int main() {
	for( scanf( "%d", &T ); T--; ) {
		char line[300];
		scanf( "%d %s", &A, &line );
		int len = strlen( line );
		if ( A == 0 ) {
			printf( "%s\n", line );
			continue;
		}
		if ( line[0] == '0' ) {
			printf( "%d\n", A );
			continue;
		}
            B = 0;
            for ( int i = 0; i < len; i++ )
			B = ( B * 10 + line[i] - '0' ) % A;
		while( A && B ) if ( B %= A ) A %= B;
		printf( "%d\n", A + B );
	}
	return 0;
}

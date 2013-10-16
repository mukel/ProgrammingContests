/*
Alfonso2
29 - 4 - 2008
TASK: TICTAC
Flujillo
*/
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

const int
    MAXC = 200,
    oo = 1000000;

int F, C, i, j, k;
int cant;
char mat[MAXC][MAXC];
int src, snk;
int from[MAXC];
int flow[MAXC];
int cap[MAXC][MAXC];
int flw[MAXC][MAXC];
vector< int > G[MAXC];

void add_edge( int s, int t, int c ) {
    G[s].push_back( t );
    G[t].push_back( s );
    cap[s][t] = c;
    flw[s][t] = c;
}

bool augment( int src, int snk ) {
    
    memset( from, 0, sizeof( from ) );
    memset( flow, 0, sizeof( flow ) );        
    
    from[src] = -1;              
    flow[src] = oo;            
    queue< int > Q;
    bool found = false;    
    
    /* BFS */
    Q.push( src );
    while ( !Q.empty() ) {
        int x = Q.front();
        Q.pop();
        for ( int i = 0; i < G[x].size(); i++ ) {
            int y = G[x][i];
            if ( !from[y] && cap[x][y] > 0 ) {
                flow[y] = min( flow[x], cap[x][y] );
                from[y] = x;
                if ( y == snk ) {
                    found = true;
                    break;    
                }
                Q.push( y );
            }
        }
        if ( found )
            break;        
    }
    
    if ( flow[snk] == 0 )
        return false;
    
    /* Reflow */
    for ( int i = snk; i != src; i = from[i] ) {
        int y = from[i];
        cap[y][i] -= flow[snk];
        cap[i][y] += flow[snk];
    }
    
    return true;    
}

int main() {
    
    #warning READ FROM FILES!!!
    freopen( "tictac.in", "r", stdin );
    freopen( "tictac.out", "w", stdout );    

    scanf( "%d %d", &F, &C );
    for ( i = 1; i <= F; i++ )
        scanf( "%s", mat[i] + 1 );
        
    src = F + C + 1;
    snk = F + C + 2;        

    /* setup rows */
    for ( i = 1; i <= F; i++ ) {
        cant = 0;
        for ( j = 1; j <= C; j++ ) {
            if ( mat[i][j] == '+' )
                cant--;
            if ( mat[i][j] == '-' )
                cant++;                
            if ( mat[i][j] == '?' ) {
                cant++;
                add_edge( i, F + j, 1 );
            }
        }        
        /* set capacity */
        add_edge( src, i, cant / 2 );
    }
    
    /* setup cols */
    for ( j = 1; j <= C; j++ ) {
        cant = 0;
        for ( i = 1; i <= F; i++ ) {
            if ( mat[i][j] == '+' )
                cant--;
            if ( mat[i][j] == '-' )
                cant++;  
            if ( mat[i][j] == '?' )
                cant++;
        }        
        /* set capacity */
        add_edge( F + j, snk, cant / 2 );
    }
    
    while ( augment( src, snk ) );
    
    /* Rebuild */
    for ( i = 1; i <= F; i++ )
        for ( j = 1; j <= C; j++ )
            if ( cap[i][j + F] < flw[i][j + F] )    
                mat[i][j] = '+';
                
    for ( i = 1; i <= F; i++ )
        for ( j = 1; j <= C; j++ )
            if ( mat[i][j] == '?' )                
                mat[i][j] = '-';
        
    for ( i = 1; i <= F; i++ )
        printf( "%s\n", mat[i] + 1 );
    
    fflush( stdout );
    
    return 0;   
}

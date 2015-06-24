(*
Alfonso Alfonso Peterssen
28 - 2 - 2008
POI 2002 Stage I "Island"
*)
{$B-,Q-,I-,R-,S-}
const
    MAXN = 50000;
var
    n, i, j, sol : longint;
    dist         : array[0..MAXN] of longint;

    function cost( i, j : longint) : longint;
    var k : longint;
    begin
        k := dist[j] - dist[i];
        if dist[n] < 2 * k
            then k := dist[n] - k;
        cost := k;
    end; { dist }

begin

    read( n );
    for i := 1 to n do begin
        read( dist[i] );
        dist[i] := dist[i] + dist[i - 1];
    end; { for }

    i := 0;
    j := 1;
    repeat
        while ( j <= n ) and ( cost( i, j + 1 ) > cost( i, j ) )
            do inc( j );
        if cost( i, j ) > sol then
            sol := cost( i, j );
        inc( i );
    until j >= n;

    writeln( sol );

end. { main }

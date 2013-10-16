(*
Alfonso2 Peterssen
13 - 6 - 2008
IOI 2004 "Hermes"
*)
const
    MAXN = 20000;
    MAXC = 1000;
var
    N, sol     : longint;
    a, b, i, j : longint;
    x, y       : array[0..MAXN] of longint;
    dpX, dpY   : array[0..1,-MAXC..MAXC] of longint;

function min( a, b : longint ) : longint; inline;
begin
    if a <= b then exit( a );
    exit( b );
end; { min }

function abs( x : longint ) : longint; inline;
begin
    if x < 0 then exit( -x );
    exit( x );
end; { abs }

begin

    readln( N );
    for i := 1 to N do
        readln( x[i], y[i] );

    for i := -MAXC to MAXC do begin
        dpX[a][i] := abs( i );
        dpY[a][i] := abs( i );
    end; { for }

    for i := 1 to N do begin
        b := a;
        a := 1 - a;
        for j := -MAXC to MAXC do begin
            dpX[a][j] := min( dpX[b][j] + abs( x[i] - x[i - 1] ),
                              dpY[b][ x[i] ] + abs( j - y[i - 1] ) );
            dpY[a][j] := min( dpY[b][j] + abs( y[i] - y[i - 1] ),
                              dpX[b][ y[i] ] + abs( j - x[i - 1] ) );
        end; { for }
    end; { for }

    sol := MaxLongint;
    for i := 0 to N do
        sol := min( sol, min( dpX[a][ y[i] ], dpY[a][ x[i] ] ) );

    writeln( sol );

end. { main }
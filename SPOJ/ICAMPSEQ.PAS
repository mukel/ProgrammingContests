(*
Alfonso Alfonso Peterssen
1 - 3 - 2008
SPOJ #1784 "IOICamp Sequence"
*)
const
    MAXN = 100000;
var
    n, i, j : longint;
    sol : double;
    sum : array[1..MAXN] of double;
    ls  : array[1..MAXN,1..4] of double;

    procedure check();
    var i, a, b : longint;
    begin
        a := 1;
        b := 1;
        for i := 2 to n do begin
            if sum[i] < sum[a] then a := i;
            if sum[i] > sum[b] then b := i;
        end; { for }
        if sum[b] - sum[a] > sol then
            sol := sum[b] - sum[a];
    end; { check }

    procedure turn_on( id : longint );
    var i : longint;
    begin
        for i := 1 to n do
            sum[i] := sum[i] + 2 * ls[i][id];
    end; { turn_on }

    procedure turn_off( id : longint );
    var i : longint;
    begin
        for i := 1 to n do
            sum[i] := sum[i] - 2 * ls[i][id];
    end; { turn_off }

begin

    assign( input, '' );
    reset( input );

    read( n );
    for i := 1 to n do
        for j := 1 to 4 do
            read( ls[i][j] );

    {++++}
    for i := 1 to n do
        for j := 1 to 4 do
            sum[i] := sum[i] + ls[i][j];

    check();

    {+++-} turn_off( 4 ); check();
    {++--} turn_off( 3 ); check();
    {+---} turn_off( 2 ); check();
    {+--+} turn_on( 4 );  check();
    {+-++} turn_on( 3 );  check();
    {+-+-} turn_off( 4 ); check();

    {++-+}
    turn_on( 2 );
    turn_on( 4 );
    turn_off( 3 );
    check();

    writeln( sol:0:3 );

end. { main }


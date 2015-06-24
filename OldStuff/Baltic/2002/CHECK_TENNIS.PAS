(*
Alfonso Alfonso Peterssen
17 - 3 - 2008
Baltic 2002 Task "Tennis"
check <input> <output>
*)
const
    MAXN = 1000;
var
    fin, fout : text;
    st        : string;
    n, i, j   : longint;
    games     : array[1..MAXN] of longint;
    mark      : array[1..MAXN,1..MAXN] of longint;

begin

    assign( fin,  paramstr( 1 ) ); reset( fin );
    assign( fout, paramstr( 2 ) ); reset( fout );

    readln( fout, st );
    writeln( st );
    if st = 'NO SCHEDULE' then
        halt( 0 );

    read( fin, n );
    for i := 1 to n do
        read( fin, games[i] );

    for i := 1 to n do begin
        while not seekeoln( fout ) do begin
            read( fout, j );
            if mark[i][j] = 2 then begin
                writeln( 'Error!!! Players plays more than once' );
                halt( 0 );
            end; { then }
            inc( mark[i][j] );
            inc( mark[j][i] );
            dec( games[i] );
        end; { while }
        readln( fout );
        if games[i] <> 0 then begin
            writeln( 'Error!!! Wrong number of games' );
            halt( 0 );
        end; { then }
    end; { for }

    writeln( 'OK!!!' );

end. { main }

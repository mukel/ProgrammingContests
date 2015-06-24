(*
Alfonso Alfonso Peterssen
11 - 12 - 2007
Task: SPL
Lang: Pascal
*)
const
    problem = 'SPL';
    MAXN = 150;
var
    N, i, j, k : longint;
    st : string;
    dp, last : array[0..MAXN, 0..MAXN] of byte;

    procedure print( lo, hi : longint );
    begin

        if lo = hi then write( st[lo] );
        if lo >= hi then exit;

        if last[lo][hi] = 0 then
        begin
            print( lo, lo );
            print( lo + 1, hi - 1 );
            print( hi, hi );
        end { then }
        else
            if last[lo][hi] = 1 then
                 print( lo + 1, hi )
            else print( lo, hi - 1 );

    end; { print }

begin

    assign( input, problem + '.in' );   reset( input );
    assign( output, problem + '.out' ); rewrite( output );

    readln( st );
    N := byte( st[0] );

    (* Init *)
    for i := 1 to N do
        dp[i][i] := 1;

    (* DP *)
    for k := 1 to N - 1 do
        for i := 1 to N - k do begin
            j := i + k;
            if st[i] = st[j] then
                dp[i][j] := dp[i + 1][j - 1] + 2
            else begin
                last[i][j] := 1;
                dp[i][j] := dp[i + 1][j];
                if dp[i][j - 1] > dp[i][j] then
                begin
                    last[i][j] := 2;
                    dp[i][j] := dp[i][j - 1];
                end { then }
            end; { else }
        end; { for }

    writeln( dp[1][N] );
    print( 1, N );
    writeln;

    flush( output );

end. { main }

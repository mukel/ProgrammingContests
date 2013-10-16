(*
Alfonso Alfonso Peterssen
30 - 11 - 2007
SPOJ #676 "Sorting is not easy"
*)
{$B-,I-,Q-,R-,S-}
const
    MAXN = 1000;
var
    T, N, i, j, k : longint;
    costi, costj  : longint;
    seq, pos      : array[0..MAXN] of longint;
    dp, less      : array[0..MAXN,0..MAXN] of longint;

    function min( a, b : longint ) : longint;
    begin
        if a < b then min := a
        else min := b;
    end; { min }

begin

    readln( T );
    for T := 1 to T do
    begin

        readln( N );
        for i := 1 to N do begin
            read( seq[i] );
            pos[ seq[i] ] := i;
        end; { for }

        (* Init *)
        fillchar( less, sizeof( less ), 0 );
        for i := 1 to N do begin
            for j := 1 to i do
                inc( less[i][ seq[j] ] );
            for j := 1 to N do
                inc( less[i, j], less[i][j - 1] );
        end; { for }

        (* DP *)
        for k := 0 to N - 1 do
            for i := 1 to N - k do begin

                j := i + k;

                costi := pos[i] - less[ pos[i] - 1 ][j]     + less[ pos[i] - 1 ][i];
                costj := pos[j] - less[ pos[j] - 1 ][j - 1] + less[ pos[j] - 1 ][i - 1];
                costi := costi * ( k + 1 );
                costj := costj * ( k + 1 );

                dp[i][j] := min( dp[i + 1][j] + costi,
                                 dp[i][j - 1] + costj );
            end; { for }

        writeln( dp[1, N] );

    end; { for }

end. { main }

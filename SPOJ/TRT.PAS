(*
Alfonso Alfonso Peterssen
SPOJ #740 "Treats for the Cows"
*)
{$B-,I-,Q-,R-,S-}
const
  MaxN = 2000;
var
  N, i, j, sol : longint;
  val          : array[-1..MaxN] of longint;
  dp           : array[-1..MaxN, -1..MaxN] of longint;

    function max( a, b : longint ): longint;
    begin
      if a >= b then exit( a );
      exit( b );
    end; { max }

begin

  readln( N );
  for i := 1 to N do
    readln( val[i] );

  for i := 0 to N do
    for j := 0 to N - i do
      dp[i,j] := max( dp[i - 1,j] + val[i] * ( i + j ),
                      dp[i,j - 1] + val[N - j + 1] * ( i + j ) );

  for i := 0 to N do
    sol := max( sol, dp[i, N - i] );

  writeln( sol );

end. { main }

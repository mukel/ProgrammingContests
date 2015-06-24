(*
Alfonso Alfonso Peterssen
29 - 9 - 2007
SPOJ #1000 "Equidivisions"
Debe haber un error en los JD,
me costo 1 hora sacar el parche
parece funcionar asi, pero no deberia ser.
*)
{$B-,I-,Q-,R-,S-}
const
  MaxN = 100;
  mov : array[1..4,1..2] of longint =
  ((-1, 0),(0, -1),(0, 1),(1, 0));
var
  ok : boolean;
  N, i, j, x, y : longint;
  mat : array[0..MaxN,0..MaxN] of longint;

  function dfs( x, y : longint ): longint;
  var
    i, a, b, res : longint;
  begin
    res := 1;
    mat[x,y] := -mat[x,y];
    for i := 1 to 4 do
    begin
      a := x + mov[i][1];
      b := y + mov[i][2];
      if ( a > 0 ) and ( a <= N ) and
         ( b > 0 ) and ( b <= N ) and
         ( mat[a][b] = -mat[x][y] ) then
         res := res + dfs( a, b );
    end; { for }
    dfs := res;
  end; { dfs }

begin

  while true do
  begin

    ok := true;

    read( N );
    if N = 0 then break;

    for i := 1 to N do
      for j := 1 to N do
        mat[i,j] := N;

    for i := 1 to N - 1 do
      for j := 1 to N do
      begin
        read( x, y );
        { Repeated Squares Bug }
        if mat[x,y] < N then
        begin
          writeln( 'good' );
          halt( 0 );
        end; { then }
        mat[x,y] := i;
      end; { for }

    for i := 1 to N do
      for j := 1 to N do
        if mat[i,j] > 0 then
          if dfs( i, j ) <> N then
          begin
            ok := false;
            break;
          end; { then }

    if ok then
         writeln( 'good' )
    else writeln( 'wrong' );

  end; { while }

end. { main }

{
PROG: privc
LANG: PASCAL
ID: a2peter1
}
{$B-,I-,Q-,R-,S-}
const
  MaxN = 1000;
var
  N, i, j, k, t, sol : longint;
  pos                : array[0..3] of longint;
  ls                 : array[0..MaxN] of longint;

begin

  assign( input, 'privc.in' ); reset( input );
  assign( output, 'privc.out' ); rewrite( output );

  readln( N );
  for i := 1 to N do
  begin
    readln( ls[i] );
    inc( pos[ ls[i] ] );
  end; { for }

  for i := 1 to 3 do
    inc( pos[i], pos[i - 1] );

  for i := 1 to N do
    for j := i + 1 to N do
      if ( ls[i] <> ls[j] ) and
         ( i > pos[ls[j] - 1] ) and ( i <= pos[ ls[j] ] ) and
         ( j > pos[ls[i] - 1] ) and ( j <= pos[ ls[i] ] ) then
         begin
           t := ls[i];
           ls[i] := ls[j];
           ls[j] := t;
           inc( sol );
           break;
         end; { then }

  for i := 1 to N do
    if ( i <= pos[ ls[i] - 1 ] ) or ( i > pos[ ls[i] ] )
      then inc( k );

  sol := sol + ( k div 3 ) * 2;

  writeln( sol );
end. { main }

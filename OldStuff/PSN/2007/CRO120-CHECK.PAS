(*
Alfonso Alfonso Peterssen
8 - 7 - 2007
PSN 2007 #120 "Is This Integration?"
Este programa revisa como deberia ser,
con un margen de error.
Sintaxis:
  check < OK_OUTPUT > < YOUR_OUTPUT >
*)
const
  OFFSET = 0.001 + 1e-6;
var
  f1, f2 : text;
  x, y   : double;

  procedure Error();
  begin
    writeln( 'Error!!! -> files are distinct.' );
    halt;
  end; { Error }

begin
  assign( f1, paramstr( 1 ) ); reset( f1 );
  assign( f2, paramstr( 2 ) ); reset( f2 );

  repeat
    read( f1, x ); read( f2, y );
    if abs( x - y ) > OFFSET then Error();
  until seekeof( f1 ) or seekeof( f2 );

  if seekeof( f1 ) and seekeof( f2 )
    then writeln( 'Ok!!! -> files are equal.' )
    else Error();

end.{main}

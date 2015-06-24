{
Alfonso Alfonso Peterssen
21 - 10 - 2007
SPOJ #108 "Decoding Morse Sequences"
}
{$B-,I-,Q-,R-,S-}
const
  MaxN = 10000;
  MaxW = 10000;
  MaxLen = 20;
  code : array['A'..'Z'] of string =
  ('.-','-...','-.-.','-..','.','..-.',
   '--.','....','..','.---','-.-','.-..',
   '--','-.','---','.--.','--.-','.-.','...',
   '-','..-','...-','.--','-..-','-.--','--..');

type
  node = record
    cant : longint;
    next : array['-'..'.'] of longint;
  end; { node }

var
  T, N, W, S,
  i, j, k, len : longint;
  st, tmp      : string;
  seq          : array[0..MaxN] of char;
  dp           : array[0..MaxN] of longint;
  ls           : array[0..4 * MaxLen * MaxW] of node;

begin

  readln( T );
  for T := 1 to T do
  begin

    (* Init *)
    S := 0;
    fillchar( ls[0], sizeof( node ), 0 );
    fillchar( dp, sizeof( dp ), 0 );

    N := 0;
    while not seekeoln do
    begin
      inc( N );
      read( seq[N] );
    end; { while }

    readln( W );
    for i := 1 to W do
    begin
      readln( tmp );
      len := byte( tmp[0] );

      st := '';
      for j := 1 to len do
        st := st + code[ tmp[j] ];

      k := 0;
      len := byte( st[0] );
      for j := 1 to len do
      begin
        if ls[k].next[ st[j] ] = 0 then
        begin
          inc( S );
          fillchar( ls[S], sizeof( node ), 0 );
          ls[k].next[ st[j] ] := S;
        end; { then }
        k := ls[k].next[ st[j] ];
      end; { for }

      inc( ls[k].cant );

    end; { for }

    dp[0] := 1;
    for i := 1 to N do
      if dp[i - 1] > 0 then
      begin
        j := i; k := 0;
        while ( j <= N ) and ( ls[k].next[ seq[j] ] > 0 ) do
        begin
          k := ls[k].next[ seq[j] ];
          if ls[k].cant > 0 then
            dp[j] := dp[j] + ( dp[i - 1] * ls[k].cant );
          inc( j );
        end;{ while}
      end; { for }

    writeln( dp[N] );
  end; { for }

end. { main }
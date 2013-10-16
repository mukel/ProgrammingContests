{
ID: a2peter1
PROG: zerosum
LANG: PASCAL
}
{$B-,I-,Q-,R-,S-}
const
  problem = 'zerosum';
  sign = ' +-';
var
  op      : char;
  st      : string;
  N       : longint;

    function eval: longint;
    var i,A,B : longint;
    begin
      i := 1; A := 0; op := '+';
      repeat
        B := 0;
        repeat
          if st[i] <> ' '
            then B := B * 10 + (i div 2 + 1);
          inc(i);
        until (i >= N) or (st[i] in ['+','-']);
        if op = '+'
          then A := A + B
          else A := A - B;
        op := st[i];
        inc(i);
      until i >= N;
      eval := A;
    end;{eval}

    procedure find(i: longint);
    var j : longint;
    begin
      if i = N then
      begin
        if eval = 0 then writeln(st);
        exit;
      end;{then}
      for j := 1 to 3 do
      begin
        st[i] := sign[j];
        find(i + 2);
      end;{for}
    end;{find}

begin
  assign(input,problem + '.in'); reset(input);
  assign(output,problem + '.out'); rewrite(output);

  readln(N);

  N := 2 * N;
  st := '1 2 3 4 5 6 7 8 9';
  byte(st[0]) := N - 1;
  find(2);

  close(output);
end.{main}
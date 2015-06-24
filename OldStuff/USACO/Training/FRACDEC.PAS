{
ID: a2peter1
PROG: fracdec
LANG: PASCAL
}
{$B-,I-,Q-,R-,S-}
const
  problem = 'fracdec';
  MaxA = 100000;
var
  A,B,r       : longint;
  st,t        : string;
  len         : byte absolute st;
  pos         : array[0..MaxA] of longint;

begin
  assign(input,problem + '.in'); reset(input);
  assign(output,problem + '.out'); rewrite(output);

  readln(A,B);

  str(A div B,st); st := st + '.';
  r := A mod B; A := r * 10;
  repeat
    pos[r] := len + 1;
    str(A div B,t); st := st + t;
    r := A mod B; A := r * 10;
  until (r = 0) or (pos[r] <> 0);

  if r <> 0 then
  begin
    insert('(',st,pos[r]);
    st := st + ')';
  end;{then}

  writeln(st);

  close(output);
end.{main}

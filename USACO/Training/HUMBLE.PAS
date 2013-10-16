{
ID: a2peter1
PROG: humble
LANG: PASCAL
}
{$B-,I-,Q-,R-,S-}
const
  problem = 'humble';
  MaxN = 100;
  MaxM = 100000;
  oo = 1 shl 29;
var
  N,M,i,j,k,h    : longint;
  ls             : array[0..MaxM] of qword;
  last,prime     : array[0..MaxN] of longint;

begin
  assign(input,problem + '.in'); reset(input);
  assign(output,problem + '.out'); rewrite(output);

  readln(N,M);
  for i := 1 to N do read(prime[i]);

  ls[0] := 1;
  for i := 1 to M do
  begin
    ls[i] := oo;
    for j := 1 to N do
    begin
      h := ls[last[j]] * prime[j];
      if h = ls[i - 1] then
      begin
        inc(last[j]);
        h := ls[last[j]] * prime[j];
      end;{then}
      if h < ls[i] then
      begin
        ls[i] := h;
        k := j;
      end;{then}
    end;{for}
    inc(last[k]);
  end;{for}

  writeln(ls[M]);

  close(output);
end.{main}

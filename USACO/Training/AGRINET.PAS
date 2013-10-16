{
ID: a2peter1
PROG: agrinet
LANG: PASCAL
}
{$B-,I-,Q-,R-,S-}
const
  problem = 'agrinet';
  MaxN = 100;
  oo = 1 shl 29;
var
  N,i,j,k,sol   : longint;
  mark          : array[0..MaxN] of boolean;
  d             : array[0..MaxN] of longint;
  C             : array[0..MaxN,0..MaxN] of longint;

begin
  assign(input,problem + '.in'); reset(input);
  assign(output,problem + '.out'); rewrite(output);

  readln(N);
  for i := 1 to N do
    for j := 1 to N do read(C[i,j]);

  d[0] := oo;
  mark[1] := true;
  for i := 1 to N do d[i] := C[1,i];
  for i := 1 to N - 1 do
  begin
    k := 0;
    for j := 2 to N do
      if (not mark[j]) and (d[j] < d[k]) then k := j;
    inc(sol,d[k]);
    mark[k] := true;
    for j := 2 to N do
      if (not mark[j]) and (C[k,j] < d[j])
        then d[j] := C[k,j];
  end;{for}

  writeln(sol);

  close(output);
end.{main}
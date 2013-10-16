{
ID: a2peter1
PROG: ariprog
LANG: PASCAL
}
{$B-,I-,Q-,R-,S-}
const
  problem = 'ariprog';
  MaxB = 125000;
var
  N,M,S,i,j,k,
  t,cant         : longint;
  mark           : array[0..MaxB] of boolean;
  list           : array[0..MaxB] of longint;

begin
  assign(input,problem + '.in'); reset(input);
  assign(output,problem + '.out'); rewrite(output);

  readln(N); readln(M);

  for i := 0 to M do
    for j := i to M
      do mark[sqr(i) + sqr(j)] := true;

  M := 2 * sqr(M);
  for i := 0 to M do
    if mark[i] then
    begin
      inc(S); list[S] := i;
    end;{then}

  for i := 1 to M div (N - 1) do
    for j := 1 to S do
    begin
      t := list[j]; k := 0;
      if t + (N - 1) * i > M then break;
      repeat
        inc(t,i); inc(k);
      until (not mark[t]) or (k = N);
      if k < N then continue;
      inc(cant);
      writeln(list[j],' ',i);
    end;{for}

  if cant = 0 then writeln('NONE');

  close(output);
end.{main}

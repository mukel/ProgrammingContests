{
ID: a2peter1
PROG: money
LANG: PASCAL
}
{$B-,I-,Q-,R-,S-}
const
  problem = 'money';
  MaxN = 25;
  MaxM = 10000;
var
  N,M,i,j   : longint;
  C         : array[0..MaxM] of int64;
  coin      : array[0..MaxN] of longint;

begin
  assign(input,problem + '.in'); reset(input);
  assign(output,problem + '.out'); rewrite(output);

  readln(N,M);
  for i := 1 to N
    do read(coin[i]);

  C[0] := 1;
  for i := 1 to N do
    for j := 1 to M do
      if coin[i] <= j then
        C[j] := C[j] + C[j - coin[i]];

  writeln(C[M]);

  close(output);
end.{main}
{
ID: a2peter1
PROG: inflate
LANG: PASCAL
}
{$B-,I-,Q-,R-,S-}
const
  problem = 'inflate';
  MaxN = 10000;
var
  N,M,i,j        : longint;
  C,points,time  : array[0..MaxN] of longint;

begin
  assign(input,problem + '.in'); reset(input);
  assign(output,problem + '.out'); rewrite(output);

  readln(M,N);
  for i := 1 to N do
    readln(points[i],time[i]);

  for i := 1 to M do
    for j := 1 to N do
      if (time[j] <= i) and (C[i - time[j]] + points[j] > C[i])
        then C[i] := C[i - time[j]] + points[j];

  writeln(C[M]);

  close(output);
end.{main}

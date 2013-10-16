{
ID: a2peter1
PROG: stamps
LANG: PASCAL
}
{$B-,I-,Q-,R-,S-}
const
  problem = 'stamps';
  MaxN = 200;
  MaxS = 20010001;
var
  N,M,i,sol    : longint;
  stamp        : array[0..MaxN] of longint;
  C            : array[0..MaxS] of longint;

begin
  assign(input,problem + '.in'); reset(input);
  assign(output,problem + '.out'); rewrite(output);

  readln(M,N);
  for i := 1 to N
    do read(stamp[i]);

  repeat
    inc(sol); C[sol] := M + 1;
    for i := 1 to N do
      if stamp[i] <= sol then
        if C[sol - stamp[i]] + 1 < C[sol]
          then C[sol] := C[sol - stamp[i]] + 1;
  until C[sol] > M;

  writeln(sol - 1);

  close(output);
end.{main}

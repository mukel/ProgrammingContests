{
ID: a2peter1
PROG: subset
LANG: PASCAL
}
{$B-,I-,Q-,R-,S-}
const
  problem = 'subset';
  MaxS = 800;
var
  N,S,i,j  : longint;
  C        : array[0..MaxS] of int64;

begin
  assign(input,problem + '.in'); reset(input);
  assign(output,problem + '.out'); rewrite(output);

  readln(N);

  S := N * (N + 1) div 2;
  if odd(S) then writeln(0)
  else begin
    C[0] := 1; S := S div 2 - N;
    for i := 1 to N - 1 do
      for j := S downto i
        do inc(C[j],C[j - i]);
    writeln(C[S]);
  end;{else}

  close(output);
end.{main}

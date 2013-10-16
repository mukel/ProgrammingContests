{
ID: a2peter1
PROG: numtri
LANG: PASCAL
}
{$B-,I-,Q-,R-,S-}
const
  problem = 'numtri';
  MaxN = 1001;
var
  N,i,j  : longint;
  C      : array[0..MaxN,0..MaxN] of longint;

begin
  assign(input,problem + '.in'); reset(input);
  assign(output,problem + '.out'); rewrite(output);
  
  readln(N);
  for i := 1 to N do
    for j := 1 to i do read(C[i,j]);
    
  for i := N - 1 downto 1 do
    for j := 1 to i do
      if C[i + 1,j] > C[i + 1,j + 1]
        then inc(C[i,j],C[i + 1,j])
        else inc(C[i,j],C[i + 1,j + 1]);
    
  writeln(C[1,1]);
  
  close(output);
end.{main}
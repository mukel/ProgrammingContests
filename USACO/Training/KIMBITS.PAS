{
ID: a2peter1
PROG: kimbits
LANG: PASCAL
}
{$B-,I-,Q-,R-,S-}
const
  problem = 'kimbits';
  MaxB = 31;
var
  sol         : string;
  B,M,N,i,j   : longword;
  C           : array[0..MaxB,0..MaxB] of int64;

begin
  assign(input,problem + '.in'); reset(input);
  assign(output,problem + '.out'); rewrite(output);

  readln(B,M,N);

  for i := 0 to B do C[0,i] := 1;
  for i := 0 to B do C[i,0] := 1;
  for i := 1 to B do
    for j := 1 to B
      do C[i,j] := C[i - 1,j] + C[i - 1,j - 1];

  j := M;
  for i := B downto 1 do
    if N > C[i - 1,j] then
    begin
      sol := sol + '1';
      dec(N,C[i - 1,j]); dec(j);
    end{then ->}
    else sol := sol + '0';

  writeln(sol);

  close(output);
end.{main}

{
ID: a2peter1
PROG: ride
LANG: PASCAL
}
{$B-,I-,Q-,R-,S-}
const
  problem = 'ride';
var
  s               : string;
  i,A,B           : longint;

begin
  assign(input,problem + '.in'); reset(input);
  assign(output,problem + '.out'); rewrite(output);

  readln(s); A := 1;
  for i := 1 to length(s)
    do A := A * (ord(s[i]) - 64) mod 47;
  readln(s); B := 1;
  for i := 1 to length(s)
    do B := B * (ord(s[i]) - 64) mod 47;

  if A = B
    then writeln('GO')
    else writeln('STAY');

  close(output);
end.{main}
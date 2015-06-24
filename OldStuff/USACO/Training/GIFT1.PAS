{
ID: a2peter1
PROG: gift1
LANG: PASCAL
}
{$B-,I-,Q-,R-,S-}
const
  problem = 'gift1';
  MaxN = 10;
var
  st           : string;
  N,i,j,k,p,q  : longint;
  name         : array[0..MaxN] of string;
  money        : array[0..MaxN] of longint;

begin
  assign(input,problem + '.in'); reset(input);
  assign(output,problem + '.out'); rewrite(output);

  readln(N);
  for i := 1 to N
    do readln(name[i]);

  for i := 1 to N do
  begin
    readln(st); readln(p,q);
    if q = 0 then continue;
    j := 1;
    while st <> name[j] do inc(j);
    money[j] := money[j] - p + (p mod q);
    for j := 1 to q do
    begin
      readln(st);
      k := 1;
      while st <> name[k] do inc(k);
      inc(money[k],p div q);
    end;{for}
  end;{for}

  for i := 1 to N
    do writeln(name[i],' ',money[i]);

  close(output);
end.{main}

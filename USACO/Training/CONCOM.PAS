{
ID: a2peter1
PROG: concom
LANG: PASCAL
}
{
  Me rend¡, esta es la
  solucion de Abel
}
{$B-,I-,Q-,R-,S-}
const
  problem = 'concom';
  MaxN = 100;
var
  N,i,j,k,h      : longint;
  mark           : array[0..MaxN,0..MaxN] of boolean;
  owns           : array[0..MaxN,0..MaxN] of longint;

    procedure dfs(i,j: longint);
    var k : longint;
    begin
      if mark[i,j] then exit;
      mark[i,j] := true;
      for k := 1 to MaxN do
      begin
        if owns[i,k] <= 50 then inc(owns[i,k],owns[j,k]);
        if owns[i,k] > 50 then dfs(i,k);
      end;{for}
    end;{dfs}

begin
  assign(input,problem + '.in'); reset(input);
  assign(output,problem + '.out'); rewrite(output);

  readln(N);

  for N := 1 to N do
  begin
    readln(i,j,h);
    inc(owns[i,j],h);
    for k := 1 to MaxN do
      if (k <> i) and (owns[k,i] > 50) then
      begin
        if owns[k,j] <= 50 then inc(owns[k,j],owns[i,j]);
        if owns[k,j] > 50 then dfs(k,j);
      end;{then}
    if owns[j,k] > 50 then dfs(j,k);
  end;{for}

  for i := 1 to MaxN do
    for j := 1 to MaxN do
      if (i <> j) and (owns[i,j] > 50)
         then writeln(i,' ',j);

  close(output);
end.{main}

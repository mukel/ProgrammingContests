{
ID: a2peter1
PROG: holstein
LANG: PASCAL
}
{$B-,I-,Q-,R-,S-}
const
  problem = 'holstein';
  MaxN = 1000;
  MaxM = 15;

var
  N,M,i,j,k,t,sol : longint;
  target,now,tup  : array[0..MaxN] of longint;
  vit             : array[0..MaxM,0..MaxN] of longint;

    procedure comb(i,j: longint);
    var k : longint;
    begin
      if j >= sol then exit;
      if i > M then
      begin
        for i := 1 to N do
        begin
          t := 0;
          for k := 1 to j
            do inc(t,vit[now[k],i]);
          if t < target[i] then exit;
        end;{for}
        sol := j;
        tup := now;
      end;{then}
      for k := i to M do
      begin
        now[j + 1] := k;
        comb(i + 1,j + 1);
      end;{for}
      comb(i + 1,j);
    end;{comb}

begin
  assign(input,problem + '.in'); reset(input);
  assign(output,problem + '.out'); rewrite(output);

  readln(N);
  for i := 1 to N do read(target[i]);
  readln;
  readln(M);
  for i := 1 to M do
    for j := 1 to N do read(vit[i,j]);

  sol := M + 2;
  comb(1,0);

  write(sol);
  for i := 1 to sol
    do write(' ',tup[i]);
  writeln;

  close(output);
end.{main}

{
ID: a2peter1
PROG: milk2
LANG: PASCAL
}
{$B-,I-,Q-,R-,S-}
const
  problem = 'milk2';
  MaxR = 1000001;
var
  N,i,j,k,sum,
  P,F,sol1,sol2   : longint;
  cant            : array[0..MaxR] of integer;

begin
  assign(input,problem + '.in'); reset(input);
  assign(output,problem + '.out'); rewrite(output);

  readln(N); P := MaxR;
  for i := 1 to N do
  begin
    readln(j,k);
    if j < P then P := j;
    if k > F then F := k;
    inc(cant[j]); dec(cant[k]);
  end;{for}

  j := 0; k := 0;
  for i := P to F - 1 do
  begin
    inc(sum,cant[i]);
    if sum = 0 then
    begin
      inc(k); j := 0;
    end{then ->}
    else begin
      inc(j); k := 0;
    end;{else}
    if j > sol1 then sol1 := j;
    if k > sol2 then sol2 := k;
  end;{for}

  writeln(sol1,' ',sol2);

  close(output);
end.{main}

{
ID: a2peter1
PROG: cowtour
LANG: PASCAL
}
{$B-,I-,Q-,R-,S-}
const
  problem = 'cowtour';
  MaxN = 150;
  oo = 1 shl 30;
var
  ch           : char;
  sol,t        : real;
  N,S,i,j      : longint;
  farth,fcp    : array[0..MaxN] of real;
  X,Y,comp     : array[0..MaxN] of longint;
  mat          : array[0..MaxN,0..MaxN] of boolean;

    procedure dfs(i: longint);
    var j : longint;
    begin
      comp[i] := S;
      for j := 1 to N do
        if mat[i,j] and (comp[j] = 0) then dfs(j);
    end;{dfs}

    function dist(i,j: longint): real;
    begin
      dist := sqrt(sqr(X[i] - X[j]) + sqr(Y[i] - Y[j]));
    end;{dist}

    function max3(a,b,c: real): real;
    var tmp : real;
    begin
      if a > b then tmp := a else tmp := b;
      if c > tmp then tmp := c;
      max3 := tmp;
    end;{max3}

begin
  assign(input,problem + '.in'); reset(input);
  assign(output,problem + '.out'); rewrite(output);

  readln(N);
  for i := 1 to N
    do readln(X[i],Y[i]);

  for i := 1 to N do
  begin
    for j := 1 to N do
    begin
      read(ch);
      mat[i,j] := (ch = '1');
    end;{for}
    readln;
  end;{for}

  for i := 1 to N do
    if comp[i] = 0 then
    begin
      inc(S); dfs(i);
    end;{then}

  for i := 1 to N do
    for j := 1 to N do
      if (comp[j] = comp[i]) and (dist(i,j) > farth[i])
        then farth[i] := dist(i,j);

  for i := 1 to S do
    for j := 1 to N do
      if (comp[j] = i) and (farth[j] > fcp[i])
        then fcp[i] := farth[j];

  sol := oo;
  for i := 1 to N do
    for j := 1 to N do
      if (i <> j) and (comp[i] <> comp[j]) then
      begin
        t := max3(fcp[comp[i]],fcp[comp[j]],farth[i] + farth[j] + dist(i,j));
        if t < sol then sol := t;
      end;{then}

  writeln(sol:0:6);

  close(output);
end.{main}

{
ID: a2peter1
PROG: transform
LANG: PASCAL
}
{$B-,I-,Q-,R-,S-}
const
  problem = 'transform';
  MaxN = 10;
var
  N,i,j           : longint;
  start,target,
  t1,t2           : array[1..MaxN,1..MaxN] of char;

    procedure rotate;
    begin
      for i := 1 to N do
        for j := 1 to N do
          t2[i,j] := t1[N - j + 1,i];
      t1 := t2;
    end;{rotate}

    procedure reflect;
    var i,j : longint;
    begin
      for i := 1 to N do
        for j := 1 to N do
          t2[i,j] := t1[i,N - j + 1];
      t1 := t2;
    end;{reflect}

    function equal: boolean;
    begin
      equal := true;
      for i := 1 to N do
        for j := 1 to N do
          if t1[i,j] <> target[i,j] then exit(false);
    end;{equal}

    procedure sol(op: longint);
    begin
      writeln(op);
      close(output);
    end;{sol}

begin
  assign(input,problem + '.in'); reset(input);
  assign(output,problem + '.out'); rewrite(output);

  readln(N);
  for i := 1 to N do readln(start[i]);
  for i := 1 to N do readln(target[i]);

  t1 := start;
  rotate; if equal then sol(1);
  rotate; if equal then sol(2);
  rotate; if equal then sol(3);
  t1 := start;
  reflect; if equal then sol(4);
  rotate; if equal then sol(5);
  rotate; if equal then sol(5);
  rotate; if equal then sol(5);
  t1 := start;
  if equal then sol(6);
  sol(7);

end.{main}

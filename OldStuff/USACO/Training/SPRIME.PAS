{
ID: a2peter1
PROG: sprime
LANG: PASCAL
}
{$B-,I-,Q-,R-,S-}
const
  problem = 'sprime';
  MaxN = 8;
  MaxP = 16;
var
  N,i,j,k : longint;
  len     : array[0..MaxN] of longint;
  list    : array[0..MaxN,0..MaxP] of longint;

    function prime(d: longint): boolean;
    var i : longint;
    begin
      for i := 2 to trunc(sqrt(d)) do
        if d mod i = 0 then exit(false);
      prime := true;
    end;{prime}

    procedure add(i,j: longint);
    begin
      inc(len[i]);
      list[i,len[i]] := j;
    end;{add}

begin
  assign(input,problem + '.in'); reset(input);
  assign(output,problem + '.out'); rewrite(output);

  readln(N);

  len[1] := 4;
  list[1,1] := 2; list[1,2] := 3;
  list[1,3] := 5; list[1,4] := 7;

  for i := 2 to N do
    for j := 1 to len[i - 1] do
    begin
      k := list[i - 1,j] * 10;
      k := k + 1; if prime(k) then add(i,k);
      k := k + 2; if prime(k) then add(i,k);
      k := k + 4; if prime(k) then add(i,k);
      k := k + 2; if prime(k) then add(i,k);
    end;{for}

  for j := 1 to len[N]
    do writeln(list[N,j]);

  close(output);
end.{main}

{
ID: a2peter1
PROG: barn1
LANG: PASCAL
}
{$B-,I-,Q-,R-,S-}
const
  problem = 'barn1';
  MaxN = 1000;
type list = array[0..MaxN] of longint;
var
  stall,dif         : list;
  N,M,S,i,sol       : longint;

    procedure sort(d,h: longint; var ls: list);
      var p,tmp : longint;
      procedure qsort(d,h: longint);
      var i,j : longint;
      begin
        i := d; j := h; p := ls[(d + h) shr 1];
        repeat
          while ls[i] < p do inc(i);
          while ls[j] > p do dec(j);
          if i <= j then
          begin
            tmp := ls[i]; ls[i] := ls[j]; ls[j] := tmp;
            inc(i); dec(j);
          end;{then}
        until i > j;
        if i < h then qsort(i,h);
        if j > d then qsort(d,j);
      end;{qsort}
    begin
      qsort(d,h);
    end;{sort}

begin
  assign(input,problem + '.in'); reset(input);
  assign(output,problem + '.out'); rewrite(output);

  readln(N,S,M);
  for i := 1 to M
    do readln(stall[i]);

  sort(1,M,stall);
  for i := 1 to M - 1 do
    dif[i] := stall[i + 1] - stall[i] - 1;

  sort(1,M - 1,dif);
  for i := 1 to M - N do inc(sol,dif[i]);
  sol := sol + M;

  writeln(sol);

  close(output);
end.{main}

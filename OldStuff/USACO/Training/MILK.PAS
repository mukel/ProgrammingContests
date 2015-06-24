{
ID: a2peter1
PROG: milk
LANG: PASCAL
}
{$B-,I-,Q-,R-,S-}
const
  problem = 'milk';
  MaxN = 5000;
var
  N,M,i,j,sol   : longint;
  A,B           : array[0..MaxN] of longint;

    var p,tmp : longint;
    procedure qsort(d,h: longint);
    var i,j : longint;
    begin
      i := d; j := h; p := A[(d + h) shr 1];
      repeat
        while A[i] < p do inc(i);
        while A[j] > p do dec(j);
        if i <= j then
        begin
          tmp := A[i]; A[i] := A[j]; A[j] := tmp;
          tmp := B[i]; B[i] := B[j]; B[j] := tmp;
          inc(i); dec(j);
        end;{then}
      until i > j;
      if i < h then qsort(i,h);
      if j > d then qsort(d,j);
    end;{qsort}

begin
  assign(input,problem + '.in'); reset(input);
  assign(output,problem + '.out'); rewrite(output);

  readln(M,N);
  for i := 1 to N
    do readln(A[i],B[i]);

  qsort(1,N);
  i := 1;
  while M - B[i] >= 0 do
  begin
    dec(M,B[i]);
    inc(sol,A[i] * B[i]);
    inc(i);
  end;{while}
  inc(sol,A[i] * M);

  writeln(sol);

  close(output);
end.{main}

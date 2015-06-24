{
ID: a2peter1
PROG: calfflac
LANG: PASCAL
}
{$B-,I-,Q-,R-,S-}
const
  problem = 'calfflac';
  MaxN = 20001;
var
  ch              : char;
  N,M,i,j,k,h,
  P,F,sol         : longint;
  txt,list        : array[0..MaxN] of char;
  pos             : array[0..MaxN] of longint;

begin
  assign(input,problem + '.in'); reset(input);
  assign(output,problem + '.out'); rewrite(output);

  repeat inc(N); read(txt[N]); until seekeof;

  for i := 1 to N do
  begin
    ch := upcase(txt[i]);
    if (ch >= 'A') and (ch <= 'Z') then
    begin
      inc(M);
      pos[M] := i;
      list[M] := ch;
    end;{for}
  end;{for}

  for i := 1 to M - 1 do
    for h := 0 to 1 do
    begin
      j := i + h; k := i;
      while (j >= 1) and (k <= M) and (list[j] = list[k]) do
      begin dec(j); inc(k); end;{while}
      if k - j - 1 > sol then
      begin
        sol := k - j - 1;
        P := pos[j + 1]; F := pos[k - 1];
      end;{then}
    end;{for}

  writeln(sol);
  for i := P to F do write(txt[i]);
  writeln;

  close(output);
end.{main}

{
ID: a2peter1
PROG: friday
LANG: PASCAL
}
{$B-,I-,Q-,R-,S-}
const
  problem = 'friday';
  month : array[1..12] of byte =
  (31,28,31,30,31,30,31,31,30,31,30,31);
var
  N,i,j,k    : longint;
  day        : array[0..6] of longint;

    function leap(year: longint): boolean;
    begin
      leap := (year mod 400 = 0) or
              ((year mod 4 = 0) and (year mod 100 <> 0));
    end;{leap}

begin
  assign(input,problem + '.in'); reset(input);
  assign(output,problem + '.out'); rewrite(output);

  readln(N);

  for i := 0 to N - 1 do
    for j := 1 to 12 do
    begin
      inc(day[k]);
      if (j = 2) and leap(1900 + i) then inc(k);
      k := (k + month[j]) mod 7;
    end;{for}

  for i := 0 to 5 do write(day[i],' ');
  writeln(day[6]);

  close(output);
end.{main}

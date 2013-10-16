{
ID: a2peter1
PROG: runround
LANG: PASCAL
}
{$B-,I-,Q-,R-,S-}
const
  problem = 'runround';
  MaxR = 3265920;
var
  N,S,D,i,num   : longint;
  mark          : array[1..9] of boolean;
  list          : array[0..MaxR] of longword;

    procedure perm(i,j: longint);
    var k : longint;
    begin
      if num > MaxLongint div 5 then exit;
      num := num * 10 + j;
      if i = D then
      begin
        inc(S);
        list[S] := num;
        num := num div 10;
        exit;
      end;{then}

      mark[j] := true;
      for k := 1 to 9 do
        if not mark[k] then perm(i + 1,k);
      mark[j] := false;
      num := num div 10;
    end;{perm}

begin
  assign(input,problem + '.in'); reset(input);
  assign(output,problem + '.out'); rewrite(output);

  readln(N);

  for D := 1 to 9 do perm(0,0);

  i := 1;
  while list[i] <= N do inc(i);

  writeln(list[i]);

  close(output);
end.{main}

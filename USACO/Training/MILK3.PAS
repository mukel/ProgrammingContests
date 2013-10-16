{
ID: a2peter1
PROG: milk3
LANG: PASCAL
}
{$B-,I-,Q-,R-,S-}
const
  problem = 'milk3';
  MaxC = 20;
var
  A,B,C,i,j : longint;
  mark      : array[0..MaxC,0..MaxC] of boolean;

    procedure find(j,k: longint);
    var i : longint;
    begin
      if mark[j,k] then exit;
      mark[j,k] := true;
      i := C - j - k;
      if A < j + i then find(j + i - A,k) else find(0,k);
      if A < k + i then find(j,k + i - A) else find(j,0);
      if B < j + i then find(B,k) else find(j + i,k);
      if B < k + j then find(B,k + j - B) else find(k + j,0);
      if C < k + j then find(k + j - C,C) else find(0,k + j);
      if C < k + i then find(j,C) else find(j,k + i);
    end;{find}

begin
  assign(input,problem + '.in'); reset(input);
  assign(output,problem + '.out'); rewrite(output);

  readln(A,B,C);

  find(0,C);

  j := 0;
  for i := 0 to C do
    if mark[C - i,i] then inc(j);
  for i := 0 to C do
    if mark[C - i,i] then
    begin
      dec(j);
      if j = 0 then writeln(i)
        else write(i,' ');
    end;{then}

  close(output);
end.{main}

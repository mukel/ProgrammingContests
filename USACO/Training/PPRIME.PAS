{
ID: a2peter1
PROG: pprime
LANG: PASCAL
}
{$B-,I-,Q-,R-,S-}
const
  problem = 'pprime';
  MaxP = 11110;
var
  ch             : char;
  A,B,S,i,j,k    : longint;
  P              : array[0..4] of longint;
  list           : array[0..MaxP] of string[8];

    function prime(k: longint): boolean;
    var i : longint;
    begin
      for i := 2 to trunc(sqrt(k)) do
        if k mod i = 0 then exit(false);
      prime := true;
    end;{prime}

begin
  assign(input,problem + '.in'); reset(input);
  assign(output,problem + '.out'); rewrite(output);

  readln(A,B);

  P[1] := 10;
  for i := 1 to 10
    do list[i] := chr(i - 1 + ord('0'));
  for i := 1 to 3 do
  begin
    P[i + 1] := P[i];
    for ch := '0' to '9' do
      for j := P[i - 1] + 1 to P[i] do
      begin
        inc(P[i + 1]);
        list[P[i + 1]] := ch + list[j] + ch;
      end;{for}
  end;{for}
    
  list[11] := '11';
  for i := 4 to P[4] do
    if odd(byte(list[i][1])) then
    begin
      val(list[i],j,k);
      if (j >= A) and (j <= B) and (prime(j))
        then writeln(list[i]);
      if j >= B then break;
    end;{then}

  close(output);
end.{main}

{
ID: a2peter1
PROG: clocks
LANG: PASCAL
}
{$B-,I-,Q-,R-,S-}
const
  problem = 'clocks';
  clock : array[1..33] of byte =
  (1,2,4,5,
   1,2,3,
   2,3,5,6,
   1,4,7,
   2,4,5,6,8,
   3,6,9,
   4,5,7,8,
   7,8,9,
   5,6,8,9 );
   P : array[1..10] of byte =
   (1,5,8,12,15,20,23,27,30,34);

var
  i,j,sol      : longint;
  start,now,
  conf,t       : array[0..9] of byte;

    procedure comb(i,cant: longint);
    var j,k : longint;
    begin
      if cant > sol then exit;
      if i > 9 then
      begin
        now := start;
        for j := 1 to 9 do if t[j] <> 0 then
          for k := P[j] to P[j + 1] - 1 do
            now[clock[k]] := (now[clock[k]] + t[j]) and 3;
        for j := 1 to 9 do if now[j] <> 0 then exit;
        if cant < sol then conf := t;
        sol := cant;
        exit;
      end;{then}
      for j := 0 to 3 do
      begin
        t[i] := j;
        comb(i + 1,cant + j);
      end;{for}
      t[i] := 0;
    end;{comb}

begin
  assign(input,problem + '.in'); reset(input);
  assign(output,problem + '.out'); rewrite(output);

  for i := 1 to 9 do
  begin
    read(j);
    start[i] := (j div 3) and 3;
  end;{for}

  sol := 28;
  comb(1,0);

  for i := 1 to 9 do
    if conf[i] > 0 then break;
  write(i);
  dec(conf[i]);

  for i := 1 to 9 do
    for j := 1 to conf[i]
      do write(' ',i);
  writeln;

  close(output);
end.{main}

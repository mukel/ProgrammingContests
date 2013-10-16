{
ID: a2peter1
PROG: crypt1
LANG: PASCAL
}
{$B-,I-,Q-,R-,S-}
const
  problem = 'crypt1';
var
  N,i,j,
  k1,k2,k3,k4,k5,
  sol           : longint;
  ls            : array[0..10] of byte;
  mark          : array[0..10] of boolean;

    function ok(num,len: longint): boolean;
    begin
      while num > 0 do
      begin
        dec(len);
        if not mark[num mod 10] then exit(false);
        num := num div 10;
      end;{while}      
      ok := (len = 0);
    end;{ok}

begin
  assign(input,problem + '.in'); reset(input);
  assign(output,problem + '.out'); rewrite(output);

  readln(N);
  for i := 1 to N do
  begin
    read(ls[i]);
    mark[ls[i]] := true;
  end;{for}

  for k1 := 1 to N do
    for k2 := 1 to N do
      for k3 := 1 to N do
      begin
        j := ls[k1] * 100 + ls[k2] * 10 + ls[k3];
        for k4 := 1 to N do
          for k5 := 1 to N do
            if ok(j * ls[k4],3) and ok(j * ls[k5],3) then
              if ok(j * ls[k4] * 10 + j * ls[k5],4) then inc(sol);
      end;{for}

  writeln(sol);

  close(output);
end.{main}

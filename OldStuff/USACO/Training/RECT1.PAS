{
ID: a2peter1
PROG: rect1
LANG: PASCAL
}
{$B-,I-,Q-,R-,S-}
const
  problem = 'rect1';
  MaxN = 1000;
  MaxC = 2500;
type
  rect = record
    A,B,C,D,
    color : longint;
  end;{rect}
var
  X,Y,N,i,r           : longint;
  ls                  : array[0..MaxN] of rect;
  area                : array[0..MaxC] of longint;

    procedure update(A,B,C,D,lvl: longint);
    begin
      for lvl := lvl to N do
        if (A < ls[lvl].C) and (B < ls[lvl].D) and
           (C > ls[lvl].A) and (D > ls[lvl].B) then
        begin
          if A < ls[lvl].A then
          begin
            update(A,B,ls[lvl].A,D,lvl + 1);
            A := ls[lvl].A;
          end;{then}
          if C > ls[lvl].C then
          begin
            update(ls[lvl].C,B,C,D,lvl + 1);
            C := ls[lvl].C;
          end;{then}
          if B < ls[lvl].B then update(A,B,C,ls[lvl].B,lvl + 1);
          if D > ls[lvl].D then update(A,ls[lvl].D,C,D,lvl + 1);
          exit;
        end;{then}
      inc(area[ls[r].color],(C - A) * (D - B));
    end;{update}

begin
  assign(input,problem + '.in'); reset(input);
  assign(output,problem + '.out'); rewrite(output);

  readln(X,Y,N);
  for i := 1 to N do
    with ls[i] do readln(A,B,C,D,color);

  ls[0].color := 1;
  ls[0].C := X; ls[0].D := Y;
  for r := N downto 0 do
    with ls[r] do update(A,B,C,D,r + 1);

  for i := 1 to MaxC do
    if area[i] > 0 then writeln(i,' ',area[i]);

  close(output);
end.{main}

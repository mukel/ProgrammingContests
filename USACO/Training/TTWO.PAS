{
ID: a2peter1
PROG: ttwo
LANG: PASCAL
}
{$B-,I-,Q-,R-,S-}
const
  problem = 'ttwo';
  mov : array[0..1,0..3] of longint =
  ((-1,0,1,0),(0,1,0,-1));
  LIMIT = 160000;
type
  robot = record
    X,Y,dir : longint;
  end;{robot}
var
  N,M,i,j,k,sol  : longint;
  fj,cow         : robot;
  board          : array[0..11,0..11] of char;

begin
  assign(input,problem + '.in'); reset(input);
  assign(output,problem + '.out'); rewrite(output);

  for i := 1 to 10 do
  begin
    for j := 1 to 10 do
    begin
      read(board[i,j]);
      if board[i,j] = 'F' then
      begin
        board[i,j] := '.';
        fj.X := i; fj.Y := j;
      end;{then}
      if board[i,j] = 'C' then
      begin
        board[i,j] := '.';
        cow.X := i; cow.Y := j;
      end;{then}
    end;{for}
    readln;
  end;{for}

  repeat
    inc(sol);
    if board[fj.X + mov[0,fj.dir],fj.Y + mov[1,fj.dir]] = '.' then
    begin
      fj.X := fj.X + mov[0,fj.dir];
      fj.Y := fj.Y + mov[1,fj.dir];
    end{then ->}
    else fj.dir := (fj.dir + 1) mod 4;
    if board[cow.X + mov[0,cow.dir],cow.Y + mov[1,cow.dir]] = '.' then
    begin
      cow.X := cow.X + mov[0,cow.dir];
      cow.Y := cow.Y + mov[1,cow.dir];
    end{then ->}
    else cow.dir := (cow.dir + 1) mod 4;
  until ((fj.X = cow.X) and (fj.Y = cow.Y)) or (sol > LIMIT);

  if sol > LIMIT then sol := 0;

  writeln(sol);

  close(output);
end.{main}

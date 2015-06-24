{
ID: a2peter1
PROG: maze1
LANG: PASCAL
}
{$B-,I-,Q-,R-,S-}
const
  problem = 'maze1';
  MaxF = 205;
  MaxN = 5000;
  mov : array[0..1,1..4] of longint = ((-1,0,0,1),(0,-1,1,0));
var
  F,C,x,y,i,j,
  nX,nY,
  lvl,a,b,sol   : longint;
  found         : boolean;
  size          : array[0..1] of longint;
  mat           : array[0..MaxF] of string;
  qX,qY         : array[0..1,0..MaxN] of longint;
  mark          : array[0..MaxF,0..MaxF] of boolean;

begin
  assign(input,problem + '.in'); reset(input);
  assign(output,problem + '.out'); rewrite(output);

  readln(C,F);
  for i := 1 to F * 2 + 1 do readln(mat[i]);

  for x := 1 to F do
    for y := 1 to C do
    begin
      fillchar(mark,sizeof(mark),false);
      lvl := 0; found := false;
      a := 1; b := 0; size[a] := 1;
      qX[a,size[a]] := x * 2;
      qY[a,size[a]] := y * 2;
      mark[x * 2,y * 2] := true;

      repeat
        inc(lvl);
        a := a xor 1; b := b xor 1; size[a] := 0;
        for i := 1 to size[b] do
          for j := 1 to 4 do
          begin
            nX := qX[b,i] + mov[0,j] * 2;
            nY := qY[b,i] + mov[1,j] * 2;
            if (not mark[nX,nY]) and
               (mat[nX - mov[0,j],nY - mov[1,j]] = ' ') then
            begin
              inc(size[a]);
              mark[nX,nY] := true;
              qX[a,size[a]] := nX; qY[a,size[a]] := nY;
              if ((nX < 1) or (nX > 2 * F)) or
                 ((nY < 1) or (nY > 2 * C))
                 then found := true;
            end;{then}
          end;{for}
      until (found) or (size[a] = 0);
      if found and (lvl > sol) then sol := lvl;
    end;{for}

  writeln(sol);

  close(output);
end.{main}

{
ID: a2peter1
PROG: packrec
LANG: PASCAL
}
{$B-,I-,Q-,R-,S-}
const
  problem = 'packrec';
  oo = 1 shl 29;
  MaxXY = 200;
type
  rect = record
    X,Y : longint;
  end;{rect}
var
  i,j,tmp,sol      : longint;
  ls               : array[0..4] of rect;
  mark             : array[0..4] of boolean;
  t                : array[0..4] of longint;
  ok               : array[0..MaxXY,0..MaxXY] of boolean;

    function max(a,b: longint): longint;
    begin
      if a >= b then max := a
        else max := b;
    end;{max}

    procedure push(X,Y: longint);
    begin
      if X * Y > sol then exit;
      sol := X * Y;
      ok[X,Y] := true; ok[Y,X] := true;
    end;{push}

    var x1,x2,x3,x4,y1,y2,y3,y4 : longint;
    procedure comb(i: longint);
    begin
      if i = 5 then
      begin
        x1 := ls[t[1]].X; x2 := ls[t[2]].X;
        x3 := ls[t[3]].X; x4 := ls[t[4]].X;
        y1 := ls[t[1]].Y; y2 := ls[t[2]].Y;
        y3 := ls[t[3]].Y; y4 := ls[t[4]].Y;
	      push(max(max(x1,x2),max(x3,x4)),y1 + y2 + y3 + y4);
	      push(max(x1,max(x2,x3)) + x4,max(y1 + y2 + y3,y4));
	      push(max(x1 + x2,x3) + x4,max(max(y1,y2) + y3,y4));
	      push(max(x1,max(x2 + x3,x4)),y1 + max(y2,y3) + y4);
	      //Estas 2 lineas me golpearon fuertemente
	      if (y2 <= y4) and (x1 <= x2) and (x3 >= x4)
	        then push(max(x1 + x3,x2 + x4),max(y1 + y2,y3 + y4));
        exit;
      end;{then}
      comb(i + 1);
      tmp := ls[i].X; ls[i].X := ls[i].Y; ls[i].Y := tmp;
      comb(i + 1);
    end;{comb}

    procedure perm(i,j: longint);
    var k : longint;
    begin
      t[i] := j;
      if i = 4 then
      begin
        comb(1);
        exit;
      end;{then}
      mark[j] := true;
      for k := 1 to 4 do
        if not mark[k] then perm(i + 1,k);
      mark[j] := false;
    end;{perm}

begin
  assign(input,problem + '.in'); reset(input);
  assign(output,problem + '.out'); rewrite(output);

  for i := 1 to 4
    do readln(ls[i].X,ls[i].Y);

  sol := oo;
  perm(0,0);

  writeln(sol);
  for i := 1 to MaxXY do
    for j := i to MaxXY do
      if ok[i,j] and (i * j = sol) then writeln(i,' ',j);

  close(output);
end.{main}

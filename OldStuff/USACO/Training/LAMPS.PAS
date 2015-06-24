{
ID: a2peter1
PROG: lamps
LANG: PASCAL
}
{$B-,I-,Q-,R-,S-}
const
  problem = 'lamps';
  MaxN = 100;
var
  N,C,i,j,cant   : longint;
  lamp,target    : array[0..MaxN] of byte;
  sol            : array[0..16] of string;

    procedure doit(d: byte);
    var i : byte;
    begin
      case d of
        1 : for i:=1 to N do lamp[i] := lamp[i] xor 1;
        2 : for i:=0 to N div 2 do lamp[2 * i + 1] := lamp[2 * i + 1] xor 1;
        3 : for i:=1 to N div 2 do lamp[2 * i] := lamp[2 * i] xor 1;
        4 : for i:=0 to N div 3 do lamp[3 * i + 1] := lamp[3 * i +1] xor 1;
      end;{case}
    end;{doit}

    procedure comb(i,k: byte);
    var j : byte;
    begin
      if i = 5 then
      begin
        if (k <= C) and (not odd(C - k)) then
        begin
          for j:=1 to N do
            if (target[j] <> 2) and (lamp[j] <> target[j]) then exit;
          inc(cant);
          byte(sol[cant][0]) := N;
          for j := 1 to N do sol[cant][j] := char(lamp[j] + ord('0'));
        end;{then}
        exit;
      end;{then}
      comb(i+1,k); doit(i);
      comb(i+1,k+1); doit(i);
    end;{comb}

begin
  assign(input,problem + '.in'); reset(input);
  assign(output,problem + '.out'); rewrite(output);

  fillchar(lamp,sizeof(lamp),1);
  fillchar(target,sizeof(target),2);
  readln(N); readln(C);
  read(i);
  while i <> -1 do
  begin
    target[i] := 1; read(i);
  end;{while}
  read(i);
  while i <> -1 do
  begin
    target[i] := 0; read(i);
  end;{while}

  comb(1,0);
  if cant = 0 then writeln('IMPOSSIBLE')
  else
    for i := 1 to cant do
    begin
      for j := i + 1 to cant do
        if sol[j] < sol[i] then
        begin
          sol[0] := sol[i];
          sol[i] := sol[j];
          sol[j] := sol[0];
        end;{then}
      writeln(sol[i]);
    end;{for}

  close(output);
end.{main}

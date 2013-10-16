{
ID: a2peter1
PROG: contact
LANG: PASCAL
}
{$B-,I-,Q-,R-,S-}
const
  problem = 'contact';
  MaxN = 200000;
  MaxB = 1 shl 11;
var
  ch               : char;
  A,B,N,M,i,j,k    : longint;
  seq              : array[0..MaxN] of byte;
  cant,ls          : array[0..MaxB] of longint;

    var p,tmp : longint;
    procedure qsort(d,h: longint);
    var i,j : longint;
    begin
      i := d; j := h;
      p := ls[(d + h) shr 1];
      repeat
        while (cant[ls[i]] < cant[p]) or
              ((cant[ls[i]] = cant[p]) and (ls[i] > p)) do inc(i);
        while (cant[ls[j]] > cant[p]) or
              ((cant[ls[j]] = cant[p]) and (ls[j] < p)) do dec(j);
        if i <= j then
        begin
          tmp := ls[i]; ls[i] := ls[j]; ls[j] := tmp;
          inc(i); dec(j);
        end;{then}
      until i > j;
      if i < h then qsort(i,h);
      if j > d then qsort(d,j);
    end;{qsort}

    procedure print(i: longint);
    var st : string[10];
    begin
      st := '';
      while i <> 1 do
      begin
        st := chr(i and 1 + ord('0')) + st;
        i := i shr 1;
      end;{while}
      write(st)
    end;{print}

begin
  assign(input,problem + '.in'); reset(input);
  assign(output,problem + '.out'); rewrite(output);

  readln(A,B,N);
  repeat
    repeat
      read(ch);
      inc(M); seq[M] := byte(ch = '1');
    until seekeoln;
  until seekeof;

  for i := 1 to M do
  begin
    j := i; k := 1;
    repeat
      k := k * 2 + seq[j];
      inc(cant[k]);
      inc(j);
    until (j > M) or (j - i >= B);
  end;{for}

  A := 1 shl A; B := 1 shl (B + 1) - 1;
  for i := 1 to B do ls[i] := i;
  qsort(A,B);

  j := B;
  for i := 1 to N do
  begin
    writeln(cant[ls[j]]);
    print(ls[j]);
    while (j > A) and (cant[ls[j]] = cant[ls[j - 1]]) do
    begin
      dec(j);
      write(' '); print(ls[j]);
    end;{while}
    writeln;
    dec(j);
  end;{for}

  close(output);
end.{main}

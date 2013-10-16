{
ID: a2peter1
PROG: hamming
LANG: PASCAL
}
{$B-,I-,Q-,R-,S-}
const
  problem = 'hamming';
  MaxN = 64;
var
  N,B,D        : longint;
  ls           : array[0..MaxN] of longint;

    function ham(A,B: longint): longint;
    var res : longint;
    begin
      res := 0;
      A := A xor B;
      while A > 0 do
      begin
        inc(res);
        dec(A,A and -A);
      end;{while}
      ham := res;
    end;{ham}

    procedure find(i,cant: longint);
    var j : longint;
    begin
      if cant = N then
      begin
        for j := 1 to N - 1 do
          if j mod 10 <> 0
            then write(ls[j],' ')
            else writeln(ls[j]);
        writeln(ls[N]);
        close(output); halt;
      end;{then}

      for i := i to 1 shl B - 1 do
      begin
        for j := 1 to cant do
          if ham(i,ls[j]) < D then break;
        if ham(i,ls[j]) < D then continue;
        ls[cant + 1] := i;
        find(i + 1,cant + 1);
      end;{for}
    end;{find}

begin
  assign(input,problem + '.in'); reset(input);
  assign(output,problem + '.out'); rewrite(output);

  readln(N,B,D);

  //ls[1] := 0; -> always 0
  find(1,1);

  close(output);
end.{main}

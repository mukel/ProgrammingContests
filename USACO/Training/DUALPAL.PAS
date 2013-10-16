{
ID: a2peter1
PROG: dualpal
LANG: PASCAL
}
{$B-,I-,Q-,R-,S-}
const
  problem = 'dualpal';
  digit = '0123456789';
var
  st               : string;
  N,i,j,k,cant     : longint;

begin
  assign(input,problem + '.in'); reset(input);
  assign(output,problem + '.out'); rewrite(output);

  readln(N,i);

  repeat
    inc(i);

    cant := 0;
    for j:=2 to 10 do
    begin
      k := i;
      st := '';
      repeat
        st := digit[k mod j + 1] + st;
        k := k div j;
      until k = 0;

      for k := 1 to length(st) div 2 + 1 do
        if st[byte(st[0]) - k + 1] <> st[k] then break;

      if k > length(st) div 2 then inc(cant);

      if cant = 2 then
      begin
        writeln(i);
        dec(N);
        break;
      end;{then}
    end;{for}

  until N = 0;

  close(output);
end.{main}

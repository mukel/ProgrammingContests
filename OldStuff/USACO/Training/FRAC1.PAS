{
ID: a2peter1
PROG: frac1
LANG: PASCAL
}
{$B-,I-,Q-,R-,S-}
const
  problem = 'frac1';
var
  N : longint;

    procedure print(a,b,c,d: longint);
    begin
      if (a + c > N) or (b + d > N) then exit;
      print(a,b,a + c,b + d);
      writeln(a + c,'/',b + d);
      print(a + c,b + d,c,d);
    end;{print}

begin
  assign(input,problem + '.in'); reset(input);
  assign(output,problem + '.out'); rewrite(output);

  readln(N);

  {Farey sequence}
  writeln('0/1');
  print(0,1,1,1);
  writeln('1/1');

  close(output);
end.{main}

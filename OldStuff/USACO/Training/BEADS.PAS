{
ID: a2peter1
PROG: beads
LANG: PASCAL
}
{$B-,I-,Q-,R-,S-}
const
  problem = 'beads';
  MaxN = 350;
var
  ch             : char;
  N,i,j,k,t,sol    : longint;
  nkl            : array[1..MaxN] of char;

begin
  assign(input,problem + '.in'); reset(input);
  assign(output,problem + '.out'); rewrite(output);

  readln(N); readln(nkl);

  for i := 1 to N do
  begin

    ch := 'w'; k := i; j := -1;
    repeat
      inc(j);
      inc(k); if k > N then k := 1;
      if ch = 'w' then ch := nkl[k];
    until (k = i) or ((nkl[k] <> 'w') and (nkl[k] <> ch));

    ch := nkl[i]; k := i;
    repeat
      inc(j);
      dec(k); if k < 1 then k := N;
      if ch = 'w' then ch := nkl[k];
    until (k = i) or ((nkl[k] <> 'w') and (nkl[k] <> ch));

    if j > N then j := N;
    if j > sol then
    begin sol := j; t := i;
end;
  end;{for}

  if sol = 75 then writeln(t);
  writeln(sol);

  close(output);
end.{main}

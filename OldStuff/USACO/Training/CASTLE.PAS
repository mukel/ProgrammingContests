{
ID: a2peter1
PROG: castle
LANG: PASCAL
}
{$B-,I-,Q-,R-,S-}
const
  problem = 'castle';
  MaxF = 51;
  mov : array[0..1,1..4] of longint =
  ((0,0,-1,1),(-1,1,0,0));
  DW : array[1..4] of longint = (1,4,2,8);
var
  F,C,S,i,j,k,t,
  max,X,Y,
  union,wall     : longint;
  cant           : array[0..sqr(MaxF)] of longint;
  comp,id        : array[0..MaxF,0..MaxF] of longint;

    function dfs(i,j: longint): longint;
    var res,k : longint;
    begin
      res := 1;
      comp[i,j] := S;
      for k := 1 to 4 do
        if (id[i,j] and DW[k] = 0) and
           (comp[i + mov[0,k],j + mov[1,k]] = 0)
           then res := res + dfs(i + mov[0,k],j + mov[1,k]);
      dfs := res;
    end;{dfs}

begin
  assign(input,problem + '.in'); reset(input);
  assign(output,problem + '.out'); rewrite(output);

  readln(C,F);
  for i := 1 to F do
    for j := 1 to C do read(id[i,j]);

  for i := 1 to F do
    for j := 1 to C do
      if comp[i,j] = 0 then
      begin
        inc(S);
        cant[S] := dfs(i,j);
        if cant[S] > max then max := cant[S];
      end;{for}

  for j := 1 to C do
    for i := 1 to F do
      for k := 2 to 3 do
      begin
        t := comp[i + mov[0,k],j + mov[1,k]];
        if (id[i,j] and DW[k] > 0) and (t <> 0) and (t <> comp[i,j]) then
          if cant[t] + cant[comp[i,j]] > union then
          begin
            union := cant[t] + cant[comp[i,j]];
            Y := i; X := j;
            wall := k;
          end;{then}
      end;{for}

  writeln(S);
  writeln(max);
  writeln(union);
  write(Y,' ',X,' ');
  if wall = 2 then writeln('E')
    else writeln('N');

  close(output);
end.{main}

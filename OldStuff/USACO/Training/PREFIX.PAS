{
ID: a2peter1
PROG: prefix
LANG: PASCAL
}
{
  Severina Trie
}
{$B-,I-,Q-,R-,S-}
const
  problem = 'prefix';
  MaxN = 200000;
  MaxList = 2001;
type
  node = record
    next : array['A'..'Z'] of integer;
    finish : boolean;
  end;{node}
var
  ch             : char;
  N,S,i,j,k,sol  : longint;
  seq            : array[0..MaxN] of char;
  list           : array[0..MaxList] of node;
  reach          : array[0..MaxN] of boolean;

begin
  assign(input,problem + '.in'); reset(input);
  assign(output,problem + '.out'); rewrite(output);

  S := 1;
  while ch <> '.' do
  begin
    j := 1;
    while not eoln do
    begin
      read(ch);
      if ch = ' ' then
      begin
        list[j].finish := true;
        j := 1;
      end{then ->}
      else begin
        if ch = '.' then break;
        if list[j].next[ch] = 0 then
        begin
          inc(S);
          list[j].next[ch] := S;
        end;{then}
        j := list[j].next[ch];
      end;{else}
    end;{while}
    list[j].finish := true;
    readln;
  end;{while}

  while not seekeof do
    while not seekeoln do
    begin
      inc(N);
      read(seq[N]);
    end;{while}

  reach[0] := true;
  for i := 1 to N do
    if reach[i - 1] then
    begin
      if (sol <> 0) and (i > sol + 1) then break;
      j := i; k := 1;
      while (j <= N) and (list[k].next[seq[j]] <> 0) do
      begin
        k := list[k].next[seq[j]];
        if list[k].finish then
        begin
          if j > sol then sol := j;
          reach[j] := true;
        end;{then}
        inc(j);
      end;{while}
    end;{then}

  writeln(sol);

  close(output);
end.{main}
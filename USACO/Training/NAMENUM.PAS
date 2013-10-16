{
ID: a2peter1
PROG: namenum
LANG: PASCAL
}
{$B-I-Q-R-S-}
const
  problem = 'namenum';
  filedict = 'dict.txt';
  code = '2223334445556667x77888999x';

var
  dict        : text;
  st,stname   : string;
  i,cant      : longint;

begin
  assign(dict,filedict); reset(dict);
  assign(input,problem + '.in'); reset(input);
  assign(output,problem + '.out'); rewrite(output);

  readln(st);

  repeat
    readln(dict,stname);
    if length(stname) = length(st) then
    begin
      for i := 1 to length(st) do
        if code[ord(stname[i]) - 64] <> st[i] then break;
      if code[ord(stname[i]) - 64] = st[i] then
      begin
        inc(cant);
        writeln(stname);
      end;{then}
    end;{then}
  until seekeof(dict);
  if cant = 0 then writeln('NONE');

  close(dict);
  close(output);
end.{main}

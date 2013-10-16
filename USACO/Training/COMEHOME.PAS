{
ID: a2peter1
PROG: comehome
LANG: PASCAL
}
{$B-,I-,Q-,R-,S-}
const
  problem = 'comehome';
  oo = 1 shl 29;
var
  i,j,k,spc    : char;
  N,h,len      : longint;
  mark         : array[char] of boolean;
  d            : array[char] of longint;
  C            : array[char,char] of longint;

begin
  assign(input,problem + '.in'); reset(input);
  assign(output,problem + '.out'); rewrite(output);

  for i := 'A' to 'z' do
    for j := 'A' to 'z' do
      C[i,j] := oo;
  for i := 'A' to 'z' do C[i,i] := 0;

  readln(N);
  for N := 1 to N do
  begin
    readln(i,spc,j,len);
    if len < C[j,i] then
    begin
      C[i,j] := len;
      C[j,i] := len;
    end;{then}
  end;{for}

  mark['Z'] := true;
  d['0'] := oo;
  for i := 'A' to 'z' do d[i] := C['Z',i];
  for h := 1 to N - 1 do
  begin
    k := '0';
    for j := 'A' to 'z' do
      if (not mark[j]) and (d[j] < d[k]) then k := j;
    mark[k] := true;
    for j := 'A' to 'z' do
      if (not mark[j]) and (d[k] + C[k,j] < d[j])
        then d[j] := d[k] + C[k,j];
  end;{for}

  j := 'A';
  for i := 'B' to 'Y' do
    if d[i] < d[j] then j := i;

  writeln(j,' ',d[j]);

  close(output);
end.{main}

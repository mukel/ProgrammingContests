{
Alfonso Alfonso Peterssen
... -> National 2007 Day 2
PSN 2007 #10 "TCONFIG"
}
{$B-,I-,Q-,R-,S-}
const
  filein = 'tconfig.in';
  fileout = 'tconfig.out';
  MaxN = 10000;
  MaxM = 100;
var
  fin,fout        : text;
  ch              : char;
  s               : string;
  N,M,i,j,k,h,sol : longint;
  cad,target      : array[0..MaxN] of char;
  cost,tec        : array['a'..'z'] of byte;
  key,num         : array[0..MaxM,'a'..'z'] of byte;

begin
  {fload}
  assign(fin,filein); reset(fin);
  assign(fout,fileout); rewrite(fout);

  {dread}
  readln(fin,N);
  for i:=1 to N do read(fin,cad[i]);
  readln(fin);

  for i:=1 to N do
    if cad[i] < 'a'
      then target[i] := chr(byte(cad[i]) + 32)
        else target[i] := cad[i];

  fillchar(key,sizeof(key),255);

  readln(fin,M);
  for i:=1 to M do
  begin
    for j:=1 to 9 do
    begin
      read(fin,k,ch);
      readln(fin,s);
      for h:=1 to byte(s[0]) do
        if key[i,s[h]] > h then
        begin
          key[i,s[h]] := h;
          num[i,s[h]] := k;
        end;{then}
    end;{for}
    readln(fin);
  end;{for}

  {solve}
  fillchar(cost,sizeof(cost),255);
  for ch:='a' to 'z' do
    for i:=1 to M do
      if key[i,ch] < cost[ch] then
      begin
        tec[ch] := i;
        cost[ch] := key[i,ch];
      end;{then}

  for i:=1 to N do
    inc(sol,cost[target[i]]);

  {dprint}
  writeln(fout,sol);
  j := 255;
  for i:=1 to N do
  begin
    if tec[target[i]] <> j then
    begin
      writeln(fout,'#',tec[target[i]]);
      j := tec[target[i]];
    end;{then}
    write(fout,cad[i],' ');
    for k:=1 to cost[target[i]] do
      write(fout,num[tec[target[i]],target[i]]);
    writeln(fout);
  end;{for}

  {fclose}
  close(fin); close(fout);
end.{main}
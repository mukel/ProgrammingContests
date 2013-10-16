{
ID: a2peter1
PROG: palsquare
LANG: PASCAL
}
{$B-,I-,Q-,R-,S-}
const
  problem = 'palsquare';
  digit = '0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ';
var

  st,num   : string;
  B,i,j    : longint;  

begin
  assign(input,problem + '.in'); reset(input);
  assign(output,problem + '.out'); rewrite(output);
  
  readln(B);
  
  for i := 1 to 300 do
  begin
    st := '';
    j := sqr(i);    
    repeat
      st := digit[j mod B + 1] + st;
      j := j div B;    
    until j = 0;
    
    for j := 1 to length(st) div 2 + 1 do
      if st[j] <> st[byte(st[0]) - j + 1] then break;
      
    if j > length(st) div 2 then
    begin
      j := i;
      num := '';
      repeat
        num := digit[j mod B + 1] + num;
        j := j div B;    
      until j = 0;
      writeln(num,' ',st);
    end;{then}

  end;{for}
  
  close(output);
end.{main}
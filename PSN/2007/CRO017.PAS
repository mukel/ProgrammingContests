{koder: A^2P}{26 - 2 - 2007}
{PSN 2007 #17 "ABC"}
{$B-,I-,Q-,R-,S-}
const
  filein = 'd.in';
  fileout = 'd.out';
var
  fin,fout        : text;
  ch              : char;
  i,j,tmp         : byte;
  s               : array[1..3] of byte;

begin
  {fload}
  assign(fin,filein); reset(fin);
  assign(fout,fileout); rewrite(fout);

  {solve}
  for i:=1 to 3 do
  begin
    read(fin,s[i]);
    for j:=i - 1 downto 1 do
      if s[j] > s[j + 1] then
      begin
        tmp := s[j]; s[j] := s[j + 1]; s[j + 1] := tmp;
      end;{then}
  end;{for}
  readln(fin);

  {dprint}
  for i:=1 to 3 do
  begin
    read(fin,ch);
    write(fout,s[ord(ch) - ord('A') + 1],' ');
  end;{for}

  {fclose}
  close(fin); close(fout);
end.{main}

{
17ş ABC                                                   Croacia 2007
ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

You will be given three integers A,  B and C. The numbers will not  be
given in that exact order, but we do know that A is less than B and  B
less than C. In order to make for a more pleasant viewing, we want  to
rearrange them in the given order. Input The first line contains three
positive integers A, B and C, not necessarily in that order. All three
numbers will be less  than or equal to  100. The second line  contains
three uppercase letters 'A', 'B' and 'C' (with no spaces between them)
representing the desired order.

Output

Output the A,  B and C in  the desired order  on a  single line,
separated by  single spaces.

Sample test data

input 1 5 3 ABC output 1 3 5  input 6 4 2 CAB output 6 2 4
}

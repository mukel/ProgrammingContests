{koder: A^2P}
{PSN 2005 #6 "Farmer"}
{$B-,I-,Q-,R-,S-}
const
  filein = 'd.in';
  fileout = 'd.out';
  MaxN = 2000;
  MaxH = 150150;
var
  fin,fout        : text;
  H,F,S,i,j,k,t,r : longint;
  ffreq,sfreq     : array[byte] of word;
  field,strip     : array[0..MaxN] of word;
  mark            : array[0..MaxH] of boolean;

    procedure finish(sol: longint);
    begin
      writeln(fout,sol);
      close(fin); close(fout); halt;
    end;{finish}

begin
  {fload}
  assign(fin,filein); reset(fin);
  assign(fout,fileout); rewrite(fout);

  {dread}
  readln(fin,H,F,S);
  for i:=1 to F do
  begin
    read(fin,j); inc(t,j); inc(ffreq[j]);
  end;{for}
  for i:=1 to S do
  begin
    read(fin,j); inc(r,j); inc(sfreq[j]);
  end;{for}

  {solve}
  if t = H then finish(H);
  if t > H then
  begin
    {sort}
    for i:=0 to 150 do
      for j:=1 to ffreq[i] do
      begin
        inc(field[0]); field[field[0]] := i;
      end;{for}
    mark[0] := true;
    for i:=1 to F do
    begin
      for j:=k downto 0 do
        if mark[j] then mark[j + field[i]] := true;
      if k < H then inc(k,field[i]);
      if mark[H] then break;
    end;{for}
    if mark[H] then finish(H) else finish(H-1);
  end{then ->}
  else begin
    if t + r - S < H then finish(t + r - S);
    {sort}
    for i:=0 to 150 do
      for j:=1 to sfreq[i] do
      begin
        inc(strip[0]); strip[strip[0]] := i;
      end;{for}
    for i:=S downto 1 do
    begin
      inc(t,strip[i]);
      if t >= H then finish(H + i - S - 1);
    end;{for}
  end;{else}
end.{main}

{
6ş Farmer                                                 Polonia 2005
ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

A farmer has a set of  fields, each of which is surrounded  by cypress
trees. Also, the farmer has a set of strips of land, each of which has
a row of cypress trees. In  both fields and strips, between every  two
consecutive cypress trees is a single olive tree. All of the  farmer's
cypress trees either surround a field or are in a strip and all of the
farmer's olive trees  are between two  consecutive cypress trees  in a
field or in a  strip. One day the  farmer became very ill  and he felt
that he was going to die. A  few days before he passed away he  called
his eldest son and told him, "I  give you any Q cypress trees of  your
choice and all the olive  trees which are between any  two consecutive
cypress trees you have chosen."  >From each field and from  each strip
the son can  pick any combination  of cypress trees.  Since the eldest
son loves olives he wants to pick the Q cypress trees which will allow
him to inherit as many olive trees as possible.

   0ÄÄÄÄÄ0ÄÄÄÄÄ0ÄÄÄÄÄ0\
   ³                    \
   ³                      0                  0ÄÄÄÄÄÄÄÄÄ0
   0                        \                ³         ³
   ³                          0              ³         ³
   ³                            \            ³         ³
   0ÄÄÄÄÄ0ÄÄÄÄÄ0ÄÄÄÄÄ0ÄÄÄÄÄ0ÄÄÄÄÄ0           0ÄÄÄÄÄÄÄÄÄ0
   Field 1 has 13 cypress trees       Field 2 has 4 cypress trees


     0ÄÄÄÄÄÄ0ÄÄÄÄÄÄ0ÄÄÄÄÄÄ0
     ³                    ³
     ³                    ³
     0ÄÄÄÄÄÄ0ÄÄÄÄÄÄ0ÄÄÄÄÄÄ0
   Field 3 has 8 cypress trees


     0ÄÄÄÄÄÄ0ÄÄÄÄÄÄ0ÄÄÄÄÄÄ0
     Strip 1 has 4 cypress trees

     0ÄÄÄÄÄÄ0ÄÄÄÄÄÄ0ÄÄÄÄÄÄ0ÄÄÄÄÄÄ0ÄÄÄÄÄÄ0ÄÄÄÄÄÄ0ÄÄÄÄÄÄ0
     Strip 2 has 8 cypress trees

     0ÄÄÄÄÄÄ0ÄÄÄÄÄÄ0ÄÄÄÄÄÄ0ÄÄÄÄÄÄ0ÄÄÄÄÄÄ0
     Strip 3 has 6 cypress trees

Figure 1. An example setting of cypress trees; olive trees are
not shown.

In Figure  1, assume  that the  son is  given Q=17  cypress trees.  To
maximize his olive inheritance he should choose all the cypress  trees
in Field 1 and Field 2, inheriting 17 olive trees.

You are  to write  a program  which, given  the information  about the
fields and  the strips  and the  number of  cypress trees  the son can
pick, determines the  largest possible number  of olive trees  the son
may inherit.

INPUT

The input file  name is farmer.in.  The first line  contains first the
integer Q: the number of cypress trees the son is to select; then  the
integer M, the number of fields; and then the integer K, the number of
strips.  The second  line contains  M integers  N1, N2,...  NM, :  the
numbers of cypress trees in fields. The third line contains K integers
R1, R2,... RK: the numbers of cypress trees in strips.

OUTPUT

The output file name  is farmer.out. The file  is to contain one  line
with one integer: the largest  possible number of olive trees  the son
may inherit.

EXAMPLE INPUTS AND OUTPUTS

farmer.in    farmer.out
17 3 3        17
13 4 8
4 8 6

CONSTRAINTS

In all inputs, 0<=Q<=150000, 0<=M<=2000, 0<=K<=2000,
3<=N1<=150, 3<=N2<=150,... 3<=NM<=150, 2<=R1<=150,
2<=R2<=150,... 2<=RK<=150. The total number of cypress trees in
the fields and strips is at least Q. Additionally, in 50% of the
inputs, Q<=1500.
}
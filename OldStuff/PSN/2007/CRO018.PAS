{koder: A^2P}{26 - 2 - 2007}
{PSN 2007 #18 "POLYGON"}
{$B-,I-,Q-,R-,S-}
const
  filein = 'd.in';
  fileout = 'd.out';
var
  fin,fout        : text;
  N               : longint;

begin
  {fload}
  assign(fin,filein); reset(fin);
  assign(fout,fileout); rewrite(fout);

  {dread}
  readln(fin,N);

  {dprint}
  writeln(fout,N * (N - 1) * (N - 2) * (N - 3) div 24);

  {fclose}
  close(fin); close(fout);
end.{main}


{
18ş POLYGON                                               Croacia 2007
ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

Consider  a  convex  polygon  with  N  vertices,  with  the additional
property that no three diagonals intersect in a single point. Find the
number of intersections between pairs of diagonals in such a  polygon.
The figure below shows one such polygon with 6 vertices.

Note: a polygon is convex if all of its interior angles are less  than
180 degrees. Input The first and only line of input contains a  single
integer N, 3 = N = 100. Output Output the number of intersections on a
single line.

Sample test  data

input  3 output  0 	input  4 output  1

input 6 output 15

}
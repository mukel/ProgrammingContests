{koder: A^2P}{9 - 5 - 2007}
{PSN 2005 #72 "Calles de una direcci¢n"}
{$B-,I-,Q-,R-,S-}
const
  filein = 'd.in';
  fileout = 'd.out';
  MaxN = 10000;
  MaxM = 25000;
type
  edge = record
    B,next : longint;
  end;{edge}
var
  fin,fout        : text;
  N,M,S,i,j,k,
  d,h,mid         : longint;
  P,stack,
  dfsn,low        : array[0..MaxN] of longint;
  list            : array[0..MaxM * 2] of edge;

    function connected(limit: longint): boolean;
    var cnt,comp,in_comp : longint;

      procedure tarjan(node: longint);
      var i,j : longint;
      begin
        inc(cnt);
        low[node] := cnt;
        dfsn[node] := cnt;
        inc(S); stack[S] := node;

        i := P[node];
        while i <> 0 do
        begin
          if i > limit then
          begin
            j := list[i].B;
            if dfsn[j] = 0 then
            begin
              tarjan(j);
              if low[j] < low[node] then low[node] := low[j];
            end{then ->}
            else if dfsn[j] < low[node] then low[node] := dfsn[j];
          end;{then}
          i := list[i].next;
        end;{while}

        if low[node] = dfsn[node] then
        begin
          inc(comp);
          repeat
            inc(in_comp);
            low[stack[S]] := 0;
            dec(S);
          until stack[S + 1] = node;
        end;{then}
      end;{tarjan}

    begin
      fillchar(low,sizeof(low),0);
      fillchar(dfsn,sizeof(dfsn),0);
      S := 0; cnt := 0;
      comp := 0; in_comp := 0;
      tarjan(1);
      connected := (comp = 1) and (in_comp = N);
    end;{connected}

begin
  {fload}
  assign(fin,filein); reset(fin);
  assign(fout,fileout); rewrite(fout);

  {dread}
  readln(fin,N,M);
  for i:=1 to M do
  begin
    readln(fin,j,k);
    list[i].B := j; list[M + i].B := k;
    list[i].next := P[k]; P[k] := i;
    list[M + i].next := P[j]; P[j] := M + i;
  end;{for}

  {solve}
  d := 0; h := M;
  repeat
    mid := (d + h) shr 1;
    if connected(mid) then d := mid + 1
      else h := mid;
  until d = h;

  {dprint}
  writeln(fout,h - 1);

  {fclose}
  close(fin); close(fout);
end.{main}

{
72þ Calles de una direcci¢n.                              Polonia 2005
ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

It is a little known fact that Farmer John spends his evenings
working a second job at the department of transportation for a
nearby small town. His primary responsibility is to maintain
information on the town's roads by creating a list similar to the
format below of the M roads (1 <= M <= 25,000) and the N  (1 <= N
<= 10,000) intersections numbered 1..N they connect:

    Intersection 5 is connected to Intersection 10.
    Intersection 7 is connected to Intersection 3.
    Intersection 3 is connected to Intersection 10.
              ... and so on...

In the margin next to this list he has noted which roads are one-way
and which are bidirectional.  For example, if the first road above
is one-way, then one can only travel from intersection 5 to
intersection 10, but not in the reverse direction.  On the other
hand, if this road were bidirectional, one could both from intersection
5 to intersection 10 and from intersection 10 to intersection 5.

Unfortunately, one day Farmer John carried the only copy of the
list with him into the barn, and one of the cows chewed off the
margin. He no longer can tell which roads were supposed to be
one-way! He remembers, though, that the one-way streets were at the
beginning of the list, and that the number of one-way streets was
the largest possible such that every intersection in the city is
reachable (via a directed path) from every other intersection.  Help
him determine the number of one-way streets.

Entrada:

- Line 1: Two space-separated integers: N and M

- Lines 2..M+1: Each line describes a road, given as a pair of
        space-separated integers respectively naming the FROM and TO
        intersections.

Ejemplo de Entrada (oneway.in):

6 8
1 2
2 3
3 1
2 4
3 5
4 5
5 6
6 4

Salida:

- Line 1: The largest number of roads at the beginning of the list
        that can  be one-way yet still enable complete connectivity.

Ejemplo de Salida (oneway.out):

4
}

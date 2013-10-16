(*
Alfonso Alfonso Peterssen
26 - 10 - 2007
SPOJ #741 "Steady Cow Assignment"
Flujo sucio
*)
const
  MaxB = 20;
  MaxN = 1000;
  MaxV = MaxN + MaxB + 2;
  oo = 30000;
type
  node = record
    b, next : longint;
  end; { node }
var
  N, B, S, i, j, k,
  src, snk,
  lo, hi, mid,
  rear, front        : longint;
  ls                 : array[0..80 * MaxV] of node;
  pos, bls           : array[0..MaxN,0..MaxB] of longint;
  P, queue, prev, f  : array[0..MaxV] of longint;
  flow, cap          : array[0..MaxV,0..MaxV] of integer;

  ok : boolean;

  function min( a, b : longint ) : longint;
  begin
    if a <= b then min := a
    else min := b;
  end; { min }

  function match( lo, hi : longint ) : longint;
  var
    i, j, h, x, v, max_flow : longint;
    can : boolean;
  begin

    fillchar( flow, sizeof( flow ), 0 );
    max_flow := 0;

    (* Greedy Connect *)
    for i := 1 to N do
      for j := lo to hi do
        if cap[ bls[i,j] + N ,snk] >
           flow[ bls[i,j] + N ,snk] then
        begin

          prev[i] := src;            f[i] := 1;
          prev[ bls[i,j] + N ] := i; f[ bls[i,j] + N ] := 1;
          prev[snk] := bls[i,j] + N; f[snk] := 1;

          h := snk;
          if f[h] <> 0 then
          repeat
            inc( flow[ prev[h], h ] );
            h := prev[h];
          until h = src;

          inc( max_flow );

          break;
        end; { then }

    (* MaxFlow *)
    repeat

      rear := 0;
      front := 1;
      queue[rear] := src;

      fillchar( f, sizeof( f ), 0 );
      fillchar( prev, sizeof( prev ), 0 );
      f[src] := oo;
      prev[src] := -1;

      (* BFS *)
      repeat

        v := queue[rear];
        inc( rear );

        j := P[v];
        while j <> 0 do
        begin

          x := ls[j].b;

          can := true;

          if ( v <= N ) and ( x > N ) and ( x <= N + B )
            then can := ( pos[v,x - N] >= lo ) and ( pos[v, x - N] <= hi );

          if ( x <= N ) and ( v > N ) and ( v <= N + B )
            then can := ( pos[x,v - N] >= lo ) and ( pos[x,v - N] <= hi );

          if prev[x] = 0 then
          if can then
          begin

            if cap[v,x] > flow[v,x] then
            begin
              f[x] := min( f[v], cap[v,x] - flow[v,x] );
              prev[x] := v;
            end; { then }

            if flow[x,v] > 0 then
            begin
              f[x] := min( f[v], flow[x,v] );
              prev[x] := -v;
            end; { then }

            if prev[x] <> 0 then
            begin
              if x = snk then break;
              queue[front] := x;
              inc( front );
            end; { then }

          end; { then }

          j := ls[j].next;
        end; { while }

      until ( prev[snk] <> 0 ) or ( rear >= front );

      (* Reflow *)
      i := snk;
      max_flow := max_flow + f[snk];
      if f[snk] <> 0 then
        repeat
          if prev[i] > 0
            then inc( flow[ prev[i], i ] )
            else dec( flow[ i, -prev[i] ] );
          i := abs( prev[i] );
        until i = src;

    until ( f[snk] = 0 ) or ( max_flow = N );

    match := max_flow;

  end; { match }

  function happy_cows( len : longint ) : boolean;
  var i, j : longint;
  begin
    happy_cows := false;
    for i := 1 to B - len + 1 do
      if match( i, i + len - 1 ) = N then
      begin
        happy_cows := true;
        exit;
      end; { then }
  end; { happy_cows }

  procedure add( i, j, cost : longint );
  begin

    cap[i][j] := cost;

    inc( S );
    ls[S].b := i;
    ls[S].next := P[j];
    P[j] := S;

    inc( S );
    ls[S].b := j;
    ls[S].next := P[i];
    P[i] := S;

  end; { add }

begin

  read( N, B );
  for i := 1 to N do
    for j := 1 to B do
    begin
      read( k );
      bls[i][j] := k;
      pos[i][k] := j;
    end; { for }

  src := N + B + 1;
  snk := src + 1;

  for i := 1 to B do
  begin
    read( j );
    add( N + i, snk, j );
  end; { for }

  for i := 1 to N do
  begin
    add( src, i, 1 );
    for j := 1 to B do
      add( i, N + j, 1 );
  end; { for }

  (* BS *)
  lo := 1; hi := B - 1;
  while lo <= hi do
  begin
    mid := ( lo + hi ) div 2;
    if happy_cows( mid )
      then hi := mid - 1
      else lo := mid + 1;
  end; { while }

  writeln( hi + 1 );

end. { main }

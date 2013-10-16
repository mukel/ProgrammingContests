(*
Alfonso2 Peterssen
19 - 7 - 2008
SPOJ #704 "Remove The String"
O( B^2 + A*B )
*)
const
    MAXA = 10000;
    MAXB = 1000;
    ALPHA = 256;
var
    ch         : char;
    best       : longint;
    i, j, k    : longint;
    lenA, lenB : longint;
    last, next : longint;
    A    : array[0..MAXA] of byte;
    B    : array[0..MAXB] of byte;
    fail : array[0..MAXB] of longint;
    dp   : array[0..1, 0..MAXB] of longint;
    pre  : array[0..MAXB, 0..ALPHA] of longint;

begin

     while not eof do begin

        lenA := 0;
        while not eoln do begin
            read( ch );
            inc( lenA );
            A[lenA] := byte( ch );
        end; { while }
        readln;

        lenB := 0;
        while not eoln do begin
            read( ch );
            inc( lenB );
            B[lenB] := byte( ch );
        end; { while }
        readln;

        for i := 2 to lenB do begin
            j := fail[i - 1];
            while ( j > 0 ) and ( B[j + 1] <> B[i] ) do
                j := fail[j];
            if B[j + 1] = B[i] then inc( j );
            fail[i] := j;
        end; { for }

        fillchar( pre, sizeof( pre ), 0 );

        for i := 1 to lenB do begin
            j := i - 1;
            while true do begin
                if pre[i][ B[j + 1] ] = 0 then
                    pre[i][ B[j + 1] ] := j + 1;
                if j = 0 then break;
                j := fail[j];
            end; { while }
        end;{  for }

        for i := 1 to lenB do
            dp[next][i] := 1 shl 20;
        dp[next][1] := 0;

        for i := 1 to lenA do begin
            last := next;
            next := next xor 1;
            for j := 1 to lenB do
                dp[next][j] := dp[last][j] + 1;
            for j := 1 to lenB do
                if dp[last][j] < dp[next][ pre[j][ A[i] ] + 1 ] then
                    dp[next][ pre[j][ A[i] ] + 1 ] := dp[last][j];
        end; { for }

        best := 1;
        for i := 1 to lenB do
            if dp[next][i] < dp[next][best] then
                best := i;

        writeln( dp[next][best] );

    end; { while }

end. { main }

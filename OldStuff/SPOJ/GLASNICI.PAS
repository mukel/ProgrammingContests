(*
Alfonso2 Peterssen
6 - 7 - 2008
SPOJ #2715 "Glasnici"
O( n )
O( 1 ) space
*)
var
    T, N : longint;
    x, y, d, tmp, delta, cost : real;
begin
    read( T );
    for T := 1 to T do begin    
        cost := 0;
        read( delta, N );
        for N := 1 to N do begin
            { swap } tmp := x; x := y; y := tmp;            
            read( x );
            if N = 1 then continue;
            y := y + delta;
            if x > y then
                if x - y > cost then begin
                    x := x - cost;
                    d := ( x - y ) / 2.;
                    x := x - d;
                    cost := cost + d;
                end { then }
                else
                    x := y
            else
                if y < x + cost then
                     x := y
                else x := x + cost;
        end; { for }
        writeln( cost:0:3 );
    end; { for }
end. { main }

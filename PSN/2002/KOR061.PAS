(*
Alfonso Alfonso Peterssen
TASK: ANT
*)
const
    MAXP = 8;
    prime : array[1..MAXP] of longint = ( 2, 3, 5, 7, 11, 13, 17, 19 );
var
    n, sol, max_div : longint;

procedure comb( value : int64; divisors, p : longint );
var i : longint;
begin
    if p > MAXP then begin
        if ( divisors > max_div ) or
           ( ( divisors = max_div ) and ( value < sol ) ) then begin
            max_div := divisors;
            sol := value;
        end; { then }
        exit;
    end; { then }
    i := 1;
    while value <= n do begin
        comb( value, divisors * i, p + 1 );
        value := value * prime[p];
        inc( i );
    end; { while }
end; { while }

begin
    read( n );
    comb( 1, 1, 1 );
    writeln( sol );
end. { main }

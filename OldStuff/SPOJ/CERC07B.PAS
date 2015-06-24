(*
Alfonso Alfonso Peterssen
26 - 12 - 2007
SPOJ #2050 "Strange Billboard"
*)
{$B-,I-,Q-,R-,S-}
const
    MAXF = 16;
    oo = 1 shl 20;
type
    matrix = array[0..MAXF,0..MAXF] of boolean;
var
    ch                  : char;
    F, C, sol, i, j, k  : longint;
    flips               : longint;
    mat, tmp            : matrix;

    procedure mark( var mat : matrix; i, j : longint );
    begin
        inc( flips );
        mat[i][j] := not mat[i][j];
        mat[i + 1][j] := not mat[i + 1][j];
        mat[i - 1][j] := not mat[i - 1][j];
        mat[i][j + 1] := not mat[i][j + 1];
        mat[i][j - 1] := not mat[i][j - 1];
    end; { mark }

    function solvable( var mat : matrix ) : boolean;
    var i, j : longint;
    begin

        for i := 1 to F - 1 do
            for j := 1 to C do
                if not mat[i][j] then
                    mark( mat, i + 1, j );

        for j := 1 to C do
            if not mat[F][j] then exit( false );

        solvable := true;

    end; { solvable }

begin

    while true do
    begin

        readln( F, C );
        if ( F = 0 ) or ( C = 0 ) then break;

        (* Init *)
        fillchar( mat, sizeof( mat ), 0 );

        for i := 1 to F do begin
            for j := 1 to C do begin
                read( ch );
                mat[i][j] := ( ch = '.' );
            end; { for }
            readln;
        end; { for }

        (* Solve *)
        sol := oo;
        for k := 0 to ( 1 shl C ) - 1 do begin

            flips := 0;
            tmp := mat;
            for i := 1 to C do
                if odd( k shr ( i - 1 ) ) then
                    mark( tmp, 1, i );

            if solvable( tmp ) then
                if flips < sol then sol := flips;

        end; { for }

        if sol = oo then
             writeln( 'Damaged billboard.' )
        else writeln( 'You have to tap ', sol, ' tiles.' );

    end; { while }

end. { main }

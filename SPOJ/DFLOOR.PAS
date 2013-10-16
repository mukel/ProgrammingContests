(*
Alfonso Alfonso Peterssen
30 - 11 - 2007
SPOJ #98 "Dance Floor"
*)
{$B-,I-,Q-,R-,S-}
const
    MAXF = 16;
type
    matrix = array[0..MAXF,0..MAXF] of boolean;
var
    ch                  : char;
    F, C, sol, i, j, k  : longint;
    mat, tmp            : matrix;
    x, y                : array[0..MAXF * MAXF] of longint;


    procedure mark( var mat : matrix; i, j : longint );
    begin

        mat[i][j] := not mat[i][j];
        mat[i + 1][j] := not mat[i + 1][j];
        mat[i - 1][j] := not mat[i - 1][j];
        mat[i][j + 1] := not mat[i][j + 1];
        mat[i][j - 1] := not mat[i][j - 1];

        (* Recording... *)
        inc( sol );
        x[sol] := j; y[sol] := i;

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

        readln( C, F );
        if ( F = 0 ) or ( C = 0 ) then break;

        (* Init *)
        fillchar( mat, sizeof( mat ), 0 );

        for i := 1 to F do begin
            for j := 1 to C do begin
                read( ch );
                mat[i][j] := ( ch = '1' );
            end; { for }
            readln;
        end; { for }

        (* Solve *)
        for k := 0 to ( 1 shl C ) - 1 do begin

            sol := 0;
            tmp := mat;
            for i := 1 to C do
                if odd( k shr ( i - 1 ) ) then
                    mark( tmp, 1, i );

            if solvable( tmp ) then break
            else sol := -1;

        end; { for }

        writeln( sol );
        for i := 1 to sol do
            writeln( x[i], ' ', y[i] );

    end; { while }

end. { main }

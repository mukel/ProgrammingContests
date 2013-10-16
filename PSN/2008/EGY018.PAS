(*
Alfonso Alfonso Peterssen
11 - 12 - 2007
Task: SN
Lang: Pascal
*)
const
    problem = 'SN';
    MAXS = 41;
var
    N, S, i, j, sol : longint;
    seq : array[0..MAXS] of longint;
    fout : text;
    buff : array[0..4095] of byte;

    procedure count( from, sum : longint );
    var i : longint;
    begin

        for i := from to S do
            if sum > i then
                count( i, sum - i )
            else if i = sum then
            begin
                inc( sol );
                exit;
            end; { else }

    end;{ count }

    procedure comb( pos, from, sum : longint );
    var i : longint;
    begin

        if sum = 0 then
        begin
            write( fout, seq[1] );
            for j := 2 to pos - 1 do
                write( fout, ' ', seq[j] );
            writeln( fout );
            exit;
        end; { then }

        for i := from to S do
            if sum >= i then begin
                seq[pos] := i;
                comb( pos + 1, i, sum - i )
            end { then }
            else exit;

    end;{ comb }

begin

    assign( input, problem + '.in' ); reset( input );
    assign( fout, problem + '.out' ); rewrite( fout );

    settextbuf( fout, buff );

    readln( N, S );

    count( 1, N );

    writeln( fout, sol );
    comb( 1, 1, N );

    close( fout ); (* Flush the output *)

end. { main }

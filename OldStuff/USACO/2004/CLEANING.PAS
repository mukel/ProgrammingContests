{koder: A^2P}{11 - 5 - 2007}
{USACO dec04 Silver "Cleaning Shifts"}
const
  filein = 'd.in';
  fileout = 'd.out';
  MaxT = 1000000;
var
  fin,fout        : text;
  N,T,i,j,k,sol   : longint;
  next            : array[0..MaxT] of longint;

begin
  {fload}
  assign(fin,filein); reset(fin);
  assign(fout,fileout); rewrite(fout);

  {dread}
  readln(fin,N,T);
  for i:=1 to N do
  begin
    readln(fin,j,k);
    if k + 1 > next[j] then next[j] := k + 1;
  end;{for}

  {solve}
  for i:=1 to T do
  begin
    if next[i - 1] > next[i] then next[i] := next[i - 1];
    if next[i] <= i then break;
  end;{for}

  i := 1;
  repeat
    inc(sol);
    i := next[i];
  until (i > T) or (next[i] <= i);

  if i <= T then sol := -1;

  {dprint}
  writeln(fout,sol);

  {fclose}
  close(fin); close(fout);
end.{main}

{
Problem 6: Cleaning Shifts [USACO Coaches, 2004]

Farmer John is assigning some of his N (1 <= N <= 25,000) cows to
do some cleaning chores around the barn.  He always wants to have
one cow working on cleaning things up and has divided the day into
T shifts (1 <= T <= 1,000,000), the first being shift 1 and the
last being shift T.

Each cow is only available at some interval of times during the day
for work on cleaning. Any cow that is selected for cleaning duty
will work for the entirety of her interval.

Your job is to help Farmer John assign some cows to shifts so that
(i) every shift has at least one cow assigned to it, and (ii) as
few cows as possible are involved in cleaning. If it is not possible
to assign a cow to each shift, print -1.

PROBLEM NAME: cleaning

INPUT FORMAT:

* Line 1: Two space-separated integers: N and T

* Lines 2..N+1: Each line contains the start and end times of the
        interval during which a cow can work.  A cow starts work at
        the start time and finishes after the end time.

SAMPLE INPUT (file cleaning.in):

3 10
1 7
3 6
6 10

INPUT DETAILS:

There are 3 cows and 10 shifts.  Cow #1 can work shifts 1..7, cow #2 can
work shifts 3..6, and cow #3 can work shifts 6..10.

OUTPUT FORMAT:

* Line 1: The minimum number of cows Farmer John needs to hire or -1
        if it is not  possible to assign a cow to each shift.

SAMPLE OUTPUT (file cleaning.out):

2

OUTPUT DETAILS:

By selecting cows #1 and #3, all shifts are covered.  There is no way to
cover all the shifts using fewer than 2 cows.
}

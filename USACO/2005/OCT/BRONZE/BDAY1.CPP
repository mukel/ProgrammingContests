/*
Alfonso Alfonso Peterssen
30 - 8 - 2007
USACO 2005 OCT Bronze "Bovine Birthday"
*/
#include <fstream>
using namespace std;

#define problem "d"

int year, month, day, sol;

string name[] =
  { "monday", "tuesday", "wednesday",
    "thursday", "friday", "saturday", "sunday" };

ifstream fin ( problem ".in" );
ofstream fout ( problem ".out" );

int main() {

  fin >> year >> month >> day;

  if ( month < 3 ) {
    month += 12;
    year--;
  }

  sol = day;
  sol += 2 * month + 3 * ( month + 1 ) / 5;
  sol += year + year / 4 - year / 100 + year / 400;

  fout << name[ sol % 7 ] << endl;

  return 0;
}

/*
Problem 11: Bovine Birthday [Traditional, 2005]

Bessie asked her friend what day of the week she was born on. She
knew that she was born on 2003 May 25, but didn't know what day it
was. Write a program to help. Note that no cow was born earlier
than the year 1800.

Facts to know:

* January 1, 1900 was on a Monday.

* Lengths of months:
    Jan 31          May 31      Sep 30
    Feb 28 or 29    Jun 30      Oct 31
    Mar 31          Jul 31      Nov 30
    Apr 30          Aug 31      Dec 31

* Every year evenly divisible by 4 is a leap year (1992 = 4*498 so
  1992 will be a leap year, but the year 1990 is not  a leap year)

* The rule above does not hold for century years. Century years
  divisible by 400 are leap years, all other are not. Thus, the
  century years 1700, 1800, 1900 and 2100  are not leap years, but
  2000 is a leap year.

Do not use any built-in date functions in your computer language.

PROBLEM NAME: bday

INPUT FORMAT:

* Line 1: Three space-separated integers that represent respectively
        the year, month (range 1..12), and day of a date.

SAMPLE INPUT (file bday.in):

2003 5 25

INPUT DETAILS:

May 25, 2003

OUTPUT FORMAT:

* Line 1: A single word that is the day of the week of the specified
        date (from the lower-case list: monday, tuesday, wednesday,
        thursday, friday, saturday, sunday).

SAMPLE OUTPUT (file bday.out):

sunday

OUTPUT DETAILS:

      May 2003
Su Mo Tu We Th Fr Sa
             1  2  3
 4  5  6  7  8  9 10
11 12 13 14 15 16 17
18 19 20 21 22 23 24
25 26 27 28 29 30 31
*/

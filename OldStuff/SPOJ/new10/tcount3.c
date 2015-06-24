/*
Alfonso2 Peterssen (mukel)
SPOJ #1731 "Counting Triangles III"
19 - 5 - 2009
Remove this comment to submit(and fix input/output)
*/
main(T){
unsigned long long N;
scanf("%d",&T);
while(T--){
scanf("%llu",&N);printf("%llu\n",N*N*(N*10+9)+N);
}
}


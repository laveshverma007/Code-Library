void  hanoiRecursion( int num,char ndl1, char ndl2, char ndl3)
{
    if ( num == 1 ) {
    printf( "\nMove top disk from needle %c to needle %c.", ndl1, ndl2 );
    return;
     }
     hanoiRecursion( num - 1,ndl1, ndl3, ndl2 );
     printf( "\nMove top disk from needle %c to needle %c.", ndl1, ndl2 );
     hanoiRecursion( num - 1,ndl3, ndl2, ndl1 );
}
int main()
{
  int no;
  printf("Enter the no. of disks to be transferred: ");
  scanf("%d",&no);
  if(no<1)
     printf("\nThere's nothing to move.");
  else
     printf("Non-Recursive");
     hanoiNonRecursion(no,'A','B','C');
     printf("\nRecursive");
     hanoiRecursion(no,'A','B','C');
  return 0;
}
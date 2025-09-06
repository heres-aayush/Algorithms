#include<stdio.h>

int count = 0 ; //global counter

void toh(int n , char A, char B, char C)
{   
    if(n==0)
        return ;
    else
    {
        toh(n-1,A,C,B);
        printf("Move %d from %c to %c \n" , n,A,C);
            count++; //increment counter at every move 
        toh(n-1,B,A,C);
    }
}
int main()
{
    printf("Enter the number of disks: ");
    int n ;
    scanf("%d",&n);
    char A = 'S'; //Source Rod 
    char B = 'A'; //Auxiliary Rod 
    char C = 'D'; //Destination Rod
    toh ( n , A,  B,  C);
    printf("The number of count is : %d", count);
}
/**
* A C program to search an element in sorted 3D Array (Sorted in all the 3 directions).
*/
#include <stdio.h>
#include<stdlib.h>
int matrix[10][10][10];

int main(int argc, char const *argv[])
{
    int i, j, k, n, el,lo,hi,mid;
    printf("Enter the order of the matrix (Assume square)\n"); // Can be easily changed to rectangular too
    scanf("%d", &n);
    printf("Enter a sorted 3D square matrix of order %d\n", n);
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            for (k = 0; k < n; k++)
                scanf("%d", &matrix[i][j][k]);
    printf("Enter the element to be searched\n");
    scanf("%d", &el);
	lo =0;
	hi =n;
	while(lo<=hi)
	{
		mid = (lo+hi)/2;
		if(matrix[mid][0][0] == el)
		{
			printf("Element found at (%d,%d,%d)",mid,0,0);
			exit(0);
		}
		else if(matrix[mid][0][0] <el) lo = mid+1;
		else  hi = mid-1;
	}
	i = hi;
	lo =0;
	hi =n;
	while(lo<=hi)
	{
		mid = (lo+hi)/2;
		if(matrix[i][mid][0] == el)
		{
			printf("Element found at (%d,%d,%d)",i,mid,0);
			exit(0);
		}
		else if(matrix[i][mid][0] <el) lo = mid+1;
		else  hi = mid-1;

	}
	j = hi;
	lo =0;
	hi =n;
	while(lo<=hi)
	{
		mid = (lo+hi)/2;
		if(matrix[i][j][mid] == el)
		{
			printf("Element found at (%d,%d,%d)",i,j,mid);
			exit(0);
		}
		else if(matrix[i][j][mid] <el) lo = mid+1;
		else  hi = mid-1;

	}
    printf("%d not found in the 3D array\n", el);

    return 0;
}

/**
* PostScript:
* The array _has_ to be a sorted one
*
* An example input may be
* 10 11 12 13 14 15 16 17 18 20 21 22 23 24 25 26 27 28 30 31 32 33 34 35 36 37 38
* Which is a 3x3x3 matrix which takes the form
*     10        20         30
*   11        21         31
* 12        22        32
*     13        23         33
*   14        24         34
* 15        25        35
*     16        26         36
*   17        27         37
* 18        28        38
*
*/
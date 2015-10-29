#include<stdio.h>

int maxSubArraySum(int a[], int size, int* max_so_far, int* max_ending_here )
{
    if(size > 0)
        *max_ending_here = maxSubArraySum(a, size-1, max_so_far, max_ending_here) + a[size];
    else
        *max_ending_here = a[size];
    if (*max_ending_here < 0)
        *max_ending_here = 0;
    if (*max_so_far < *max_ending_here)
        *max_so_far = *max_ending_here;

    return *max_ending_here;
}

int maxSubArray(int a[], int size)
{
    int max_so_far = 0, max_ending_here = 0;
    maxSubArraySum(a, size-1, &max_so_far, &max_ending_here );
    return max_so_far;
}

int main()
{
    int a[] = {-2, -3, 4, -1, -2, 1, 5, -3};
    int n = sizeof(a)/sizeof(a[0]);
    int max_sum = maxSubArray(a, n);
    printf("Maximum contiguous sum is %d \n", max_sum);
    return 0;
}

#include <stdio.h>

int main()
{
    int temp = 0;
    int array_1[4][3] = { {10, 11, 14}, {1,3,7}, {2,9,12}, {3,6,15} };
    int *ptr = &array_1[0][0];
    int* ptr1 = ptr + 1;
    for (int i = 0; i < 11; i++)
    {
        temp = *ptr;    // Store array[0][0] (10) in temp
        *ptr = *ptr1;   // 
        *ptr1 = temp;
        ptr++;
        ptr1++;
    }
    for (int i = 0; i < 4; i++)
    {
            for (int j = 0; j < 3; j++)
            {
                    printf("%d ", array_1[i][j]);
            }
            printf("\n");
    }
    return 0;
}
#include <stdio.h>

int main()
{
    int size;
    scanf("%d", &size);

    int numbers[size];

    for(int i = 0; i < size; i++)
    {
        scanf("%d", &numbers[i]);
    }

    for(int pass = 0; pass < size - 1; pass++)
    {
        for(int index = 0; index < size - pass - 1; index++)
        {
            if(numbers[index] > numbers[index + 1])
            {
                int swap = numbers[index];
                numbers[index] = numbers[index + 1];
                numbers[index + 1] = swap;
            }
        }
    }

    for(int i = 0; i < size; i++)
    {
        printf("%d ", numbers[i]);
    }

    printf("\n");

    return 0;
}

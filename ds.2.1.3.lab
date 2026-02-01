#include <stdio.h>

int main()
{
    int size;
    scanf("%d", &size);

    int list[size];

    for(int index = 0; index < size; index++)
    {
        scanf("%d", &list[index]);
    }

    for(int step = 1; step < size; step++)
    {
        int current = list[step];
        int prev = step - 1;

        while(prev >= 0 && list[prev] > current)
        {
            list[prev + 1] = list[prev];
            prev--;
        }

        list[prev + 1] = current;
    }

    for(int i = 0; i < size; i++)
    {
        printf("%d ", list[i]);
    }

    return 0;
}

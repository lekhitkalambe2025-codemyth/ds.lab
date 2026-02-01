#include <stdio.h>

int main()
{
    int size;
    scanf("%d", &size);

    int values[size];

    for(int i = 0; i < size; i++)
    {
        scanf("%d", &values[i]);
    }

    for(int pos = 0; pos < size - 1; pos++)
    {
        int biggest = pos;

        for(int check = pos + 1; check < size; check++)
        {
            if(values[check] > values[biggest])
            {
                biggest = check;
            }
        }

        if(biggest != pos)
        {
            int change = values[pos];
            values[pos] = values[biggest];
            values[biggest] = change;
        }
    }

    for(int i = 0; i < size; i++)
    {
        printf("%d ", values[i]);
    }

    printf("\n");

    return 0;
}

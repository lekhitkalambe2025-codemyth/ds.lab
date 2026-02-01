#include <stdio.h>

int main()
{
    int size, key;

    scanf("%d", &size);

    int numbers[size];

    for(int i = 0; i < size; i++)
    {
        scanf("%d", &numbers[i]);
    }

    scanf("%d", &key);

    int start = 0;
    int end = size - 1;
    int pos = -1;

    while(start <= end)
    {
        int middle = (start + end) / 2;

        if(numbers[middle] == key)
        {
            pos = middle;
            break;
        }
        else if(numbers[middle] < key)
        {
            start = middle + 1;
        }
        else
        {
            end = middle - 1;
        }
    }

    if(pos != -1)
        printf("Element found at index %d\n", pos);
    else
        printf("Element not found\n");

    return 0;
}

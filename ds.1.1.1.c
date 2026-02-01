#include <stdio.h>

int main()
{
    int total, target;
    
    scanf("%d", &total);

    int data[total];

    for(int i = 0; i < total; i++)
    {
        scanf("%d", &data[i]);
    }

    scanf("%d", &target);

    int foundIndex = -1;

    for(int i = 0; i < total; i++)
    {
        if(data[i] == target)
        {
            foundIndex = i;
            break;
        }
    }

    if(foundIndex >= 0)
        printf("found at position %d\n", foundIndex);
    else
        printf("%d not found\n", target);

    return 0;
}

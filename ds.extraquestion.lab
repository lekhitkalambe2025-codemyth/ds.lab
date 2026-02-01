#include <stdio.h>

int main() {
    int n;

    // Input size of array
    printf("Enter size of array: ");
    scanf("%d", &n);

    int arr[n];

    // Input array elements
    printf("Enter array elements:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int target;

    // Input target value
    printf("Enter target: ");
    scanf("%d", &target);

    int found = 0;   // 0 = not found, 1 = found

    // Checking pairs
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {

            if (arr[i] + arr[j] == target) {
                printf("Answer: %d %d\n", i, j);
                found = 1;
                break;
            }
        }

        if (found) {
            break;
        }
    }

    if (!found) {
        printf("No pair found\n");
    }

    return 0;
}

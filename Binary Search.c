#include <stdio.h>

int binarySearch(int arr[], int left, int right, int target) {
    while (left <= right) {
        int mid = left + (right - left) / 2;

       
        if (arr[mid] == target) {
            return mid;
        }

      
        if (arr[mid] > target) {
            right = mid - 1;
        } else {
           
            left = mid + 1;
        }
    }

   
    return -1;
}

int main() {
    int n, target;

   
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    int arr[n];

    
    printf("Enter %d sorted elements: ", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

   
    printf("Enter the element to search for: ");
    scanf("%d", &target);

    
    int result = binarySearch(arr, 0, n - 1, target);

    if (result == -1) {
        printf("Element not found in the array.\n");
    } else {
        printf("Element found at index %d.\n", result);
    }

    return 0;
}
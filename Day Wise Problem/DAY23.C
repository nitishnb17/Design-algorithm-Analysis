#include <stdio.h>
void sortArrayByParity(int nums[], int n) {
    int left = 0;
    int right = n - 1;
    while (left < right) {
        // Find an odd number from the left
        while (left < right && nums[left] % 2 == 0) {
            left++;
        }
        // Find an even number from the right
        while (left < right && nums[right] % 2 != 0) {
            right--;
        }
        // Swap odd and even numbers
        if (left < right) {
            int temp = nums[left];
            nums[left] = nums[right];
            nums[right] = temp;
            left++;
            right--;
        }
    }
}
int main() {
    int nums[] = {3, 1, 2, 4};
    int n = sizeof(nums) / sizeof(nums[0]);
    sortArrayByParity(nums, n);
    printf("Output: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", nums[i]);
    }
    return 0;}
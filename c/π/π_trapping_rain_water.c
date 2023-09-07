#include <stdio.h>

int trap(int* height, int heightSize) {
    int left = 0;
    int right = heightSize - 1;
    int maxLeft = 0;
    int maxRight = 0;

    int result = 0;

    while (left <= right) {
        if (height[left] <= height[right]) {
            if (height[left] >= maxLeft) {
                maxLeft = height[left];
            }
            else {
                result += maxLeft - height[left];
            }
            left++;
        }
        else {
            if (height[right] >= maxRight) {
                maxRight = height[right];
            }
            else {
                result += maxRight - height[right];
            }
            right--;

        }
    }
    return result;
}

void visualizer(int*height, int heightSize) {
    int sum = 0;
    for (int k = 0; k < heightSize; k++) {
        printf("_");
    }
    printf("\n");
    do {
        sum = 0;
        for (int k = 0; k < heightSize; k++) {
            if (height[k] > 0) {
                printf("|");
                height[k]--;
            }
            else {
                printf(" ");
            }
            sum += height[k];
        }
        printf("\n");
    }
    while (sum != 0);
    for (int k = 0; k < heightSize; k++) {
        printf("-");
    }
    printf("\n");
}

int main() {
    int input[10] = {3, 2, 1, 0, 3, 0, 2, 1, 2, 3};
    int result = trap(input, 10);
    visualizer(input, 10);
    printf("This formation collects %d units of rain.\n", result);
}

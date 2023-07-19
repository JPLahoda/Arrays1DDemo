//Jason Lahoda, 2/26/2023, CIS2107
//Lab 4 1D Arrays
//This program contains a series of 1D array functions.

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define RAND_MIN 0
#define RAND_MAX 100

void printArray(int arr[], int size){
    for (int i = 0; i < size; i++) {
        if (i % 10 == 0 && i != 0){
            puts("\n");
        }
        printf("%d ", arr[i]);
    }
}

void fillArray(int arr[], int size) {

    srand((unsigned)time(NULL));

    for (int i = 0; i < size; i++) {
        arr[i] = rand() % (RAND_MAX - RAND_MIN + 1) + RAND_MIN;
    }
    
}

int findWithRange(int arr[], int lowSelectedRange, int highSelectedRange) {

    if (lowSelectedRange < 0 || highSelectedRange < 0 || highSelectedRange < lowSelectedRange) {
        puts("Error: out of bounds or invalid range. Exiting program.\n");
        exit(0);
    }

    int greatest = arr[lowSelectedRange];

    for (int i = lowSelectedRange + 1; i <= highSelectedRange; i++) {
        if (arr[i] > greatest) {
            greatest = arr[i];
        }
    }

    return greatest;
}

void reverseArray(int arr[], int size) {
    int temp;
    
    for(int i = 0; i < size / 2; i++) {
        temp = arr[i];
        arr[i] = arr[size - i - 1];
        arr[size - i - 1] = temp;
    }
    
}

void reverseSelectedRangeWithinArray(int arr[], int size, int startRange, int endRange) {
    
    if(startRange >= endRange || startRange >= size || endRange >= size || startRange < 0 || endRange < 0) {
        return;
        puts("Error: The selected range could not be reversed. Exiting program.\n");
    }
    
    int temp;
    
    for(int i = startRange; i <= (startRange + endRange) / 2; i++) {
        temp = arr[i];
        arr[i] = arr[endRange - i + startRange];
        arr[endRange - i + startRange] = temp;
    }
    
}

int findSequence(int arr[], int size, int num1, int num2) {
    
    for(int i = 0; i < size - 1; i++) {
        if(arr[i] == num1 && arr[i + 1] == num2) {
            return i;
        }
    }
    
    return -1;
}


int main() {
    //fillArray()
    int size;
    puts("What will the size of the array be?");
    scanf("%d", &size);
    int arr[size];
    fillArray(arr, size);
    printArray(arr, size);
    
    
    printf("\n");
    
    
    //findWithRange()
    int lowRange;
    int highRange;
    puts("What will the low range be?\n");
    scanf("%d", &lowRange);
    puts("What will the high range be?\n");
    scanf("%d", &highRange);
    int withRange = findWithRange(arr, lowRange, highRange);
    
    if (withRange == -1){
        puts("Error: out of bounds or invalid range. Exiting program.\n");
        exit(0);
    }
    
    printf("The maximum in the given range of elements is %d.\n", withRange);
    
    
    //reverseArray
    reverseArray(arr, size);
    puts("This is the array reversed:\n");
    printArray(arr, size);
    
    
    //reverseSelectedRangeWithinArray()
    reverseSelectedRangeWithinArray(arr, size, lowRange, highRange);
    puts("\nThese are the elements in the selected range of the newly reversed array, reversed:\n");
    printArray(arr, size);
    
    
    //findSequence()
    int num1;
    int num2;
    puts("\nWhat will the first number be?\n");
    scanf("%d", &num1);
    puts("What will the second number be?\n");
    scanf("%d", &num2);
    int sequence = findSequence(arr, size, num1, num2);
    if (sequence == -1){
        puts("Error: The sequence was not found. Exiting program.");
    }
    else{
        printf("The sequence %d and %d was found at index %d.", num1, num2, sequence);
    }
    
    exit(0);
}
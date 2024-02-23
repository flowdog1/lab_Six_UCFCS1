#include <stdio.h>
#include <stdlib.h>

// Recursive binary search 
int search(int numbers[], int low, int high, int value) {
    if (high >= low) {
        int mid = low + (high - low) / 2;
      
        if (numbers[mid] == value) return mid;
      
        if (numbers[mid] > value) return search(numbers, low, mid - 1, value);
      
        return search(numbers, mid + 1, high, value);
    }
    return -1;
}

//Prints the array
void printArray(int numbers[], int sz) {
    int i;
    printf("Number array : ");
    for (i = 0; i < sz; ++i) {
        printf("%d ", numbers[i]);
    }
    printf("\n");
}

int main(void) {
    int i, numInputs;
    int value;
    int index;
    int* numArray = NULL;
    int countOfNums;
    FILE* inFile = fopen("input.txt", "r");

    if (inFile == NULL) {
        printf("Failed to open the file\n");
        return 1;
    }

    fscanf(inFile, " %d\n", &numInputs);

  
  // Loop through test cases by numInputs
    while (numInputs-- > 0) {
        fscanf(inFile, " %d\n", &countOfNums);
        numArray = (int *)malloc(countOfNums * sizeof(int));
        float average = 0;
        for (i = 0; i < countOfNums; i++) {
            fscanf(inFile, " %d", &value);
            numArray[i] = value;
            average += numArray[i];
        }

        printArray(numArray, countOfNums);
        value = (int)(average / countOfNums); 
        index = search(numArray, 0, countOfNums - 1, value);
        if (index >= 0) {
            printf("Item %d exists in the number array at index %d!\n", value, index);
        } else {
            printf("Item %d does not exist in the number array!\n", value);
        }

        free(numArray);
    }

    fclose(inFile);
    return 0;
}
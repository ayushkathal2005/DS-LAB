
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 50

void display_array(int* array, int size);
void insert_at_begin(int* array, int* size, int num);
void insert_at_end(int* array, int* size, int num);
void insert_at_pos(int* array, int* size, int num, int pos);
// Delete Operations
void delete_first(int* array, int* size);
void delete_last(int* array, int* size);
void delete_at_pos(int* array, int* size, int pos);

// Linear Search
void linear_search(int* array, int size, int num);

// Sorting
void bubble_sort(int* array, int size);

int main ()  {
    int n;
    printf("Enter the size for the array.\n");
    scanf("%d", &n);
    if (n > MAX_SIZE) {
        printf("Array size cannot be greater than allowed size (%d)\n", MAX_SIZE);
        n = MAX_SIZE;
    } 
    printf("Creating an array of size %d\n", n);

    int arr[MAX_SIZE];

    for (int i = 0; i < n; i++) {
        if ((i + 1) % 10 == 1 && (i + 1) % 100 != 11) {
            printf("Enter %dst number - ", (i + 1));
            scanf("%d", &arr[i]);
        }
        else if ((i + 1) % 10 == 2 && (i + 1) % 100 != 12) {
            printf("Enter %dnd number - ", (i + 1));
            scanf("%d", &arr[i]);
        }
        else if ((i + 1) % 10 == 3 && (i + 1) % 100 != 13) {
            printf("Enter %drd number - ", (i + 1));
            scanf("%d", &arr[i]);
        } 
        else {
            printf("Enter %dth number - ", (i + 1));
            scanf("%d", &arr[i]);
        }
    }

    printf("Displaying array elements\n");
    display_array(arr, n);

    printf("Inserting 24 at the beginning\n");
    insert_at_begin(arr, &n, 24);
    display_array(arr, n);

    printf("Inserting 12 at the end\n");
    insert_at_end(arr, &n, 12);
    display_array(arr, n);

    printf("Inserting 48 at the 4th position\n");
    insert_at_pos(arr, &n, 48, 4);
    display_array(arr, n);

    printf("Deleting first element\n");
    delete_first(arr, &n);
    display_array(arr, n);

    printf("Deleting last element\n");
    delete_last(arr, &n);
    display_array(arr, n);

    printf("Deleting element at 3rd position\n");
    delete_at_pos(arr, &n, 3);
    display_array(arr, n);

    printf("Finding 4 in the array\n");
    linear_search(arr, n, 4);

    printf("Sorting the array using Bubble Sort\n");
    bubble_sort(arr, n);
    display_array(arr, n);

    return 0;
}

void display_array(int* array, int size) {
    for (int i = 0; i < size; i++) {
        if ((i + 1) % 10 == 1 && (i + 1) % 100 != 11) {
            printf("%dst element : %d\n", (i + 1), array[i]);
        }
        else if ((i + 1) % 10 == 2 && (i + 1) % 100 != 12) {
            printf("%dnd element : %d\n", (i + 1), array[i]);
        }
        else if ((i + 1) % 10 == 3 && (i + 1) % 100 != 13) {
            printf("%drd element : %d\n", (i + 1), array[i]);
        } 
        else {
            printf("%dth element : %d\n", (i + 1), array[i]);
        }
    }
} 

void insert_at_begin(int* array, int* size, int num) {
   if (*size >= MAX_SIZE) {
        printf("Array is full.\n");
   } else {
       for (int i = *size - 1; i >= 0; i--) {
            array[i + 1] = array[i];
       } 
       array[0] = num;
        (*size)++;
   }
}

void insert_at_end(int* array, int* size, int num) {
   if (*size >= MAX_SIZE) {
        printf("Array is full.\n");
   } else {
       array[*size] = num; 
       (*size)++;
   }
}

void insert_at_pos(int* array, int* size, int num, int pos) {
   if (pos < 0 || pos >= *size) {
        printf("Enter a valid position.\n");
        return;
   }
   if (*size >= MAX_SIZE) {
        printf("Array is full.\n");
        return;
   }
    for (int i = *size; i >= pos; i--) {
        array[i] = array[i - 1];
    }     
    array[pos - 1] = num;
    (*size)++;
}

void delete_first(int* array, int* size) {
    array[0] = (int)NULL;
    for (int i = 0; i < *size; i++) {
        array[i] = array[i + 1];
    }
    (*size)--;
}

void delete_last(int* array, int* size) {
    array[*size - 1] = (int)NULL;
    (*size)--;
}

void delete_at_pos(int* array, int* size, int pos) {
   if (pos < 0 || pos > *size || pos > MAX_SIZE) {
        printf("Enter a valid position.\n");
        return;
   } 

   for (int i = pos - 1; i < *size; i++) {
       array[i] = array[i + 1];
   }
   array[*size - 1] = (int)NULL;
   (*size)--;
}

void linear_search(int* array, int size, int num) {
    for (int i = 0; i < size; i++) {
        if (array[i] == num) {
            printf("Found %d at position %d\n", num, (i + 1));
            return;
        }
    }
    printf("Could not find %d in the array.\n");
}

void bubble_sort(int* array, int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - 1 - i; j++) {
            if (array[j] > array[j + 1]) {
                int temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }
}
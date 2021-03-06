#include <string.h>
#include <stdio.h>
#include <stdlib.h>

// TODO:
// Create a struct called CircularBuffer
// It should store:
// A pointer that points to the start of a dynamically allocated array of ints (could be null) (head pointer)
// A pointer that points to the end of the dynamically allocated array of ints (could be null) (tail pointer)
// A pointer that points to the currently readable buffer item (could be null) (read pointer))
// A pointer that points to the currently writable buffer item (could be null) (write pointer)
// The lenght of the buffer

// TODO:
// Create a function that returns a dynamically allocated CircularBuffer (the buffer itself should be allocated as well, not just the array inside)
// It should take a normal array and it's length as argument, and it should fill all the buffer values from the array

// TODO:
// Create a function that resizes a CircularBuffer, it should take a CircularBuffer as a pointer and change that buffers length and reallocate it's array as well. (copying it's values)

// TODO:
// Create a function that takes a CircularBuffer and returns a new CircularBuffer that only contains the even numbers from the old CircularBuffer

// TODO:
// Try all the functions in the main function, plase deallocate any buffer and the array inside it after using them

typedef struct {
    int* head;
    int* tail;
    int* read;
    int* write;
} CircularBuffer;

CircularBuffer *DynamicalAllocateArray (int *arr, int arr_len);

int main()
{
    int array_of_ints[] = {21, 32, 54};
    int len_arr = sizeof(array_of_ints)/sizeof(array_of_ints[0]);

    CircularBuffer *cir;
    cir = DynamicalAllocateArray(array_of_ints, 3);


    return 0;
}

CircularBuffer *DynamicalAllocateArray (int *arr, int arr_len)
{
    int *temp = (int*)calloc(arr_len, sizeof(int));
    memccpy(temp, arr, arr_len*sizeof(int));

    CircularBuffer *CB_Temp = malloc(sizeof(CircularBuffer));
    CB_Temp -> head = temp; // az �j CircuralBuffer feje be lett �ll�tva a temp els� elem�re.
    CB_Temp -> read = temp;
    CB_Temp -> write = temp;
    CB_Temp -> tail = temp[arr_len - 1];

    return CB_Temp;
}





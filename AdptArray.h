#ifndef ADAPTARRAY_H
#define ADAPTARRAY_H

typedef void* PElement;
typedef enum  {FAIL = 0, SUCCESS=1} Result;

typedef void(*DEL_FUNC)(PElement);
typedef PElement(*COPY_FUNC)(PElement);
typedef void(*PRINT_FUNC)(PElement);

typedef struct AdptArray_{
    int size;
    DEL_FUNC f_del;
    COPY_FUNC f_copy;
    PRINT_FUNC f_print;
    PElement * arr;
}AdptArray;

typedef struct AdptArray_* PAdptArray;


// Create a new adaptive array with the given functions
PAdptArray CreateAdptArray(COPY_FUNC, DEL_FUNC, PRINT_FUNC);

// Free the memory allocated for the adaptive array and its elements
void DeleteAdptArray(PAdptArray);

// Set the element at the given index in the adaptive array
Result SetAdptArrayAt(PAdptArray, int, PElement);

// Get the element at the given index in the adaptive array
PElement GetAdptArrayAt(PAdptArray, int);

// Get the current size of the adaptive array
int GetAdptArraySize(PAdptArray);

// Print the contents of the adaptive array
void PrintDB(PAdptArray);

//increase the adaptive array if the index>size
int increase_arr(PAdptArray adpt,int i);


#endif
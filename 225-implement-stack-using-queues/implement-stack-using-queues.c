
#include <stdlib.h>
#include <stdbool.h>

#define STACK_CAPACITY 105

typedef struct {
    int q1[STACK_CAPACITY];
    int q2[STACK_CAPACITY];
    int f1, r1;
    int f2, r2;
} MyStack;

MyStack* myStackCreate() {
    MyStack* obj = malloc(sizeof(MyStack));

    obj->f1 = 0;
    obj->r1 = -1;
    obj->f2 = 0;
    obj->r2 = -1;

    return obj;
}

// Push operation
void myStackPush(MyStack* obj, int x) {

    obj->q2[++obj->r2] = x;

    // Move q1 elements into q2
    while (obj->f1 <= obj->r1) {
        obj->q2[++obj->r2] = obj->q1[obj->f1++];
    }

    // Reset q1
    obj->f1 = 0;
    obj->r1 = -1;

    // Copy q2 to q1 in the SAME order
    while (obj->f2 <= obj->r2) {
        obj->q1[++obj->r1] = obj->q2[obj->f2++];
    }

    // Reset q2
    obj->f2 = 0;
    obj->r2 = -1;
}

// Pop operation
int myStackPop(MyStack* obj) {
    return obj->q1[obj->f1++];
}

// Top operation
int myStackTop(MyStack* obj) {
    return obj->q1[obj->f1];
}

// Empty operation
bool myStackEmpty(MyStack* obj) {
    return obj->f1 > obj->r1;
}

// Free memory
void myStackFree(MyStack* obj) {
    free(obj);
}

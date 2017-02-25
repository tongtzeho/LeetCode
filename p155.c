typedef struct {
    int *val;
    int *minval;
    int maxsize;
    int size;
} MinStack;

/** initialize your data structure here. */
MinStack* minStackCreate(int maxSize) {
    MinStack *result = (MinStack*)malloc(sizeof(MinStack));
    result->size = 0;
    result->maxsize = maxSize;
    result->val = (int*)malloc(sizeof(int)*maxSize);
    result->minval = (int*)malloc(sizeof(int)*maxSize);
    return result;
}

void minStackPush(MinStack* obj, int x) {
    obj->val[obj->size] = x;
    if (obj->size == 0)
    {
        obj->minval[0] = x;
    }
    else
    {
        if (x < obj->minval[obj->size-1]) obj->minval[obj->size] = x;
        else obj->minval[obj->size] = obj->minval[obj->size-1];
    }
    obj->size++;
}

void minStackPop(MinStack* obj) {
    obj->size--;
}

int minStackTop(MinStack* obj) {
    return obj->val[obj->size-1];
}

int minStackGetMin(MinStack* obj) {
    return obj->minval[obj->size-1];
}

void minStackFree(MinStack* obj) {
    
}

/**
 * Your MinStack struct will be instantiated and called as such:
 * struct MinStack* obj = minStackCreate(maxSize);
 * minStackPush(obj, x);
 * minStackPop(obj);
 * int param_3 = minStackTop(obj);
 * int param_4 = minStackGetMin(obj);
 * minStackFree(obj);
 */
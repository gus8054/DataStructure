#include "ArrayList.h"

ArrayList* AL_Create(int maxElementCount){
    if(maxElementCount <= 0) return NULL;

    ArrayList* pReturn = (ArrayList*)malloc(sizeof(ArrayList));
    if(pReturn == NULL) return NULL;

    pReturn->currentElementCount = 0;
    pReturn->maxElementCount = maxElementCount;
    ArrayListNode* pTemp = (ArrayListNode*)malloc(sizeof(ArrayListNode) * maxElementCount);
    if(pTemp == NULL){
        free(pReturn);
        return NULL;
    }
    pReturn->pElement = pTemp;
    return pReturn;
}

void AL_Destroy(ArrayList* pList){
    if(pList == NULL) return;
    if(pList->pElement != NULL) free(pList->pElement);
    free(pList);
}

bool AL_Insert(ArrayList* pList, int position, ElementType data){
    if(pList == NULL) return false;
    if(position < 0 || position > pList->currentElementCount) return false;
    if(pList->currentElementCount == pList->maxElementCount){
        pList->maxElementCount *= 2;
        ArrayListNode* pTemp = (ArrayListNode*)realloc(pList->pElement, sizeof(ArrayListNode) * pList->maxElementCount);
        if(pTemp == NULL) return false;
        pList->pElement = pTemp;
    }

    memmove(&(pList->pElement[position + 1]), &(pList->pElement[position]), sizeof(ArrayListNode) * (pList->currentElementCount - position));
    pList->pElement[position].data = data;
    pList->currentElementCount++;
    return true;
}

bool AL_Remove(ArrayList* pList, int position){
    if(pList == NULL) return false;
    if(position < 0 || position > pList->currentElementCount - 1) return false;
    memmove(&(pList->pElement[position]), &(pList->pElement[position + 1]), sizeof(ArrayListNode) * (pList->currentElementCount - position - 1));
    pList->currentElementCount--;
    return true;
}

bool AL_Clear(ArrayList* pList){
    if(pList == NULL) return false;
    pList->currentElementCount = 0;
    return true;
}

int AL_Search(ArrayList* pList, ElementType data){
    if(pList == NULL) return -1;
    
    for(int i = 0; i < pList->currentElementCount; i++){
        if(pList->pElement[i].data == data) return i;
    }
    return -1;
}

ArrayListNode* AL_GetAt(ArrayList* pList, int position){
    if(pList == NULL) return NULL;
    if(position < 0 || position > pList->currentElementCount - 1) return NULL;
    return &(pList->pElement[position]);
}

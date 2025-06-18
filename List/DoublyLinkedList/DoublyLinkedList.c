#include "DoublyLinkedList.h"

DoublyLinkedList* DLL_Create(){
    DoublyLinkedList* pReturn = (DoublyLinkedList*)malloc(sizeof(DoublyLinkedList));
    if(pReturn == NULL) return NULL;

    pReturn->currentElementCount = 0;
    pReturn->headNode.pLeftLink = &(pReturn->headNode);
    pReturn->headNode.pRightLink = &(pReturn->headNode);
    return pReturn;
}

void DLL_Destroy(DoublyLinkedList* pList){
    if(pList == NULL) return;
    
    DoublyLinkedListNode* pCurrentNode = pList->headNode.pRightLink;
    DoublyLinkedListNode* pDelNode = NULL;

    for(int i = 0; i < pList->currentElementCount; i++){
        pDelNode = pCurrentNode;
        pCurrentNode = pCurrentNode->pRightLink;
        DLL_DestroyNode(pDelNode);
    }

    free(pList);
}

DoublyLinkedListNode* DLL_CreateNode(ElementType data){
    DoublyLinkedListNode* pReturn = (DoublyLinkedListNode*)malloc(sizeof(DoublyLinkedListNode));
    if(pReturn == NULL) return NULL;

    pReturn->data = data;
    pReturn->pLeftLink = NULL;
    pReturn->pRightLink = NULL;
    return pReturn;
}

void DLL_DestroyNode(DoublyLinkedListNode* pNode){
    if(pNode == NULL) return;
    free(pNode);
}

bool DLL_InsertNode(DoublyLinkedList* pList, int position, DoublyLinkedListNode* pNode){
    if(pList == NULL || pNode == NULL) return false;
    if(position < 0 || position > pList->currentElementCount) return false;

    DoublyLinkedListNode* pPreNode = &(pList->headNode);
    for(int i = 0; i < position; i++){
        pPreNode = pPreNode->pRightLink;
    }
    DoublyLinkedListNode* pNextNode = pPreNode->pRightLink;
    pNode->pRightLink = pNextNode;
    pNode->pLeftLink = pPreNode;
    pPreNode->pRightLink = pNode;
    pNextNode->pLeftLink = pNode;
    
    pList->currentElementCount++;
    return true;
}

bool DLL_RemoveNode(DoublyLinkedList* pList, int position){
    if(pList == NULL) return false;
    if(position < 0 || position > pList->currentElementCount-1) return false;

    DoublyLinkedListNode* pPreNode = &(pList->headNode);
    for(int i = 0; i < position; i++){
        pPreNode = pPreNode->pRightLink;
    }
    DoublyLinkedListNode* pDelNode = pPreNode->pRightLink;
    DoublyLinkedListNode* pNextNode = pDelNode->pRightLink;
    pPreNode->pRightLink = pNextNode;
    pNextNode->pLeftLink = pPreNode;
    DLL_DestroyNode(pDelNode);

    pList->currentElementCount--;
    return true;
}

bool DLL_Clear(DoublyLinkedList* pList){
    if(pList == NULL) return false;

    DoublyLinkedListNode* pCurrentNode = pList->headNode.pRightLink;
    DoublyLinkedListNode* pDelNode = NULL;

    for(int i = 0; i < pList->currentElementCount; i++){
        pDelNode = pCurrentNode;
        pCurrentNode = pCurrentNode->pRightLink;
        DLL_DestroyNode(pDelNode);
    }

    pList->currentElementCount = 0;
    pList->headNode.pLeftLink = &(pList->headNode);
    pList->headNode.pRightLink = &(pList->headNode);
    return true;
}

int DLL_Search(DoublyLinkedList* pList, ElementType data){
    if(pList == NULL) return -1;

    DoublyLinkedListNode* pCurrentNode = pList->headNode.pRightLink;
    for(int i = 0; i < pList->currentElementCount; i++){
        if(pCurrentNode->data == data) return i;
        pCurrentNode = pCurrentNode->pRightLink;
    }
    return -1;
}

DoublyLinkedListNode* DLL_GetAt(DoublyLinkedList* pList, int position){
    if(pList == NULL) return NULL;
    if(position < 0 || position > pList->currentElementCount - 1) return NULL;

    DoublyLinkedListNode* pTargetNode = &(pList->headNode);
    for(int i = 0; i < position+1; i++){
        pTargetNode = pTargetNode->pRightLink;
    }
    return pTargetNode;
}
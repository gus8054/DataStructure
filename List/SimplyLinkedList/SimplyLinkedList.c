#include "SimplyLinkedList.h"

SimplyLinkedList* SLL_Create(){
    SimplyLinkedList* pReturn = (SimplyLinkedList*)malloc(sizeof(SimplyLinkedList));
    if(pReturn == NULL) return NULL;
    
    memset(pReturn, 0, sizeof(SimplyLinkedList));
    return pReturn;
}

void SLL_Destroy(SimplyLinkedList* pList){
    if(pList == NULL) return;
    
    SimplyLinkedListNode* pCurrentNode = pList->headNode.pLink;
    SimplyLinkedListNode* pDelNode = NULL;

    while(pCurrentNode){
        pDelNode = pCurrentNode;
        pCurrentNode = pCurrentNode->pLink;
        SLL_DestroyNode(pDelNode);
    }
    free(pList);
}

SimplyLinkedListNode* SLL_CreateNode(ElementType data){
    SimplyLinkedListNode* pReturn = (SimplyLinkedListNode*)malloc(sizeof(SimplyLinkedListNode));
    if(pReturn == NULL) return NULL;

    pReturn->data = data;
    pReturn->pLink = NULL;

    return pReturn;
}

void SLL_DestroyNode(SimplyLinkedListNode* pNode){
    if(pNode == NULL) return;
    free(pNode);
}

bool SLL_InsertNode(SimplyLinkedList* pList, int position, SimplyLinkedListNode* pNewNode){
    if(pList == NULL) return false;
    if(position < 0 || position > pList->currentElementCount) return false;

    SimplyLinkedListNode* pPreNode = &(pList->headNode);
    for(int i = 0; i < position; i++){
       pPreNode = pPreNode->pLink; 
    }
    pNewNode->pLink = pPreNode->pLink;
    pPreNode->pLink = pNewNode;
    pList->currentElementCount++;
    return true;
}

bool SLL_RemoveNode(SimplyLinkedList* pList, int position){
    if(pList == NULL) return false;
    if(position < 0 || position > pList->currentElementCount - 1) return false;

    SimplyLinkedListNode* pPreNode = &(pList->headNode);
    for(int i = 0; i < position; i++){
        pPreNode = pPreNode->pLink;
    }
    SimplyLinkedListNode* pDelNode = pPreNode->pLink;
    pPreNode->pLink = pDelNode->pLink;
    SLL_DestroyNode(pDelNode);
    pList->currentElementCount--;
    return true;
}

bool SLL_Clear(SimplyLinkedList* pList){
    if(pList == NULL) return false;

    SimplyLinkedListNode* pCurrentNode = pList->headNode.pLink;
    SimplyLinkedListNode* pDelNode = NULL;
    while(pCurrentNode){
        pDelNode = pCurrentNode;
        pCurrentNode = pCurrentNode->pLink;
        SLL_DestroyNode(pDelNode);
    }
    pList->currentElementCount = 0;
    pList->headNode.pLink = NULL;
    return true;
}

int SLL_Search(SimplyLinkedList* pList, ElementType data){
    if(pList == NULL) return -1;

    SimplyLinkedListNode* pCurrentNode = pList->headNode.pLink;
    for(int i = 0; i < pList->currentElementCount; i++){
        if(pCurrentNode->data == data) return i;
        pCurrentNode = pCurrentNode->pLink;
    }
    return -1;
}

SimplyLinkedListNode* SLL_GetAt(SimplyLinkedList* pList, int position){
    if(pList == NULL) return NULL;
    if(position < 0 || position > pList->currentElementCount - 1) return NULL;

    SimplyLinkedListNode* pTargetNode = pList->headNode.pLink;
    for(int i = 0; i < position; i++){
        pTargetNode = pTargetNode->pLink;
    }
    return pTargetNode;
}
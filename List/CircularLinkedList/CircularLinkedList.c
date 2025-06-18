#include "CircularLinkedList.h"

CircularLinkedList* CLL_Create(){
    CircularLinkedList* pReturn = (CircularLinkedList*)malloc(sizeof(CircularLinkedList));
    if(pReturn == NULL) return NULL;

    pReturn->currentElementCount = 0;
    pReturn->pHeader = NULL;
    return pReturn;
}

void CLL_Destroy(CircularLinkedList* pList){
    if(pList == NULL) return;

    CircularLinkedListNode* pCurrentNode = pList->pHeader;
    CircularLinkedListNode* pDelNode = NULL;

    for(int i = 0; i < pList->currentElementCount; i++){
        pDelNode = pCurrentNode;
        pCurrentNode = pCurrentNode->pLink;
        CLL_DestroyNode(pDelNode);
    }
    free(pList);
}

CircularLinkedListNode* CLL_CreateNode(ElementType data){
    CircularLinkedListNode* pReturn = (CircularLinkedListNode*)malloc(sizeof(CircularLinkedListNode));
    if(pReturn == NULL) return NULL;

    pReturn->data = data;
    pReturn->pLink = pReturn;
    return pReturn;
}

void CLL_DestroyNode(CircularLinkedListNode* pNode){
    if(pNode == NULL) return;
    free(pNode);
}

bool CLL_InsertNode(CircularLinkedList* pList, int position, CircularLinkedListNode* pNode){
    if(pList == NULL) return false;
    if(position < 0 || position > pList->currentElementCount) return false;

    if(pList->pHeader == NULL) pList->pHeader = pNode;
    else if(position == 0){
        CircularLinkedListNode* pLastNode = pList->pHeader;
        while(pLastNode->pLink != pList->pHeader){
            pLastNode = pLastNode->pLink;
        }
        pNode->pLink = pList->pHeader;
        pLastNode->pLink = pNode;
        pList->pHeader = pNode;
    }else{
        CircularLinkedListNode* pPreNode = pList->pHeader;
        for(int i = 0; i < position - 1; i++){
            pPreNode = pPreNode->pLink;
        }
        pNode->pLink = pPreNode->pLink;
        pPreNode->pLink = pNode;
    }
    pList->currentElementCount++;
    return true;
}

bool CLL_RemoveNode(CircularLinkedList* pList, int position){
    if(pList == NULL) return false;
    if(position < 0 || position > pList->currentElementCount - 1) return false;

    if(pList->currentElementCount == 1){
        CLL_DestroyNode(pList->pHeader);
        pList->pHeader = NULL;
    }else if(position == 0){
        CircularLinkedListNode* pLastNode = pList->pHeader;
        while(pLastNode->pLink != pList->pHeader){
            pLastNode = pLastNode->pLink;
        }
        CircularLinkedListNode* pDelNode = pList->pHeader;
        pLastNode->pLink = pDelNode->pLink;
        pList->pHeader = pDelNode->pLink;
        CLL_DestroyNode(pDelNode);
    }else{
        CircularLinkedListNode* pPreNode = pList->pHeader;
        for(int i = 0; i < position - 1; i++){
            pPreNode = pPreNode->pLink;
        }
        CircularLinkedListNode* pDelNode = pPreNode->pLink;
        pPreNode->pLink = pDelNode->pLink;
        CLL_DestroyNode(pDelNode);
    }
    pList->currentElementCount--;
    return true;
}

bool CLL_Clear(CircularLinkedList* pList){
    if(pList == NULL) return false;
    
    CircularLinkedListNode* pCurrentNode = pList->pHeader;
    CircularLinkedListNode* pDelNode = NULL;

    for(int i = 0; i < pList->currentElementCount; i++){
        pDelNode = pCurrentNode;
        pCurrentNode = pCurrentNode->pLink;
        CLL_DestroyNode(pDelNode);
    }

    pList->currentElementCount = 0;
    pList->pHeader = NULL;
    return true;
}

int CLL_Search(CircularLinkedList* pList, ElementType data){
    if(pList == NULL) return -1;

    CircularLinkedListNode* pCurrentNode = pList->pHeader;
    for(int i = 0; i < pList->currentElementCount; i++){
        if(pCurrentNode->data == data) return i;
        pCurrentNode = pCurrentNode->pLink;
    }
    return -1;
}

CircularLinkedListNode* CLL_GetAt(CircularLinkedList* pList, int position){
    if(pList == NULL) return false;
    if(position < 0 || position > pList->currentElementCount - 1) return false;

    CircularLinkedListNode* pCurrentNode = pList->pHeader;
    for(int i = 0; i < position; i++){
        pCurrentNode = pCurrentNode->pLink;
    }
    return pCurrentNode;
}
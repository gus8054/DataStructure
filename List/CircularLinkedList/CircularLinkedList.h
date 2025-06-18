#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef int ElementType;

typedef struct CircularLinkedListNodeTag{
    ElementType data;
    struct CircularLinkedListNodeTag* pLink;
}CircularLinkedListNode;

typedef struct CircularLinkedListTag{
    int currentElementCount;
    CircularLinkedListNode* pHeader;
} CircularLinkedList;

CircularLinkedList* CLL_Create();
void CLL_Destroy(CircularLinkedList* pList);
CircularLinkedListNode* CLL_CreateNode(ElementType data);
void CLL_DestroyNode(CircularLinkedListNode* pNode);
bool CLL_InsertNode(CircularLinkedList* pList, int position, CircularLinkedListNode* pNode);
bool CLL_RemoveNode(CircularLinkedList* pList, int position);
bool CLL_Clear(CircularLinkedList* pList);
int CLL_Search(CircularLinkedList* pList, ElementType data);
CircularLinkedListNode* CLL_GetAt(CircularLinkedList* pList, int position);

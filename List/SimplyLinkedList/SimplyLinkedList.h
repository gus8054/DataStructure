#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef int ElementType;

typedef struct SimplyLinkedListNodeTag{
    ElementType data;
    struct SimplyLinkedListNodeTag* pLink;
} SimplyLinkedListNode;

typedef struct SimplyLinkedListTag{
    int currentElementCount;
    SimplyLinkedListNode headNode;
} SimplyLinkedList;

SimplyLinkedList* SLL_Create();
void SLL_Destroy(SimplyLinkedList* pList);
SimplyLinkedListNode* SLL_CreateNode(ElementType data);
void SLL_DestroyNode(SimplyLinkedListNode* pNode);
bool SLL_InsertNode(SimplyLinkedList* pList, int position, SimplyLinkedListNode* pNode);
bool SLL_RemoveNode(SimplyLinkedList* pList, int position);
bool SLL_Clear(SimplyLinkedList* pList);
int SLL_Search(SimplyLinkedList* pList, ElementType data);
SimplyLinkedListNode* SLL_GetAt(SimplyLinkedList* pList, int position);


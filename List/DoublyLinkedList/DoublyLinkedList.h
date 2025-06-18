#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef int ElementType;

typedef struct DoublyLinkedListNodeTag{
    ElementType data;
    struct DoublyLinkedListNodeTag* pLeftLink;
    struct DoublyLinkedListNodeTag* pRightLink;
} DoublyLinkedListNode;

typedef struct DoublyLinkedListTag{
    int currentElementCount;
    DoublyLinkedListNode headNode;
} DoublyLinkedList;

DoublyLinkedList* DLL_Create();
void DLL_Destroy(DoublyLinkedList* pList);
DoublyLinkedListNode* DLL_CreateNode(ElementType data);
void DLL_DestroyNode(DoublyLinkedListNode* pNode);
bool DLL_InsertNode(DoublyLinkedList* pList, int position, DoublyLinkedListNode* pNode);
bool DLL_RemoveNode(DoublyLinkedList* pList, int position);
bool DLL_Clear(DoublyLinkedList* pList);
int DLL_Search(DoublyLinkedList* pList, ElementType data);
DoublyLinkedListNode* DLL_GetAt(DoublyLinkedList* pList, int position);



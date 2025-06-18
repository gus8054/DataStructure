#include "CircularLinkedList.c"
// 테스트 매크로
#define TEST_ASSERT(cond, msg) \
    do { \
        if (cond) printf("[PASS] %s\n", msg); \
        else printf("[FAIL] %s\n", msg); \
    } while(0)

// 테스트 함수
void test_create_and_destroy() {
    CircularLinkedList* list = CLL_Create();
    TEST_ASSERT(list != NULL, "Create returns non-NULL");
    TEST_ASSERT(list->currentElementCount == 0, "Initial element count is 0");
    TEST_ASSERT(list->pHeader == NULL, "Initial header is NULL");
    CLL_Destroy(list);
    printf("\n");
}

void test_insert_and_get() {
    CircularLinkedList* list = CLL_Create();
    CLL_InsertNode(list, 0, CLL_CreateNode(10));
    CLL_InsertNode(list, 1, CLL_CreateNode(20));
    CLL_InsertNode(list, 2, CLL_CreateNode(30));

    TEST_ASSERT(list->currentElementCount == 3, "3 elements inserted");

    CircularLinkedListNode* node0 = CLL_GetAt(list, 0);
    CircularLinkedListNode* node1 = CLL_GetAt(list, 1);
    CircularLinkedListNode* node2 = CLL_GetAt(list, 2);

    TEST_ASSERT(node0 && node0->data == 10, "GetAt(0) == 10");
    TEST_ASSERT(node1 && node1->data == 20, "GetAt(1) == 20");
    TEST_ASSERT(node2 && node2->data == 30, "GetAt(2) == 30");

    CLL_Destroy(list);
    printf("\n");
}

void test_remove() {
    CircularLinkedList* list = CLL_Create();
    CLL_InsertNode(list, 0, CLL_CreateNode(1));
    CLL_InsertNode(list, 1, CLL_CreateNode(2));
    CLL_InsertNode(list, 2, CLL_CreateNode(3));

    CLL_RemoveNode(list, 1);  // remove '2'
    TEST_ASSERT(list->currentElementCount == 2, "1 element removed, count = 2");

    CircularLinkedListNode* n0 = CLL_GetAt(list, 0);
    CircularLinkedListNode* n1 = CLL_GetAt(list, 1);
    TEST_ASSERT(n0 && n0->data == 1, "Remaining node at 0 is 1");
    TEST_ASSERT(n1 && n1->data == 3, "Remaining node at 1 is 3");

    CLL_Destroy(list);
    printf("\n");
}

void test_search() {
    CircularLinkedList* list = CLL_Create();
    CLL_InsertNode(list, 0, CLL_CreateNode(100));
    CLL_InsertNode(list, 1, CLL_CreateNode(200));

    int idx1 = CLL_Search(list, 100);
    int idx2 = CLL_Search(list, 999);

    TEST_ASSERT(idx1 == 0, "Search 100 returns index 0");
    TEST_ASSERT(idx2 == -1, "Search 999 returns -1");

    CLL_Destroy(list);
    printf("\n");
}

void test_clear() {
    CircularLinkedList* list = CLL_Create();
    CLL_InsertNode(list, 0, CLL_CreateNode(11));
    CLL_InsertNode(list, 1, CLL_CreateNode(22));

    bool cleared = CLL_Clear(list);
    TEST_ASSERT(cleared, "List cleared successfully");
    TEST_ASSERT(list->currentElementCount == 0, "Element count is 0 after clear");
    TEST_ASSERT(list->pHeader == NULL, "Header is NULL after clear");

    CLL_Destroy(list);
    printf("\n");
}

void test_invalid_access() {
    CircularLinkedList* list = CLL_Create();
    CLL_InsertNode(list, 0, CLL_CreateNode(123));

    CircularLinkedListNode* invalid = CLL_GetAt(list, 5);
    TEST_ASSERT(invalid == NULL, "GetAt out-of-bounds returns NULL");

    bool removed = CLL_RemoveNode(list, 5);
    TEST_ASSERT(removed == false, "Remove out-of-bounds returns false");

    CLL_Destroy(list);
    printf("\n");
}

int test() {
    printf("===== Circular Linked List Unit Tests =====\n\n");
    test_create_and_destroy();
    test_insert_and_get();
    test_remove();
    test_search();
    test_clear();
    test_invalid_access();
    printf("===== Tests Completed =====\n");
    return 0;
}
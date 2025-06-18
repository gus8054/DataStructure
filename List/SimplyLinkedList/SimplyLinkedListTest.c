#include "SimplyLinkedList.c"

// 유닛 테스트 출력 매크로
#define TEST_ASSERT(cond, msg) \
    do { \
        if (cond) printf("[PASS] %s\n", msg); \
        else printf("[FAIL] %s\n", msg); \
    } while(0)

// 테스트 함수 정의
void test_create_and_destroy() {
    SimplyLinkedList* list = SLL_Create();
    TEST_ASSERT(list != NULL, "Create list returns non-NULL");
    TEST_ASSERT(list->currentElementCount == 0, "List initialized with 0 elements");
    SLL_Destroy(list);
    printf("\n");
}

void test_insert_and_get() {
    SimplyLinkedList* list = SLL_Create();
    SimplyLinkedListNode* node1 = SLL_CreateNode(10);
    SimplyLinkedListNode* node2 = SLL_CreateNode(20);

    bool inserted1 = SLL_InsertNode(list, 0, node1);
    bool inserted2 = SLL_InsertNode(list, 1, node2);

    TEST_ASSERT(inserted1, "Insert node at position 0");
    TEST_ASSERT(inserted2, "Insert node at position 1");
    TEST_ASSERT(list->currentElementCount == 2, "Element count is 2");

    SimplyLinkedListNode* get1 = SLL_GetAt(list, 0);
    SimplyLinkedListNode* get2 = SLL_GetAt(list, 1);

    TEST_ASSERT(get1 != NULL && get1->data == 10, "GetAt(0) returns node with data 10");
    TEST_ASSERT(get2 != NULL && get2->data == 20, "GetAt(1) returns node with data 20");

    SLL_Destroy(list);
    printf("\n");
}

void test_remove() {
    SimplyLinkedList* list = SLL_Create();
    SLL_InsertNode(list, 0, SLL_CreateNode(1));
    SLL_InsertNode(list, 1, SLL_CreateNode(2));
    SLL_InsertNode(list, 2, SLL_CreateNode(3));

    bool removed = SLL_RemoveNode(list, 1); // Remove node with data 2
    TEST_ASSERT(removed, "Remove node at position 1");
    TEST_ASSERT(list->currentElementCount == 2, "Element count is 2 after removal");

    SimplyLinkedListNode* get1 = SLL_GetAt(list, 1);
    TEST_ASSERT(get1 != NULL && get1->data == 3, "Node at index 1 is now 3");

    SLL_Destroy(list);
    printf("\n");
}

void test_search() {
    SimplyLinkedList* list = SLL_Create();
    SLL_InsertNode(list, 0, SLL_CreateNode(100));
    SLL_InsertNode(list, 1, SLL_CreateNode(200));
    SLL_InsertNode(list, 2, SLL_CreateNode(300));

    int idx1 = SLL_Search(list, 200);
    int idx2 = SLL_Search(list, 999);

    TEST_ASSERT(idx1 == 1, "Search finds correct index for 200");
    TEST_ASSERT(idx2 == -1, "Search returns -1 for missing value");

    SLL_Destroy(list);
    printf("\n");
}

void test_clear() {
    SimplyLinkedList* list = SLL_Create();
    SLL_InsertNode(list, 0, SLL_CreateNode(10));
    SLL_InsertNode(list, 1, SLL_CreateNode(20));

    bool cleared = SLL_Clear(list);
    TEST_ASSERT(cleared, "Clear returns true");
    TEST_ASSERT(list->currentElementCount == 0, "Element count is 0 after clear");
    TEST_ASSERT(SLL_GetAt(list, 0) == NULL, "GetAt(0) returns NULL after clear");

    SLL_Destroy(list);
    printf("\n");
}

void test_invalid_access() {
    SimplyLinkedList* list = SLL_Create();
    SLL_InsertNode(list, 0, SLL_CreateNode(10));

    SimplyLinkedListNode* invalid = SLL_GetAt(list, 5);
    TEST_ASSERT(invalid == NULL, "GetAt(5) returns NULL for out-of-bounds");

    bool removed = SLL_RemoveNode(list, 3);
    TEST_ASSERT(!removed, "Remove at invalid index returns false");

    SLL_Destroy(list);
    printf("\n");
}

// 메인 실행
int test() {
    printf("===== Simply Linked List Unit Tests =====\n\n");
    test_create_and_destroy();
    test_insert_and_get();
    test_remove();
    test_search();
    test_clear();
    test_invalid_access();
    printf("===== Tests Completed =====\n");
    return 0;
}
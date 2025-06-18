#include "ArrayList.c"

// 유닛 테스트 도우미 함수
#define TEST_ASSERT(cond, msg) \
    do { \
        if (cond) printf("[PASS] %s\n", msg); \
        else printf("[FAIL] %s\n", msg); \
    } while (0)

// 테스트 함수 정의
void test_create_and_destroy() {
    ArrayList* list = AL_Create(3);
    TEST_ASSERT(list != NULL, "Create list");
    TEST_ASSERT(list->maxElementCount == 3, "Initial maxElementCount == 3");
    TEST_ASSERT(list->currentElementCount == 0, "Initial currentElementCount == 0");
    AL_Destroy(list);
    printf("\n");
}

void test_insert_and_expand() {
    ArrayList* list = AL_Create(2);
    AL_Insert(list, 0, 10);
    AL_Insert(list, 1, 20);
    bool expanded = AL_Insert(list, 2, 30);  // Should trigger realloc

    TEST_ASSERT(expanded, "Insert triggers capacity expansion");
    TEST_ASSERT(list->currentElementCount == 3, "Element count after 3 insertions == 3");
    TEST_ASSERT(AL_GetAt(list, 2)->data == 30, "Check inserted value 30 at index 2");

    AL_Destroy(list);
    printf("\n");
}

void test_remove() {
    ArrayList* list = AL_Create(3);
    AL_Insert(list, 0, 10);
    AL_Insert(list, 1, 20);
    AL_Insert(list, 2, 30);
    bool removed = AL_Remove(list, 1);  // Remove 20

    TEST_ASSERT(removed, "Remove element at index 1");
    TEST_ASSERT(list->currentElementCount == 2, "Element count after removal == 2");
    TEST_ASSERT(AL_GetAt(list, 1)->data == 30, "Element at index 1 is now 30");

    AL_Destroy(list);
    printf("\n");
}

void test_search() {
    ArrayList* list = AL_Create(5);
    AL_Insert(list, 0, 100);
    AL_Insert(list, 1, 200);
    AL_Insert(list, 2, 300);

    int idx = AL_Search(list, 200);
    TEST_ASSERT(idx == 1, "Search returns correct index for existing value");

    idx = AL_Search(list, 999);
    TEST_ASSERT(idx == -1, "Search returns -1 for non-existing value");

    AL_Destroy(list);
    printf("\n");
}

void test_get_at_invalid() {
    ArrayList* list = AL_Create(2);
    AL_Insert(list, 0, 1);
    ArrayListNode* node = AL_GetAt(list, 5);

    TEST_ASSERT(node == NULL, "GetAt returns NULL for invalid index");

    AL_Destroy(list);
    printf("\n");
}

void test_clear() {
    ArrayList* list = AL_Create(2);
    AL_Insert(list, 0, 42);
    AL_Insert(list, 1, 84);
    bool cleared = AL_Clear(list);

    TEST_ASSERT(cleared, "Clear returns true");
    TEST_ASSERT(list->currentElementCount == 0, "List is empty after clear");

    AL_Destroy(list);
    printf("\n");
}

// 메인 테스트 실행 함수
int test() {
    printf("===== ArrayList Unit Tests =====\n\n");
    test_create_and_destroy();
    test_insert_and_expand();
    test_remove();
    test_search();
    test_get_at_invalid();
    test_clear();
    printf("===== Tests Completed =====\n");
    return 0;
}
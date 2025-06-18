#include "DoublyLinkedList.c"

void test_DLL_Create_Destroy() {
    printf("[TEST] DLL_Create & DLL_Destroy\n");

    DoublyLinkedList* list = DLL_Create();
    if (list && list->currentElementCount == 0) {
        printf("PASS: List created successfully.\n");
    } else {
        printf("FAIL: List creation failed.\n");
    }

    DLL_Destroy(list);
    printf("PASS: List destroyed (check for memory leak separately).\n\n");
}

void test_DLL_InsertNode() {
    printf("[TEST] DLL_InsertNode\n");
    DoublyLinkedList* list = DLL_Create();

    // 경계값: head에 삽입
    DoublyLinkedListNode* node1 = DLL_CreateNode(10);
    if (DLL_InsertNode(list, 0, node1)) {
        printf("PASS: Insert at head (position 0).\n");
    } else {
        printf("FAIL: Insert at head failed.\n");
    }

    // 중간에 삽입
    DoublyLinkedListNode* node2 = DLL_CreateNode(20);
    DLL_InsertNode(list, 1, node2);

    // 경계값: 마지막 위치에 삽입
    DoublyLinkedListNode* node3 = DLL_CreateNode(30);
    if (DLL_InsertNode(list, 2, node3)) {
        printf("PASS: Insert at tail (position 2).\n");
    } else {
        printf("FAIL: Insert at tail failed.\n");
    }

    // 오류: 음수 인덱스
    DoublyLinkedListNode* node4 = DLL_CreateNode(40);
    if (!DLL_InsertNode(list, -1, node4)) {
        printf("PASS: Invalid insert position -1 rejected.\n");
    } else {
        printf("FAIL: Insert accepted invalid negative position.\n");
    }

    // 오류: 범위 초과 인덱스
    DoublyLinkedListNode* node5 = DLL_CreateNode(50);
    if (!DLL_InsertNode(list, 100, node5)) {
        printf("PASS: Insert beyond bounds rejected.\n");
    } else {
        printf("FAIL: Insert accepted out-of-range position.\n");
    }

    DLL_Destroy(list);
    printf("\n");
}

void test_DLL_RemoveNode() {
    printf("[TEST] DLL_RemoveNode\n");
    DoublyLinkedList* list = DLL_Create();
    DLL_InsertNode(list, 0, DLL_CreateNode(1));
    DLL_InsertNode(list, 1, DLL_CreateNode(2));
    DLL_InsertNode(list, 2, DLL_CreateNode(3)); // List: [1, 2, 3]

    // 중간 노드 삭제
    if (DLL_RemoveNode(list, 1) && DLL_GetAt(list, 1)->data == 3) {
        printf("PASS: Remove middle node.\n");
    } else {
        printf("FAIL: Failed to remove middle node.\n");
    }

    // 경계값: 첫 번째 노드 삭제
    if (DLL_RemoveNode(list, 0) && DLL_GetAt(list, 0)->data == 3) {
        printf("PASS: Remove first node.\n");
    } else {
        printf("FAIL: Failed to remove first node.\n");
    }

    // 경계값: 마지막 남은 노드 삭제
    if (DLL_RemoveNode(list, 0) && list->currentElementCount == 0) {
        printf("PASS: Remove last node, list now empty.\n");
    } else {
        printf("FAIL: Failed to remove last node.\n");
    }

    // 오류: 빈 리스트에서 삭제
    if (!DLL_RemoveNode(list, 0)) {
        printf("PASS: Remove from empty list rejected.\n");
    } else {
        printf("FAIL: Remove accepted on empty list.\n");
    }

    DLL_Destroy(list);
    printf("\n");
}

void test_DLL_GetAt() {
    printf("[TEST] DLL_GetAt\n");
    DoublyLinkedList* list = DLL_Create();
    DLL_InsertNode(list, 0, DLL_CreateNode(100));
    DLL_InsertNode(list, 1, DLL_CreateNode(200)); // [100, 200]

    // 유효 위치
    if (DLL_GetAt(list, 1)->data == 200) {
        printf("PASS: GetAt valid index 1.\n");
    } else {
        printf("FAIL: GetAt failed on valid index.\n");
    }

    // 경계값: 음수 인덱스
    if (DLL_GetAt(list, -1) == NULL) {
        printf("PASS: GetAt rejected negative index.\n");
    } else {
        printf("FAIL: GetAt accepted negative index.\n");
    }

    // 경계값: 범위 초과 인덱스
    if (DLL_GetAt(list, 5) == NULL) {
        printf("PASS: GetAt rejected out-of-bounds index.\n");
    } else {
        printf("FAIL: GetAt accepted out-of-bounds index.\n");
    }

    DLL_Destroy(list);
    printf("\n");
}

void test_DLL_Search() {
    printf("[TEST] DLL_Search\n");
    DoublyLinkedList* list = DLL_Create();
    DLL_InsertNode(list, 0, DLL_CreateNode(10));
    DLL_InsertNode(list, 1, DLL_CreateNode(20));
    DLL_InsertNode(list, 2, DLL_CreateNode(30));

    int pos = DLL_Search(list, 20);
    if (pos == 1) {
        printf("PASS: Search found correct index.\n");
    } else {
        printf("FAIL: Search returned incorrect index.\n");
    }

    pos = DLL_Search(list, 99);
    if (pos == -1) {
        printf("PASS: Search returned -1 for missing element.\n");
    } else {
        printf("FAIL: Search failed to return -1.\n");
    }

    DLL_Destroy(list);
    printf("\n");
}

void test_DLL_Clear() {
    printf("[TEST] DLL_Clear\n");
    DoublyLinkedList* list = DLL_Create();
    DLL_InsertNode(list, 0, DLL_CreateNode(10));
    DLL_InsertNode(list, 1, DLL_CreateNode(20));

    if (DLL_Clear(list) && list->currentElementCount == 0 &&
        list->headNode.pRightLink == &(list->headNode) &&
        list->headNode.pLeftLink == &(list->headNode)) {
        printf("PASS: Clear emptied the list and reset pointers.\n");
    } else {
        printf("FAIL: Clear failed.\n");
    }

    DLL_Destroy(list);
    printf("\n");
}

int test() {
    test_DLL_Create_Destroy();
    test_DLL_InsertNode();
    test_DLL_RemoveNode();
    test_DLL_GetAt();
    test_DLL_Search();
    test_DLL_Clear();

    return 0;
}

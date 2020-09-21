#include <stdio.h>
#include <stdlib.h>

typedef struct LinkList{
    int val;
    struct LinkList *next;
} MyLinkedList;

/** Initialize your data structure here. */

MyLinkedList* myLinkedListCreate() {
    return (MyLinkedList *)calloc(1, sizeof(MyLinkedList));
}

/* find the prior node of index */
MyLinkedList *myLinkedListFind(MyLinkedList* obj, int index) {
    while (index > 0 && obj->next != NULL) {
        obj = obj->next;
        index--;
    }
    return obj;
}

/** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
void myLinkedListAddAtIndex(MyLinkedList* obj, int index, int val) {
    if (index > obj->val) {
        return;
    }
    MyLinkedList *prev = myLinkedListFind(obj, index);
    MyLinkedList *node = (MyLinkedList*)malloc(sizeof(MyLinkedList));
    /* 添加节点逻辑，找到前驱 */
    node->val = val;
    node->next = prev->next;
    prev->next = node;
    obj->val++;  // 链表长度+1
}

/** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
void myLinkedListAddAtHead(MyLinkedList* obj, int val) {
    // MyLinkedList *node = (MyLinkedList*)malloc(sizeof(MyLinkedList));
    // node->val = val;
    // node->next = obj->next;
    // obj->next = node;
    // obj->val++;
    myLinkedListAddAtIndex(obj, 0, val);
}

/** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
int myLinkedListGet(MyLinkedList* obj, int index) {
    if (index < 0 || index >= obj->val) {
        return -1;
    }
    return myLinkedListFind(obj, index)->next->val;
}

/** Append a node of value val to the last element of the linked list. */
void myLinkedListAddAtTail(MyLinkedList* obj, int val) {
    myLinkedListAddAtIndex(obj, obj->val, val);
}

/** Delete the index-th node in the linked list, if the index is valid. */
void myLinkedListDeleteAtIndex(MyLinkedList* obj, int index) {
    if (index < 0 || index >= obj->val) {
        return;
    }
    MyLinkedList *prev = myLinkedListFind(obj, index);
    MyLinkedList *remove = prev->next;
    prev->next = remove->next;
    free(remove);
    obj->val--;  // 链表长度-1
}

void myLinkedListFree(MyLinkedList* obj) {
    /* 销毁可迭代删除，也可每次调用上面删除函数删除第0个节点 */
    while (obj->val) {
        myLinkedListDeleteAtIndex(obj, 0);
    }
}

/**
 * Your MyLinkedList struct will be instantiated and called as such:
 * MyLinkedList* obj = myLinkedListCreate();
 * int param_1 = myLinkedListGet(obj, index);
 
 * myLinkedListAddAtHead(obj, val);
 
 * myLinkedListAddAtTail(obj, val);
 
 * myLinkedListAddAtIndex(obj, index, val);
 
 * myLinkedListDeleteAtIndex(obj, index);
 
 * myLinkedListFree(obj);
*/

int main(){
    MyLinkedList* obj = myLinkedListCreate();
    myLinkedListAddAtHead(obj, 1);
    myLinkedListAddAtHead(obj, 2);
    myLinkedListAddAtIndex(obj, 2, 3);
    printf("obj_num:%d\n",obj->val);
    printf("obj_1:%d\n",myLinkedListGet(obj, 0));
    printf("obj_2:%d\n",myLinkedListGet(obj, 1));
    printf("obj_3:%d\n",myLinkedListGet(obj, 2));
    myLinkedListFree(obj);

}

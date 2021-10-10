#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>

typedef struct node
{
    int data;
    struct node *pNext;
}nodeInfo;

int CreatLink(nodeInfo *pMove, int len)
{
    srand((unsigned int)time(0));
    for (int i = 0; i < len; i++) {
        nodeInfo *pTemp = malloc(sizeof(nodeInfo));
        pTemp->data = rand() % 100 + 1;
        pTemp->pNext = NULL;
        pMove->pNext = pTemp;
        pMove = pTemp;
    }

    return 0;
}

int ShowLink(nodeInfo *pMove)
{
    if (pMove == NULL) {
        return -1;
    }

    while (pMove != NULL) {
        printf("data: %d\n", pMove->data);
        pMove = pMove->pNext;
    }

    return 0;
}

int GetLinkLength(nodeInfo *pMove, int *len)
{
    if (pMove == NULL || len == NULL) {
        return -1;
    }

    *len = 0;
    while (pMove != NULL) {
        (*len)++;
        pMove = pMove->pNext;
    }

    return 0;
}

// 头结点为index 0，
int InsertLink(nodeInfo *pMove, int index, int element)
{
    int linkLenth = 0;
    GetLinkLength(pMove, &linkLenth);

    if (pMove == NULL || index < 1 || index > linkLenth) {
        return -1;
    }

    for (int i = 0; i < index - 1; i++) {
            // pMove++;
            pMove = pMove->pNext;
    }

    nodeInfo *pTemp = malloc(sizeof(nodeInfo));
    pTemp->data = element;

    pTemp->pNext = pMove->pNext;
    pMove->pNext = pTemp;

    return 0;
}

// 头结点为index 0，
int DeletetLink(nodeInfo *pMove, int index)
{
    int linkLenth = 0;
    GetLinkLength(pMove, &linkLenth);

    if (pMove == NULL || index < 1 || index > linkLenth) {
        return -1;
    }

    nodeInfo *pStart = pMove;

    for (int i = 0; i < index - 1; i++) {
            pMove = pMove->pNext;
    }

    if (pMove->pNext->pNext == NULL) {
        free(pMove->pNext);
        pMove->pNext = NULL;
    }
    else {
        nodeInfo *pTemp = pMove->pNext->pNext;
        free(pMove->pNext);
        pMove->pNext = pTemp;
    }

    printf("the deleted link success, and new link below:\n");
    ShowLink(pStart);
    return 0;
}

int FreeLink(nodeInfo *pMove)
{
    if (pMove == NULL) {
        return -1;
    }

    while (pMove != NULL) {
        printf("delete element: %d\n", pMove->data);
       nodeInfo *pNext =  pMove->pNext;
       free(pMove);
       pMove = pNext;
    }

    printf("FreeLink success!\n");
    return 0;
}

// 新生成一个link，较为简单，但占用内存大。
int ReverseLink(nodeInfo **pMove)
{
    nodeInfo *pOrigin = (*pMove);
    nodeInfo *pOriginStart = pOrigin;
    nodeInfo *pHead = malloc(sizeof(nodeInfo));
    pHead->data = -1;
    pHead->pNext = NULL;
    pOrigin = pOrigin->pNext;

    while (pOrigin != NULL) {
        nodeInfo *newNode = malloc(sizeof(nodeInfo));
        newNode->data = pOrigin->data;

        if (pHead->pNext == NULL) {
            newNode->pNext = NULL;
            pHead->pNext = newNode;
        }
        else {
            newNode->pNext = pHead->pNext;
            pHead->pNext = newNode;
        }
            pOrigin = pOrigin->pNext;
    }
 
    FreeLink(pOriginStart);

    printf("-------------reverse success-------------\n");
 
    *pMove = pHead;
    return 0;
}

// 不从新分配内存，内存占用小，使用原来的链表。逻辑稍微复杂一点。需要用到固定的头指针，原始的第一个节点指针，及后续的插入节点指针，共三个。
int ReverseLink2(nodeInfo *pHead)
{
    if (pHead == NULL) {
        return -1;
    }
    printf("before link2 reverse\n"); 
    ShowLink(pHead);

    nodeInfo *pFirst = pHead->pNext;
    if (pFirst->pNext == NULL) {
        return 0;
    }

    nodeInfo *pInsert = pFirst->pNext;
    while (pInsert != NULL) {
        pFirst->pNext = pInsert->pNext;
        pInsert->pNext = pHead->pNext;
        pHead->pNext = pInsert;

        pInsert = pFirst->pNext;
    }
    printf("after link2 reverse\n"); 
    ShowLink(pHead);

    return 0;
}

int SortLink(nodeInfo *pHead)
{
    if (pHead == NULL) {
        return -1;
    }

    if (pHead->pNext == NULL) { // only one element
        return 0;
    }

    for(nodeInfo *pNode1 = pHead->pNext; pNode1->pNext != NULL; pNode1 = pNode1->pNext) {
        for (nodeInfo *pNode2 = pNode1->pNext; pNode2 != NULL; pNode2 = pNode2->pNext)
        {
            if (pNode1->data > pNode2->data) {
                int temp = pNode2->data;
                pNode2->data = pNode1->data;
                pNode1->data = temp;
            }
        }
    }
    return 0;
}

int main(void)
{
    nodeInfo *pMove = malloc(sizeof(nodeInfo));
    pMove->data = -1;
    pMove->pNext = NULL;
    CreatLink(pMove, 10);

    ShowLink(pMove);

    if (InsertLink(pMove, 6, 88) != 0) {
        printf("insertLink error\n");
    }

    printf("*****************************\n");
    ShowLink(pMove);

    ReverseLink(&pMove);
    printf("*****************************\n");
    ShowLink(pMove);

    ReverseLink2(pMove);

    if (DeletetLink(pMove, 6) != 0) {
        printf("insertLink error\n");
    }

    printf("the pop sort link is as follows:\n");
    SortLink(pMove);
    ShowLink(pMove);
    return 0;
}

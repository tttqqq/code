#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<time.h>

typedef struct node {
    int data;
    struct node *pPre;
    struct node *pNext; 
}nodeInfo;

#define DOUBLE_LINK_LENGTH 10

int CreatDoubleLink(nodeInfo *pHead, int len)
{
    if (pHead == NULL || len == 0) {
        return -1;
    }

    srand((unsigned int)time(0));
    for(int i = 0; i < len; i++) {
        nodeInfo* pTemp =  malloc(sizeof(nodeInfo));
        pTemp->data = rand() % 100 + 1;

        if (pHead->pNext == NULL) {
            pTemp->pPre = pHead;
            pTemp->pNext = NULL;
            pHead->pNext = pTemp;
        }
        else {
            pHead->pNext->pPre = pTemp;
            pTemp->pNext = pHead->pNext;
            pTemp->pPre = pHead;
            pHead->pNext = pTemp;
        }
    }

    return 0;
}

int ShowDoubleLink(nodeInfo *pHead)
{
    if (pHead == NULL) {
        return -1;
    }

    nodeInfo *pMove  = pHead->pNext;
    while (pMove != NULL) {
        printf("element: %d\n", pMove->data);
        pMove = pMove->pNext;
    }

    return 0;
}

int GetLinkLength(nodeInfo *pHead, int *len)
{
    if (pHead == NULL) {
        return -1;
    }
    
    *len = 0;
    nodeInfo *pMove = pHead->pNext;
    while (pMove != NULL) {
        (*len)++;

        pMove = pMove->pNext;
    }

    return 0;
}

int InsertLink(nodeInfo *pHhead, int index, int ele)
{
    nodeInfo *pMove = pHhead->pNext;

    nodeInfo *pTemp = malloc(sizeof(nodeInfo));
    pTemp->data = ele;
    
    if (pMove == NULL) {
        pTemp->pNext = NULL;
        pTemp->pPre = pHhead;
        pHhead->pNext = pTemp;
    }

    for(int i = 0; i < index -1; i++) {
        pMove = pMove->pNext;
    }

    // pMove->pNext->pPre = pTemp;
    // pTemp->pNext = pMove->pNext;
    // pTemp->pPre = pMove->pPre;
    // pMove->pPre->pNext = pTemp;
    pTemp->pPre = pMove->pPre;
    pTemp->pNext = pMove;
    pMove->pPre->pNext = pTemp;
    pMove->pPre = pTemp;
    return 0;
}

int main(void)
{
    nodeInfo *pHead = malloc(sizeof(nodeInfo));
    pHead->data = -1;
    pHead->pNext = NULL;
    pHead->pNext = NULL;

    CreatDoubleLink(pHead, DOUBLE_LINK_LENGTH);

    printf("The origin array is as follows:\n");
    ShowDoubleLink(pHead);
    int len = 0;
    GetLinkLength(pHead, &len);
    printf("The double link lenth: %d\n", len);

    InsertLink(pHead, 6, 666);

    printf("The Insert array is as follows:\n");
    ShowDoubleLink(pHead);
    return 0;
}
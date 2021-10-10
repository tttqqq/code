#include<stdio.h>
#include<string.h>
#include<stdlib.h>

char *GetSubString(char *src, char *sub)
{
    if (src == NULL || sub == NULL) {
        return NULL;
    }

    while(*src) {
        char *pSrcMove = src;
        char *pSubMove = sub;

        while(*pSrcMove == *pSubMove && *pSrcMove != '\0' && *pSubMove != '\0') {
            pSrcMove++;
            pSubMove++;
        }

        if (*pSubMove == '\0')
        {
            return src;
        }

        src++;
    }

    return NULL;
}

int main(void)
{
    char a[] = "hellow world!";
    char *pa = a;
    char b[] = "world!";
    char *pb = b;
    int index  = 0;
    while (*pa != '\0') {
        char *paMove = pa;
        char *pbMove = pb;
        while(*paMove == *pbMove && *pbMove != '\0' && *paMove != '\0') {
            paMove++;
            pbMove++;
        }

        if (*pbMove == '\0') {
            printf("find the sub tring: %s, index: %d\n", b, index);
            break;
        }

        index++;
        pa++;
    }
    
    if (pa == NULL) {
        printf("not find the sub tring: %s\n", b);
    }

    char *pSub = strstr(a,b);
    memcpy(pSub,"tao",3);

    printf("%s\n",a);
    printf("%s\n",pa);
    printf("%s\n",b);
    printf("sub string--> %s", GetSubString("ni hao zhuguo", "hao"));
}
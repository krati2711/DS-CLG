#include <stdio.h>

#define MAX 20

int ht[MAX];
int m;

void insert(int key)
{
    int index=key %m;
    while (ht[index] != -1){
            index = (index + 1) % m;
    }
    ht[index] = key;
}

void display()
{
    int i;
    printf("\nHash Table:\n");
    for (i=0;i<m;i++)
    {
        if (ht[i] != -1) printf("HT[%d] = %d\n", i, ht[i]);
        else printf("HT[%d] = EMPTY\n", i);
    }
}

int main2()
{
    int n,key,i;
    printf("Enter size of hash table (m): ");
    scanf("%d", &m);
    for (i=0;i<m;i++)
        ht[i] = -1;
    printf("Enter number of employee records: ");
    scanf("%d", &n);
    printf("Enter %d employee keys (4-digit):\n", n);
    for (i=0;i<n;i++)
    {
        scanf("%d", &key);
        insert(key);
    }
    display();
    return 0;
}


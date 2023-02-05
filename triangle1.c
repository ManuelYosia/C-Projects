#include <stdio.h>

int main()
{
    int n;
    n = 0;

    printf("Masukkan jumlah bintang: ");
    scanf("%d", &n);

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < i + 1; j++)
        {
            printf("*");
        }
        printf("\n");
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = n; j > i; j--)
        {
            printf("*");
        }
        
        printf("\n");
    }
    
    return 0;
}

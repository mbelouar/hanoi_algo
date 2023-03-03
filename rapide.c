#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void swap(int *a, int *b) 
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[], int first, int last)
 {
    int pivot = arr[last];
    int i = first - 1; 
    int j = first;
    while (j <= last -1)
    {
        if (arr[j] <= pivot)
        {
            i++;
            swap(&arr[i], &arr[j]);
        }
        j++;
    }
    swap(&arr[i + 1], &arr[last]);
    return i + 1; 
}

void quicksort(int arr[], int first, int last) {
    if (first < last)
    { 
        int pivot_index = partition(arr, first, last); 
        quicksort(arr, first, pivot_index - 1); 
        quicksort(arr, pivot_index + 1, last);
    }
}

int main()
{
    int *T;
    int n;
    double t_debut, t_fin;

    printf("Combien de nombres voulez vous triee par fusion : ");
    scanf("%d", &n);

    T = malloc(sizeof(int) * n);
    if (!T)
        return (0);
    printf("\nle Tableau : \n");
    int  i = 0;
    while (i < n)
    {
        printf("T[%d] = ",i);
        scanf("%d", &T[i]);
        i++;
    }
    t_debut = (double)clock();
    ft_triFusion(T, n);
    t_fin = (double)clock();

    printf("\nle tableau triee : ");
    i = 0;
    while (i < n)
        printf("%d ", T[i++]);
    printf("\nLe temps d'execution est : %lf (s)", (t_fin - t_debut) / CLOCKS_PER_SEC);
}
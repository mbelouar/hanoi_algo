#include <stdio.h>
#include <time.h>
#include <stdlib.h>

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
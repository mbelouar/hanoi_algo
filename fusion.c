#include <stdio.h>
#include <time.h>
#include <stdlib.h>

// void    tri(int *T, int debut, int milieu, int fin)
// {
//     int i, j, k;


// }

void    triFusion(int *T, int debut, int fin)
{
    int milieu;

    if (debut > fin)  // dans notre cas on suppose quand a une trie croissante
    {
        milieu = (debut + fin) / 2;
        triFusion(T, debut, milieu);
        triFusion(T, milieu + 1, fin);
        //tri(T, debut, milieu, fin);
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
    triFusion(T, 0, n - 1);
    t_fin = (double)clock();
    printf("Le temps d'execution est : %lf (s)", (t_fin - t_debut) / CLOCKS_PER_SEC);
}
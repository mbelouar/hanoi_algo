#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void    ft_fusion(int *T, int *T_gauche, int gauche_size, int *T_droite, int droite_size)
{
    int i = 0, j = 0, k = 0;

    while (i < gauche_size && j < droite_size)
    {
        if (T_gauche[i] <= T_droite[j])
            T[k++] = T_gauche[i++];
        else
            T[k++] = T_droite[j++];
    }
    while (i < gauche_size)
        T[k++] = T_gauche[i++];
    while (j < droite_size)
        T[k++] = T_droite[j++];
}

void    ft_triFusion(int *T, int size)
{
    if (size < 2)
        return ;
    int milieu = size / 2;
    int T_gauche[milieu], T_droite[size - milieu];
    int i = 0;
    while (i < milieu)
    {
        T_gauche[i] = T[i];
        i++;
    }
    i = milieu;
    while (i < size)
    {
        T_droite[i - milieu] = T[i];
        i++;
    }
    ft_triFusion(T_gauche, milieu);
    ft_triFusion(T_droite, size - milieu);
    ft_fusion(T, T_gauche, milieu, T_droite, size - milieu);
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
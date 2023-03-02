#include <stdio.h>
#include <time.h>

void ft_Hanoi_algo(int n, char Depart, char Arrive, char Inter) {
    if (n == 1)
    printf("Disque 1 de %c a %c \n" , Depart , Arrive);
    else 
    {
        // Depart à Arrive
        ft_Hanoi_algo(n - 1, Depart, Inter, Arrive);
        printf("Disque %d de %c a %c \n", n , Depart ,Arrive);
        //Inter à Arrive
        ft_Hanoi_algo(n - 1, Inter, Arrive, Depart);
    }
}

int main() {
    int nDisques;
    double h_debut, h_final, h_total;

    printf("Enter le nombre de disques : ");
    scanf("%d", &nDisques);
    
    if (nDisques > 0)
    {
        h_debut = (double)clock();
        ft_Hanoi_algo(nDisques, 'A', 'B', 'C');
        h_final = (double)clock();

        h_total = (h_final - h_debut) / CLOCKS_PER_SEC;
        printf("Le temps d'execution est : %lf (s)", h_total);
    }
    else
        printf("Vefifie le nombre de disque entrer\n");
    return (0);
}

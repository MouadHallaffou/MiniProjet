
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MaxLivre 1000

char titres[MaxLivre][100];
char auteurs[MaxLivre][100];
float prix[MaxLivre];
int quantite[MaxLivre];
int QuantiteLivre = 0;

/*********************** fonctions:*******************************/

//Ajouter un livre au stock.

void Ajoutation()
{
    printf("entre le nbr des types ouvrages que tu doit ajoute:");
    scanf("%d",&QuantiteLivre);
    if (QuantiteLivre < MaxLivre)
    {
        printf(" Entrer le titre du livre: ");
        fflush(stdin);
        gets(titres[QuantiteLivre]);
        printf(" Entrer l'auteur du livre: ");
        fflush(stdin);
        gets(auteurs[QuantiteLivre]);
        printf(" Entrer le prix du livre: ");
        scanf("%f", &prix[QuantiteLivre]);
        printf(" Entrer la quantite du livre: ");
        scanf("%d", &quantite[QuantiteLivre]);
        QuantiteLivre++;
        printf(" le livre est bien ajoute.\n");
    }
    else
    {
        printf(" le Stock est plein.\n");
    }
}

//Afficher tous les livres disponibles.

void Affichage()
{
    if (QuantiteLivre == 0)
    {
        printf("le stock est vide.\n");
    }
    else
    {
        printf("\n les ouvrages disponibles est: \n");
        for (int i = 0; i < QuantiteLivre; i++)
        {
            printf(" Titre: %s\n Auteur: %s\n Prix: %.2f\n Quantite: %d\n", titres[i], auteurs[i], prix[i], quantite[i]);
            printf("\n");
        }
    }
}

//Rechercher un livre par son titre.

void recherche()
{
    char titre[100];
    printf("Entrer le titre du livre a rechercher: ");
    fflush(stdin);
    gets(titre);

    for (int i = 0; i < QuantiteLivre; i++)
    {
        if (strcmp(titres[i], titre) == 0)
        {
            printf("Livre Disponible: Titre: %s, Auteur: %s, Prix: %.2f, Quantite: %d\n", titres[i], auteurs[i], prix[i], quantite[i]);
            return;
        }
    }
    printf("aucun ouvrage a ce titre.\n");
}

//Afficher le nombre total de livres en stock.

void TotalOuvrages()
{
    int Total = 0;
    for (int i = 0; i < QuantiteLivre; i++)
    {
        Total += quantite[i];
    }
    printf("le nbr total des ouvrages disponibles dans le stock est: %d\n", Total);
}

//Supprimer un livre du stock.

void Suprimer()
{
    titres[100];
    printf("entre le titre de l'ouvrage que tu doit suprimer:");
    fflush(stdin);
    gets(titres);
    for(int i=0; i<=QuantiteLivre; i++)
    {
        if(strcmp(titres[i],titres)==0)
            for(int j=i ; j<QuantiteLivre-1 ; j++)
            {
                strcpy(titres[j],titres[j+1]);
                strcpy(auteurs[j],auteurs[j+1]);
                prix[j]=prix[j+1];
                quantite[j]=quantite[j+1];
            }
        QuantiteLivre--;
        printf("le livre est suprimer.");
        return ;
    }
    printf("livre non trouve.");
}

//Mettre ajoure Quantite.

void mettre_a_jour_quantite()
{
    char titre[100];
    int nouvelleQte;
    printf("Entrer le titre du livre que tu doit modifie leur Quantite: ");
    fflush(stdin);
    gets(titre);
    for (int i = 0; i < QuantiteLivre; i++)
    {
        if (strcmp(titres[i], titre) == 0)
        {
            printf("Quantite actuelle: %d\n", quantite[i]);
            printf("Entrer la nouvelle quantite: ");
            scanf("%d", &nouvelleQte);
            quantite[i] = nouvelleQte;
            printf("Quantite modified.\n");
            return;
        }
    }
    printf("je ni pas trouve ce livre.\n");
}


int main()
{
    int choix;

    do
    {
        printf("\n **** systeme de gestion ****\n");
        printf("\n");
        printf("\t  Quelle est votre choix: \n");
        printf("\t 1. Ajouter un livre.\n");
        printf("\t 2. Voir le stock.\n");
        printf("\t 3. Recherche un livre par son Tittre.\n");
        printf("\t 4. Calcule le total.\n");
        printf("\t 5. Suprimer.\n");
        printf("\t 6. Mettre a Jour la Qte d'un Livre.\n");
        printf("\t 7. Quitter!!\n");
        scanf("%d", &choix);

        switch (choix)
        {
        case 1:
            Ajoutation();
            break;
        case 2:
            Affichage();
            break;
        case 3:
            recherche();
            break;
        case 4:
            TotalOuvrages();
            break;
        case 5:
            Suprimer();
            break;
        case 6:
            mettre_a_jour_quantite();
            break;
        case 7:
            printf("good bye!\n");
            break;
        default:
            printf("choix inconnu.\n");
        }
    }
    while (choix != 7);

    return 0;
}





#include<stdio.h>
#include<stdlib.h>


/* declaration de la cellule de la liste */
typedef struct cellule 
{
    int valeur ;
    struct cellule *suivant ;
    struct cellule *precedent ;
}cellule ;



/* declaration de la tete de la liste */
typedef struct liste 
{
    struct cellule *debut ;
    struct cellule *fin ;
}liste ;


/* initialisation de la liste */
void initialisation_liste (liste *l)
{
    l->debut = NULL ;               /* initialisation de la debut de la liste */
    l->fin = NULL ;                     /* initialisation de la fin de la liste */
}



/* remplissage de la liste */
liste *remplissage_liste (liste *l , int valeur )
{
    cellule *a ;
    a = (cellule*)malloc(sizeof(cellule)) ;   /* reserver une memoire pour la cellule a */
    a->valeur = valeur ;
    a->precedent = NULL ;
    if (l->fin == NULL)                
    {
        a->suivant = NULL ;
        l->fin = a ;
    }
    else
    {
        l->debut->precedent = a ;
        a->suivant = l->debut ;
    }
    l->debut = a ;
    return l ;
}



/* l'affichage de la liste */
void affichage_liste  (liste *l)
{
    cellule *x ;
    int i ;
    if (l->debut != NULL)
    {
        x = l->debut ;
        while(x != NULL)
        {
            printf("%d \n",x->valeur) ;
            x = x->suivant ;
        }
    }
    printf("LISTE NULL \n") ;
}



/* le programme principale */
int main(void)
{
    int valeur , i , taille ;
    liste *l ;
    l = (liste*)malloc(sizeof(liste)) ;
    initialisation_liste(l) ;
    printf("tapper le nombre des liste  : \n") ;
    scanf("%i",&taille) ;
    for (i = 1 ; i <= taille ; i++)
    {
        printf("tapper le contenus de la liste %i : ",i) ;
        scanf("%i",&valeur) ; 
        l = remplissage_liste (l , valeur) ;
    }
    affichage_liste (l) ; 
    return 0 ;
}
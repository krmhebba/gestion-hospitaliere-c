#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct consult {
    char date[11];
    char med[30];
    char soin[30];
    struct consult *suiv;
} consult;

typedef struct pat {
    int id;
    char nom[30];
    int age;
    char ant[100];
    int urg;
    consult *hist;
    struct pat *prec, *suiv;
} pat;

typedef struct {
    pat *tete, *fin;
} liste_pat;

void empiler(consult **pile, char *date, char *med, char *soin) {
    consult *nv = malloc(sizeof(consult));
    strcpy(nv->date, date);
    strcpy(nv->med, med);
    strcpy(nv->soin, soin);
    nv->suiv = *pile;
    *pile = nv;
}

void ajout_pat(liste_pat *lp, int id, char *nom, int age, char *ant, int urg) {
    pat *nv = malloc(sizeof(pat));
    nv->id = id;
    strcpy(nv->nom, nom);
    nv->age = age;
    strcpy(nv->ant, ant);
    nv->urg = urg;
    nv->hist = NULL;
    nv->prec = nv->suiv = NULL;

    pat *p = lp->tete;
    while (p && urg <= p->urg) p = p->suiv;

    if (!p) {
        if (!lp->tete) lp->tete = lp->fin = nv;
        else {
            nv->prec = lp->fin;
            lp->fin->suiv = nv;
            lp->fin = nv;
        }
    } else {
        nv->suiv = p;
        nv->prec = p->prec;
        if (p->prec) p->prec->suiv = nv;
        else lp->tete = nv;
        p->prec = nv;
    }
}

void maj_dossier(pat *p, char *date, char *med, char *soin) {
    empiler(&(p->hist), date, med, soin);
}

void aff_hist(consult *pile) {
    while (pile) {
        printf("Date: %s | Médecin: %s | Soin: %s\n", pile->date, pile->med, pile->soin);
        pile = pile->suiv;
    }
}

void aff_patients(liste_pat lp) {
    pat *p = lp.tete;
    while (p) {
        printf("\nID: %d | Nom: %s | Âge: %d | Urgence: %d\nAntécédents: %s\n",
               p->id, p->nom, p->age, p->urg, p->ant);
        printf("Historique:\n");
        aff_hist(p->hist);
        p = p->suiv;
    }
}

pat *rech_pat(liste_pat lp, int id) {
    pat *p = lp.tete;
    while (p) {
        if (p->id == id) return p;
        p = p->suiv;
    }
    return NULL;
}

int main() {
    liste_pat lp;
    lp.tete = NULL;
    lp.fin = NULL;
    int choix, id, age, urg;
    char nom[30], ant[100], date[11], med[30], soin[30];
    pat *p;

    do {
        printf("\n\tMENU\t\n");
        printf("1. Ajouter patient\n2. Mise a jour dossier\n3. Afficher tous les patients\n4. Afficher historique d’un patient\n0. Quitter\nChoix: ");
        scanf("%d", &choix);
        getchar();

        switch (choix) {
            case 1:
                printf("ID: "); scanf("%d", &id); getchar();
                printf("Nom: "); fgets(nom, 30, stdin); nom[strcspn(nom, "\n")] = 0;
                printf("Age: "); scanf("%d", &age); getchar();
                printf("Antecedents: "); fgets(ant, 100, stdin); ant[strcspn(ant, "\n")] = 0;
                printf("Niveau d’urgence (1-5): "); scanf("%d", &urg);
                ajout_pat(&lp, id, nom, age, ant, urg);
                printf("Patient ajoute.\n");
                break;

            case 2:
                printf("ID patient: "); scanf("%d", &id); getchar();
                p = rech_pat(lp, id);
                if (p) {
                    printf("Date: "); fgets(date, 11, stdin); date[strcspn(date, "\n")] = 0;
                    printf("Medecin: "); fgets(med, 30, stdin); med[strcspn(med, "\n")] = 0;
                    printf("Soin: "); fgets(soin, 30, stdin); soin[strcspn(soin, "\n")] = 0;
                    maj_dossier(p, date, med, soin);
                    printf("Dossier mis a jour.\n");
                } else {
                    printf("Patient non trouve.\n");
                }
                break;

            case 3:
                aff_patients(lp);
                break;

            case 4:
                printf("ID patient: "); scanf("%d", &id);
                p = rech_pat(lp, id);
                if (p) aff_hist(p->hist);
                else printf("Patient non trouve.\n");
                break;
        }

    } while (choix != 0);

    return 0;
}

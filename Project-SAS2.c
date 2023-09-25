#include <stdio.h>
#include <string.h>
#include <time.h>
// Structure pour représenter une tâche
struct task
{
    char titre[100];
    char description[100];
    int time, id, stat;
    char status[100];
};
// Variables globales
int numId = 1;
int taskCount = 0;
int complètes = 0;
int incomplètes = 0;
struct task entre[100];
// Fonction pour ajouter des tâches
//______________________________________________________________________________________________________________________________________
void add_tasks()
{

    int jour, nombre;
    printf("##ENTRE LES NOMBRE DES TACHE :");
    scanf("%d", &nombre);
    for (int i = 0; i < nombre; i++)
    {
        entre[taskCount].id = numId;
        printf("##ENTRE LE TITRE DE LA TÂCHE %d:\n", numId);
        scanf(" %[^\n]", entre[taskCount].titre);
        printf("##ENTRE LA DESCRIPTION DE LA TÂCHE %d:\n",numId);
        scanf(" %[^\n]", entre[taskCount].description);

        do
        {

            printf("##ENTRE LA DEADLINE DE LA TÂCHE %d (EN JOURS) : ",numId);
            scanf("%d", &jour);
            long long seconds = (long long)jour * 86400;
            time_t nowTime;
            time(&nowTime);
            seconds += nowTime;
            entre[i].time = seconds;
        } while (jour < 1);
        do
        {
            printf("##ENTRE LE STATUT DE LA TÂCHE :\n 1: TO DO \n 2: DOWING \n 3: DONE \n");
            scanf(" %d", &entre[taskCount].stat);
            switch (entre[taskCount].stat)
            {
            case 1:
                strcpy(entre[taskCount].status, "TO DO");
                break;
            case 2:
                strcpy(entre[taskCount].status, "DOWING");
                break;
            case 3:
                strcpy(entre[taskCount].status, "DONE");
                break;
            }
        } while (entre[taskCount].stat < 1 || entre[taskCount].stat > 3);
        numId++;
        taskCount++;
        printf("\n");
    }
}
// Fonction pour afficher les tâches
//______________________________________________________________________________________________________________________________________
void output_tasks()
{
    for (int i = 0; i < taskCount; i++)
    {
        
        printf("-->  LE ID DE LA TÂCHE %d EST : %d\n", i + 1, entre[i].id);
        printf("--> Le titre de la tâche %d est : %s\n", i + 1, entre[i].titre);
        printf("--> Description de la tâche %d : %s\n", i + 1, entre[i].description);
        time_t solution_Time = entre[i].time - time(NULL);
        printf("--> LE time in = %lld JOUR %lld hur\n", (long long)(solution_Time / 86400), (long long)(solution_Time / 3600));
        printf("--> Statut de la tâche : %s \n\n", entre[i].status);
    }
}
// Fonction pour trier les tâches par ordre alphabétique
//______________________________________________________________________________________________________________________________________
void alphabetical()
{
    struct task transfer;
    int i, j;
    for (i = 0; i < taskCount; i++)
    {
        for (j = i + 1; j < taskCount; j++)
        {
            if (strcmp(entre[i].titre, entre[j].titre) > 0)
            {
                transfer = entre[i];
                entre[i] = entre[j];
                entre[j] = transfer;
            }
        }
    }
}
// Fonction pour trier les tâches par deadline
//______________________________________________________________________________________________________________________________________
void deadline_tri()
{
    struct task transfer;
    int i, j;
    for (i = 0; i < taskCount; i++)
    {
        for (j = i + 1; j < taskCount; j++)
        {
            if (entre[i].time > entre[j].time)
            {
                transfer = entre[i];
                entre[i] = entre[j];
                entre[j] = transfer;
            }
        }
    }
}
// Fonction pour afficher les tâches dont le deadline est dans 3 jours ou moins
//______________________________________________________________________________________________________________________________________
void jour_3_tri()
{

for (int i = 0 ; i < taskCount ; i++)
{
    time_t solution_Time = entre[i].time - time(NULL);
    if (solution_Time <= 259200 )
    {
      printf("le deadline de tache ID %d est : %ld jour\n",numId,(long)solution_Time / 86400);  

      printf("-->  LE ID DE LA TÂCHE %d EST : %d\n", i + 1, entre[i].id);
      printf("--> Le titre de la tâche %d est : %s\n", i + 1, entre[i].titre);
      printf("--> LE time in = %lld JOUR %lld hur\n", (long long)(solution_Time / 86400), (long long)(solution_Time / 3600));
      printf("--> Statut de la tâche : %s \n\n", entre[i].status);
    }
    
}




}
// Fonction pour le menu de triage
//______________________________________________________________________________________________________________________________________
int menu_triage()
{

    int order_choose;
    printf(" 1 : Trier les tâches par ordre alphabétique.\n");
    printf(" 2 : Trier les tâches par deadline.\n");
    printf(" 3 : Afficher les tâches dont le deadline est dans 3 jours ou moins..\n");
    printf(" 4 : back in menu prancipal.\n");
    scanf("%d", &order_choose);
    switch (order_choose)
    {
    case 1:
        alphabetical(entre); 
        output_tasks(entre); 
        break;
    case 2:
        deadline_tri(entre);
        output_tasks(entre);
        break;
    case 3:
        jour_3_tri(entre);
        break;
    case 4:
        return 0;
    default:
        printf("Choix non valide.\n");
        break;
    }
}
// Fonction pour modifier une tâche
//______________________________________________________________________________________________________________________________________
void modifier_tasks()
{
    int i;
    int target_id, jour;
    printf("entre  id de tache:\n");
    scanf("%d", &target_id);
    for ( i = 0; i < taskCount; i++)
    {
        if (entre[i].id == target_id)
        {
            printf("Entre la description de la tâche :\n");
            scanf(" %[^\n]", entre[i].description);
            printf("Entre la deadline de la tâche (en jour):\n");
            scanf("%d", &jour);
            long long seconds = (long long)jour * 86400; 
            time_t nowTime;
            time(&nowTime);
            seconds += nowTime;
            
            entre[i].time = seconds;
            do{
            printf("Entre la status de la tâche :\n 1: TO DO \n 2: DOIND \n 3: DONE \n");
            scanf(" %d",&entre[taskCount].stat);
            switch (entre[taskCount].stat)
            {
            case 1:
                strcpy(entre[taskCount].status, "TO DO");
                break;
            case 2:
                strcpy(entre[taskCount].status, "DOWING");
                break;
            case 3:
                strcpy(entre[taskCount].status, "DONE");
                break;
            }
            } while (entre[taskCount].stat < 1 || entre[taskCount].stat > 3);
           
        }
    }
     if(target_id != entre[i].id){
        printf("la tache ne pas exist\n");
    }
    
}
// Fonction pour rechercher une tâche par son ID
//______________________________________________________________________________________________________________________________________
void Rechercher_tasks_id()
{
    int i;
    int target_id ;
    printf("entre  id de tache:\n");
    scanf("%d", &target_id);
    for (i = 0; i < taskCount; i++)
    {
        if (target_id == entre[i].id)
        {
            printf("la position de tache est :%d \n", i);
           
        }
    }
    if(target_id != entre[i].id){
        printf("la tache ne pas exist\n");
    }
  
}
// Fonction pour rechercher une tâche par son TITRE
//______________________________________________________________________________________________________________________________________
void Rechercher_tasks_titre()
{
    char target_titre[20];
    printf("entre  le titre de tache:\n");
    scanf(" %[^\n]", target_titre);
    for (int i = 0; i < taskCount; i++)
    {
        if (strcmp(entre[i].titre, target_titre) == 0)
        {
            printf("la position de titre tache est :%d \n", i);
        }
    }
}
// Fonction pour le menu de recherche
//______________________________________________________________________________________________________________________________________
void Rechercher()
{
    int Rechercher;
    do
    {
        printf("1: Rechercher une tâche par son Id.\n");
        printf("2: Rechercher une tâche par son TITRE.\n");
        scanf("%d", &Rechercher);
        switch (Rechercher)
        {
        case 1:
            Rechercher_tasks_id(entre);
            break;
        case 2:
            Rechercher_tasks_titre(entre);
            break;
        }
    } while (Rechercher < 1 || Rechercher > 2);
}
// Fonction pour compter le nombre de tâches complètes et incomplètes
//______________________________________________________________________________________________________________________________________
void LE_STATUS()
{
    for (int i = 0; i < taskCount; i++)
    {
        if (strcmp(entre[i].status, "DONE") == 0 )
        {
            complètes++;
        }
        else 
        {
            incomplètes++;
        }
    }
    printf("\ncomplet tasks count =  %d", complètes);
    printf("\nincomplètes tasks count =  %d\n", incomplètes);
}
// Fonction pour afficher le délai restant jusqu'à la deadline d'une tâche
//______________________________________________________________________________________________________________________________________
void deadline()
{
    int dead_id;

    time_t nowTime;
    time(&nowTime);

    printf("entre id de tasks");
    scanf("%d", &dead_id);
    for (int i = 0; i < taskCount; i++)
    {
        if (entre[i].id == dead_id)
        {
            time_t solution_Time = entre[i].time - time(NULL);
            printf("le time in days: %lld\n", (long long)(solution_Time / 86400)); 
        }
    }
}
// Fonction pour afficher des statistiques
//______________________________________________________________________________________________________________________________________
void Statistiques()
{
    int statis;
    do
    {
        printf("1: Afficher le nombre total des tâches.\n");
        printf("2: Afficher le nombre de tâches complètes et incomplètes.\n");
        printf("3: Afficher le nombre de jours restants jusqu'au délai de chaque tâche.\n");
        scanf("%d", &statis);
        switch (statis)
        {
        case 1:
            printf("LE TOTAL TASKS : %d\n\n", taskCount);

            break;
        case 2:
            LE_STATUS();
            break;
        case 3:
            deadline();
            break;
        }

    } while (statis < 1 || statis > 3);
}
// Fonction pour supprimer une tâche
//______________________________________________________________________________________________________________________________________
void Supprimer()
{
    int sup_id;
    printf("ENTRE ID DE TACHE POUR SUPPRIMER :");
    scanf("%d", &sup_id);
    for (int i = 0; i < taskCount; i++)
    {
        if (entre[i].id == sup_id)
        {
            for (int j = i; j < taskCount - 1; j++)
            {
                entre[j] = entre[j + 1];
            }
            taskCount--;
            printf("TACHE SUPPRIMEE AVEC SUCCES .\n");
        }
    }
}
// Fonction principale
//______________________________________________________________________________________________________________________________________
int main()
{
    int choose, order_choose, nombre_tasks, d;
    while (1)
    {
        printf("1: Ajouter tasks\n");
        printf("2: Afficher la liste des tasks\n");
        printf("3: Modifier tache\n");
        printf("4: aficher les statistique\n");
        printf("5: Rechercher un tasks \n");
        printf("6: Supprimer une tâche par identifiant \n");
        printf("7: Quitter le programme\n");
        scanf("%d", &choose);

        switch (choose)
        {
        case 1:
            add_tasks(); 
            break;
        case 2:
            menu_triage();
            break;
        case 3:
            modifier_tasks();
            break;
        case 4:
            Statistiques();
            break;
        case 5:
            Rechercher();
            break;
        case 6:
            Supprimer();
            break;
        case 7:
            return 0;
        }
    }
}

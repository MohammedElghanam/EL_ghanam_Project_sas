#include <stdio.h>
#include <string.h>
#include <time.h>

struct task
{
    char titre[100];
    char description[100];
    int time, id, stat;
    char status[100];
};
int numId = 1;
int taskCount = 0;
int complètes = 0;
int incomplètes = 0;
struct task entre[5];
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
            long long seconds = (long long)jour * 86400; // 86400 secs in 1 day
            time_t nowTime;
            time(&nowTime);
            seconds += nowTime;
            // store task time
            entre[i].time = seconds;
        } while (jour < 1);
        do
        {
            printf("##ENTRE LE STATUT DE LA TÂCHE :\n 1: À RÉALISER \n 2: EN COURS DE RÉALISATION \n 3: FINALISÉE \n");
            scanf(" %d", &entre[taskCount].stat);
            switch (entre[taskCount].stat)
            {
            case 1:
                strcpy(entre[taskCount].status, "À RÉALISER");
                break;
            case 2:
                strcpy(entre[taskCount].status, "EN COURS DE RÉALISATIONon");
                break;
            case 3:
                strcpy(entre[taskCount].status, "FINALISÉE");
                break;
            }
        } while (entre[taskCount].stat < 1 || entre[taskCount].stat > 3);
        numId++;
        taskCount++;
        printf("\n");
    }
}
//______________________________________________________________________________________________________________________________________
void output_tasks()
{
    for (int i = 0; i < taskCount; i++)
    {
        // entre[i].id = numId ;
        printf("-->  LE ID DE LA TÂCHE %d EST : %d\n", i + 1, entre[i].id);
        printf("--> Le titre de la tâche %d est : %s\n", i + 1, entre[i].titre);
        printf("--> Description de la tâche %d : %s\n", i + 1, entre[i].description);
        time_t solution_Time = entre[i].time - time(NULL);
        printf("--> LE time in = %lld JOUR %lld hur\n", (long long)(solution_Time / 86400), (long long)(solution_Time / 3600));
        printf("--> Statut de la tâche : %s \n\n", entre[i].status);
    }
}
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
        alphabetical(entre); // Sort the tasks alphabetically
        output_tasks(entre); // Display the sorted tasks
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
//______________________________________________________________________________________________________________________________________
void modifier_tasks()
{
    int target_id, exist = 0, jour;
    printf("entre  id de tache:\n");
    scanf("%d", &target_id);
    for (int i = 0; i < taskCount; i++)
    {
        if (entre[i].id == target_id)
        {
            printf("Entre la description de la tâche :\n");
            scanf(" %[^\n]", entre[i].description);
            printf("Entre la deadline de la tâche %d (en jour):\n", numId);
            scanf("%d", &jour);
            long long seconds = (long long)jour * 86400; // 86400 secs in 1 day

            time_t nowTime;

            time(&nowTime);

            seconds += nowTime;

            // store task time
            entre[i].time = seconds;
            printf("Entre la status de la tâche :\n");
            scanf(" %[^\n]", entre[i].status);
            exist = 1;
            break;
        }
    }
    if (!exist)
    {
        printf("le ID %d ne pa6666666s exist\n", target_id);
    }
}
//______________________________________________________________________________________________________________________________________
void Rechercher_tasks_id()
{
    int target_id, found = 0;
    printf("entre  id de tache:\n");
    scanf("%d", &target_id);
    for (int i = 0; i < taskCount; i++)
    {
        if (target_id == entre[i].id)
        {
            printf("la position de tache est :%d \n", i);
            found = 1;
            break;
        }
    }
    if (!found)
    {
        printf(" le ID %d ne pasoooooooo exist \n", target_id);
    }
}
//______________________________________________________________________________________________________________________________________
void Rechercher_tasks_titre()
{
    char target_titre[20], found = 0;
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
//______________________________________________________________________________________________________________________________________
void LE_STATUS()
{
    // == 0 || strcmp(entre[i].status, "EN COURS DE RÉALISATIONon") == 0
    for (int i = 0; i < taskCount; i++)
    {
        if (strcmp(entre[i].status, "FINALISÉE") == 0 )
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

            /*    printf("remaining time in seconds= %lld \n", (long long)solution_Time);
                printf("remaining time in minuts = %lld\n", (long long)(solution_Time / 60)); // 60 s in 1 min
                printf("remaining time in Hrs = %lld\n", (long long)(solution_Time / 3600));  // 3600 second in an hour */
            printf("le time in days: %lld\n", (long long)(solution_Time / 86400)); // 86400 second in a day
        }
    }
}
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
            LE_STATUS(entre);
            break;
        case 3:
            deadline(entre);
            break;
        }

    } while (statis < 1 || statis > 3);
}
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
            printf("TACHE SUPPRIMEE AVEC SUCES .\n");
        }
    }
}
//______________________________________________________________________________________________________________________________________
int main()
{
    int choose, order_choose, nombre_tasks, d;
    // struct task entre[100]; 

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

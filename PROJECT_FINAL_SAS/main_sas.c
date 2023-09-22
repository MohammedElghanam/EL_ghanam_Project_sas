#include <stdio.h>
#include <string.h>

struct task {
    char titre[100];
    char description[100];
    int jour, month, year, id,stat;
    char status [100];
};
int numId = 1; 
int taskCount = 0;

//________________________________________________________________________________________________________________________________________________________________________

void add_tasks( struct task entre[]) {

    entre[taskCount].id= numId;
    printf("Entre le titre de la tâche %d:\n",numId);
    scanf(" %[^\n]", entre[taskCount].titre);
    printf("Entre la description de la tâche :\n");
    scanf(" %[^\n]", entre[taskCount].description);
    printf("Entre la deadline de la tâche %d (JJ/MM/YYYY):\n", numId);
    scanf("%d/%d/%d", &entre[taskCount].jour, &entre[taskCount].month, &entre[taskCount].year);
    do{
    printf("Entre le status de la tâche :\n 1: à réaliser \n 2: en cours de réalisation \n 3: finalisée \n");
    scanf(" %d",&entre[taskCount].stat);
    
     switch (entre[taskCount].stat)
    {
    case 1:
        strcpy(entre[taskCount].status, "à réaliser");
        break;
    case 2:
        strcpy(entre[taskCount].status, "en cours de réalisation");
        break;
    case 3:
        strcpy(entre[taskCount].status, "finalisée");
        break;
    }
    }while(entre[taskCount].stat<1 || entre[taskCount].stat>3);

    numId++;
    taskCount++;
    printf("\n");
}


  //___________________________________________________________________________________________________________________________________________________________________________

// Function to display tasks
void output_tasks( struct task entre[]) {
    for (int i = 0; i < taskCount; i++) {
        // entre[i].id = numId ;
        printf("--> Le ID de la tâche %d est : %d\n", i + 1, entre[i].id);
        printf("--> Le titre de la tâche %d est : %s\n", i + 1, entre[i].titre);
        printf("--> Description de la tâche %d : %s\n", i + 1, entre[i].description);
        printf("--> La deadline de la tâche %d est : %d/%d/%d \n", i + 1, entre[i].jour, entre[i].month, entre[i].year);
        printf("--> Statut de la tâche : %s \n\n", entre[i].status);

	}
}

//______________________________________________________________________________________________________________________________________________


// Function to perform alphabetical sorting
void alphabetical( struct task entre[]) {
    struct task transfer;
    int i, j;
    for (i = 0; i < taskCount; i++) {
        for (j = i + 1; j < taskCount; j++) {
            if (strcmp(entre[i].titre, entre[j].titre) > 0) {
                transfer = entre[i];
                entre[i]= entre[j];
                entre[j]= transfer;
            }
        }
    }
}






//________________________________________________________________________________________________________________________________________

//________________________________________________________________________________________________________________________________________

int  menu_triage( struct task entre[] ){

                int order_choose;
		        printf(" 1 : Trier les tâches par ordre alphabétique.\n");
              /*  printf(" 2 : Trier les tâches par deadline.\n");
                printf(" 3 : Afficher les tâches dont le deadline est dans 3 jours ou moins.\n"); */
                scanf("%d", &order_choose);
                switch (order_choose) {
                    case 1:
                        alphabetical( entre); // Sort the tasks alphabetically
                        output_tasks( entre); // Display the sorted tasks
                        break;
                /*    case 2 :
                        printf("par deadline");
                        break;
                    case 3 :
                        printf("3 jours");
                        break; */
                    case 4 :
                        return 0;
                    default: printf("Choix non valide.\n");
                        break;
                }
}

//______________________________________________________________________________________________________________________________________

void modifier_tasks(struct task entre[]){
    int target_id;
    printf("entre  id de tache:\n");
    scanf("%d",&target_id);
    for (int i = 0; i < taskCount; i++)
    {
        if(target_id == entre[i].id){
            printf("Entre la description de la tâche :\n");
            scanf(" %[^\n]", entre[i].description);
            printf("Entre la deadline de la tâche %d (JJ/MM/YYYY):\n", numId);
            scanf("%d/%d/%d", &entre[i].jour, &entre[i].month, &entre[i].year);
            printf("Entre la description de la tâche :\n");
            scanf(" %[^\n]", entre[i].status);

        }else printf("%d ne pas exist \n",target_id);
    }
    




}


//_______________________________________________________________________________________________________________________________________________


void Rechercher_tasks_id(struct task entre[]){
    int target_id;
    printf("entre  id de tache:\n");
    scanf("%d",&target_id);
    for (int i = 0; i < taskCount; i++)
    {
        if(target_id == entre[i].id){
            printf("la position de tache est :%d \n",i);
            

        }else printf("%d ne pas exist \n",target_id);
    }
    

}

//__________________________________________________________________________________________________________________________________________________

void Rechercher_tasks_titre(struct task entre[]){
    char target_titre[20];
    printf("entre  le titre de tache:\n");
    scanf(" %[^\n]",target_titre);
    for (int i = 0; i < taskCount; i++)
    {
        if(strcmp(entre[i].titre,target_titre)==0){
            printf("la position de titre tache est :%d \n",i);}
        else{ 
            printf(" ne pas exist \n");}
    }
    




}
//_____________________________________________________________________________________________________________________________________________________________


 void Rechercher (struct task entre[]){
        int Rechercher;
        do{
         printf("1: Rechercher une tâche par son Identifiant.\n");
         printf("2: Rechercher une tâche par son Identifiant.\n");
         scanf("%d",&Rechercher);
        switch (Rechercher)
        {
        case 1: Rechercher_tasks_id(entre);
            break;
        case 2: Rechercher_tasks_titre(entre);
            break;
        }
        }while(Rechercher<1 || Rechercher>2);
 }
//______________________________________________________________________________________________________________________________________________
int complètes=0;
int  incomplètes=0;
void LE_STATUS(struct task entre[]){
    for(int i=0; i<taskCount; i++){
        if (strcmp(entre[i].status,"à réaliser")==0)
        {
            complètes++;
        }else if (strcmp(entre[i].status,"à réaliser")!=0)
        {
            incomplètes++;
        }

    }
        printf("complet tasks count =  %d",complètes);
        printf("incomplètes tasks count =  %d",incomplètes);

}

 void Statistiques(struct task entre[]){
            int statis;
            do{
         printf("1: Afficher le nombre total des tâches.\n");
         printf("2: Afficher le nombre de tâches complètes et incomplètes.\n");
         printf("3: Afficher le nombre de jours restants jusqu'au délai de chaque tâche.\n");
         scanf("%d",&statis);
        switch (statis)
        {
        case 1: printf("%d",taskCount);
            
            break;
        case 2: LE_STATUS(entre);
            break;
        
        
        }

            }while(statis<1 || statis>3);
 }
//________________________________________________________________________________________________________________________________________________________________



//___________________________________________________________________________________________________________________________________________







int main() {
    int choose, order_choose, nombre_tasks,d;
    struct task entre[100]; // Define an array to store tasks

    while (1) {
        printf("1: Ajouter tasks\n");
        printf("2: Afficher la liste des tasks\n");
        printf("3: Modifier tache\n");
        printf("4: aficher les statistique\n");
        printf("5: Rechercher un tasks \n");
        printf("7: Quitter le programme\n");
        scanf("%d", &choose);

        
            
        switch (choose) {
            case 1:
                
                add_tasks(entre); // Pass the task array to the function
                break;
            case 2:
                menu_triage(entre);
                break;
            case 3 :
                modifier_tasks(entre);
                break;
            case 4:
                Statistiques(entre);
                break; 
            case 5: Rechercher (entre);
                break;
         /*   case 6: Rechercher_tasks_titre(entre);
	            break; */
            case 7: 
	             return 0;
            default: printf("Le choix n'existe pas.\n");
        }
    }
    
}

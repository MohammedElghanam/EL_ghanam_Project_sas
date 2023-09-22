#include <stdio.h>
#include <string.h>

struct task {
    char titre[100];
    char description[100];
    int jour, month, year, id;
    char status [100];
};
int numId = 1; 
int taskCount = 0;


void add_tasks( struct task entre[]) {
    
    entre[taskCount].id= numId;
    printf("Entre le titre de la tâche %d:\n",numId);
    scanf(" %[^\n]", entre[taskCount].titre);
    printf("Entre la description de la tâche :\n");
    scanf(" %[^\n]", entre[taskCount].description);
    printf("Entre la deadline de la tâche %d (JJ/MM/YYYY):\n", numId);
    scanf("%d/%d/%d", &entre[taskCount].jour, &entre[taskCount].month, &entre[taskCount].year);
    
    strcpy(entre[taskCount].status, "à réaliser");
    numId++;
    taskCount++;
    printf("\n");
}
   
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
                printf(" 2 : Trier les tâches par deadline.\n");
                printf(" 3 : Afficher les tâches dont le deadline est dans 3 jours ou moins.\n");
                scanf("%d", &order_choose);
                switch (order_choose) {
                    case 1:
                        alphabetical( entre); // Sort the tasks alphabetically
                        output_tasks( entre); // Display the sorted tasks
                        break;
                    case 2 :
                        printf("par deadline");
                        break;
                    case 3 :
                        printf("3 jours");
                        break;
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






int main() {
    int choose, order_choose, nombre_tasks,d;
    struct task entre[100]; // Define an array to store tasks

    while (1) {
        printf("1: Ajouter plusieurs nouvelles tâches\n");
        printf("2: Afficher la liste de toutes les tâches\n");
        printf("3: Modifier tache\n");
        printf("4: aficher le nombre des tasks\n");
        printf("5: Rechercher un tasks ID\n");
        printf("6: Rechercher un tasks TITRE\n");
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
            printf("%d",taskCount);
                break;
            case 5: Rechercher_tasks_id(entre);
                break;
            case 6: Rechercher_tasks_titre(entre);
	            break; 
            case 7: 
	             return 0;
            default: printf("Le choix n'existe pas.\n");
        }
    }
    
}

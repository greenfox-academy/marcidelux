#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <stdint.h>
#include "todoes.h"



//Functions
void clrscr();
void delay(unsigned int mseconds);
void print_ui();


int main()
{
    char command[255];
    char path = "todo.txt";
    char command_saved[255];

    todo_list list_of_todoes;
    init_todoes(&list_of_todoes);


    while(1) {

        print_ui();
        printf("Your command: ");
        gets(command);
        strcpy(command_saved, command);
        char *com_ptr;
        com_ptr = strtok(com_ptr, " ");

        if(strstr(com_ptr, "-a") != NULL) {
            com_ptr = strtok(NULL, " ");
            int ischecked = 0;
            char task[255];
            strcpy(task, com_ptr);
            unsigned int priority = 0;
            add_todo(&list_of_todoes, ischecked, task, priority);

        } else if(strstr(command, "-wr") != NULL){
            printf("-wr");
        } else if(strstr(command, "-rd") != NULL){

        } else if(strstr(command, "-l") != NULL){

        } else if(strstr(command, "-e") != NULL){

        } else if(strstr(command, "-r") != NULL){

        } else if(strstr(command, "-c") != NULL){

        } else if(strstr(command, "-pl") != NULL){

        } else if(strstr(command, "-quit") != NULL){
            exit(0);
        } else {
            printf("!!!!Wrong Command!!!!");
            delay(2000);
        }

        clrscr();

    }
    return 0;
}

void clrscr()
{
    system("@cls||clear");
}

void delay(unsigned int mseconds)
{
    clock_t goal = mseconds + clock();
    while (goal > clock());
}

void print_ui()
{
    printf("Todo application\n");
    printf("====================\n");
    printf("-a\tAdds a new task\n");
    printf("-wr\tWrite current todos to file\n");
    printf("-rd\tRead todos froexit(0);m a file\n");
    printf("-l\tLists all the tasks\n");
    printf("-e\tEmpty the list\n");
    printf("-r\tRemoves a task\n");
    printf("-c\tAdd priority to a task\n");
    printf("-pl\tLists all the tasks by priority\n");
    printf("-exit\tExits from Todo\n\n");
}


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <stdint.h>
#include "todoes.h"

#define CHEC 1 //checked task
#define NCHEC 0 // unchecked task


typedef struct{
    char task[255];
    uint8_t ischecked:1;
    int priority;
}todo;

//Functions
void clrscr();
void delay(unsigned int mseconds);
void print_ui();
todo* add_todo_to_list(todo *old_list, todo input_todo );
//Global variables
todo todo_list[NULL];
int length_of_list = 0;


int main()
{
    char command[255];
    char *sub_command1;
    char *sub_command2;
    FILE *todofile;


    while(1) {

        print_ui();
        printf("Your command: ");
        gets(command);

        sub_command1 = strtok(command, " ");
        printf("%s\n", sub_command1);
        sub_command2 = strtok(NULL, " ");
        printf("%s\n", sub_command2);

        if(strstr(command, "-a") != NULL) {
            todo new_todo;
            new_todo.ischecked = NCHEC;
            new_todo.task = ;
            add_todo_to_list(todo_list, new_todo);

            delay(3000);
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

todo* add_todo_to_list(todo *old_list, todo input_todo )
{
    length_of_list++;
    todo *new_list = (todo*)calloc(length_of_list, sizeof(todo));

    for (int i = 0; i < length_of_list - 1; i++) {
        new_list[i] = old_list[i];
    }

    new_list[length_of_list - 1] = input_todo;

    free(old_list);

    return new_list;

}








#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <time.h>
#include "command_handle.h"

char port_name[50];
int port_index;
char decide[1];
char input;
char write_file_name[100];
char read_file_name[100];
int log_on = 1;

//variables for logging
int file_opened = 0;
char buffer[1];
char temp[5];
int temp_int;
int avarage_array[10];
int i = 0;
time_t curtime;
struct tm *lt;
float avarage;

void command_execution(char *instruction)
{
    if (strcmp(instruction, "h") == 0) {
        show_command_list();
    } else if (strcmp(instruction, "e") == 0) {
        exit_program();
    } else if (strcmp(instruction, "l") == 0) {
        list_aviable_ports();
    } else if (strcmp(instruction, "p") == 0) {
        set_port_name();
    } else if (strcmp(instruction, "w") == 0) {
        set_write_file_name();
    } else if (strcmp(instruction, "o") == 0) {
        open_port();
    } else if (strcmp(instruction, "s") == 0) {
        logging_temperature();
    } else if (strcmp(instruction, "r") == 0) {
        set_read_file_name();
    } else if (strcmp(instruction, "a") == 0) {
        calculate_avarage_in_time();
    } else {
        printf("Invalid instruction!\n");
        Sleep(1000);
        print_menu();
    }
}

void exit_program(){
    printf("program will shut down in:\n");
    for (int i = 3; i >=1; i--) {
        printf("%d..\n",i);
        Sleep(1000);
    }
    exit(0);
}

void list_aviable_ports()
{
    int num_of_ports = comEnumerate();

    printf("\nAviable ports: ");
    for (int i = 0; i < num_of_ports; i++) {
        printf("%s, ", comGetPortName(i));
    }
    printf("\n-> Next command:");
}

void set_port_name()
{
    printf("Which port should be used? ");
    scanf("%s", &port_name);
    port_index = comFindPort(port_name);
    printf("\n-> Next command:");
}

void show_command_list(){

    printf("Clear screen before print commands (y/n)?");
    scanf("%s", decide);

    if(sizeof(decide) > 1) {
        printf("\nError! Type y/n next time.\n");
    } else if (strcmp(decide, "y") == 0) {
        clear_screen();
        print_menu();
    } else if (strcmp(decide, "n") == 0) {
        printf("\n");
        print_menu();
    } else {
        printf("\nError! Type y/n next time.\n");
    }
}

void open_port()
{
    if (port_name[0] == '\0') {
        printf("Invalid port name!");
        printf("\n-> Next command:");
    } else {
        comOpen(port_index, BITRATE);
        file_opened = 1;
        printf("%s has been opened.", port_name);
        printf("\n-> Next command:");
    }
}

void set_write_file_name()
{
    printf("Give a file name for saving temperature logs, [format->(*.txt)]: ");
    scanf("%s", write_file_name);
    printf("\n-> Next command:");
}

void set_read_file_name()
{
    printf("Give a file name for read log, [format->(*.txt)]: ");
    scanf("%s", read_file_name);
    printf("\n-> Next command:");
}

void logging_temperature()
{
    if(file_opened == 0) {
        printf("File was not opened!");
        printf("\n-> Next command:");
        return;
    }

    FILE *log;
    log = fopen(write_file_name, "w");

    if (log == NULL) {
        printf("Error opening file!\n");
    }

    while(log_on) {

        if (_kbhit() != 0) {
            input = _getch();
        }

        if(input == 's') {
            printf("\n-> Next command:");
            input = 'q';
            log_on = 0;
        }

        if (comRead(port_index, buffer, 1)) {

            if (buffer[0] != '\n') {
                temp[i] = buffer[0];
                i++;
            } else {
                temp[i] = '\0';
                i = 0;

                curtime = time(NULL);
                lt = localtime(&curtime);
                fprintf(log, "%d-%d-%d %d:%d:%d\t", lt -> tm_year + 1900, lt -> tm_mon, lt -> tm_mday,
                                                 lt ->tm_hour, lt ->tm_min, lt->tm_sec);
                fputs(temp, log);
                fprintf(log, "\n");
            }
        }
    }

    fclose(log);
    log_on = 1;
}

void calculate_avarage_in_time()
{
    char hour_f[2], min_f[2], sec_f[2], hour_t[2], min_t[2], sec_t[2], hour_x[2], min_x[2], sec_x[2];
    int h_f, m_f, s_f, h_t, m_t, s_t, h_x, m_x, s_x;
    int temp_x;
    int sum = 0;
    int counter = 0;

    printf("Give a period for calculate average\n");
    printf("from (h:m:s): ");
    scanf("%d", &h_f);
    scanf("%d", &m_f);
    scanf("%d", &s_f);
    printf("to (h:m:s): ");
    scanf("%d", &h_t);
    scanf("%d", &m_t);
    scanf("%d", &s_t);

    printf("from: %d:%d:%d\n", h_f, m_f, s_f);
    printf("to: %d:%d:%d\n", h_t, m_t, s_t);


    FILE *f;
    char row[255];
    char *row_ptr;

    if ((f = fopen(read_file_name,"r")) == NULL) {
       printf("Error! opening file!\n");
       exit(1);
    }

    while (fgets(row, sizeof(row), f) != NULL) {
        row_ptr = strtok(row, " ");

        row_ptr = strtok(NULL, ":");
        strcpy(hour_x, row_ptr);
        h_x = atoi(hour_x);
        //printf("hour: %d\n", h_x);

        row_ptr = strtok(NULL, ":");
        strcpy(min_x, row_ptr);
        m_x = atoi(min_x);
        //printf("minute: %d\n", m_x);

        row_ptr = strtok(NULL, "\t");
        strcpy(sec_x, row_ptr);
        s_x = atoi(sec_x);
        //printf("seconds: %d\n", s_x);

        row_ptr = strtok(NULL, "\n");
        temp_x = atoi(row_ptr);
        //printf("temp: %d\n", temp_x);

        if (h_f <= h_x && h_x <= h_t) {
            if (m_f <= m_x && m_x <= m_t) {
                if (m_f <= m_x && h_x <= m_t) {
                    sum += temp_x;
                    //printf("sum %d, counter: %d\n", sum, counter);
                    counter++;
                }
            }
        }
    }
    if (sum == 0) {
        printf("Bad period!\n");
        return;
    }

    avarage = (float)sum / counter;
    printf("Avarage: %.02f\n", avarage);
    printf("\n-> Next command:");
    fclose(f);

}


void clear_screen()
{
    system("@cls||clear");
}






















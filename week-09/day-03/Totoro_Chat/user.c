#include "user.h"

void add_user(char name, char IP, int port)
{

}

void init_users() {
    totoro_user_list.users_len = 0;
}

void clear_user_list
{

}

void print_active_users()
{
    printf("IP\t\tPort\tName\n");
    for (int i = 0; i < totoro_user_list.users_len; i++) {
        printf("%s\t%d\t%s\n", totoro_user_list.users[i].IP_addr, totoro_user_list.users[i].Port, totoro_user_list.users[i].name);
    }
}

totoro_user* find_user_by_name(char *user_name)
{
    int i = 0;
    int len = totoro_user_list.users_len - 1

    while (strcmp(user_name, totoro_user_list.users[i].name) != 0) {
        i++;
        if ( i > len) {
            printf("There was no user with the given name!\n");
            return NULL;
        }
    }

    totoro_user *user_ptr = &(totoro_user_list.users[i]);
    return user_ptr;
}

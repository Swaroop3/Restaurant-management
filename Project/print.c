#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "print.h"
#include "struct.h"

void print_menu()
{
	FILE *m;
        menu item[60];
        m=fopen("menu","r");
        for(int i=0;i<=55;i++)
                fscanf(m, "%d %s %d" , &item[i].id , item[i].name , &item[i].price);
        printf("------------------------------------\n");
        printf("|Sl.no  |Dish name\t     |Price|\n");
	printf("------------------------------------\n");
        for(int i=0;i<=55;i++)
                printf("|%-6d |%-20s|%-3d  |\n",item[i].id,item[i].name,item[i].price);
        printf("------------------------------------\n");
	fclose(m);
}

void print_instructions()
{
    printf("\nInstructions:\n");
    printf("1 for Reservations\n");
    printf("2 for Placing order\n");
}

void print_ui(){
    printf("1 for login\n");
    printf("2 for singup\n");
    printf("0 for exit program\n");
}

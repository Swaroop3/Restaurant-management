#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "edit_menu.h"
#include "print.h"

void change_price(menu item[]){
    FILE *ptr;
    ptr=fopen("menu","r");
    int i,new_price;
    int index=-1;
    int num_of_items=0;
    printf("Enter the id of the item you want to change the price of: ");
    scanf("%d",&i);
    while(fscanf(ptr,"%d %s %d\n",&item[num_of_items].id,item[num_of_items].name,&item[num_of_items].price)!=EOF){
        if(item[num_of_items].id==i){
            index=num_of_items;
        }
        num_of_items++;

    }
    fclose(ptr);
    if(index==-1){
        printf("Item with ID %d not found in the menu\n",i);
        return;
    }
    printf("Enter the new price of %s: ",item[i-1].name);
    scanf("%d",&new_price);
    item[index].price=new_price;
    
    ptr=fopen("menu","w");
    for(int i=0;i<num_of_items;i++){
        fprintf(ptr,"%d %s %d\n",item[i].id,item[i].name,item[i].price);
    }
    fclose(ptr);
    printf("Price of %s has been updated to %d\n",item[index].name,new_price);


}

void add_item(menu item[]){
    FILE *q;
    char str[60];
    int n,price;
    print_menu();
    printf("Enter the new item: ");
    scanf("%s",str);
    printf("Enter the price of new item: ");
    scanf("%d",&price);
    printf("Enter the id of the new item: ");
    scanf("%d",&n);
    int num_items=0;
    q=fopen("menu","r");
    while(fscanf(q,"%d %s %d",&item[num_items].id,item[num_items].name,&item[num_items].price)!=EOF){
        num_items++;
    }
    fclose(q);
    for(int i=0;i<num_items;i++){
        if(item[i].id==n){
            printf("You entered an existing ID\n");
            return;
        }
    }
    item[n-1].price=price;
    strcpy(item[n-1].name,str);
    item[n-1].id=n;
    num_items++;
    q=fopen("menu","a");

    fprintf(q,"%d %s %d\n",item[n-1].id,item[n-1].name,item[n-1].price);
 
    fclose(q);
}


void remove_item(menu item[]) {
    FILE *menu_file = fopen("menu", "r"); // opening the  file in read mode
    FILE *temp_file = fopen("temp", "w"); // opening the  temporary file in write mode
    if (menu_file == NULL || temp_file == NULL) { //if any of them is empty it prints null.
        printf("Error opening file.\n");
        return;
    }

    
    int item_id;

    printf("Enter the ID of the item to remove: ");//taking id of  item to remove form user.
    scanf("%d", &item_id);

    // copy all lines except the lines in which item to remove is present  to the  temporary file
    int id;
    char name[60];
    int  price;
    int removed = 0; //initiationg the remove variable to zero.

    while (fscanf(menu_file, "%d %30s        %d\n",&id,name,&price) == 3) {
        if (id != item_id) {
            fprintf(temp_file, "%d %30s        %d\n",id,name,price);
        } 
        else {
            removed = 1; //remove variable changes to 1 , when item is sucessfully removed.
        }
    }

    if (removed==0) { //if remove variable remians zero , it means , the item is not removed/id not found.
        printf("ITEM WITH ID %d NOT FOUND.\n", item_id);
    }
    else{
        printf("ITEM WITH ID %d SUCCESSFULLY REMOVED.\n",item_id);
    }

    // closing and delete the menu file and renaming the temporary file as menu.
    fclose(menu_file);
    fclose(temp_file);
    remove("menu");
    rename("temp", "menu");

}

void edit_menu(){
    menu item[100];
    int num_items=0;
    FILE *p;
    p=fopen("menu","r");
    while(fscanf(p,"%d %s %d",&item[num_items].id,item[num_items].name,&item[num_items].price)!=EOF){
        num_items++;
    }
    fclose(p);
    int n;
    printf("\nEnter 1 for changing price\n");
    printf("Enter 2 for adding new item\n");
    printf("Enter 3 for removing item\n\n"); 
    label_1:
            scanf("%d",&n);
            switch(n){
                case 1:
                       change_price(item);
                       break;
                case 2:
                       add_item(item);
                       break;
                case 3:
                       remove_item(item);
                       break;
                
               
                default:
                       printf("Enter a valid input(1-3)\n");
                       goto label_1;  
            }
 }

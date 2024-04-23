#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "order.h"
#include "print.h"

typedef struct place // customer order
{
    char name[100]; // name of person
    int count;      // number of items he wants
    int quantity;
} place;

int place_order(char* name)
{
    place customer; //instance of place
    int noi; // name of item as per the ID
    menu item[56]; // menu items from Menu_1.txt
    int i, count = 0, bill = 0;

    FILE *m;

    m = fopen("menu", "r");
    for (i = 0; i < 56; i++) // read all menu items
          fscanf(m, "%d %s %d", &item[i].id, item[i].name, &item[i].price);
    strcpy(customer.name,name);
   
    char list[100][100]; //array of strings,for all valid items 
    int price_list[100]; // for all prices of valid items
    int quantity_list[100]; // all items's quantities
    bill =0; count=0; // final bill
   
    print_menu(); 
    printf("Enter 0 to stop ordering\n");
    while(1==1)
    {
        printf("Item %d id: ",count+1);
        scanf("%d", &noi);

        if(noi <= 56 && noi>=1) // a hit in the menu and item id
	{
                noi--; 
                customer.quantity = 1; // assume number of default items is 1
		printf("Enter number of %s you want: ",item[noi].name); // quantity of stored item name preferred(key)
		scanf("%d", &customer.quantity);
		int t=0, k=0, m=1; // to check if item name repeated
	        for(k=0; k<count; k++)
		{
			m=strcmp(list[k],item[noi].name);
			if(m==0)
			{
				t=1;
				break;
			}
			else
			{
				t=0;
			}
		}
		if(t==1)
		{
			customer.quantity=customer.quantity+quantity_list[k];
			quantity_list[k]=customer.quantity;
		}
		else
		{	
                	strcpy(list[count],item[noi].name); // copy the name 
                	price_list[count]=item[noi].price; // store it's price
                	quantity_list[count] = customer.quantity; // store the quantity of each associated items(value)
                	count++;
		}
	}
	else if(noi==0)
	{
		break;
	}
    }
    printf("Price\tQuantity     \tAmount\tItem Name\n");
    for(int h=0; h < count; h++)
    {
        if(price_list != 0)
        printf("%d\t%d\t\t%d\t%s\n",price_list[h], quantity_list[h],quantity_list[h]*price_list[h],list[h]);
	bill = bill + quantity_list[h]*price_list[h];
    }
    printf("Final Bill is %d \n", bill);
    fclose(m);
    return 0;
}

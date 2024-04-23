#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "reservation.h"
#include "print.h"
#define NUM_TABLES 50
#define twoseater 20
#define fourseater 20
#define fiveseater 10
int datecheck(int dd,int mm,int yyyy){
 
       if(mm>=1 && mm<=12){
            //check days
            if((dd>=1 && dd<=31) && (mm==1 || mm==3 || mm==5 || mm==7 || mm==8 || mm==10 || mm==12))
                return 1;
            else if((dd>=1 && dd<=30) && (mm==4 || mm==6 || mm==9 || mm==11))
                return 1;
            else if((dd>=1 && dd<=28) && (mm==2))
                return 1;
            else if(dd==29 && mm==2 && (yyyy%400==0 ||(yyyy%4==0 && yyyy%100!=0)))
                return 1;
	    else
                return 0;
	}
        else{
            return 0;
        }
}

int reserved_tables[NUM_TABLES] = {0};

void reservation(char* name) {
    FILE *ptr;
    ptr=fopen("Pdate.txt","w");
    fprintf(ptr,"%s",__DATE__);
    fclose(ptr);
    ptr=fopen("Pdate.txt","r");
    int present_date,present_year,present_month;
    char present_m[10];
    fscanf(ptr,"%s  %d %d",present_m,&present_date,&present_year);
    if (strcmp(present_m,"Jan")==0) {
	    present_month=1;
    }
    else if (strcmp(present_m,"Feb")==0) {
	    present_month=2;
    }
    else if (strcmp(present_m,"Mar")==0) {
	    present_month=3;
    }
    else if (strcmp(present_m,"Apr")==0) {
	    present_month=4;
    }
    else if (strcmp(present_m,"May")==0) {
	    present_month=5;
    }
    else if (strcmp(present_m,"Jun")==0) {
	    present_month=6;
    }
    else if (strcmp(present_m,"Jul")==0) {
	    present_month=7;
    }
    else if (strcmp(present_m,"Aug")==0) {
	    present_month=8;
    }
    else if (strcmp(present_m,"Sep")==0) {
	    present_month=9;
    }
    else if (strcmp(present_m,"Oct")==0) {
	    present_month=10;
    }
    else if (strcmp(present_m,"Nov")==0) {
	    present_month=11;
    }
    else if (strcmp(present_m,"Dec")==0) {
	    present_month=12;
    }

    int table_num,n,choice,validity;
    int date,month,year;
    while(1){
	   
	   printf("\nPlease enter date to reserve the table in dd/mm/yyyy format within two months of present date: ");
	   scanf("\n%d/%d/%d",&date,&month,&year);
	   validity=datecheck(date,month,year);

	   if(year<present_year || (year==present_year && month<present_month) || (year==present_year && month==present_month && date<present_date)){
	   printf("We dont make reservations in the past\n");
	   continue;
	   }

	   if(validity==1){
		   if(present_date<date && present_month==month && present_year==year){
			   break;
		   }
		   else if(present_year==year && month-present_month>0){
			   if(month-present_month==1){
				   break;
			   }
			   else if (month-present_month==2 && date<=present_date){
				   break;
			   }
	           }
		   else if(year-present_year==1 && present_month==11 && month==1 && date<=present_date){
				   break;
	           }
	           else if(year-present_year==1 && present_month==12){
	 		 if(month==1){
	  			   break;
			 }
			 else if(month==2 && date<=present_date){
			           break;
			 }
		   }      
	           else{
		         printf("Enter a date within two months\n");
		   }		 
	   }
	   else{
		  printf("Enter a valid date\n");
	   }
   }
   int nrtables=0;
   for(int j=0; j<NUM_TABLES; j++){
	if (reserved_tables[j]==0){
		   nrtables++;
	   }
   }
   while(1){
    	printf("Enter the no of tables to reserve: ");

    	scanf("\n%d",&n);
    	if(n<=nrtables){
     
        // Print table status
        printf("\nTable Status:\n");
	printf("2 seater tables are numbered from 1 to 20\n");
	printf("4 seater tables are numbered from 21 to 40\n");
	printf("5 seater tables are numbered from 41 to 50\n");

	printf("\n2 seater tables available: ");
        for (int i=0;i<twoseater;i++) {
            if (reserved_tables[i]==0) {
                printf("%d ", i+1);
            } 
        }

	printf("\n4 seater tables available: ");
	for (int i=twoseater;i<fourseater+twoseater;i++) {
            if (reserved_tables[i] == 0) {
                printf("%d ", i+1);
            } 
        }
	
	printf("\n5 seater tables available: ");
 	for (int i = twoseater+fourseater; i<fiveseater+fourseater+twoseater ; i++) {
            if (reserved_tables[i]== 0) {
                printf("%d ", i+1);
            }
        }
	printf("\n");
	while(n--) {
        // Prompt user for table number
		printf("\nEnter table number (1-%d) to reserve: ",NUM_TABLES);
        	scanf("%d", &table_num);

        if (table_num > 0 && table_num <= NUM_TABLES) {
            // Check if table is already reserved
            if (reserved_tables[table_num-1] == 1) {
                printf("Sorry, table %d is already reserved.\n", table_num);
		n++;
            }
	    else {
                // Reserve table
                reserved_tables[table_num-1] = 1;
                printf("Table %d has been reserved succesfully.\n", table_num);
            }
        }
       	else  {
            printf("Invalid table number. Please enter a number between 1 and 50.\n");
	    n++;
        }
   }
    printf("\nThank you for using our reservation system.\n");
    break;
    }
}
}

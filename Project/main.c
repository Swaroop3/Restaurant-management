#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "struct.h"
#include "print.h"
#include "reservation.h"
#include "signup_login.h"
#include "edit_menu.h"
#include "order.h"
				//For executable, compile all .c files together :)
void main()                     
{
	int i,user;             //Most of the functions are self-explanatory
	char name[50];          //with their names signifying the functionality
	printf("WELCOME TO THE HORIZON\n");
	label_1a:                                   	                  //Code block 1: For signup and login
		printf("\n");
		print_ui();
		printf("\n");
	label_1b:
		scanf("%d",&i);
		switch(i)
		{
			case 1:
				user=login(name);
				break;
			case 2:
				signup();
				goto label_1a;
			case 0:
				exit(0);
			default:
				printf("Enter a valid input\n");
				goto label_1b;
		}
	if(user==2)
		goto label_3a;  //Owner interface
	else if(user==1)
		goto label_2a;  //Customer interface
	else if (user==0)
		goto label_1a;  //Signup-login

	label_2a:                                  	                  //Code block 2: For the Customer
		printf("\n");
		print_instructions();
		printf("\n");
	label_2b:
		scanf("%d",&i);
		switch(i)
		{
			case 1:
				reservation(name);
			        break;
			case 2:
				place_order(name);
				break;
			default:
				printf("Enter a valid input\n");
				goto label_2b;
		}
	goto label_1a;
	label_3a:						          //Code block 3: For owner i.e:Swaroop (can be changed)
		//print_owner_opt();                                      //For trying this interface, use
	label_3b:                                                         //pno:9353733620 and pwd:1234
		//scanf("%d",&i);
		i=1;
		switch(i)
		{
			case 1:
				edit_menu();
				break;
			/*case 2:
				edit_employee_database(); //Feature not in use
				break;
			*/
			default:
				printf("Enter a valid input\n");
				goto label_3b;
		}
	goto label_1a;
}

//Contributions(in %):
//
//			Swaroop AR	Srinivas DA	Saketh M	Vaibhav M	Rahul M		Aditya J
//main.c		100.00		0.00		0.00		0.00		0.00		0.00		done
//print.c		70.00		0.00		30.00		0.00		0.00		0.00		done
//reservation.c		22.50		0.00		0.00		62.50		0.00		15.00		done
//order.c		0.00		0.00		0.00		10.00		60.00		30.00		done
//signup_login.c	100.00		0.00		0.00		0.00		0.00		0.00		done
//edit_menu.c		0.00		50.00		50.00		0.00		0.00		0.00		done
//
//Miscellaneous	       -All .h files	-features	-Menu		-Empoyee	-Motivated	-Minor
//		        and final 	blueprint	database	database	others		debugging
//		        compilation			(menu)		(Feature not
//		       -Customer					in use)
//		        database
//		    (login_credentials)

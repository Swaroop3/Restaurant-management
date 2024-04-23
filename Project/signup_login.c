#include<stdio.h>
#include<stdlib.h>
#include <string.h>
#include "signup_login.h"

int signup()
{
	char name[50],iname[50];
	int pwd,pwdc,ipwd;
	unsigned long long int pno,ipno;
	FILE *p;
	p=fopen("login_credentials","r");
	printf("Enter your name: ");
	scanf("%s",name);
	printf("Enter phone number: ");
	scanf("%llu",&pno);
	fscanf(p,"%s %llu %d",iname,&ipno,&ipwd);
	while(!(feof(p)))
	{
		if(pno==ipno)
		{
			printf("This phone number is already registered, you may log in\n");
			return 0;
		}
		fscanf(p,"%s %llu %d",iname,&ipno,&ipwd);
	}
	label_1:
		printf("Set your 4-digit password: ");
		scanf("%d",&pwd);
		printf("Confirm your 4-digit password: ");
		scanf("%d",&pwdc);
		if(pwd!=pwdc)
		{
			printf("Password does not match\n");
			goto label_1;
		}
	fclose(p);
	p=fopen("login_credentials","a");
	fprintf(p,"%s %llu %d\n",name,pno,pwd);
	fclose(p);
	printf("Account has been succesfully created, you may login\n");
	return 1;
}
int login(char *rname)
{
	int pwd,ipwd;
	unsigned long long int pno,ipno;
	char name[50],c;
	FILE *p;
	p=fopen("login_credentials","r");
	label_3:
		printf("\nEnter phone number: ");
		scanf("%llu",&pno);
		printf("Enter password: ");
		scanf("%d",&pwd);
		label_1:
			fscanf(p,"%s %llu %d",name,&ipno,&ipwd);
			if(feof(p))
			{
				printf("You need to be an existing member, please sign up\n");
				return 0;
			}
			if(pno!=ipno)
				goto label_1;
			if(pno==ipno)
			{
				label_2:
					if(pwd==ipwd)
					{
						printf("Hello %s\n",name);
						strcpy(rname,name);
						if(pno==9353733620)
							return 2;
						return 1;
					}
					else
					{
						printf("Incorrect password\nEnter '-1' to change phone number\nRe-enter password: ");
						scanf("%d",&pwd);
						if(pwd==-1)
							goto label_3;
						goto label_2;
					}
			}
}

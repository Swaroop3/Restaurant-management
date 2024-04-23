#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct item
{
	int id;
	char name[50];
	char *type;
	int price;
}item;
void main()
{
	item menu[100];
	int i;
	for(i=0;i<=55;i++){
		menu[i].id=i+1;
	}	
	strcpy(menu[0].name,"PLAIN DOSA");
	menu[0].price=45;

	strcpy(menu[1].name,"MASALA DOSA");
	menu[1].price=55;

	strcpy(menu[2].name,"ONION DOSA");
	menu[2].price=45;

	strcpy(menu[3].name,"SET DOSA");
	menu[3].price=50;

	strcpy(menu[4].name,"IDLY");
	menu[4].price=25;

	strcpy(menu[4].name,"MEDHU VADA");
	menu[4].price=30;

	strcpy(menu[5].name,"RAVA KESARI");
	menu[5].price=40;

	strcpy(menu[6].name,"MINI TIFFIN");
	menu[6].price=80;

	strcpy(menu[7].name,"POORI");
	menu[7].price=40;

	strcpy(menu[8].name,"SWEET PONGAL");
	menu[8].price=40;

	strcpy(menu[9].name,"GHEE PONGAL");
	menu[9].price=45;

	strcpy(menu[10].name,"KARA BATH");
	menu[10].price=40;

	strcpy(menu[11].name,"ALOO PARATHA");
	menu[11].price=70;

	strcpy(menu[12].name,"GOBI PARATHA");
	menu[12].price=70;

	strcpy(menu[13].name,"METHI PARATHA");
	menu[13].price=70;

	strcpy(menu[14].name,"MIX PARATHA");
	menu[14].price=70;

	strcpy(menu[15].name,"POHA");
	menu[15].price=70;

	strcpy(menu[16].name,"PAV BHAJI");
	menu[16].price=100;

	strcpy(menu[17].name,"EXTRA PAV");
	menu[17].price=20;

	strcpy(menu[18].name,"DHOKLA");
	menu[18].price=30;

	strcpy(menu[19].name,"GULAB JAMUN");
	menu[19].price=40;

	strcpy(menu[20].name,"GAJAR KA HALWA");
	menu[20].price=50;

	strcpy(menu[21].name,"PANEER 65");
	menu[21].price=200;

	strcpy(menu[22].name,"CHILLY PANEER");
	menu[22].price=220;

	strcpy(menu[23].name,"CHILLY GOBI");
	menu[23].price=210;

	strcpy(menu[24].name,"MUSHROOM 65");
	menu[24].price=215;

	strcpy(menu[25].name,"BABY CORN");
	menu[25].price=200;

	strcpy(menu[26].name,"CHILLY CHICKEN(BONELESS)");
	menu[26].price=240;

	strcpy(menu[27].name,"CHICKEN 65");
	menu[27].price=240;

	strcpy(menu[28].name,"CHICKEN LOLLYPOP");
	menu[28].price=250;

	strcpy(menu[29].name,"CHICKEN MAHARAJA");
	menu[29].price=280;

	strcpy(menu[30].name,"MUTTON PEPPER FRY");
	menu[30].price=275;

	strcpy(menu[31].name,"VEG KADAI");
	menu[31].price=225;

	strcpy(menu[32].name,"PALAK PANEER CURRY");
	menu[32].price=275;

	strcpy(menu[33].name,"PANEER BUTTER MASALA");
	menu[33].price=280;

	strcpy(menu[34].name,"KAJU MASALA");
	menu[34].price=295;

	strcpy(menu[35].name,"ALOO DUM BIRYANI");
	menu[35].price=215;

	strcpy(menu[36].name,"PANEER BIRYANI");
	menu[36].price=270;

	strcpy(menu[37].name,"BIRYANI RICE");
	menu[37].price=190;

	strcpy(menu[38].name,"VEG FRIED RICE");
	menu[38].price=190;

	strcpy(menu[39].name,"MUSHROOM BIRYANI");
	menu[39].price=270;

	strcpy(menu[40].name,"SPECIAL VEG BIRYANI");
	menu[40].price=230;

	strcpy(menu[41].name,"CHICKEN CURRY(BONELESS)");
	menu[41].price=250;

	strcpy(menu[42].name,"BUTTER CHICKEN CURYY");
	menu[42].price=260;

	strcpy(menu[43].name,"MUTTON CURRY");
	menu[43].price=280;

	strcpy(menu[44].name,"FISH CURRY");
	menu[44].price=295;

	strcpy(menu[45].name,"PRAWNS CURRY");
	menu[45].price=300;

	strcpy(menu[46].name,"CHICKEN BIRYANI");
	menu[46].price=240;

	strcpy(menu[47].name,"CHICKEN FRY BIRYANI");
	menu[47].price=260;

	strcpy(menu[48].name,"MUTTON BIRYANI");
	menu[48].price=300;

	strcpy(menu[49].name,"KHEEMA BIRYANI");
	menu[49].price=315;

	strcpy(menu[50].name,"FISH BIRYANI");
	menu[50].price=315;

	strcpy(menu[51].name,"MINT LIME SODA");
	menu[51].price=50;

	strcpy(menu[51].name,"BLUE LIME SODA");
	menu[51].price=50;

	strcpy(menu[52].name,"JAL JEERA SODA");
	menu[52].price=60;

	strcpy(menu[53].name,"MINT MOJITO");
	menu[53].price=60;

	strcpy(menu[54].name,"STRAWBERRY LASSI");
	menu[54].price=60;

	strcpy(menu[55].name,"MANGO LASSI");
	menu[55].price=60;

	for(int i=0;i<=10;i++)
		menu[i].type="SOUTH INDIAN";

	for(int i=11;i<=20;i++)
		menu[i].type="NORTH INDIAN";

	for(int i=21;i<=25;i++)
		menu[i].type="VEG STARTER";
	
	for(int i=26;i<=30;i++)
		menu[i].type="NON VEG STARTER";

	for(int i=31;i<=34;i++)
		menu[i].type="VEG CURRIES";

	for(int i=35;i<=40;i++)
		menu[i].type="VEG BIRIYANI";

	for(int i=41;i<=45;i++)
		menu[i].type="NON VEG CURRIES";

	for(int i=46;i<=50;i++)
		menu[i].type="NON VEG BIRIYANI";

	for(int i=51;i<=55;i++)
		menu[i].type="BEVERAGES";
	FILE *p;
	p=fopen("Menu","w");
	for(i=0;i<56;i++)
		fprintf(p,"%d %s %d\n",menu[i].id,menu[i].name,menu[i].price);
}

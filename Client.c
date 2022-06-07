/***************************************************************************************/
/********************************  Hythm Saad Khalifa **********************************/
/***************************************************************************************/
/****** This file is developed by Hythm Saad Khalifa, All copyrights are reserved ******/
/***************************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include "STD_TYPES.h"
#include <string.h>
#include "Private.h"
#include "Client.h"
#include "Admin.h"

extern node* head;

u8 clientMode(node ** TempNode)
{
	u32 accountID;
	u8 password[20];
	system("cls");
	system("cls");
	printf("/***************************************************************************************/\n");
	printf("/**************************  IMT Bank System -- Client Mode ****************************/\n");
	printf("Please Enter your Account ID:");
	openExistingAccount(TempNode);
	if (*TempNode != NULL)
	{	
		printf("\nPlease Enter your Password:");
		scanf("%s",&password);
		if(strcmp((*TempNode)->data.accountPassword,password))
		{	
			printf("Wrong Password");
			getchar();
			return 0;
		}
		else
		{
			displayData(*TempNode);
			return 1;
		}
	}
	else
	{
		printf("There is no such account");
		return 0;
	}
} 
void changeAccountPass(node* TempNode)
{
	u8 password[20];
	printf("\nPlease Enter your Password:");
	scanf("%s",&password);
	if(strcmp(TempNode->data.accountPassword,password))
	{	
		printf("Wrong Password");
		getchar();
	}
	else
	{
		printf("Correct Password");
		getchar();
		printf("\nPlease Enter your Password:");
		scanf("%s",&password);
		strcpy(TempNode->data.accountPassword,password);
	}
	
}
	
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

#define		NOT_EXIST		0
#define		EXIST			1

u8 clientMode(node ** TempNode)
{
	u32 accountID;
	u8 password[20];
	system("cls");
	system("cls");
	printf("/***************************************************************************************/\n");
	printf("/**************************  IMT Bank System -- Client Mode ****************************/\n");
	printf("Please Enter your Account ID:");
	openExistingAccount(TempNode);	//Search for The Account ID
	if (*TempNode != NULL)		//If The Account ID is Found
	{	
		printf("\nPlease Enter your Password:");
		scanf("%s",&password);
		if(strcmp((*TempNode)->data.accountPassword,password))	//IF The Password Entered is Wrong
		{	
			printf("Wrong Password");
			printf("Press any key........");
			getchar();
			getchar();
			return NOT_EXIST;
		}
		else
		{
			displayData(*TempNode);
			return EXIST;
		}
	}
	else
	{
		printf("There is no such account");
		printf("Press any key........");
		getchar();
		getchar();
		return NOT_EXIST;
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
		printf("Press any key........");
		getchar();
		getchar();
	}
	else
	{
		printf("Correct Password");
		getchar();
		printf("\nPlease Enter your  New Password:");
		scanf("%s",&password);
		strcpy(TempNode->data.accountPassword,password);
	}
	
}
	
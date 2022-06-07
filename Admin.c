/***************************************************************************************/
/********************************  Hythm Saad Khalifa **********************************/
/***************************************************************************************/
/****** This file is developed by Hythm Saad Khalifa, All copyrights are reserved ******/
/***************************************************************************************/
#include "STD_TYPES.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "Private.h"
#include "Admin.h"

#define 	ADMIN_MODE_USERNAME		"admin"
#define 	ADMIN_MODE_PASSWORD		"admin"

node head;
u32 ListLength=0;

u8 const alpha[] = "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ$%&*";


u8 adminMode(void)
{
	u8 userName[20],password[20];
	system("cls");
	system("cls");
	printf("/***************************************************************************************/\n");
	printf("/***************************  IMT Bank System -- Admin Mode ****************************/\n");
	printf("Please Enter your Username:");
	scanf("%s",&userName);
	printf("\nPlease Enter your Password:");
	scanf("%s",&password);
	if(strcmp(ADMIN_MODE_USERNAME,userName) && strcmp(ADMIN_MODE_PASSWORD,password))
		return 1;
	else
	{
		return 0;
}
}

void addData(node * Data)
{
	u8 index=0;
	system("cls");
	printf("/***************************************************************************************/\n");
	printf("/***************************  IMT Bank System -- Admin Mode ****************************/\n");
	printf("Enter the Full Name\n:");
	scanf(" %[^\n]%*c",&Data->data.fullName);
	printf("Enter the Full Address\n:");
	scanf(" %[^\n]%*c",&Data->data.fullAddress);
	printf("Enter the Age\n:");
	scanf("%d",&Data->data.age);
	if(Data->data.age<21)
	{
		printf("Enter the Guardian ID Number\n:");
		scanf("%d",&Data->data.guardianID);
	}
	printf("Enter the National ID Number\n:");
	scanf("%llu",&Data->data.nationalID);
	Data->data.accountID = ((100000*(rand()%1000000000)) | (rand()%1000000000));
	printf("The Account ID: %lu\n",Data->data.accountID);
	srand(time(0));
	printf("Your Password:");
	for(index=0;index<20;index++)
	{
		Data->data.accountPassword[index]=alpha[rand()%strlen(alpha)];
		printf("%c",Data->data.accountPassword[index]);
	}
	printf("\nEnter the Balance:");
	scanf("%d",&Data->data.balance);	
	Data->data.accountStatus = Closed;
	getchar();
}
void displayData(node * Data)
{
	system("cls");
	printf("/***************************************************************************************/\n");
	printf("/***************************  IMT Bank System -- Admin Mode ****************************/\n");
	printf("Full Name: %s\n",Data->data.fullName);
	printf("Full Address: %s\n",Data->data.fullAddress);
	printf("Age: %d\n",Data->data.age);
	printf("National ID: %llu\n",Data->data.nationalID);
	printf("Account ID: %lu\n",Data->data.accountID);
	printf("Account Balance: %lu\n",Data->data.balance);
	switch(Data->data.accountStatus)
	{
		case 1:
		printf("Account Status: Active\n");
		break;
		case 2:
		printf("Account Status: Restricted\n");
		break;
		case 3:
		printf("Account Status: Closed\n");
		break;		
	}
	getchar();
	getchar();
}

void createNewAccount(void)
{
		/* First Node to Create */
	if (ListLength == 0)/*first node */
	{
		addData(&head);
		head.Next  = NULL;
		ListLength++;
		displayData(&head);		
	}
	else
	{
		node *NewAccount = (node*)malloc(sizeof(node));
		NewAccount->Next = NULL;
		node *TempNode;
		
		addData(NewAccount);
		TempNode = &head;
		while(TempNode->Next !=NULL)
		{
			TempNode = TempNode->Next; 
		}
		TempNode->Next = NewAccount;
		
		TempNode->Next->Next = NULL;
		
		ListLength++;
	displayData(NewAccount);
	}
	
}

void openExistingAccount(node ** TempNode)
{
		u8 flag=0;
		u32 accountID;
		*TempNode= &head;
		scanf("%lu",&accountID);
		while(flag == 0 && *TempNode != NULL)
			{
				if((*TempNode)->data.accountID == accountID)
				{
					flag=1;	
				}
				else
				{
					*TempNode = (*TempNode)->Next;	
				}
			}	
		 if(flag==0) 
			{
				printf("There is no such Account\n");
				getchar();
				getchar();
			}
}
void makeTransaction(node * Data)
{
	if(ListLength>1)
	{
		u32 accountID;
		u32 transactionAmount=0;
		node *TempNode;
		printf("Enter The Reciever ID: ");
		openExistingAccount(&TempNode);
		if(TempNode !=NULL)
			{
				printf("Balance = %ul \nPlease, Enter the Transaction Amount: ",Data->data.balance);
				scanf("%ul",&transactionAmount);
				while(transactionAmount < transactionAmount)
					{
					printf("NOT POSSIBLE \nPlease Enter Amount less than  %ul\n:",Data->data.balance);
					scanf("%ul",&transactionAmount);
					}
					TempNode->data.balance -= transactionAmount;
					Data->data.balance+=transactionAmount;
					displayData(Data);
					displayData(TempNode);
					getchar();
					getchar();
			}
		else
			{
				printf("There is no such Account\n");
				getchar();
				getchar();
			}		
	}
	else
	{
		printf("There is no enough Account yet\n");
		getchar();
		getchar();
	}
}
void changeAccountStatus(node * Data)
{
	u8 x=0;
	while(x != '1' &&x != '2' &&x != '3')
	{
	printf("Set the Account Status to :\n\t1 Active\n\t2 Restricted\n\t3 Closed\n\t:");
	scanf(" %c",&x);
	}
	Data->data.accountStatus=x-'0';
	displayData(Data);
}
void getCash(node * Data)
{
	u32 Amount=0;
	printf("Balance = %ul \nPlease, Enter the Cash Amount: ",Data->data.balance);
	scanf("%ul",&Amount);
	while(Amount > Data->data.balance)
		{
			printf("NOT POSSIBLE \nPlease Enter Amount less than  %ul\n:",Data->data.balance);
			scanf("%ul",&Amount);
		}
	Data->data.balance-=Amount;
	displayData(Data);
	getchar();
	getchar();
}
void makeDeposit(node * Data)
{
	u32 Amount=0;
	printf("Balance = %ul \nPlease, Enter the Deposit Amount: ",Data->data.balance);
	scanf("%ul",&Amount);
	Data->data.balance+=Amount;
	displayData(Data);
	getchar();
	getchar();
}
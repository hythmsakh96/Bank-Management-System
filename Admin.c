/***************************************************************************************/
/********************************  Hythm Saad Khalifa **********************************/
/***************************************************************************************/
/****** This file is developed by Hythm Saad Khalifa, All copyrights are reserved ******/
/***************************************************************************************/
#include "STD_TYPES.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>		//Essential for making random numbers
#include "Private.h"
#include "Admin.h"

#define 	ADMIN_MODE_USERNAME		"admin" // Username for Admin Mode
#define 	ADMIN_MODE_PASSWORD		"admin"	// Password for Admin Mode

#define		EXIST			1
#define		NOT_EXIST		0

#define		ALLOWED			1
#define		NOT_ALLOWED		0

#define 	ACTIVE_STATUS		'1'
#define 	RESTRICTED_STATUS	'2'
#define 	CLOSED_STATUS		'3'


node head;			//Head of the Linked List

u32 ListLength=0;	// Number of Account Created

u8 const alpha[] = "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ$%&*";	
// Array of characters could be used in the password 


u8 adminMode(void)	
{
	u8 userName[20]/*To Store The Username from the User*/,password[20]/*To Store The Username from the User*/;
	system("cls");	//Clear The Entire Screen
	printf("/***************************************************************************************/\n");
	printf("/***************************  IMT Bank System -- Admin Mode ****************************/\n");
	printf("Please Enter your Username:");
	scanf("%s",&userName);
	printf("\nPlease Enter your Password:");
	scanf("%s",&password);
	if(strcmp(ADMIN_MODE_USERNAME,userName) && strcmp(ADMIN_MODE_PASSWORD,password))
		return ALLOWED;
	else
	{
		return NOT_ALLOWED;
}
}

void addData(node * Data)
{
	u8 index=0;
	system("cls");
	printf("/***************************************************************************************/\n");
	printf("/***************************  IMT Bank System -- Admin Mode ****************************/\n");
	printf("Enter the Full Name\n:");
	scanf(" %[^\n]%*c",&Data->data.fullName);			//
	printf("Enter the Full Address\n:");				//
	scanf(" %[^\n]%*c",&Data->data.fullAddress);		//Get The Data from The User
	printf("Enter the Age\n:");							//
	scanf("%d",&Data->data.age);						//
	if(Data->data.age<21)				
	{
		printf("Enter the Guardian ID Number\n:");
		scanf("%d",&Data->data.guardianID);
	}
	printf("Enter the National ID Number\n:");
	scanf("%llu",&Data->data.nationalID);
	Data->data.accountID = ((100000*(rand()%1000000000)) | (rand()%1000000000));	//Creates A random ID
	printf("The Account ID: %lu\n",Data->data.accountID);
	srand(time(0));				//Set The Seed for Random Password Creator
	printf("Your Password:");
	for(index=0;index<20;index++)	//Creating Password Array and Display It
	{
		Data->data.accountPassword[index]=alpha[rand()%strlen(alpha)];
		printf("%c",Data->data.accountPassword[index]);
	}
	printf("\nEnter the Balance:");
	scanf("%d",&Data->data.balance);	
	Data->data.accountStatus = Closed;
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
		case ACTIVE_STATUS:
		printf("Account Status: Active\n");
		break;
		case CLOSED_STATUS:
		printf("Account Status: Restricted\n");
		break;
		case RESTRICTED_STATUS:
		printf("Account Status: Closed\n");
		break;		
	}
	printf("Press any key........");
	getchar();		// Pause the System to Display
	getchar();
}

void createNewAccount(void)
{
		// First Node to Create 
	if (ListLength == 0)//first node 
	{
		addData(&head);				// Get The Account Data from the user and Store it in the Head of The Linked List
		head.Next  = NULL;			
		ListLength++;				// Increase the number of Accounts Created
		displayData(&head);			// Display The Created Account's Data 
	}
	else	/*	non-firset node*/
	{
		node *NewAccount = (node*)malloc(sizeof(node));		//Assign Memory in The Heap for the New Account
		NewAccount->Next = NULL;						
		node *TempNode;			//A Temporary Node to search for the last element of the  Linked List
		
		addData(NewAccount);	// Get The Account Data from the user and Store it in the New Account
		TempNode = &head;		// Give the Head address to the Temporary Node to start Searching for the last element
		while(TempNode->Next !=NULL)	//Stay in The LOOP Till the temorary node points to the last element
		{
			TempNode = TempNode->Next; //Move to The Next Element
		}								// Now the Temporary Node point to the last element
		TempNode->Next = NewAccount;	// Add the The New Account to the Linked List to be the Last element of the list
		
		TempNode->Next->Next = NULL;
		
		ListLength++;				//Increase The Number of Accounts
		displayData(NewAccount);	//Display The New Account After Creation 
	}
	
}

void openExistingAccount(node ** TempNode)
{
	u8 Existinceflag=NOT_EXIST;	//	The Existence of input ID in The Linked List 
	u32 accountID;			// The Input ID
	*TempNode= &head;		// Assign The Temporary node to The Head of The Linked List to Search for The ID
	scanf("%lu",&accountID);	//Scan The Required ID from The User
	while(Existinceflag == NOT_EXIST && *TempNode != NULL)	//Stay in The Loop As long As The ID is not found yet or ypu have reached the last element
		{
			if((*TempNode)->data.accountID == accountID)	//If you Found The ID in The List
			{
				Existinceflag=EXIST;	//Raise The Flag of Existence	
			}
			else	//If You Haven't Found The ID
			{
				*TempNode = (*TempNode)->Next;	// Move to The Next Node	
			}
		}	
	if(Existinceflag==NOT_EXIST)	//The Flag of Existence Stayed down so this ID doesn't Exist in The List 
		{
			printf("There is no such Account\n");
			getchar();
			getchar();
		}
		//Else Now The Temporary Node points to The Account Containing The ID
}
void makeTransaction(node * Data)
{
	if(ListLength>1)	//Check if There Are Enough Accounts To make The Transaction
	{
		u32 accountID;
		u32 transactionAmount=0;
		node *TempNode;
		printf("Enter The Reciever ID: ");
		openExistingAccount(&TempNode);		//Search for THe ID	of The Reciever
		if(TempNode !=NULL)				//Only Enter if the ID Exist
			{
				printf("Balance = %ul \nPlease, Enter the Transaction Amount: ",Data->data.balance);
				scanf("%ul",&transactionAmount);
				while(transactionAmount < transactionAmount) // Make sure The AccountHave Enough Money 
					{
					printf("NOT POSSIBLE \nPlease Enter Amount less than  %ul\n:",Data->data.balance);
					scanf("%ul",&transactionAmount);
					}
				TempNode->data.balance -= transactionAmount;
				Data->data.balance+=transactionAmount;
				displayData(Data);
				displayData(TempNode);
			}
		else
			{
				printf("There is no such Account\n");
				printf("Press any key........");
				getchar();
				getchar();
			}		
	}
	else	//Not Enough Accounts
	{
		printf("There is no enough Account yet\n");
		printf("Press any key........");
		getchar();
		getchar();
	}
}
void changeAccountStatus(node * Data)
{
	u8 Selector=0;
	while(Selector != ACTIVE_STATUS &&	Selector != CLOSED_STATUS && Selector != RESTRICTED_STATUS) //Validate The Input from The user
	{
	printf("Set the Account Status to :\n\t1 Active\n\t2 Restricted\n\t3 Closed\n\t:");
	scanf(" %c",&Selector);
	}
	Data->data.accountStatus=Selector;
	displayData(Data);
}
void getCash(node * Data)
{
	u32 Amount=0;
	printf("Balance = %ul \nPlease, Enter the Cash Amount: ",Data->data.balance);
	scanf("%ul",&Amount);
	while(Amount > Data->data.balance)//Make Sure of the possibility of the operation
		{
			printf("NOT POSSIBLE \nPlease Enter Amount less than  %ul\n:",Data->data.balance);
			scanf("%ul",&Amount);
		}
	Data->data.balance-=Amount;	//Subtract the money from the account
	displayData(Data);
}
void makeDeposit(node * Data)
{
	u32 Amount=0;
	printf("Balance = %ul \nPlease, Enter the Deposit Amount: ",Data->data.balance);
	scanf("%ul",&Amount);
	Data->data.balance+=Amount;
	displayData(Data);
}
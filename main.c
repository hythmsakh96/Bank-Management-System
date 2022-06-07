/***************************************************************************************/
/********************************  Hythm Saad Khalifa **********************************/
/***************************************************************************************/
/****** This file is developed by Hythm Saad Khalifa, All copyrights are reserved ******/
/***************************************************************************************/
#include "STD_TYPES.h"
#include "Private.h"
#include "Admin.h"
#include "Client.h"
#include <stdio.h>
#include <stdlib.h>

extern node  head;
extern u8 ListLength;

void main(void)
{
	u8 x = 0;
	node * TempNode = NULL;					
	while(1)
	{
		x=0;
		while (x != '1' && x != '2')
		{
			system("cls");
			printf("/***************************************************************************************/\n");
			printf("/****************************  Welcome to IMT Bank System ******************************/\n");
			printf("Press \n\t1 Admin Mode \t\t\t\t\t2 Client Mode \n\n\t\t:");
			scanf("%c",&x);
		}
		switch (x)
		{
			case '1' :   //admin mode
			x = '0';
				if(adminMode()==1)
				{
					printf("WRONG DATA\n");
					printf("Press any key");
					getchar();
					getchar();			
				}
				else 
				{	
					printf("\t\t\t\t\tCORRECT DATA\n");
					printf("Press any key");
					getchar();
					getchar();
					while(1)
					{		
						x = 0;
						while (x != '1' && x != '2'&& x != '3')
						{
							system("cls");
							system("cls");
							printf("/***************************************************************************************/\n");
							printf("/***************************  IMT Bank System -- Admin Mode ****************************/\n");
							printf("Press \n\t1 Create a new Account \t\t\t\t2 Open an Existing Account  \n\t3 Exit The System\t\t\t\t4 Display All Existing Account\n\t\t:");
							scanf("%c",&x);
						}
							if(x=='3')
							{
								x = '0';
								break;
							}
							switch(x)
							{
								case '1':
								createNewAccount();
								break;
								case '2':
								if(ListLength==0)
								{
									printf("There is no Accounts yet\n");
									getchar();
									getchar();
								}
								else{
								printf("Enter The Account ID: ");
								openExistingAccount(&TempNode);
								if(TempNode != NULL)
								{
									while(1)
									{
										x = 0;
										while (x != '1' && x != '2'&& x != '3'&& x != '4'&& x != '5')
										{
										system("cls");
										system("cls");
										printf("/***************************************************************************************/\n");
										printf("/***************************  IMT Bank System -- Admin Mode ****************************/\n");
										printf("Press \n\t1 Make a Transaction \t\t\t\t\t2 Change Account Status   \n\t3 Get Cash\t\t\t\t\t\t4 Make a Deposit\n\t5 Return to Main Menu\n\t:");
										scanf("%c",&x);
										}
										if(x=='5')
										{
											x = '0';
											break;
										}
										switch(x)
										{
											case '1'://makeTransaction
											makeTransaction(TempNode);
											break;
											case '2'://change account status
											changeAccountStatus(TempNode);
											break;									
											case '3'://get cash
											getCash(TempNode);
											break;
											case '4'://deposit  in account
											makeDeposit(TempNode);
											break;
										}
									
									}
								}
								break;
								case '4':
								TempNode = &head;
								while(TempNode !=NULL)
								{
									printf("%lu\n",TempNode->data.accountID);
									TempNode = TempNode->Next;	
								}
								printf("%d\n",ListLength);
								getchar();
								getchar();				
								break;
								}
							}
				}
				}
			break;
			case '2' :  //client mode
			TempNode = NULL;
				if(clientMode(&TempNode)==0)
				{
					printf("WRONG DATA\n");
					printf("Press any key");
					getchar();
					getchar();			
				}
				else 
				{	
					printf("\t\t\t\t\tCORRECT DATA\n");
					printf("Press any key");
					getchar();
					getchar();
					while(1)
					{		
						x = 0;
						while (x != '1' && x != '2'&& x != '3'&& x != '4'&& x != '5')
						{
							system("cls");
							system("cls");
							printf("/***************************************************************************************/\n");
							printf("/***************************  IMT Bank System -- Client Mode ****************************/\n");
							printf("Press \n\t1 Make a Transaction \t\t\t2 Change Account Password  \n\t3 Get Cash\t\t\t\t4 Deposit in Account\n\t5 Return to Main Menu\n\t\t:");
							scanf("%c",&x);
						}
							if(x=='5')
							{
								x = '0';
								break;
							}
							switch(x)
							{
								case '1'://make transaction
								makeTransaction(TempNode);
								break;
								case '2':// change account password
								changeAccountPass(TempNode);
								break;
								case '3':// get cash
								getCash(TempNode);
								break;
								case '4'://make a deposit
								makeDeposit(TempNode);
								break;
							}
						
					}
				}
			break;
		}
}
}

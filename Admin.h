/***************************************************************************************/
/********************************  Hythm Saad Khalifa **********************************/
/***************************************************************************************/
/****** This file is developed by Hythm Saad Khalifa, All copyrights are reserved ******/
/***************************************************************************************/

#ifndef _ADMIN_H
#define _ADMIN_H

u8	 adminMode(void);					// This Function Checks for Admin Username & Password
void createNewAccount(void);			// This Function Creates a New Account then adds it to the Linked List


void openExistingAccount(node **);		// THis Function Scans Account ID and search for it in the Linked List
void addData(node * Data);				// THis Function Scans The Account Data from the user and stores it in the Account


void displayData(node * Data);			// THis Function Displays The Data of the Account
void makeTransaction(node * Data);		// THis Function makes Transaction Between Two Accounts 


void changeAccountStatus(node * Data);	// THis Function Changes the status of the Account
void getCash(node * Data);				// THis Function Withdraw Cash from The Account


void makeDeposit(node * Data);			// THis Function Deposits Cash to the Account

#endif
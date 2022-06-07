/***************************************************************************************/
/********************************  Hythm Saad Khalifa **********************************/
/***************************************************************************************/
/****** This file is developed by Hythm Saad Khalifa, All copyrights are reserved ******/
/***************************************************************************************/

#ifndef _ADMIN_H
#define _ADMIN_H

u8	 adminMode(void);
void createNewAccount(void);
void openExistingAccount(node **);
void addData(node * Data);
void displayData(node * Data);
void makeTransaction(node * Data);
void changeAccountStatus(node * Data);
void getCash(node * Data);
void makeDeposit(node * Data);


#endif
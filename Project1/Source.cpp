// Book Store 

#include "clsAdminAccount.h"
#include "clsLogin.h"

#include "clsPurchasedBooks.h"
#include "clsAdminScreen.h"
#include "clsAuthorScreen.h"
#include "clsUserScreen.h"
#include <iostream>
using namespace std; 

//#include <windows.h>
//// Clearing one line
//void EnableANSI() {
//	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
//	DWORD dwMode = 0;
//	GetConsoleMode(hOut, &dwMode);
//	dwMode |= ENABLE_VIRTUAL_TERMINAL_PROCESSING;
//	SetConsoleMode(hOut, dwMode);
//}

int main()
{
	clsLogin Login; 
	Login.Start();

	return 0;
}
// Book Store 

#include "clsAdminAccount.h"
#include "clsLogin.h"

#include "clsPurchasedBooks.h"
#include "clsAdminScreen.h"
#include "clsAuthorScreen.h"
#include "clsUserScreen.h"
#include <iostream>
using namespace std; 

int main()
{
	clsLogin Login; 
	Login.Start();

	return 0;
}
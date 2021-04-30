

#include<iostream>
#include "blackjack.h"

int main()
{
	int option;

	do
	{
		std::cout<<"\nMain Menu\n\n1. Blackjack\n1\n2. Exit\n\n";
		std::cout<<"Select an option: ";
		std::cin>>option;
		if(option == 1)
		{
			blackjack myBlackJack;
			myBlackJack.run();
		}
		else if(option == 2)
		{
			std::cout<<"exiting...\n";
		}
		else
		{
			std::cout<<"Invaid option\n";
		}
	}while(option != 2);

return(0);
}

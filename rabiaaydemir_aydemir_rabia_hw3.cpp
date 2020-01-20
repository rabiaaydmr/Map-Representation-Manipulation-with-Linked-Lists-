#include <iostream>
#include <fstream>
#include <sstream>
#include "Header.h"

using namespace std;
void Asking()
{
	cout<< "Please select an option [1-2-3]."<<endl;
		cout<<"1. Annexation! War for the iron throne continues..."<<endl;
		cout<<"2. Tyrion must travel, do a path check for the famous imp."<<endl;
		cout<<"3. Exit "<<endl;
	
}


int main()	
{ 
	ifstream inputtxt;                                          //we get filename from the user until the user write the correct txt name.
	string txtname;
	cout << "Please enter a file name." <<endl;
	do
	{
		cin >> txtname;
		inputtxt.open(txtname);
		
	}while (!inputtxt.is_open());                       
	
	cout << "Successfully opened file" << txtname<< endl;
	cout << endl;
	cout << "######## TOPOLOGY ########" <<endl <<endl;
	
	
	string house;              
	string neighboringhouse;
	string line;
	linkedlist list;
	while (getline(inputtxt,line))                         // we read the txt line by line
	{
		
		istringstream ss(line);
		ss>> house >>neighboringhouse;
		if(!list.nnExists(house,neighboringhouse))             //if our inputs are not neighbor we add the pairs
		{
			cout <<"Processing" <<" "<< house <<", " << neighboringhouse <<endl;
			cout<<"Topology information successfully added."<< endl <<endl;
		}
		else if(list.nnExists(house,neighboringhouse))         
		{
			cout<< "Processing" <<" "<< house <<", " << neighboringhouse <<endl;
			cout<< "Redundant information! An entry with " << house <<" and " << neighboringhouse << " is already processed."<<endl<<endl;
			
		}

		list.addHouseNode(house);                        
		list.addNeighborNode(house,neighboringhouse);
		list.addHouseNode(neighboringhouse);
		list.addNeighborNode(neighboringhouse,house);
		
	}
	cout <<"######## MAP ########" << endl;
	list.printAll();

	

	int option = 0;
	string conquer;
	string conquered;
	
	while(option!=3)                      //while input is not equal to 3 the game dont finish. and we continue to ask the options
	{
	
		cout<< "Please select an option [1-2-3]."<<endl;
		cout<<"1. Annexation! War for the iron throne continues..."<<endl;
		cout<<"2. Tyrion must travel, do a path check for the famous imp."<<endl;
		cout<<"3. Exit "<<endl;
		cin >> option;
		
		if(option==1)                     //if the user choose the option 1 
		{
			
			cout<<"Please enter two houses first the annexer and the annexed. (ex: Tyrell Stark). "<<endl;
			cin>>conquer>>conquered;                 //we get two input one is conquer and the other one is conquered.
			if(!list.hnExists(conquer))                //if the user give the invalid input for conquer , we give error message.
			{
			cout<<conquer<<"does not exist! "<<endl;
			cout<<"Update failed."<<endl<<endl;
			Asking();
			cin>>option;
			}
			else if(!list.hnExists(conquered))         //if the user give the invalid input for conquered , we give error message.
			{
			cout<<conquered<<" " <<"does not exist! "<<endl;
			cout<<"Update failed."<<endl<< endl;
			Asking();
			cin>>option;
			}
			else if(list.hnExists(conquer))          // if the user inputs are correct 
			{
				if(conquer==conquered)                 // and the conquer and the conquered name is same we give an error message
					{
						cout<<"A House cannot conquer itself!"<<endl; 
						cout<<"Update failed."<<endl<<endl; 
					}
				if(list.nnExists(conquer,conquered))    //if we get correct input from the user and the inputs are neighbors
				{
				list.transferItem(conquer, conquered);       //we transfer the conquered neighbors to conquer neighbor and 
				list.deleteByName(conquered);                 //delete the conquered house
				cout<< conquer<<" " <<"conquered" <<" "<<conquered << endl;
				cout <<"######## MAP ########" << endl;
				list.printAll();
				cout<< endl;
				}
				else if(!list.nnExists(conquer, conquered))              //if the user inputs are correct but the houses are not neigbors we gave an error message
				{
					cout<<"A house can only conquer a neighboring house!"<<conquered<<" is not a neighbor of "<<conquer<<endl;
					cout<<"Update failed."<<endl<<endl;
				}

			}
		}

		else if(option==2)         // if the user choose the option 2.
		{
			cin.clear();
			string line1;
			cout<<"Please enter a path. (ex: Tyrell Martell Tully) "<<endl;  
			getline(cin, line1);            
			getline(cin, line1);
			istringstream ss1(line1);
			istringstream ss2(line1);
			string road, road2;
			ss2>>road2;
			bool check=true;
			while (check&&(ss1>>road)&& (ss2>>road2))     
			{	
				if(!list.hnExists(road))     //if the paths not exist we gave an error message
				{
					cout<<road<<" does not exist in the map. "<<endl;
					check=false;
				}	
				if(check&&(road==road2))                    
					cout<< "You are already in " << road<<endl;
				else if(check && !list.nnExists(road,road2))
				{
					cout<<road2<< " is not a neighbor of "<<road<<endl;
					check=false;
				}
			    else if(check && list.nnExists(road,road2))
				    cout<<"Path found between "<<road <<" and "<<road2<<endl;
				
			}
			if (check)
				cout<<"Path search succeeded. "<< endl<<endl;
			else
				cout<<"Path search failed! "<<endl<<endl;
		}
		else if(option!=3)       
		{
			cout<<"Invalid option please select from the menu. "<<endl <<endl;
			Asking();
		    cin>>option;
		
		}
	}

	if (option == 3)
	{
		list.deleteAll();
		cout<<"List deleted and program ended. "<<endl;
		
	}

	return 0;
}
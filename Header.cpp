#include <iostream>
#include <fstream>
#include <string>
#include "Header.h"

using namespace std;

linkedlist::linkedlist ()
{  head = NULL;
}

/* Begin: code taken from linkedList.cpp and updated */ 
	void linkedlist ::printAll()
{
	houseNode*ptr=head;
		while(ptr!=NULL)
		{
			neighborNode*p;
			p=ptr->neighborListHead;
			cout<<ptr->houseName<< ": ";
		
			while(p!=NULL)
				{
					cout<< p->neighborName<<", ";
					p=p->next;
				}
			cout<< endl;
			ptr=ptr->next;
			
		}


}
	/* End: code taken from linkedList.cpp and updated*/

bool linkedlist::hnExists(string hname)            //we check that housename is exist
{   
	houseNode* ptr= head;
	if(ptr == NULL)
		return false;

	while (ptr!=NULL)
	{
		if(ptr->houseName == hname)
			return true;
		ptr=ptr->next;
	}

	return false;

}  

bool linkedlist::nnExists(string hname, string nname)          // we check that that neighborname is exist
{
	houseNode* SearchHouse=head;

	while(SearchHouse!=NULL)
	{
		if(SearchHouse->houseName==hname)
		{
			neighborNode * searchneighbors=SearchHouse->neighborListHead;
			if(searchneighbors==NULL)
				return false;
			
			while(searchneighbors!=NULL)
			{
				if(searchneighbors->neighborName==nname)
					return true;
				searchneighbors=searchneighbors->next;
			}
		}
		SearchHouse=SearchHouse->next;
	}

		return false;	

}

void linkedlist::deleteAll()             // to delete list
{
	houseNode*ptr=head;
	while(head!=NULL)
	{
		ptr=head;
		head=head->next;
		delete ptr;
	}
}

bool linkedlist::addNeighborNode (string hname, string nname)           // we create the houses neighbors
{
	if(nnExists(hname,nname))
	{
		return true;
	}

	houseNode*ptr=head;
	while(ptr!=NULL )
	{
		if(ptr->houseName == hname)
		{
			neighborNode *temp = new neighborNode(nname,NULL);
			neighborNode*ptr1=ptr->neighborListHead;
			if(ptr1==NULL)
			{
				ptr->neighborListHead=temp;
			}
			else
			{
				while(ptr1->next!=NULL)
				{
					ptr1 =ptr1->next;
				}
			ptr1->next= temp;
			}
		}

		ptr=ptr->next;
		
	}
	return false;
}
/* Begin: code taken from linkedList.cpp and updated */ 
bool linkedlist::addHouseNode (string hname)              //when we read the txt we create the houses
{	
	if(hnExists(hname))
	{
		return true;
	}

	houseNode *ptr = head;
	houseNode *temp = new houseNode(hname, NULL,NULL);
	//List is empty
	
	if(head == NULL)
	{
		head = temp;
	}
	else
	{
		
		while(ptr->next != NULL)
		{
			ptr = ptr->next;
		}
		ptr->next = temp;
	
	}
	return false;
}	
/* End: code taken from linkedList.cpp and updated*/

/* Begin: code taken from linkedList.cpp */ 
void linkedlist::deleteByName(string hname) 
{
	//do nothing if list is empty
	if (head != NULL) {
		houseNode *ptr = head;
		//update head if the head contains the data requested for deletion
		if (head->houseName == hname) {
			head = head->next;
			delete ptr;
		}
		else {
			//search for the node with the correct data
			//ptr != NULL is necessary for the special case where the last element is deleted and ptr is updated
			//to NULL and the program crashes when ptr->next is executed in the while boolean expression.
			while (ptr != NULL && ptr->next != NULL) {
				if (ptr->next->houseName == hname) {
					houseNode * temp = ptr->next;
					ptr->next = ptr->next->next;
					delete temp;
				}
				ptr = ptr->next;
			}
		}
	}
}
/* End: code taken from linkedList.cpp */


void linkedlist::transferItem(string conquer, string conquered)
{
	houseNode*ptr=head;
	while(ptr!=NULL && ptr->houseName!=conquered)          //we transfer the conquered neighbors to conquerer neighbors
	{
		ptr=ptr->next;
	}
	houseNode *ptr1=head;
	
	while(ptr1!=NULL && ptr1->houseName!=conquer)
	{
		ptr1=ptr1->next;
	}
	neighborNode *q=ptr->neighborListHead;
	while(q!=NULL)
	{
		if(!nnExists(ptr1->houseName,q->neighborName) && ptr1->houseName!=q->neighborName)
		{
			addNeighborNode(ptr1->houseName,q->neighborName);
		}
		q = q->next;
	}
}

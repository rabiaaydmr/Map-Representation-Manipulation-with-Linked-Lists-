#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

struct neighborNode {                     //creat the neighbor node
	
	string neighborName;    
	neighborNode * next; 
	
	// constructors 
	neighborNode::neighborNode ()
	{
		neighborName="";
		next=nullptr;
	}

	neighborNode::neighborNode (string Nname, neighborNode * Nlink)
		: neighborName(Nname), next (Nlink)
	{}
 
}; 
 
struct houseNode {         //creat the house node
	 string houseName;   
	 neighborNode * neighborListHead;  
	 houseNode * next; 
	
	 // constructors 
	 houseNode::houseNode ()
		 :houseName(""),neighborListHead(NULL),next(NULL)
	 {}
	 
	 houseNode::houseNode (string Hname, neighborNode *NlistHead,houseNode *Hlink)
		 : houseName(Hname), neighborListHead(NlistHead), next (Hlink)
	 {}
 }; 
class linkedlist       // list is a class which has the below member functions
{ 
public:  
	linkedlist(); 
bool addHouseNode(string hname);  
bool addNeighborNode (string hname, string nname); 
void printAll();    
bool hnExists(string hname);  
bool nnExists(string hname, string nname);  
void deleteAll();  //to deallocate all dynamic data  //other member functions… 
void transferItem(string hname, string nname);
void linkedlist::deleteByName(string hname) ;

private:  
	houseNode * head;  
		  // any helper functions you see necessary  // ... 
}; 

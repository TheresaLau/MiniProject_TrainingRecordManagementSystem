#include "Plan.h"
#include <iostream>
#include <string>
#include <iomanip>
#include <ios> //used to get stream size
#include <limits> //used to get numeric limits
#include <fstream>
using namespace std;

Plan::Plan()
{
	front=rear=NULL;
}

void Plan::readPlan()
{
	ifstream read;
    read.open("Plan.txt");
    if(read.fail())
		cout<<"Sorry, input file does not exist!\n";
    
    while(!read.eof())
    {
    	NodePlan *reading= new NodePlan;
    	read>>reading->planID;
    	read.ignore(numeric_limits<streamsize>::max(), '\t');
        getline(read, reading->planName, '\t');
        read>>reading->planPrice;
        read.ignore(numeric_limits<streamsize>::max(), '\n');
        reading->next=NULL;
        if(front==NULL)
        	front=rear=reading;
        else
        {
        	rear->next=reading;
        	rear=reading;
		}
    }
    read.close();
}

void Plan::writePlan()
{
	ofstream write("Plan.txt");
	NodePlan *temp=front;
	while(temp)
	{
		write<<temp->planID<<"\t"<<temp->planName<<"\t"<<temp->planPrice;
        if(temp!=rear)
			write<<"\n";
		temp=temp->next;
	}
	write.close();
}

void Plan::insertPlan()
{
	NodePlan* temp=new NodePlan;
	
    cout<<endl;
	cout<<"Enter the Plan ID:    ";
	cin>>temp->planID;
	cout<<"Enter the Plan Name:  ";
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	getline(cin, temp->planName);
	cout<<"Enter the Plan Price: RM ";
	cin>>temp->planPrice;
	
	string pid=temp->planID;
	temp->next=NULL;
	if(front==NULL){
        front=rear=temp;
    }
    else{
        rear->next=temp;
        rear=temp;
    }
    cout<<endl<<pid<<" has been inserted successfully."<<endl<<endl;
}

void Plan::deletePlan()
{
	if (front==NULL){
        cout<<"Plan Underflow"<<endl;
        return;
    }
     
    cout<<endl<<front->planID<<" is being deleted "<<endl<<endl;
    if(front==rear)//if only one node is there
        front=rear=NULL;
    else
        front=front->next;
}

void Plan::displayPlan()
{
	cout<<endl;
	if(front==NULL){
        cout<<"Plan Underflow"<<endl;
        return;
    }
    NodePlan *temp=front;
    int i=1;
    //will check until NULL is not found
    while(temp)
	{
    	cout<<"["<<i<<"]"<<endl;
        cout<<"Plan ID:    "<<temp->planID<<endl;
        cout<<"Plan Name:  "<<temp->planName<<endl;
        cout<<"Plan Price: RM "<<temp->planPrice<<endl;
        temp=temp->next;
        i++;
        cout<<endl;
    }
}

//Update the price for a plan
void Plan::updatePrice()
{
	string pid;
	double updated;
	bool status=false;
	cout<<"\n********************Plan********************"<<endl;
	cout<<"Enter the plan ID that you would like to update: ";
	cin>>pid;
	NodePlan *temp=front;
	while(temp)
	{
		if(pid==temp->planID)
		{
			cout<<"\nThe plan ID ("<<pid<<")'s price is ";
			cout<<"========== RM "<<temp->planPrice<<endl;
			status=true;
			break;
		}
		temp=temp->next;
	}
	if(status==false)
	{
		cout<<"Sorry, No Record."<<endl;
	}
	else
	{
		cout<<"Updated Plan Price: RM ";
		cin>>updated;
		temp->planPrice=updated;
	}
}

//Search the plan information
void Plan::searchPlan()
{
	string pid;
	double updated;
	bool status=false;
	cout<<"\n********************Plan********************"<<endl;
	cout<<"Enter the plan ID that you would like to search: ";
	cin>>pid;
	NodePlan *temp=front;
	while(temp)
	{
		if(pid==temp->planID)
		{
			cout<<endl;
			cout<<"Plan ID:    "<<pid<<endl;
			cout<<"Plan Name:  "<<temp->planName<<endl;
			cout<<"Plan Price: RM "<<temp->planPrice<<endl;
			status=true;
			break;
		}
		temp=temp->next;
	}
	if(status==false)
	{
		cout<<"\nSorry, No Record."<<endl;
	}
}
#include "Payment.h"
#include <iostream>
#include <string>
#include <ios> //used to get stream size
#include <limits> //used to get numeric limits
#include <fstream>

using namespace std;

Payment::Payment()
{
	front=rear=NULL;
}

//read the payment status for each trainee in data file
void Payment::readPayment()
{
	ifstream read;
    read.open("PaymentStatus.txt");
    if(read.fail())
		cout<<"Sorry, input file does not exist!\n";
    
    while(!read.eof())
    {
    	NodePayment *reading= new NodePayment;
    	read>>reading->traineeID;
        read>>reading->paymentStatus;
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

//Save the changes about payment status for each trainee in data file
void Payment::writePayment()
{
	ofstream write("PaymentStatus.txt");
	NodePayment *temp=front;
	while(temp)
	{
		write<<temp->traineeID <<"\t"<<temp->paymentStatus;
        if(temp!=rear)
			write<<"\n";
		temp=temp->next;
	}
	write.close();
}

//Insert new payment status
void Payment::insertPayment()
{
	NodePayment* temp=new NodePayment;
	
    cout<<endl;
	cout<<"Enter the Trainee ID:            ";
	cin>>temp->traineeID;
	cout<<"Enter the Payment Status (Y/N):  ";
	cin>>temp->paymentStatus;
	
	string tid=temp->traineeID;
	temp->next=NULL;
	if(front==NULL){
        front=rear=temp;
    }
    else{
        rear->next=temp;
        rear=temp;
    }
    cout<<endl<<tid<<" has been inserted successfully."<<endl<<endl;
}

//Delete the first payment status
void Payment::deletePayment()
{
	if (front==NULL){
        cout<<"Payment Status Underflow"<<endl;
        return;
    }
     
    cout<<endl<<front->traineeID<<" is being deleted."<<endl<<endl;
    if(front==rear)//if only one node is there
        front=rear=NULL;
    else
        front=front->next;
}

//Display all the payment status
void Payment::displayPayment()
{
	cout<<endl;
	if(front==NULL){
        cout<<"Payment Status Underflow"<<endl;
        return;
    }
    NodePayment *temp=front;
    int i=1;
    //will check until NULL is not found
    while(temp)
	{
    	cout<<"["<<i<<"]"<<endl;
        cout<<"Trainee ID:      "<<temp->traineeID<<endl;
        cout<<"Payment Status:  "<<temp->paymentStatus<<endl;
        temp=temp->next;
        i++;
        cout<<endl;
    }
}

//Search the payment status for a trainee
void Payment::searchPayment()
{
	string tid;
	bool status=false;
	cout<<"\n********************Payment Status********************"<<endl;
	cout<<"Enter the trainee ID that you would like to search: ";
	cin>>tid;
	NodePayment *temp=front;
	while(temp)
	{
		if(tid==temp->traineeID)
		{
			cout<<"\nThe trainee ID ("<<tid<<")'s payment status is ";
			cout<<"========== "<<temp->paymentStatus<<endl;
			status=true;
			break;
		}
		temp=temp->next;
	}
	if(status==false)
	{
		cout<<"Sorry, No Record."<<endl;
	}
}

//Update the payment status for trainee ID that already stored in data file
void Payment::updatePayment()
{
	string tid;
	char updated;
	bool status=false;
	cout<<"\n********************Payment Status********************"<<endl;
	cout<<"Enter the trainee ID that you would like to update: ";
	cin>>tid;
	NodePayment *temp=front;
	while(temp)
	{
		if(tid==temp->traineeID)
		{
			cout<<"\nThe trainee ID ("<<tid<<")'s payment status is ";
			cout<<"========== "<<temp->paymentStatus<<endl;
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
		cout<<"Updated Payment Status (Y/N): ";
		cin>>updated;
		temp->paymentStatus=updated;
	}
}
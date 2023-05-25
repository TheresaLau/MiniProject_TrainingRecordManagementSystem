#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <ios> 
#include <limits> 
using namespace std;

#include "Trainee.h"

void Trainee::createQueue(){
    backPtr = NULL;
    frontPtr = NULL;
}

bool Trainee::isEmpty(){
    return ((backPtr == NULL) && (frontPtr == NULL));
}

void Trainee::readFile(){
    ifstream infile;
    infile.open("TraineeData.txt",ios::in);
    if(!infile){
        cout<<"the input file does not exist!\n";
        return;
    }
    while(!infile.eof()){
        TraineeNode* tempNode = new TraineeNode;
 
        getline(infile, tempNode->traineeID, '\t');
        getline(infile, tempNode->trainee_name, '\t');
        
        getline(infile, tempNode->trainee_age, '\t');
        getline(infile, tempNode->trainee_contact, '\t');
        getline(infile, tempNode->planID, '\n');

        tempNode->next = NULL;
        if(frontPtr == NULL){
            frontPtr = backPtr = tempNode;
        }
        else{
            backPtr->next = tempNode;
            backPtr = tempNode;
        }
    }
    infile.close();
}

void Trainee::writeFile(TraineeNode* temp){
    ofstream writefile;
    writefile.open("TraineeData.txt", ios_base::app);
    //write single line of data to txtfile
    string new_line = "\n"+temp->traineeID +"\t"+ temp->trainee_name +"\t"+temp->trainee_age +"\t"+temp->trainee_contact+"\t"+temp->planID;
    writefile<<new_line;
    writefile.close();
}

void Trainee::insert_trainee(){
    TraineeNode* current = new TraineeNode;
    system("CLS");
    cout<<"\n====== Insert new trainee ====== \n";
    cout<<"enter trainne's ID: ";
    cin>>current->traineeID;
    cout<<"enter trainne's name: ";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
	getline(cin, current->trainee_name);
    cout<<"enter Trainee's age: ";
    cin>>current->trainee_age;
    cout<<"enter trainee's contact no: ";
    cin>>current->trainee_contact;
    cout<<"enter trainee's Plan ID: ";
    cin>>current->planID;
    
    writeFile(current); // call writefile to write to Traineedata.txt
    current->next = NULL;
    if (frontPtr == NULL){
        frontPtr = backPtr = current; }
    else{
        backPtr->next = current;
        backPtr = current;
    }
    cout<<"trainee information insert successfully.\n\n";

}

void Trainee::delete_trainee(){
    if(isEmpty()){
        cout<<"\nthere's no trainee can be delete..!!\n";
		return;
    }
    cout<<"\nTrainee with id "<<frontPtr->traineeID<<" is be deleted.\n\n";
 

    ifstream in("TraineeData.txt");
    if( !in.is_open())
    {
          cout << "Input file failed to open\n";
          return;
    }
    string delID = frontPtr->traineeID;
    ofstream out("outfile.txt");
    
    TraineeNode* replaceNode = frontPtr->next;
    while(replaceNode!= NULL){
        out<<replaceNode->traineeID<<"\t";
        out<<replaceNode->trainee_name<<"\t";
        out<<replaceNode->trainee_age<<"\t";
        out<<replaceNode->trainee_contact<<"\t";
        out<<replaceNode->planID<<endl;
        replaceNode = replaceNode->next;
    }
    in.close();
    out.close();
    remove("TraineeData.txt");
    rename("outfile.txt","TraineeData.txt");


    if(frontPtr == backPtr)
        frontPtr = backPtr = NULL;
    else
        frontPtr = frontPtr->next;
}


void Trainee::search_trainee(){
    string tid;
    bool search_status = false;
    system("CLS");
    cout<<"\n********************Trainee********************"<<endl;
	cout<<"Enter the Trianee ID that you would like to view: ";    
    cin>>tid;
    TraineeNode *search_temp = frontPtr;
    while(search_temp!=NULL){
        if(tid==search_temp->traineeID)
		{
			cout<<endl;
            cout<<">>>>>> Trainee Information <<<<<<\n";
			cout<<"Trainee ID:        "<<search_temp->traineeID<<endl;
			cout<<"Trainee Name:      "<<search_temp->trainee_name<<endl;
			cout<<"Trainee Age:       "<<search_temp->trainee_age<<endl;
            cout<<"Trainee Contact No: "<<search_temp->trainee_contact<<endl;
            cout<<"Trainee Plan ID:   "<<search_temp->planID<<endl;
			search_status=true;
			break;
		}
		search_temp = search_temp->next;

    }//end while
    if(search_status==false)
	{
		cout<<"\nSorry, cannot found this trainee."<<endl;
	}
}


void Trainee::display_traineeinfo(){
    if(frontPtr==NULL){
        cout<<"\nthere's no trainee can be display..!!\n";
		return;
    }
    system("CLS");
    TraineeNode* start = frontPtr;
    while(start!= NULL){
        cout<<">>>> Trainee's personal info:\n";
        cout<<"Trainee ID: "<<start->traineeID<<endl;
        cout<<"Trainee Name: "<<start->trainee_name<<endl;
        cout<<"Trainee Age: "<<start->trainee_age<<endl;
        cout<<"Trainee Contact No: "<<start->trainee_contact<<endl;
        cout<<"Trainee's plan ID: "<<start->planID<<endl;
        start = start->next;
        cout<<endl;
    }
    cout<<endl;
}



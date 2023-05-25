#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
using namespace std;

#include "Training.h"

void Training::createQueue(){
    backPtr = NULL;
    frontPtr = NULL;
}

bool Training::isEmpty(){
    return ((backPtr == NULL) && (frontPtr == NULL));
}

void Training::readFile(){
    fstream infile;
    infile.open("TrainingData.txt",ios::in);
    if(!infile){
        cout<<"the input file does not exist!\n";
        return;
    }
    while(!infile.eof()){
        TrainingNode* tempNode = new TrainingNode;
        getline(infile, tempNode->t_id, '\t');
        getline(infile, tempNode->t_date, '\t');
        getline(infile, tempNode->t_time, '\t');
        getline(infile, tempNode->t_duration, '\n');

        tempNode->next = NULL;
        if(isEmpty()){
            frontPtr = backPtr = tempNode;
        }
        else{
            backPtr->next = tempNode;
            backPtr = tempNode;
        }
    }
    infile.close();
}

void Training::writeFile(TrainingNode* temp){
    ofstream writefile;
    writefile.open("TrainingData.txt", ios_base::app);

    string new_line = "\n"+temp->t_id+"\t"+temp->t_date +"\t"+ temp->t_time+"\t"+ temp->t_duration;
    writefile<<new_line;
    writefile.close();
}

void Training::insert_training(){
    TrainingNode* current = new TrainingNode;
    system("CLS");
    cout<<"\n====== Insert new Training ====== \n";
    cout<<"enter trainne's ID: ";
    cin>>current->t_id;
    cout<<"enter trainne's Training date (dd/mm/yyyy): ";
    cin>>current->t_date;
    cout<<"enter trainne's specific training time (hh:mm): ";
    cin>>current->t_time;
    cout<<"enter trainne's training hour: ";
    cin>>current->t_duration;
    
    writeFile(current);//write to file.

    current->next = NULL;
    if (isEmpty()){
        frontPtr = backPtr = current; }
    else{
        backPtr->next = current;
        backPtr = current;
    }
    cout<<"Trainee's Training information insert successfully.\n\n";

}

void Training::delete_training(){
    if(isEmpty()){
        cout<<"\nthere's no Training can be delete..!!\n";
		return;
    }

    cout<<"\nTraining at "<<frontPtr->t_date<<" "<<frontPtr->t_time<<" is be deleted.\n\n";
    ifstream in("TraineeData.txt");
    if( !in.is_open())
    {
          cout << "Input file failed to open\n";
          return;
    }
    string delID = frontPtr->t_id;
    ofstream out("outfile.txt");

    TrainingNode* replaceNode = frontPtr->next;
    while(replaceNode!= NULL){
        out<<replaceNode->t_id<<"\t";
        out<<replaceNode->t_date<<"\t";
        out<<replaceNode->t_time<<"\t";
        out<<replaceNode->t_duration<<endl;
        replaceNode = replaceNode->next;
    }
    in.close();
    out.close();
    remove("TrainingData.txt");
    rename("outfile.txt","TrainingData.txt");

    if(frontPtr == backPtr)
        frontPtr = backPtr = NULL;
    else
        frontPtr = frontPtr->next;
}

void Training::search_training(){
    string tid;
    bool search_status = false;
    system("CLS");
    cout<<"\n********************Trainee********************"<<endl;
	cout<<"Enter the Trianee ID that you would like to view: ";    
    cin>>tid;
    TrainingNode *search_temp = frontPtr;
    while(search_temp!=NULL){
        if(tid==search_temp->t_id)
		{
			cout<<endl;
            cout<<">>>>>> Training Information <<<<<<\n";
			cout<<"Trainee ID:        "<<search_temp->t_id<<endl;
			cout<<"Training Data:     "<<search_temp->t_date<<endl;
			cout<<"Training Time:     "<<search_temp->t_time<<endl;
            cout<<"Training Duration: "<<search_temp->t_duration<<" hour"<<endl;
			search_status=true;
			break;
		}
		search_temp = search_temp->next;

    }//end while
    if(search_status==false)
	{
		cout<<"\nSorry, cannot found this training."<<endl;
	}
}

void Training::display_traininginfo(){
    if(isEmpty()){
        cout<<"\nthere's no Training can be display..!!\n";
		return;
    }

    TrainingNode* start = frontPtr;
    system("CLS");
    cout<<"====== all Trainne information ======"<<endl;
    while(start!= NULL){
        cout<<">>>>ID "<<start->t_id<<" Trainee's Training's info:\n";
        cout<<"Training Date and time: "<<start->t_date<<" "<<start->t_time<<endl;
        cout<<"Training duration: "<<start->t_duration<<endl;
        start = start->next;

        cout<<endl;
    }
        cout<<endl;
}

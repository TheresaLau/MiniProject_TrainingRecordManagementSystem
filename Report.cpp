#include "Report.h"
#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <ios>
#include <limits>
#include <stdlib.h>

using namespace std;

Report::Report(){
    front = back = NULL;
}

void Report::insertReport(string id){
    string planID;
    ofstream outfile;
    outfile.open("Report.txt",ios::out | ios::app);
    //read trainee file
        ifstream infile("TraineeData.txt",ios::in);

        if(infile.fail())
            cout << "Sorry,input file does not exist!\n";
        NodeReport *r = new NodeReport;
        while(!infile.eof()){
            
		        infile >> r->te_ID;
				infile.ignore(numeric_limits<streamsize>::max(), '\t');
                getline (infile, r->te_name, '\t');
                infile >> r->te_age;
                infile >> r->te_contactNo;
                infile >> r->plan_ID;
                
                if(id == r->te_ID){
                	outfile << r->te_ID << '\t' << r->te_name << '\t' << r->te_age << '\t' << r->te_contactNo << '\t' << r->plan_ID << '\t';
                	planID = r->plan_ID;
				}

            r->next = NULL;
            if (front == NULL)
                front = back = r;
            else{
                back->next = r;
                back = r;
            }
        }
        infile.close();

    //read plan file
        ifstream read("Plan.txt");

        if(read.fail())
            cout << "Sorry,input file does not exist!\n";
    
    	NodeReport *p = new NodeReport;
    	bool plan =true;
        while(!read.eof()){
            getline(read, p->plan_ID, '\t');
            getline(read, p->plan_name, '\t');
            getline(read, p->plan_price, '\n');
            if (planID == p->plan_ID){
                outfile << p->plan_name << '\t' << p->plan_price << '\t';
                plan = false;
                break;
            }
            p->next = NULL;
            if (front == NULL)
                front = back = p;
            else{
                back->next = p;
                back = p;
            }
        }
        if(plan == true){
        	p->plan_name = "NULL";
        	p->plan_price = "NULL";
        	outfile << p->plan_name << '\t' << p->plan_price << '\t';
		}
        read.close();

    //read training file
        ifstream readtr("TrainingData.txt");

        if(readtr.fail())
            cout << "Sorry,input file does not exist!\n";
    
    	NodeReport *tr = new NodeReport;
    	bool training = true;
        while(!readtr.eof()){
            getline(readtr, tr->tr_ID, '\t');
            getline(readtr, tr->tr_date, '\t');
            getline(readtr, tr->tr_time, '\t');
            getline(readtr, tr->tr_duration, '\n');
            if (id == tr->tr_ID){
                outfile << tr->tr_date << '\t';
				outfile << tr->tr_time << '\t';
				outfile << tr->tr_duration << '\t';
				training = false;
				break;
            }
            tr->next = NULL;
            if (front == NULL)
                front = back = tr;
            else{
                back->next = tr;
                back = tr;
            }
        }
        if(training == true){
        	tr->tr_date = "NULL";
        	tr->tr_time = "NULL";
        	tr->tr_duration = "NULL";
        	outfile << tr->tr_date << '\t' << tr->tr_time << '\t' << tr->tr_duration << '\t';
		}
        readtr.close();

    //read payment file
    	ifstream readp("PaymentStatus.txt");

        if(readp.fail())
            cout << "Sorry,input file does not exist!\n";
    
    	NodeReport *pay = new NodeReport;
    	bool payment = true;
        while(!readp.eof()){
            getline(readp, pay->p_ID, '\t');
            readp >> pay->payment_status;
            infile.ignore(numeric_limits<streamsize>::max(), '\n');
            if (id == pay->p_ID){
                outfile << pay->payment_status << endl;
                payment = false;
                break;
            }
            pay->next = NULL;
            if (front == NULL)
                front = back = pay;
            else{
                back->next = pay;
                back = pay;
            }
        }
        if(payment == true){
        	pay->payment_status ='N'; 
        	outfile << pay->payment_status << endl;
		}
        readp.close();

    outfile.close();

    cout << "Report for trainee with ID " << id << " is created.\n" << endl;
    system("Pause");
}

void Report::deleteReport(string id){
	string line;
    ifstream ori{"Report.txt",ios::in};
    ofstream cop{"Temp.txt",ios::out};

	if(ori && cop){
		while(getline(ori, line)){
			cop << line << "\n";
		}
	}
	
	cout << "Finished copying.\n";
	cop.close();
	ori.close();
	
	ifstream tem{"Temp.txt", ios::in};
	ofstream rew{"Report.txt",ios::out | ios::trunc};
	
	if(tem.fail())
            cout << "Sorry,input file does not exist!\n";
    
    	NodeReport *del = new NodeReport;
        while(!tem.eof()){
            tem >> del->te_ID;
        	tem.ignore(numeric_limits<streamsize>::max(), '\t');
       		getline(tem, del->te_name, '\t');
        	getline(tem, del->te_age, '\t');
        	getline(tem, del->te_contactNo, '\t');
        	getline(tem, del->plan_ID, '\t');
        	getline(tem, del->plan_name, '\t');
        	getline(tem, del->plan_price, '\t');
        	getline(tem, del->tr_date, '\t');
        	getline(tem, del->tr_time, '\t');
        	getline(tem, del->tr_duration, '\t');
        	tem >> del->payment_status;
        	tem.ignore(numeric_limits<streamsize>::max(), '\n');
            if (id == del->te_ID){
            }
            else{
            	rew << del->te_ID << '\t' << del->te_name << '\t' 
				<< del->te_age << '\t' << del->te_contactNo << '\t' 
				<< del->plan_ID << '\t' << del->plan_name << '\t' 
				<< del->plan_price << '\t' << del->tr_date << '\t'
				<< del->tr_time << '\t' << del->tr_duration << '\t'
				<< del->payment_status << endl;
			}
            del->next = NULL;
            if (front == NULL)
                front = back = del;
            else{
                back->next = del;
                back = del;
            }
        }
            cout << "\nReport for Trainee ID " << id << " is deleted.\n" << endl;
            rew.close();
    		tem.close();
            system("Pause");
        }

void Report::displayReport(string id){
    //read report file
    ifstream infile("Report.txt");

    if(infile.fail())
        cout << "Sorry,input file does not exist!\n";
    
    NodeReport *temp = new NodeReport;
    bool display = true;
    while(!infile.eof()){
        infile >> temp->te_ID;
        infile.ignore(numeric_limits<streamsize>::max(), '\t');
        getline(infile, temp->te_name, '\t');
        getline(infile, temp->te_age, '\t');
        getline(infile, temp->te_contactNo, '\t');
        getline(infile, temp->plan_ID, '\t');
        getline(infile, temp->plan_name, '\t');
        getline(infile, temp->plan_price, '\t');
        getline(infile, temp->tr_date, '\t');
        getline(infile, temp->tr_time, '\t');
        getline(infile, temp->tr_duration, '\t');
        infile >> temp->payment_status;
        infile.ignore(numeric_limits<streamsize>::max(), '\n');
        
        if(temp->te_ID == id){
            display = false;
    		//display report for the specific trainee
        	cout << "\n====================TRAINEE REPORT====================" << endl;
       		cout << "\n***************************************************" << endl;
        	cout << "\tTrainee Information" << endl;
        	cout << "***************************************************" << endl;
        	cout << "Trainee ID : " << temp->te_ID << endl;
        	cout << "Trainee Name : " << temp->te_name << endl;
        	cout << "Trainee Age : " << temp->te_age << endl;
        	cout << "Trainee Contact No : " << temp->te_contactNo << endl;
        	cout << "\n***************************************************" << endl;
        	cout << "\tPlan Information" << endl;
        	cout << "***************************************************" << endl;
        	cout << "Plan ID : " << temp->plan_ID << endl;
        	cout << "Plan Name : " << temp->plan_name << endl;
        	cout << "Plan Price : " << temp->plan_price << endl;
        	cout << "\n***************************************************" << endl;
        	cout << "\tTraining Information" << endl;
        	cout << "***************************************************" << endl;
        	cout << "Training Date : " << temp->tr_date << endl;
        	cout << "Training Time : " << temp->tr_time << endl;
        	cout << "Training Duration : " << temp->tr_duration << " hours" << endl;
        	cout << "\n***************************************************" << endl;
        	cout << "\tPayment Status" << endl;
        	cout << "***************************************************" << endl;
				
			if(temp->payment_status == 'Y'){
				cout << "Payment Status : Trainee had done the payment.\n" << endl;
			}
			else{
				cout << "Payment Status : Trainee has not done the payment yet.\n" << endl;
			}
			break;
		}
        temp->next = NULL;
        if (front == NULL)
            front = back = temp;
        else{
            back->next = temp;
            back = temp;
        }
    }
    infile.close();
    if(display == true){ 
            cout << "\nReport for trainee with ID " << "id" << " not found." << endl;
            cout << "Please create report before display." << endl;
        }
    system("Pause");
}

void Report::traineeList(){
    cout << "\n***************************************************" << endl;
    cout << "\tList of Trainee Available" << endl;
    cout << "***************************************************" << endl;
    ifstream infile("TraineeData.txt");

        if(infile.fail())
            cout << "Sorry,input file does not exist!\n";
    
        NodeReport *r = new NodeReport;
        while(!infile.eof()){
            infile >> r->te_ID;
            infile.ignore(numeric_limits<streamsize>::max(), '\t');
            getline(infile, r->te_name, '\t');
            getline(infile, r->te_age, '\t');
            getline(infile, r->te_contactNo, '\t');
            getline(infile, r->plan_ID, '\n');
            cout << r->te_ID << endl;

            r->next = NULL;
            if (front == NULL)
                front = back = r;
            else{
                back->next = r;
                back = r;
            }
        }
        infile.close();
}

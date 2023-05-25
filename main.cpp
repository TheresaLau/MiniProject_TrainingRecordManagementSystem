#include "Plan.cpp"
#include "AdminLogin.cpp"
#include "Report.cpp"
#include "Trainee.cpp"
#include "Training.cpp"
#include "Payment.cpp"

#include <iostream>
#include <string>
#include <stdlib.h>

using namespace std;

int main()
{
    //Admin Login
    AdminLogin admin;
    string AID, password;
    bool loginStatus;
    cout << "\tWelcome to YSL Training Record Management System" << endl;
    cout << "********************************************************************" << endl;
    cout << "\t\tMade by : " << endl;
    cout << "\t\t\tZhu Yi Chen" << endl;
    cout << "\t\t\tTheresa Lau Xin Yi" << endl;
    cout << "\t\t\tSiew Yu Xuan\n" << endl;
    cout << "********************************************************************" << endl;
    cout << "Note : This system is only authorized by the admin of YSL Training." << endl;
    cout << "********************************************************************" << endl;
    
    do{
        cout << "\n====================ADMIN LOGIN====================" << endl;
            cout << "Admin ID : ";
            cin  >> AID;
            cout << "Password : ";
            cin  >> password;
                loginStatus =  admin.login(AID, password);
        
        if(loginStatus == false){
            cout << "Invalid ID or password. Please enter again." << endl;
        }
        else 
            cout << "\nCongrats! Login Successful." << endl;
    }while(loginStatus == false);
    system("Pause");
    
    //Admin Menu
    int choiceM;
    do{
        system("CLS");
        cout<<"\t\tYSL Training Record Management System"<<endl;
        cout << "********************************************************************" << endl;
        cout << "\n====================ADMIN MENU====================" << endl;
        cout << "[1] Trainee" << endl;
        cout << "[2] Plan" << endl;
        cout << "[3] Training" << endl;
        cout << "[4] Payment" << endl;
        cout << "[5] Report" << endl;
        cout << "[6] Log Out" << endl;
        cout << "Enter the choice : ";
        cin >> choiceM;

    switch(choiceM){
        case 1:
            //Trainee
                    {
            system("CLS");
            //Trainee (Queue Implementation Linked List)
	        Trainee trainee;
	        trainee.readFile();
	        int choiceT;
	        do
	        {
                cout<<"\t\tYSL Training Record Management System"<<endl;
                cout << "********************************************************************" << endl;
            cout<<"\n====================TRAINEE===================="<<endl;
		        cout<<"[1] Insert new Trainee"<<endl;
		        cout<<"[2] Delete first Trainee"<<endl;
		        cout<<"[3] Search TRAINEE information by ID"<<endl;
		        cout<<"[4] Display all Trainee information"<<endl;
		        cout<<"[5] Exit and Save changes"<<endl;
		        cout<<"Enter the choice: ";
		        cin>>choiceT;
		
		        switch(choiceT)
		        {
			        case 1: trainee.insert_trainee(); break;
			        case 2: trainee.delete_trainee(); break;
                    case 3: trainee.search_trainee(); break;
			        case 4: trainee.display_traineeinfo(); break;
		        }
	        }while(choiceT!=5);
        }
            break;

        case 2:
        {
            system("CLS");
            //Plan (Queue Implementation Linked List)
	        Plan plan;
	        plan.readPlan();
	        int choiceP;
	        do
	        {
                cout<<"\t\tYSL Training Record Management System"<<endl;
                cout << "********************************************************************" << endl;
            cout<<"\n====================PLAN===================="<<endl;
		        cout<<"[1] Insert new plan"<<endl;
		        cout<<"[2] Delete first plan"<<endl;
		        cout<<"[3] Update price for a plan"<<endl;
		        cout<<"[4] Search plan information"<<endl;
		        cout<<"[5] Display all plan"<<endl;
		        cout<<"[6] Exit and Save changes"<<endl;
		        cout<<"Enter the choice: ";
		        cin>>choiceP;
		
		        switch(choiceP)
		        {
			        case 1: plan.insertPlan(); system("Pause"); system("CLS"); break;
			        case 2: plan.deletePlan(); system("Pause"); system("CLS"); break;
                    case 3: plan.updatePrice(); system("Pause"); system("CLS"); break;
			        case 4: plan.searchPlan(); system("Pause"); system("CLS"); break;
			        case 5: plan.displayPlan(); system("Pause"); system("CLS"); break;
			        case 6: plan.writePlan(); break;
		        }
	        }while(choiceP!=6);
        }break;
        case 3:
            //Training
            {
            system("CLS");
            //Training (Queue Implementation Linked List)
	        Training training;
	        training.readFile();
	        int choiceT;
	        do
	        {
                cout<<"\t\tYSL Training Record Management System"<<endl;
                cout << "********************************************************************" << endl;
            cout<<"\n====================TRAINING===================="<<endl;
		        cout<<"[1] Insert new Training"<<endl;
		        cout<<"[2] Delete first Training info"<<endl;
		        cout<<"[3] Search Training information by Trainee's ID"<<endl;
		        cout<<"[4] Display all Training information"<<endl;
		        cout<<"[5] Exit"<<endl;
		        cout<<"Enter the choice: ";
		        cin>>choiceT;
		
		        switch(choiceT)
		        {
			        case 1: training.insert_training(); break;
			        case 2: training.delete_training(); break;
                    case 3: training.search_training(); break;
			        case 4: training.display_traininginfo(); break;
		        }
	        }while(choiceT!=5);
        }
            break;
        case 4:
         {
             system("CLS");
             //Payment (Queue Implementation Linked List)
	        Payment payment;
	        payment.readPayment();
	        int choicePay;
	        do
	        {
                cout<<"\t\tYSL Training Record Management System"<<endl;
                cout << "********************************************************************" << endl;
                cout<<"\n====================PAYMENT STATUS===================="<<endl;
		        cout<<"[1] Insert new payment status"<<endl;
		        cout<<"[2] Delete first payment status"<<endl;
		        cout<<"[3] Update payment status for a trainee"<<endl;
		        cout<<"[4] Search payment status for a trainee"<<endl;
		        cout<<"[5] Display all payment status"<<endl;
		        cout<<"[6] Exit and Save changes"<<endl;
		        cout<<"Enter the choice: ";
		        cin>>choicePay;
		
		        switch(choicePay)
		        {
			        case 1: payment.insertPayment(); system("Pause"); system("CLS"); break;
			        case 2: payment.deletePayment(); system("Pause"); system("CLS"); break;
			        case 3: payment.updatePayment(); system("Pause"); system("CLS"); break;
			        case 4: payment.searchPayment(); system("Pause"); system("CLS"); break;
			        case 5: payment.displayPayment(); system("Pause"); system("CLS"); break;
			        case 6: payment.writePayment(); break;
		        }
	        }while(choicePay!=6);
         }
            break;
        case 5:
        {
            system("CLS");  
			//Report
            Report report;
            Trainee trainee;
            int choiceR;
            string RID;
            do{
                cout<<"\t\tYSL Training Record Management System"<<endl;
                cout << "********************************************************************" << endl;
                cout << "\n====================TRAINEE REPORT====================" << endl;
                cout << "[1] Create Report" << endl;
                cout << "[2] Delete Report" << endl;
                cout << "[3] Display Report" << endl;
                cout << "[4] Exit" << endl;
                cout << "Enter the choice : ";
                cin >> choiceR;

                switch(choiceR){
                    case 1:
                    {   
                        system("CLS");
                        //list of trainee available
                       	report.traineeList();
                        cout <<"\nEnter the trainee ID to create report : ";
                        cin.ignore();
                        getline(cin,RID);
                        report.insertReport(RID);
                        system("CLS");
                        break;
                    }
                    case 2:
                    {   
                        system("CLS");
                    	//list of trainee available
                       	report.traineeList();
                        cout <<"\nEnter the trainee ID to delete report : ";
                        cin.ignore();
                        getline(cin,RID);
                        report.deleteReport(RID);
                        system("CLS");
                        break;
                    }
                    case 3:
                    {   
                        system("CLS");
                        //list of trainee available
                        report.traineeList();
                        cout << "Enter the trainee ID to display report : ";
                        cin.ignore();
                        getline(cin,RID);
                        report.displayReport(RID);
                        system("CLS");
                        break;
                    }
                    case 4:
                        system("CLS");
                        break;
                }
            }while(choiceR != 4);
            }break;
    }
    }while(choiceM != 6);

    system("CLS");
    cout << "\n********************************************************************" << endl;
    cout << "\tThanks for using YSL Training Record Management System" << endl;
    cout << "********************************************************************" << endl;

    	
	return 0;
}
#include <string>
using namespace std;

#ifndef TRAINEE_H_
#define TRAINEE_H_
#include "Training.h"
class Trainee{

    public:
    struct TraineeNode{
        string traineeID;
        string trainee_name;
        string trainee_age;
        string trainee_contact;
        string planID;
        TraineeNode* next;
    };

    TraineeNode* frontPtr, *backPtr;
    void createQueue();
    bool isEmpty();
    void readFile();
    void writeFile(TraineeNode*);//write the single new insert trainee's data to txtfile

    void insert_trainee();
    void delete_trainee();
    void search_trainee();
    void display_traineeinfo();


    Trainee(){
        createQueue();
    }
};

#endif
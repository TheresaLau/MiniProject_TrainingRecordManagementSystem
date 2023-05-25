#include <string>
using namespace std;

#ifndef TRAINING_H_
#define TRAINING_H_

class Training{

    public:
    struct TrainingNode{
        string t_id;
        string t_date;
        string t_time;
        string t_duration;
        TrainingNode* next;
    };

    TrainingNode* frontPtr, *backPtr;
    void createQueue();
    bool isEmpty();

    void readFile();
    void writeFile(TrainingNode*);

    void insert_training();
    void delete_training();
    void search_training();
    void display_traininginfo();

    Training(){
        createQueue();
    }
};

#endif
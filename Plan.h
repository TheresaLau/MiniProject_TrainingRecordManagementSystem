#ifndef PLAN_H
#define PLAN_H
#include <string>

using namespace std;

class Plan
{
    private:
        struct NodePlan
		{
			string planID, planName;
    		double planPrice;
    		NodePlan* next;
		};
    public:
    	NodePlan *front, *rear;
    	Plan();
        void readPlan();
        void insertPlan();
		void deletePlan();
		void displayPlan();
		void writePlan(); 
        void updatePrice();
		void searchPlan();
};

#endif
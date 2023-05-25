#ifndef PAYMENT_H
#define PAYMENT_H
#include <string>

using namespace std;

class Payment
{
    private:
        struct NodePayment
		{
			string traineeID;
            char paymentStatus;
    		NodePayment* next;
		};
    public:
    	NodePayment *front, *rear;
    	Payment();
    	void readPayment();
        void insertPayment();
		void deletePayment();
		void displayPayment();
		void writePayment();
		void searchPayment();
		void updatePayment();
};

#endif
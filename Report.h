#ifndef REPORT_H
#define REPORT_H
#include <string>

using namespace std;

class Report
{
    private:
        struct NodeReport{
            string te_ID, te_name, te_age, te_contactNo, plan_ID, plan_name, plan_price, tr_ID, tr_date, tr_time, tr_duration,p_ID;
            char payment_status;
            NodeReport* next;
        };

    public:
        NodeReport *front, *back;
        Report();
        void insertReport(string);
        void deleteReport(string);
        void displayReport(string);
        void traineeList();
};

#endif
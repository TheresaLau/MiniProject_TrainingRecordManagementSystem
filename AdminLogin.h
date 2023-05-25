#ifndef USERLOGIN_H
#define USERLOGIN_H
#include <string>

using namespace std;

class AdminLogin
{
    private:
        string adminID, adminPassword;
        bool admin = false;
    public:
    	bool login(string, string);
        bool getLogin();
};

#endif
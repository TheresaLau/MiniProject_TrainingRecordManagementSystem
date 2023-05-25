#include "AdminLogin.h"
#include <iostream>

using namespace std;

//Check Admin Login
bool AdminLogin::login(string id,string p){
    if((id == "YSL") && (p == "dsagroup11"))
        admin = true;
    else
        admin = false;
    return admin;
}

//Get Admin Login Status
bool AdminLogin::getLogin(){
    return admin;
}
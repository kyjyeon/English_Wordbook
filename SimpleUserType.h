#pragma once
#include <iostream>
#include "User.h"
using namespace std;


class SimpleUserType {
public:
    SimpleUserType() {
        m_user = nullptr;
    }

    void SetPtr(UserType* user) {
        m_user = user;
    }
    UserType* GetPtr() {
        return m_user;
    }

    bool operator<(SimpleUserType& s) {
        return(GetPtr()->GetTestScore() < s.GetPtr()->GetTestScore());
    }
    bool operator>(SimpleUserType& s) {
        return(GetPtr()->GetTestScore() > s.GetPtr()->GetTestScore());
    }
    bool operator==(SimpleUserType& s) {
        return(GetPtr()->GetTestScore() == s.GetPtr()->GetTestScore());
    }
    bool operator<=(SimpleUserType& s) {
        return(GetPtr()->GetTestScore() <= s.GetPtr()->GetTestScore());
    }

private:
    UserType* m_user; //Pointer member for pointing user address
};

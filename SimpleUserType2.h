#pragma once
#include <iostream>
#include "User.h"
using namespace std;


class SimpleUserType2 {
public:
    SimpleUserType2() {
        m_user = nullptr;
    }

    void SetPtr(UserType* user) {
        m_user = user;
    }
    UserType* GetPtr() {
        return m_user;
    }

    bool operator<(SimpleUserType2& s) {
        return(GetPtr()->GetId().compare(s.GetPtr()->GetId()) < 0);
    }
    bool operator>(SimpleUserType2& s) {
        return(GetPtr()->GetId().compare(s.GetPtr()->GetId()) > 0);
    }
    bool operator==(SimpleUserType2& s) {
        return(GetPtr()->GetId().compare(s.GetPtr()->GetId()) == 0);
    }

private:
    UserType* m_user;
};

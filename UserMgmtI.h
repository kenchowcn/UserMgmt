#ifndef USER_MGMT_I_H
#define USER_MGMT_I_H

#include <UserMgmt.h>

class UserMgmtI : public UserMgmt::UserManagement
{
public:

    virtual void Login(const ::UserMgmt::UserInfo&, ::UserMgmt::LoginResult&, const ::Ice::Current& = ::Ice::Current());
    virtual void shutdown(const Ice::Current&);
};

#endif

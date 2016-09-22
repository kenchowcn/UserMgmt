#include <IceUtil/IceUtil.h>
#include <Ice/Ice.h>
#include <UserMgmtI.h>

using namespace std;

void UserMgmtI::Login(const ::UserMgmt::UserInfo& info, ::UserMgmt::LoginResult& result, const Ice::Current&)
{
    std::cout << "    Name:" << info.userName << std::endl;
    std::cout << "Password:" << info.UserPassord << std::endl;

    result.validationResult = ::UserMgmt::Welcome;
    result.sessionToken = 0755;
}

void UserMgmtI::shutdown(const Ice::Current& c)
{
    cout << "Shutting down..." << endl;
    c.adapter->getCommunicator()->shutdown();
}

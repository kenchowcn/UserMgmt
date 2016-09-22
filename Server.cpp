#include <Ice/Ice.h>
#include <UserMgmtI.h>

using namespace std;

class UserManagementServer : public Ice::Application
{
public:

    virtual int run(int, char*[]);
};

int main(int argc, char* argv[])
{
    UserManagementServer app;
    return app.main(argc, argv, "./config.server");
}

int UserManagementServer::run(int argc, char*[])
{
    Ice::ObjectAdapterPtr adapter = communicator()->createObjectAdapter("UserManagement");

    UserMgmt::UserManagementPtr UserManagement = new UserMgmtI;

    adapter->add(UserManagement, Ice::stringToIdentity("UserManagement"));
    adapter->activate();
    communicator()->waitForShutdown();
    return EXIT_SUCCESS;
}

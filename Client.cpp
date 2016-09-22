#include <Ice/Ice.h>
#include <UserMgmt.h>

using namespace std;
using namespace UserMgmt;

class UserMgmtClient : public Ice::Application
{
public:
    UserMgmtClient();
    virtual int run(int, char*[]);
};

int main(int argc, char* argv[])
{
    UserMgmtClient app;
    std::cout << "Start Client" << std::endl;
    return app.main(argc, argv, "./config.client");
}

UserMgmtClient::UserMgmtClient() : Ice::Application(Ice::NoSignalHandling)
{
    std::cout << "NoSignalHandling" << std::endl;
}

int UserMgmtClient::run(int argc, char* argv[])
{
    std::cout << "Start Running" << std::endl;

    UserManagementPrx twoway = UserManagementPrx::checkedCast(
        communicator()->propertyToProxy("UserManagement.Proxy")->ice_twoway()->ice_secure(false));

    const UserInfo info = {"Jenny", "123456"};
    LoginResult result;

    std::cout << "Start Login" << std::endl;
    twoway->Login(info, result);

    std::cout << "Validation Result:" << result.validationResult << std::endl;
    std::cout << "    Session Token:" << result.sessionToken << std::endl;

    return EXIT_SUCCESS;
}

#include "server.h"


int main(int argc,char** argv)
{
    Server server(2000);
    server.acceptClients();
}
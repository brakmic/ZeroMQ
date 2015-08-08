// zmqClient1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#define sleep(x) Sleep(x)
using namespace std;
using namespace zmq;

int main(void)
{
    const int MAX_MSGS = 10;
	context_t context(1);
    //  Socket to talk to server
    printf("Connecting to hello world server...\n");
    socket_t sock(context, ZMQ_REQ);
	sock.connect("tcp://localhost:5555");

    int request_nbr;
    for (request_nbr = 0; request_nbr != MAX_MSGS; request_nbr++) {
		//send a message
		s_send(sock, "Hello");
		printf("Sending Hello %d...\n", request_nbr);
		sleep(2000);
		//receive a reply, if any
		auto reply = s_recv(sock);
        cout << "Received " << reply << endl;
    }

    sock.close();
	context.close();
    system("PAUSE");
    return 0;
}



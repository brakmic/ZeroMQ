// zmqClient1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#define sleep(x) Sleep(x)
using namespace std;

int main(void)
{
    const int MAX_MSGS = 10;
    void *context = zmq_ctx_new();
    //  Socket to talk to server
    printf("Connecting to hello world server...\n");
    void *requester = zmq_socket(context, ZMQ_REQ);
    zmq_connect(requester, "tcp://localhost:5555");

    int request_nbr;
    for (request_nbr = 0; request_nbr != MAX_MSGS; request_nbr++) {
        zmq_msg_t request;
        zmq_msg_init_size(&request, 5);
        memcpy(zmq_msg_data(&request), "Hello", 5);
        printf("Sending Hello %d...\n", request_nbr);
        zmq_msg_send(&request, requester, 0);
        zmq_msg_close(&request);

        auto response = s_recv(requester);
        cout << "Received " << response << endl;
        /*zmq_msg_t reply;
        zmq_msg_init(&reply);
        zmq_msg_recv(&reply, requester, 0);
        printf("Received World %d\n", request_nbr);
        zmq_msg_close(&reply);*/
    }

    sleep(2);
    zmq_close(requester);
    zmq_ctx_destroy(context);
    system("PAUSE");
    return 0;
}



// ZeroMQTest1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
//
//  Hello World server
//  Binds REP socket to tcp://*:5555
//  Expects "Hello" from client, replies with "World"
//

void show_info() {
    int major, minor, patch;
    zmq_version(&major, &minor, &patch);
    printf("Using 0MQ version %d.%d.%d\n", major, minor, patch);
}

int main(void)
{
    void *context = zmq_ctx_new();
    //  Socket to talk to clients
    void *responder = zmq_socket(context, ZMQ_REP);
    zmq_bind(responder, "tcp://*:5555");
    show_info();

    while (1) {
        //  Wait for next request from client
        zmq_msg_t request;
        zmq_msg_init(&request);
        //zmq_msg_recv(&request, responder, 0);
        char* message = s_recv(responder);
        printf("Received %s\n", message);
        zmq_msg_close(&request);
        //  Do some 'work'
        sleep(1);
        //  Send reply back to client
        //zmq_msg_t reply;
        //zmq_msg_init_size(&reply, 5);
        //memcpy(zmq_msg_data(&reply), "World", 5);
        //zmq_msg_send(&reply, responder, 0);
        //zmq_msg_close(&reply);
        char* response = "World";
        s_send(responder, response);
    }
    //  We never get here but if we did, this would be how we end
    zmq_close(responder);
    zmq_ctx_destroy(context);
    return 0;
}

// ZeroMQTest1.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
//
//  Hello World server
//  Binds REP socket to tcp://*:5555
//  Expects "Hello" from client, replies with "World"
//
using namespace zmq;

void show_info() {
    int major, minor, patch;
    zmq_version(&major, &minor, &patch);
    printf("Using 0MQ version %d.%d.%d\n", major, minor, patch);
}

int main(void)
{
    context_t context(1);
    //  Socket to talk to clients
	socket_t sock(context, ZMQ_REP);
    sock.bind("tcp://*:5555");
    show_info();

    while (1) {
        //  Wait for next request from client
		auto data = s_recv(sock);
		std::cout << "Received " << data << std::endl;
        //  Do some 'work'
        sleep(1);
		std::string reply = "World";
		s_send(sock, reply);
    }
    //  We never get here but if we did, this would be how we end
	sock.close();
	context.close();
    return 0;
}

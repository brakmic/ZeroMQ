// Publisher.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

using namespace std;

typedef struct _WeatherData {
    int zip;
    int temp;
    int hum;
}WeatherDtaa,*pWeatherData;

void show_info() {
    int major, minor, patch;
    zmq_version(&major, &minor, &patch);
    printf("Using 0MQ version %05d.%d.%d\n", major, minor, patch);
}

void stop_server(void* context, void* publisher) {
    zmq_close(publisher);
    zmq_ctx_destroy(context);
}

void send_updates(void* publisher) {
    srandom((unsigned)time(NULL));
    while (1) {
        //get random values
        int zipcode, temperature, relhumidity;
        zipcode = 10001;//randof(100000);
        temperature = randof(215) - 80;
        relhumidity = randof(50) + 10;
        auto update = boost::format("%d %d %d") % zipcode % temperature % relhumidity;
        cout << "Sending: " << update << endl;
        sleep(2000);
        s_send(publisher, (char*)update.str().c_str());
    }
}

int main(int argc, char** argv)
{
    void* context = NULL;
    void* publisher = NULL;
    show_info();
    
    context = zmq_ctx_new();
    publisher = zmq_socket(context, ZMQ_PUB);
    int rc = zmq_bind(publisher, "tcp://*:5556");
    assert(rc == 0);
    send_updates(publisher);
    system("PAUSE");
    stop_server(context, publisher);
    return 0;
}


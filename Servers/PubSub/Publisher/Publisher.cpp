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

void send_updates(zmq::socket_t& publisher) {

    while (1) {
        //get random values
        int zipcode, temperature, relhumidity;
        zipcode = 10001;
        temperature = within(215) - 80;
        relhumidity = within(50) + 10;
        auto update = boost::format("%d %d %d") % zipcode % temperature % relhumidity;
        cout << "Sending: " << update << endl;
        sleep(2000);
        s_send(publisher, update.str());
    }
}

int main(int argc, char** argv)
{
    
    zmq::context_t context;
    zmq::socket_t publisher(context, ZMQ_PUB);
    
    show_info();

    publisher.bind("tcp://*:5556");
    send_updates(publisher);
    system("PAUSE");
    stop_server(context, publisher);
    return 0;
}


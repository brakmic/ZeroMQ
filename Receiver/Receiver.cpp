// Receiver.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
using namespace std;
namespace qi = boost::spirit::qi;

void show_info() {
    int major, minor, patch;
    zmq_version(&major, &minor, &patch);
    printf("Using 0MQ version %d.%d.%d\n", major, minor, patch);
}

void process_messages(int max_messages, void* subscriber) {
    int update_nbr;
    long total_temp = 0;
    for (update_nbr = 0; update_nbr < max_messages; update_nbr++)
    {
        char* message = s_recv(subscriber);
        int zip = 0, temp = 0, hum = 0;
        string str(message);
        string::iterator begin = str.begin();
        string::iterator end = str.end();

        qi::phrase_parse(begin, end, qi::int_ >> qi::int_ >> qi::int_, qi::ascii::space, zip, temp, hum);
        cout << "ZIP: " << zip << " TEMP: " << temp << " HUM: " << hum << endl;
        total_temp += temp;
        
        free(message);
    }
    cout << "TOTAL TEMP: " << total_temp << endl;
    cout << "AVG. TEMP: " << (int)(total_temp / update_nbr) << endl;
}

int main(int argc, char** argv)
{
    int max_messages = 100;
    void* context = NULL;
    void* subscriber = NULL;
    show_info();
    context = zmq_ctx_new();
    //open socket to server to get updates
    cout << "Collecting updates from server\n";
    subscriber = zmq_socket(context, ZMQ_SUB);
    int rc = zmq_connect(subscriber, "tcp://localhost:5556");
    assert(rc == 0);
    //subscribe to queue
    char* filter = (argc > 1) ? argv[1] : "10001";
    
    rc = zmq_setsockopt(subscriber, ZMQ_SUBSCRIBE, filter, strlen(filter));
    assert(rc == 0);

    process_messages(max_messages, subscriber);
    //close 0MQ
    zmq_close(subscriber);
    zmq_ctx_destroy(context);
    system("PAUSE");
    return 0;
}


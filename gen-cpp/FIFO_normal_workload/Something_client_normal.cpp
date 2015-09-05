#include "Something.h"

#include <transport/TSocket.h>
#include <transport/TBufferTransports.h>
#include <protocol/TBinaryProtocol.h>
#include <fstream>
#include <sstream>
#include <string>
#include <curl/curl.h>
#include <random>
#include <iostream>
#include <time.h>
#include <sys/time.h>

using namespace apache::thrift;
using namespace apache::thrift::protocol;
using namespace apache::thrift::transport;

using namespace Test;

void generate_normal_distribution(SomethingClient client){
    struct timeval start, end;
    double acc_time;
    std::string body;
    const int nrolls = 150;
    std::default_random_engine generator;
    std::normal_distribution<double> distribution(10.0, 5.0);

    int p[15]={};
    int s[150]={};

    for(int i=0; i<nrolls; i++){
        s[i] = 5;
    }

    for(int i=0; i<nrolls; i++){
        double number = distribution(generator);
        //std::cout << "random number generated " << number << std::endl;
        if(number>=0.0 && number<15.0){
            ++p[int(number)];
            s[i] = number;
        }
    }
    gettimeofday(&start, NULL);
    for (int i=0; i<150; i++){
        if(s[i] == 0) client.ping(body,"http://www.gmail.com");
        if(s[i] == 1) client.ping(body,"http://www.google.com");
        if(s[i] == 2) client.ping(body,"http://www.facebook.com");
        if(s[i] == 3) client.ping(body,"http://www.cc.gatech.edu");
        if(s[i] == 4) client.ping(body,"http://www.hindu.com");
        if(s[i] == 5) client.ping(body,"http://www.bbc.com/news");
        if(s[i] == 6) client.ping(body,"http://www.cnn.com");
        if(s[i] == 7) client.ping(body,"http://www.nationalgeographic.com");
        if(s[i] == 8) client.ping(body,"http://www.yahoo.com");
        if(s[i] == 9) client.ping(body,"http://www.amazon.com");
        if(s[i] == 10) client.ping(body,"http://www.washingtonpost.com");
        if(s[i] == 11) client.ping(body,"http://www.ebay.com");
        if(s[i] == 12) client.ping(body,"http://www.cisco.com");
        if(s[i] == 13) client.ping(body,"http://www.time.com");
        if(s[i] == 14) client.ping(body,"http://www.forbes.com");
    }
    gettimeofday(&end, NULL);
    acc_time = (double) (end.tv_usec - start.tv_usec)/1000000 +
     (double) (end.tv_sec - start.tv_sec);
    std::cout << "Fetching completed for the workload. Access Time was " << acc_time << std::endl;
}


int main(int argc, char **argv) {
        boost::shared_ptr<TSocket> socket(new TSocket("10.0.0.5",9090));
        boost::shared_ptr<TTransport> transport(new TBufferedTransport(socket));
        boost::shared_ptr<TProtocol> protocol(new TBinaryProtocol(transport));

        SomethingClient client(protocol);
        transport->open();
//        get_URLlist(client,argv[1]);
        generate_normal_distribution(client);
//        client.ping();
        transport->close();

        return 0;
}

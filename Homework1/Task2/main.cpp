#include <iostream>
#include "DNSRecord.h"
#include "DNSRecord.cpp"
#include "DNSCache.h"
#include "DNSCache.cpp"

using namespace std;

int main()
{
    DNSRecord first;
    DNSRecord second;
    DNSRecord third;

    DNSRecord trying;

    first.setDomainName("Simona");
    first.setIpAddress("94.022.177.32");

    second.setDomainName("Martin");
    second.setIpAddress("456.143.554.559");

    third.setDomainName("Simona");
    third.setIpAddress("111.123.983.540");

    trying.setDomainName("Iva");
    trying.setIpAddress("98.77.19.43");

    //first.printRecord();
    //second.printRecord();
    //third.printRecord();

    //cout << first.getDomainName() << " " << first.getIpAddress() << endl;
    //cout << second.getDomainName() << " " << second.getIpAddress() << endl;
    //cout << third.getDomainName() << " " << third.getIpAddress() << endl;

    DNSCache full;

    full.addRecord(first);
    full.addRecord(second);
    full.addRecord(third);

    //full+= trying;

    //full.flush();

    full.printCache();

    //full-= 1;

    //full.printCache();

    full.lookup("Simona");

    full.flush();

    full.printCache();

    return 0;
}

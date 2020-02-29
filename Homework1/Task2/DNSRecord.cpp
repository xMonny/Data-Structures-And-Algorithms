#include <iostream>
#include "DNSRecord.h"

int strLen(char* arr)
{
    int cnt = 0;

    while(arr[cnt] != '\0')
    {
        cnt++;
    }
    return cnt;
}

void doubleLen(char* &arr)
{
    char* helpArr = new char[strLen(arr)*2 + 1];

    for (int i = 0; i <= strLen(arr); i++)
    {
        helpArr[i] = arr[i];
    }

    delete[] arr;

    arr = helpArr;
}

void strCoppy(char* &place, const char* src)
{
    int cnt = 0;

    while (src[cnt] != '\0')
    {
        if (cnt == strLen(place))
        {
            doubleLen(place);
        }

        place[cnt] = src[cnt];
        cnt++;
    }
    place[cnt] = '\0';
}

DNSRecord::DNSRecord()
{
    domainName = new char[1];
    domainName[0] = '\0';

    ipAddress = new char[1];
    ipAddress[0] = '\0';
}

DNSRecord::DNSRecord(const DNSRecord &record)
{
    int sizeDomainName = strLen(record.domainName);
    domainName = new char[sizeDomainName + 1];
    strCoppy(domainName, record.domainName);

    int sizeIpAddress = strLen(record.ipAddress);
    ipAddress = new char[sizeIpAddress + 1];
    strCoppy(ipAddress, record.ipAddress);
}

DNSRecord& DNSRecord::operator=(const DNSRecord &record)
{
    if (this != &record)
    {
        delete[] domainName;
        delete[] ipAddress;

        int sizeDomainName = strLen(record.domainName);
        domainName = new char[sizeDomainName + 1];
        strCoppy(domainName, record.domainName);

        int sizeIpAddress = strLen(record.ipAddress);
        ipAddress = new char[sizeIpAddress + 1];
        strCoppy(ipAddress, record.ipAddress);
    }
    return *this;
}

void DNSRecord::setDomainName(char* dName)
{
        int sizeDomainName = strLen(dName);
        delete[] domainName;
        domainName = new char[sizeDomainName + 1];
        strCoppy(domainName, dName);
}

char* DNSRecord::getDomainName() const
{
    return domainName;
}

void DNSRecord::setIpAddress(char* ipAd)
{
        int sizeIpAddress = strLen(ipAd);
        delete[] ipAddress;
        ipAddress = new char[sizeIpAddress + 1];
        strCoppy(ipAddress, ipAd);
}

char* DNSRecord::getIpAddress() const
{
    return ipAddress;
}

void DNSRecord::printRecord() const
{
    std::cout << "Record: " << getDomainName() << " " << getIpAddress() << std::endl;
}

DNSRecord::~DNSRecord()
{
    delete[] domainName;
    delete[] ipAddress;
}

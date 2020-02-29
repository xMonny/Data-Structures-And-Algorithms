#pragma once
#include "DNSRecord.h"

class DNSCache
{
private:
    DNSRecord* records;
    int smallSize;
    int maxSize;
    void changeSize();

public:
    DNSCache();
    DNSCache(const DNSCache&);
    DNSCache& operator=(const DNSCache&);

    void addRecord(DNSRecord&);
    void removeRecord(int);
    void lookup(char*);
    void flush();
    void printCache() const;

    DNSCache& operator+=(DNSRecord&);
    DNSCache& operator-=(int);

    ~DNSCache();
};

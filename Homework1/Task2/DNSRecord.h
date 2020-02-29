#pragma once

class DNSRecord
{
private:
    char* domainName;
    char* ipAddress;

public:
    DNSRecord();
    DNSRecord(const DNSRecord&);
    DNSRecord& operator=(const DNSRecord&);

    void setDomainName(char*);
    char* getDomainName() const;
    void setIpAddress(char*);
    char* getIpAddress() const;

    void printRecord() const;

    ~DNSRecord();
};

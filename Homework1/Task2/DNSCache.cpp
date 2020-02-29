#include <iostream>
#include "DNSRecord.h"
#include "DNSCache.h"

DNSCache::DNSCache()
{
    smallSize = 0;
    maxSize = 10;

    records= new DNSRecord[maxSize];
}

DNSCache::DNSCache(const DNSCache& cache)
{
    smallSize = cache.smallSize;
    maxSize = cache.maxSize;

    records = new DNSRecord[maxSize];

    for (int i = 0; i < smallSize; i++)
    {
        records[i] = cache.records[i];
    }
}

DNSCache& DNSCache::operator=(const DNSCache &cache)
{
    if (this != &cache)
    {
        delete[] records;

        smallSize = cache.smallSize;
        maxSize = cache.maxSize;

        records = new DNSRecord[maxSize];

        for (int i = 0; i < smallSize; i++)
        {
            records[i] = cache.records[i];
        }
    }
    return *this;
}

void DNSCache::changeSize()
{
    maxSize*=2;

    DNSRecord* helpRecords = new DNSRecord[maxSize];

    for (int i = 0; i < smallSize; i++)
    {
        helpRecords[i] = records[i];
    }

    delete[] records;

    records = helpRecords;
}

void DNSCache::addRecord(DNSRecord &record)
{
    if (smallSize == maxSize)
    {
        changeSize();
    }

    records[smallSize] = record;
    smallSize++;
}

void DNSCache::removeRecord(int index)
{
    for (int i = index; i < smallSize - 1; i++)
    {
        records[i] = records[i+1];
    }
    smallSize--;
}

void DNSCache::lookup(char* dName)
{
    int cnt = 0;
    int finals = 0;
    for (int i = 0; i < smallSize; i++)
    {
        char* help = records[i].getDomainName();

        if (strLen(help) <= strLen(dName))
        {
            int sizes = strLen(dName);

            for (int j = 0; j < sizes; j++)
            {
                if (dName[j] == help[j])
                {
                    cnt++;
                }

                else
                {
                    cnt = 0;
                    break;
                }
            }

            if (cnt == sizes)
            {
                finals++;
                std::cout << "IP " << i << " -> " << records[i].getIpAddress() << std::endl;
                cnt = 0;
                delete[] help;
            }

            if (finals == 0 && i == smallSize - 1)
            {
                std::cout << "NULL" << std::endl;
                delete[] help;
            }
        }

        else
        {
            int sizes = strLen(help);

            for (int j = 0; j < sizes; j++)
            {
                if (help[j] == dName[j])
                {
                    cnt++;
                }

                else
                {
                    cnt = 0;
                    break;
                }
            }

            if (cnt == sizes)
            {
                finals++;
                std::cout << "IP " << i << " -> " << records[i].getIpAddress() << std::endl;
                cnt = 0;
                delete[] help;
            }

            if (finals == 0 && i == smallSize - 1)
            {
                std::cout << "NULL" << std::endl;
                delete[] help;
            }
        }
    }
}

void DNSCache::flush()
{
    for (int i = 0; i < smallSize; i++)
    {
        records[i].setDomainName(nullptr);
        records[i].setIpAddress(nullptr);
    }
}

DNSCache& DNSCache::operator+=(DNSRecord &record)
{
    addRecord(record);

    return *this;
}

DNSCache& DNSCache::operator-=(int index)
{
    removeRecord(index);

    return *this;
}

void DNSCache::printCache() const
{
    for (int i = 0; i < smallSize; i++)
    {
        std::cout << "Record: " << records[i].getDomainName() << " " << records[i].getIpAddress() << std::endl;
    }
}

DNSCache::~DNSCache()
{
    delete[] records;
}

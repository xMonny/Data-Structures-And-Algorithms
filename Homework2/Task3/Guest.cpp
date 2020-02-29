#include <iostream>
#include "Guest.h"

int strLen(const char* arr)
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

Guest::Guest(const Guest &guest)
{
    int sizeIP = strLen(guest.IpAddress);
    IpAddress = new char[sizeIP + 1];
    strCoppy(IpAddress, guest.IpAddress);
}

Guest::Guest(const char* newIP)
{
    int sizeIP = strLen(newIP);
    IpAddress = new char[sizeIP + 1];
    strCoppy(IpAddress, newIP);
}

Guest& Guest::operator=(const Guest &guest)
{
    if (this != &guest)
    {
        delete[] IpAddress;

        int sizeIP = strLen(guest.IpAddress);
        IpAddress = new char[sizeIP + 1];
        strCoppy(IpAddress, guest.IpAddress);
    }
    return *this;
}

void Guest::print() const
{
    std::cout << "IP: " << IpAddress << std::endl;
}

Guest::~Guest()
{
    delete[] IpAddress;
}

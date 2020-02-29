/**
*
* Solution to homework assignment 2
* Introduction to programming course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2018/2019
*
* @author Simona Lyubenova
* @idnumber 62258
* @task 2
* @compiler GCC
*
*/

#include <iostream>
#include <cstring>
#include <math.h>
#include <stdlib.h>

using namespace std;

int FindArr (char fArr[], char uArr[], char** arr1, char** arr2)
{
    arr1 = &fArr;
    arr2 = &uArr;

    char helpArr[strlen(uArr)];
    int cnt = 0;
    int helper = 0;
    int pointer = 0;

    if (strlen(uArr) == 1)
    {
        for (int k = 0; k < strlen(uArr); k++)
        {
            for (int l = 0; l < strlen(fArr); l++)
            {
                if (uArr[k] == fArr[l])
                {
                    if (cnt == helper)
                    {
                        pointer = abs(helper-l);
                    }
                    cnt++;
                    if (cnt >= helper)
                    {
                        helper = cnt;
                    }
                    if (uArr[k] != fArr[l+1])
                    {
                        cnt = 0;
                    }
                }
            }
        }
    }

    else
    {
        for (int i = 0; i < strlen(fArr); )
        {
            if (uArr[0] == fArr[i])
            {
                if (cnt == helper)
                {
                    pointer = abs(helper - i);
                }
                cnt++;
                for (int j = 0; j < strlen(uArr)-1; j++)
                {
                    if (uArr[j+1] == fArr[i+1])
                    {
                        cnt++;
                        if (cnt%strlen(uArr) == 0 && cnt >= helper)
                        {
                            helper = cnt;
                        }
                    }
                    else
                    {
                        if (cnt%strlen(uArr) == 0 && cnt >= helper)
                        {
                            helper = cnt;
                        }
                        i++;
                        cnt = 0;
                        break;
                    }
                    i++;
                    if (j == strlen(uArr)-2)
                    {
                        i++;
                    }
                }
            }
            else
            {
                i++;
                cnt = 0;
            }
        }
    }

    cout << "Maximal length: " << helper << endl;
    cout << "Index: " << pointer;

    return 0;
}

int main()
{
    char firstArr[100];
    char userArr[100];
    char helpArr[strlen(userArr)];

    cout << "Write maximum 100 letters between a(A) and z(Z): ";
    cin >> firstArr;

    if (strlen(firstArr) > 100)
    {
        cout << "Wrong length!" << endl;
        return 0;
    }

    for (int i = 0; i < strlen(firstArr); i++)
    {
        if (firstArr[i] < 'A' || firstArr[i] > 'z')
        {
            cout << "Error in letters!" << endl;
            return 0;
        }
    }

    cout << "Search letters: ";
    cin >> userArr;

    if (strlen(userArr) > strlen(firstArr))
    {
        cout << "Wrong length!" << endl;
        return 0;
    }

    for (int i = 0; i < strlen(userArr); i++)
    {
        if (userArr[i] < 'A' || userArr[i] > 'z')
        {
            cout << "Error in letters!" << endl;;
            return 0;
        }
    }

    char *pointerFirstArr = firstArr;
    char *pointerUserArr = userArr;

    FindArr(firstArr, userArr, &pointerFirstArr, &pointerUserArr);

    return 0;
}

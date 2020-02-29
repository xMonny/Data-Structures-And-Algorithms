/**
*
* Solution to homework assignment 2
* Introduction to programming course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2018/2019
*
* @author Simona Lyubenova
* @idnumber 62258
* @task 1
* @compiler GCC
*
*/

#include <iostream>
#include <math.h>
#include <limits>
#include <stdlib.h>

using namespace std;

int Shift (int nArr[], int shiftArr, int lengthArr, int* sizeArr, int** arrs)
{
    sizeArr = &lengthArr;
    arrs = &nArr;
    int secondArr[lengthArr];
    int b;

    if (shiftArr >= 0)
    {
        for (int j = 0; j < lengthArr; j++)
        {
            if (j+shiftArr < lengthArr)
            {
                b = nArr[j];
                secondArr[j+shiftArr] = b;
            }

            else
            {
                b = nArr[j];
                secondArr[shiftArr-(lengthArr-j)] = b;
            }
        }
    }

    if (shiftArr <= 0)
    {
        for (int j = 0; j < lengthArr; j++)
        {
            if (j+shiftArr >= 0)
            {
                b = nArr[j];
                secondArr[j+shiftArr] = b;
            }

            else
            {
                b = nArr[j];
                secondArr[lengthArr+(j+shiftArr)] = b;
            }
        }
    }

    cout << "New array: ";

    for (int i = 0; i < lengthArr; i++)
    {
        cout << secondArr[i] << " ";
    }

    cout << endl;

    return 0;
}

int main()
{
    int L = 5;

    if (L >= 100)
    {
        cout << "Error!" << endl;
        return 0;
    }


    int M;

    int arr[L] = {6, 5, 6, 0, 3};

    int *pointerArr = arr;
    int *pointerSize = &L;

    for (int i = 0; i < L; i++)
    {
        cout << arr[i] << " ";
    }

    cout << endl << "Write number between " << "-" << L-1 << " and " << L-1 << endl;
    cout << "Your shift: ";
    cin >> M;

    if (cin.fail())
    {
        std::cout << "Wrong input!" << endl;
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        return 0;
    }

    if (abs(M) >= L)
    {
        cout << "Error!" << endl;
        return 0;
    }

    Shift(arr, M, L, pointerSize, &pointerArr);

    return 0;
}

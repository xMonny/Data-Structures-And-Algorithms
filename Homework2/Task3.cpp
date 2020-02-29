/**
*
* Solution to homework assignment 2
* Introduction to programming course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2018/2019
*
* @author Simona Lyubenova
* @idnumber 62258
* @task 3
* @compiler GCC
*
*/

#include <iostream>
#include <cstring>
#include <limits>

using namespace std;

const int len = 6;

int FindInMatrix (int matr[len][len], char userNumber[], char** inputNumber)
{
    int side = len;
    inputNumber = &userNumber;

    char rotated[side];
    int cnt = 0;
    int found = 0;

    int matrixArr[side];

    int numberArr[strlen(userNumber)];
    int numberHelper = 0;

    int rotatedArr[strlen(userNumber)];
    int rotatedHelper = 0;

    for (int i = 0; i < strlen(userNumber); i++)
    {
        numberHelper = userNumber[i] - 48;
        numberArr[i] = numberHelper;
    }

    if (strlen(userNumber) == 1)
    {
        for (int r = 0; r < side; r++)
        {
            for (int c = 0; c < side; c++)
            {
                if (numberArr[0] == matr[r][c])
                {
                    found++;
                }
            }
        }
        cout << "Repeat: " << found << endl;
        return 0;
    }

    if (strlen(userNumber) == side)
    {
        for (int r = 0; r < side; r++)
        {
            for (int c = 0; c < side; c++)
            {
                matrixArr[c] = matr[r][c];
            }

            for (int i = 0; i < side; )
            {
                if (numberArr[0] == matrixArr[i])
                {
                    cnt++;
                    for (int j = 0; j < strlen(userNumber)-1; j++)
                    {
                        if (numberArr[j+1] == matrixArr[i+1])
                        {
                            cnt++;
                            if (cnt%strlen(userNumber) == 0)
                            {
                                found++;
                            }
                        }
                        else
                        {
                            if (cnt%strlen(userNumber) == 0)
                            {
                                found++;
                            }
                            i++;
                            cnt = 0;
                            break;
                        }
                        i++;
                        if (j == strlen(userNumber)-2)
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
        cout << "Repeat: " << found*2 + 2 << endl;
        return 0;
    }

    for (int f = 0; f < strlen(userNumber); f++)
    {
        for (int l = strlen(userNumber)-1; l >= 0; l--)
        {
            rotated[f] = userNumber[l];
            f++;
        }
    }

    for (int i = 0; i < strlen(userNumber); i++)
    {
        rotatedHelper = rotated[i] - 48;
        rotatedArr[i] = rotatedHelper;
    }

    for (int r = 0; r < side; r++)
    {
        for (int c = 0; c < side; c++)
        {
            matrixArr[c] = matr[r][c];
        }

        for (int i = 0; i < side; )
        {
            if (numberArr[0] == matrixArr[i])
            {
                cnt++;
                for (int j = 0; j < strlen(userNumber)-1; j++)
                {
                    if (numberArr[j+1] == matrixArr[i+1])
                    {
                        cnt++;
                        if (cnt%strlen(userNumber) == 0)
                        {
                            found++;
                        }
                    }
                    else
                    {
                        if (cnt%strlen(userNumber) == 0)
                        {
                            found++;
                        }
                        i++;
                        cnt = 0;
                        break;
                    }
                    i++;
                    if (j == strlen(userNumber)-2)
                    {
                        i++;
                    }
                }
            }
            else
            {
                if (rotatedArr[0] == matrixArr[i])
                {
                    cnt++;
                    for (int j = 0; j < strlen(userNumber)-1; j++)
                    {
                        if (rotatedArr[j+1] == matrixArr[i+1])
                        {
                            cnt++;
                            if (cnt%strlen(userNumber) == 0)
                            {
                                found++;
                            }
                        }
                        else
                        {
                            if (cnt%strlen(userNumber) == 0)
                            {
                                found++;
                            }
                            i++;
                            cnt = 0;
                            break;
                        }
                        i++;
                        if (j == strlen(userNumber)-2)
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
    }

    for (int c = 0; c < side; c++)
    {
        for (int r = 0; r < side; r++)
        {
            matrixArr[r] = matr[r][c];
        }

        for (int i = 0; i < side; )
        {
            if (numberArr[0] == matrixArr[i])
            {
                cnt++;
                for (int j = 0; j < strlen(userNumber)-1; j++)
                {
                    if (numberArr[j+1] == matrixArr[i+1])
                    {
                        cnt++;
                        if (cnt%strlen(userNumber) == 0)
                        {
                            found++;
                        }
                    }
                    else
                    {
                        if (cnt%strlen(userNumber) == 0)
                        {
                            found++;
                        }
                        i++;
                        cnt = 0;
                        break;
                    }
                    i++;
                    if (j == strlen(userNumber)-2)
                    {
                        i++;
                    }
                }
            }
            else
            {
                if (rotatedArr[0] == matrixArr[i])
                {
                    cnt++;
                    for (int j = 0; j < strlen(userNumber)-1; j++)
                    {
                        if (rotatedArr[j+1] == matrixArr[i+1])
                        {
                            cnt++;
                            if (cnt%strlen(userNumber) == 0)
                            {
                                found++;
                            }
                        }
                        else
                        {
                            if (cnt%strlen(userNumber) == 0)
                            {
                                found++;
                            }
                            i++;
                            cnt = 0;
                            break;
                        }
                        i++;
                        if (j == strlen(userNumber)-2)
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
    }

    cout << "Repeat: " << found << endl;

    return 0;
}

int main()
{
    int simple = 0;
    int matrix[len][len] = {5, 4, 3, 8, 0, 6,
                            9, 4, 5, 1, 0, 2,
                            8, 5, 8, 0, 6, 1,
                            0, 9, 6, 8, 4, 2,
                            6, 1, 0, 2, 6, 1,
                            2, 1, 8, 4, 2, 6};

    char number[len];

    for (int rows = 0; rows < len; rows ++)
    {
        for (int cols = 0; cols < len; cols ++)
        {
            cout << matrix[rows][cols] << " ";
            if (matrix[rows][cols] < 0 || matrix[rows][cols] > 9)
            {
                simple ++;
            }
        }
        cout << endl;
    }
    cout << endl;

    if (simple > 0)
    {
        cout << "Matrix is not simple" << endl;
        return 0;
    }

    else
    {
        cout << "Matrix is simple" << endl;
    }

    cout << "Type number between 0 and " << len << " symbols: ";
    cin >> number;

    if (strlen(number) > len)
    {
        cout << "Error!" << endl;
        return 0;
    }

    for (int i = 0; i < strlen(number); i++)
    {
        if (number[i] < '0' || number[i] > '9')
        {
            cout << "Wrong input!" << endl;
            return 0;
        }
    }

    char *pointerNumber = number;

    FindInMatrix (matrix, number, &pointerNumber);

    return 0;
}

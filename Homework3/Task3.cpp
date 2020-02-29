/**
*
* Solution to homework assignment 3
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
#include <math.h>

using namespace std;

const int elements = 4;

void FindTotalBase (double matrixGausA[][elements], double matrixGausB[][elements], const int& n, const int& m, double arrayForFinalVectors[][elements], int& things)
{
    double helpMatrixGausB[m][elements]; //matrix which we use in Gaus method for vectors B

    double arrB[elements]; //array where we record rows from matrix of vectors B

    double zeroMatrix[elements] = {}; //zero matrix

    double firstB = 0; //"enclosed" number
    double secondB = 0; //number under "enclosed" number
    double y = 0; //number which we multiply with next row from Gaus matrix in order to work over it

    int foundB = 0; //found number in Gaus matrix which is not 0
    int cntB = 0; //variable which we use as number of rows which contain only 0

    for (int r = 0; r < m; r++) //Gaus method
    {
        for (int c = 0; c < elements; c++)
        {
            helpMatrixGausB[0][c] = matrixGausB[0][c];
            arrB[c] = matrixGausB[0][c];
        }

        for (int i = 0; i < elements; i++)
        {
            if (arrB[i] != 0)
            {
                foundB++;
                firstB = arrB[i];
                int colsB = i;
                for (int rows = 0; rows <= m-1; rows++)
                {
                    if (rows == m-1)
                    {
                        for (int f = 0; f < m; f++)
                        {
                            if (f == m-1)
                            {
                                for (int col = 0; col < elements; col++)
                                {
                                    matrixGausB[f][col] = round(helpMatrixGausB[f-(m-1)][col]*10000000000)/10000000000;
                                }
                            }
                            else
                            {
                                for (int v = 0; v < elements; v++)
                                {
                                    matrixGausB[f][v] = round(helpMatrixGausB[f+1][v]*10000000000)/10000000000;
                                }
                            }
                        }
                    }
                    else
                    {
                        if (matrixGausB[rows+1][colsB] == 0)
                        {
                            for (int j = 0; j < elements; j++)
                            {
                                helpMatrixGausB[rows+1][j] = matrixGausB[rows+1][j] + zeroMatrix[j];
                            }
                        }
                        else
                        {
                            secondB = matrixGausB[rows+1][colsB];
                            y = (-secondB)/firstB;
                            for (int j = 0; j < elements; j++)
                            {
                                helpMatrixGausB[rows+1][j] = arrB[j]*y + matrixGausB[rows+1][j];
                            }
                        }
                    }
                }
            }
            if (foundB == 0 && i == elements-1)
            {
                cntB ++;
                for (int rows = 0; rows <= m-1; rows++)
                {
                    if (rows == m-1)
                    {
                        for (int f = 0; f < m; f++)
                        {
                            if (f == m-1)
                            {
                                for (int col = 0; col < elements; col++)
                                {
                                    matrixGausB[f][col] = round(helpMatrixGausB[f-(m-1)][col]*10000000000)/10000000000;
                                }
                            }
                            else
                            {
                                for (int v = 0; v < elements; v++)
                                {
                                    matrixGausB[f][v] = round(helpMatrixGausB[f+1][v]*10000000000)/10000000000;
                                }
                            }
                        }
                    }
                    else
                    {
                        for (int j = 0; j < elements; j++)
                        {
                            helpMatrixGausB[rows+1][j] = matrixGausB[rows+1][j] + zeroMatrix[j];
                        }
                    }
                }
            }

            if (foundB == 1)
            {
                foundB = 0;
                break;
            }
        }
    }

    double tryArrB[elements]; //array where we record current row of matrix
    double tryMatrixB[m-cntB][elements]; //help matrix
    int tryFoundB = 0; //variable which increases if it meet element which is not 0
    int placeB = 0; //position of number which we meet which is not 0

    for (int r = 0; r < m; r++)
    {
        for (int c = 0; c < elements; c++)
        {
            tryArrB[c] = matrixGausB[r][c];
        }

        for (int i = 0; i < elements; i++)
        {
            if (tryArrB[i] != 0)
            {
                tryFoundB++;
                for (int j = 0; j < elements; j++)
                {
                    tryMatrixB[placeB][j] = tryArrB[j];
                }
            }
            if (tryFoundB == 1)
            {
                tryFoundB = 0;
                placeB++;
                break;
            }
        }

        if (placeB == m-cntB)
        {
            break;
        }
    }


    double arrayForVectorsB[m-cntB][elements]; //matrix where we record independent vectors (without these wehich are 0)

    for (int r = 0; r < m-cntB; r++)
    {
        for (int c = 0; c < elements; c++)
        {
            arrayForVectorsB[r][c] = tryMatrixB[r][c];
        }
    }

    double matrixVectorsB[m-cntB][elements];
    double helpVectorsB[elements];
    double newArrB[elements] = {}; //zero array
    double savedB = 0;
    double b = 1; //parameter (if we need to use it)
    double sumB = 0;

    if (m-cntB < elements)
    {
        int positionArrB[elements] = {}; //zero array
        int savePositionB = 0; //variable which save positions

        for (int r = 0; r < m-cntB; r++)
        {
            for (int c = 0; c < elements; c++)
            {
                if (arrayForVectorsB[r][c] != 0)
                {
                    positionArrB[c] = c+1;
                    break;
                }
            }
        }

        for (int k = 0; k < elements; k++)
        {
            if (positionArrB[k] == 0)
            {
                for (int r = 0; r < m-cntB; r++)
                {
                    for (int c = 0; c < elements; c++)
                    {
                        helpVectorsB[c] = arrayForVectorsB[r][c];
                    }
                    for (int i = 0; i < elements; i++)
                    {
                        if (helpVectorsB[i] != 0)
                        {
                            savedB = helpVectorsB[i];
                            for (int j = i; j < elements-1; j++)
                            {
                                sumB += helpVectorsB[j+1];
                            }
                            helpVectorsB[i] = (-sumB)/savedB;
                            newArrB[i] = helpVectorsB[i];
                            sumB = 0;
                            break;
                        }
                    }
                }

                for (int pos = 0; pos < elements - k; pos++)
                {
                    if (positionArrB[pos+k] == newArrB[pos+k])
                    {
                        newArrB[pos+k] = b;
                    }
                }
                break;

            }
        }

        for (int k = 0; k < m-cntB; k++)
        {
            for (int s = 0; s < elements; s++)
            {
                matrixVectorsB[k][s] = newArrB[s]*b;
                if (matrixVectorsB[k][s] == -0)
                {
                    matrixVectorsB[k][s] = 0;
                }
            }
            b++;
        }

    }

    else
    {
        for (int r = 0; r < m-cntB; r++)
        {
            for (int c = 0; c < elements; c++)
            {
                matrixVectorsB[r][c] = arrayForVectorsB[r][c];
            }
        }
    }

    double finalMatrixGaus[n+m-cntB][elements];

    for (int r = 0; r < n+m-cntB; r++)
    {
        if (r < n)
        {
            for (int c = 0; c < elements; c++)
            {
                finalMatrixGaus[r][c] = matrixGausA[r][c];
                round(finalMatrixGaus[r][c]*10000000000)/10000000000;
            }
        }
        else
        {
            for (int c = 0; c < elements; c++)
            {
                finalMatrixGaus[r][c] = matrixVectorsB[r-n][c];
                round(finalMatrixGaus[r][c]*10000000000)/10000000000;
            }
        }
    }

    //same way with that difference that we don't use parameters

    double helpMatrixFinalGaus[n+m-cntB][elements];
    double finalArr[elements];
    int finalCnt = 0;
    int finalFound = 0;
    double finalFirst = 0;
    double finalSecond = 0;
    double finalX = 0;

    for (int r = 0; r < n+m-cntB; r++)
    {
        for (int c = 0; c < elements; c++)
        {
            helpMatrixFinalGaus[0][c] = finalMatrixGaus[0][c];
            finalArr[c] = finalMatrixGaus[0][c];
        }

        for (int i = 0; i < elements; i++)
        {
            if (finalArr[i] != 0)
            {
                finalFound++;
                finalFirst = finalArr[i];
                int finalCols = i;
                for (int rows = 0; rows <= n+m-cntB-1; rows++)
                {
                    if (rows == n+m-cntB-1)
                    {
                        for (int f = 0; f < n+m-cntB; f++)
                        {
                            if (f == n+m-cntB-1)
                            {
                                for (int col = 0; col < elements; col++)
                                {
                                    finalMatrixGaus[f][col] = round(helpMatrixFinalGaus[f-(n+m-cntB-1)][col]*10000000000)/10000000000;
                                }
                            }
                            else
                            {
                                for (int v = 0; v < elements; v++)
                                {
                                    finalMatrixGaus[f][v] = round(helpMatrixFinalGaus[f+1][v]*10000000000)/10000000000;
                                }
                            }
                        }
                    }
                    else
                    {
                        if (finalMatrixGaus[rows+1][finalCols] == 0)
                        {
                            for (int j = 0; j < elements; j++)
                            {
                                helpMatrixFinalGaus[rows+1][j] = finalMatrixGaus[rows+1][j] + zeroMatrix[j];
                            }
                        }
                        else
                        {
                            finalSecond = finalMatrixGaus[rows+1][finalCols];
                            finalX = (-finalSecond)/finalFirst;
                            for (int j = 0; j < elements; j++)
                            {
                                helpMatrixFinalGaus[rows+1][j] = finalArr[j]*finalX + finalMatrixGaus[rows+1][j];
                            }
                        }
                    }
                }
            }

            if (finalFound == 0 && i == elements-1)
            {
                finalCnt++;
                for (int rows = 0; rows <= n+m-cntB-1; rows++)
                {
                    if (rows == n+m-cntB-1)
                    {
                        for (int f = 0; f < n+m-cntB; f++)
                        {
                            if (f == n+m-cntB-1)
                            {
                                for (int col = 0; col < elements; col++)
                                {
                                    finalMatrixGaus[f][col] = round(helpMatrixFinalGaus[f-(n+m-cntB-1)][col]*10000000000)/10000000000;
                                }
                            }
                            else
                            {
                                for (int v = 0; v < elements; v++)
                                {
                                    finalMatrixGaus[f][v] = round(helpMatrixFinalGaus[f+1][v]*10000000000)/10000000000;
                                }
                            }
                        }
                    }
                    else
                    {
                        for (int j = 0; j < elements; j++)
                        {
                            helpMatrixFinalGaus[rows+1][j] = finalMatrixGaus[rows+1][j] + zeroMatrix[j];
                        }
                    }
                }
            }

            if (finalFound == 1)
            {
                finalFound = 0;
                break;
            }
        }
    }

    double tryFinalArr[elements];
    double tryFinalMatrix[n+m-cntB-finalCnt][elements];
    int tryFound = 0;
    int place = 0;

    for (int r = 0; r < n+m-cntB; r++)
    {
        for (int c = 0; c < elements; c++)
        {
            tryFinalArr[c] = finalMatrixGaus[r][c];
        }

        for (int i = 0; i < elements; i++)
        {
            if (tryFinalArr[i] != 0)
            {
                tryFound++;
                for (int j = 0; j < elements; j++)
                {
                    tryFinalMatrix[place][j] = tryFinalArr[j];
                }
            }
            if (tryFound == 1)
            {
                tryFound = 0;
                place++;
                break;
            }
        }

        if (place == n+m-cntB-finalCnt)
        {
            break;
        }
    }

    things = n+m-cntB-finalCnt;

    for (int r = 0; r < n+m-cntB-finalCnt; r++)
    {
        for (int c = 0; c < elements; c++)
        {
            arrayForFinalVectors[r][c] = tryFinalMatrix[r][c];
            if (arrayForFinalVectors[r][c] == - 0)
            {
                arrayForFinalVectors[r][c] = 0;
            }
        }
    }
}

int main()
{
    const int lengthB = 2; //this is m
    const int lengthA = 4; //this is n

    double vectorsA[lengthA][elements] = {2, 8, -3, 14,
                                          -1, 2, 3, 5,
                                          -1, 14, 6, 29,
                                          0, 12, 3, 24};

    double vectorsB[lengthB][elements] = {0, 1, 1, 0,
                                          10, 7, 0, -8};

    int things = 0;

    double answerBase[lengthA][elements];

    if (lengthA > 10 || lengthB > 10)
    {
        cout << "Too many vectors!";
        return 0;
    }

    for (int r = 0; r < lengthA; r++)
    {
        for (int c = 0; c < elements; c++)
        {
            if (vectorsA[r][c] > 500 || vectorsA[r][c] <-500)
            {
                cout << "Big element in vectors A!" << endl;
                return 0;
            }
        }
    }

    for (int r = 0; r < lengthB; r++)
    {
        for (int c = 0; c < elements; c++)
        {
            if (vectorsB[r][c] > 500 || vectorsB[r][c] < -500)
            {
                cout << "Big element in vectors B!" << endl;
                return 0;
            }
        }
    }

    cout << "VectorsA: " << endl;
    for (int r = 0; r < lengthA; r++)
    {
        cout << "a" << r+1 << ": ";
        for (int c = 0; c < elements; c++)
        {
            cout << vectorsA[r][c] << " ";
        }
        cout << endl;
    }

    cout << endl;

    cout << "VectorsB: " << endl;
    for (int r = 0; r < lengthB; r++)
    {
        cout << "b" << r+1 << ": ";
        for (int c = 0; c < elements; c++)
        {
            cout << vectorsB[r][c] << " ";
        }
        cout << endl;
    }

    cout << endl;

    FindTotalBase(vectorsA, vectorsB, lengthA, lengthB, answerBase, things);

    cout << "One total base: " << endl;

    for (int r = 0; r < things; r++)
    {
        for (int c = 0; c < elements; c++)
        {
            cout << answerBase[r][c] << " ";
        }
        cout << endl;
    }

    cout << endl;

    return 0;
}

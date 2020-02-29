/**
*
* Solution to homework assignment 3
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
#include <math.h>

using namespace std;

const int side = 3; //side of squared matrix
const int indexE = 5; //index before E matrix
const int indexAC = -3; //index before A trans and C

void SolveMatrixEquation (double matrixA[side][side], double matrixC[side][side], double transX[side][side], int& noDec, int& infinityDec)
{
    double matrixX[side][side];
    double transA[side][side]; //transposed A

    double matrixE[side][side]; //single matrix

    double matrixLeft[side][side]; //left matrix which we get from A+5E

    double matrixF[side][side]; //right matrix which we get from transA*C

    double helpMatrix[side]; //array where we record the row form transposed A in order to multiply with columns from matrix C

    double matrixRight[side][side]; //whole right matrix which we get from (-3)*transA*C

    double transMatrixLeft[side][side]; //transposed left matrix
    double transMatrixRight[side][side]; //transposed right matrix

    double matrixGaus[side][side*2]; //Gaus matrix

    double helpMatrixGaus[side][side*2]; //matrix where we work over rows and then we transfer them in Gaus matrix

    double arr[side*2]; //array where we record the row which we will work over from Gaus matrix
    double zeroMatrix[side*2] = {}; //zero array which we sum with row from Gaus matrix if that row doesn't need processing (if the number under "enclosed" number is 0)

    double newArr[side]; //array where we record row from Gaus matrix in order to see if we get the single matrix in the left side

    double first = 0; //"enclosed" number
    double second = 0; //number under "enclosed" number
    double x = 0; //number which we multiply with next row from Gaus matrix in order to work over it
    double cnt = 0; //variable which we use to save the multiplication transposed A and C

    int found = 0; //found number in Gaus matrix which is not 0

    double helper = 0; //number which we multiply final matrix in order to get single matrix in left side

    int point = 0; //variable which save how many times we meet a number which is not 1 - we use it in final step

    int meetZero1 = 0; //variable which save how many times we meet a number which is 0 in left side in Gaus matrix
    int meetZero2 = 0; //variable which save how many times we meet a number which is 0 in right side in Gaus matrix
    int detMatr = 0;

    for (int c = 0; c < side; c++)
    {
        for (int r = 0; r < side; r++)
        {
            transA[c][r] = matrixA[r][c];
        }
    }

    for (int r = 0; r < side; r++)
    {
        for (int c = 0; c < side; c++)
        {
            if (r == c)
            {
                matrixE[r][c] = 1;
            }
            else
            {
                matrixE[r][c] = 0;
            }
        }
    }

    for (int r = 0; r < side; r++)
    {
        for (int c = 0; c < side; c++)
        {
            matrixLeft[r][c] = indexE*matrixE[r][c] + matrixA[r][c];
        }
    }

    for (int r = 0; r < side; r++) //multiplication - transposed A with C
    {
        for (int c = 0; c < side; c++)
        {
            helpMatrix[c] = transA[r][c];
        }
        for (int i = 0; i < side; i++)
        {
            for (int j = 0; j < side; j++)
            {
                cnt += helpMatrix[j]*matrixC[j][i];
                if (j == side-1)
                {
                    matrixF[r][i] = cnt;
                    cnt = 0;
                }
            }
        }
    }

    for (int r = 0; r < side; r++) //multiply right matrix with (-3)
    {
        for (int c = 0; c < side; c++)
        {
            matrixRight[r][c] = indexAC*matrixF[r][c];
        }
    }

    for (int c = 0; c < side; c++)
    {
        for (int r = 0; r < side; r++)
        {
            transMatrixLeft[c][r] = matrixLeft[r][c];
        }
    }

    if (side == 3) //find transMatrixLeft determinant
    {
        if (transMatrixLeft[0][0]*transMatrixLeft[1][1]*transMatrixLeft[2][2] + transMatrixLeft[0][1]*transMatrixLeft[1][2]*transMatrixLeft[2][0] + transMatrixLeft[0][2]*transMatrixLeft[1][0]*transMatrixLeft[2][1] - transMatrixLeft[2][0]*transMatrixLeft[1][1]*transMatrixLeft[0][2] - transMatrixLeft[2][1]*transMatrixLeft[1][2]*transMatrixLeft[0][0] - transMatrixLeft[2][2]*transMatrixLeft[1][0]*transMatrixLeft[0][1] == 0)
        {
            detMatr ++;
        }
    }

    for (int c = 0; c < side; c++)
    {
        for (int r = 0; r < side; r++)
        {
            transMatrixRight[c][r] = matrixRight[r][c];
        }
    }

    for (int r = 0; r < side; r++) //first look of Gaus matrix
    {
        for (int c = 0; c < side*2; c++)
        {
            if (c < side)
            {
                matrixGaus[r][c] = transMatrixLeft[r][c];
            }
            else
            {
                matrixGaus[r][c] = transMatrixRight[r][c-side];
            }
        }
    }

    for (int r = 0; r < side; r++) //Gaus method
    {
        for (int c = 0; c < side*2; c++)
        {
            helpMatrixGaus[0][c] = matrixGaus[0][c];
            arr[c] = matrixGaus[0][c];
        }

        for (int i = 0; i < side; i++)
        {
            if (arr[i] != 0)
            {
                found++;
                first = arr[i];
                int cols = i;
                for (int rows = 0; rows <= side-1; rows++)
                {
                    if (rows == side-1)
                    {
                        for (int f = 0; f < side; f++)
                        {
                            if (f == side-1)
                            {
                                for (int col = 0; col < side*2; col++)
                                {
                                    matrixGaus[f][col] = round(helpMatrixGaus[f-(side-1)][col]*10)/10;
                                }
                            }
                            else
                            {
                                for (int v = 0; v < side*2; v++)
                                {
                                    matrixGaus[f][v] = round(helpMatrixGaus[f+1][v]*10)/10;
                                }
                            }
                        }
                    }
                    else
                    {
                        if (matrixGaus[rows+1][cols] == 0)
                        {
                            for (int j = 0; j < side*2; j++)
                            {
                                helpMatrixGaus[rows+1][j] = matrixGaus[rows+1][j] + zeroMatrix[j];
                            }
                        }
                        else
                        {
                            second = matrixGaus[rows+1][cols];
                            x = (-second)/first;
                            for (int j = 0; j < side*2; j++)
                            {
                                helpMatrixGaus[rows+1][j] = arr[j]*x + matrixGaus[rows+1][j];
                            }
                        }
                    }
                }
            }

            if (found == 1)
            {
                found = 0;
                break;
            }
        }
    }

    for (int r = 0; r < side; r++)
    {
        for (int c = 0; c < side; c++)
        {
            newArr[c] = matrixGaus[r][c];
        }
        for (int i = 0; i < side; i++)
        {
            if (newArr[i] != 1 && newArr[i] != 0)
            {
                point++;
                helper = 1/(newArr[i]);
                for (int cols = 0; cols < side*2; cols++)
                {
                    matrixGaus[r][cols]*= helper;
                }
            }
            if (point == 1)
            {
                point = 0;
                break;
            }
        }
    }

    for (int r = 0; r < side; r++)
    {
        for (int c = 0; c < side*2; c++)
        {
            round(matrixGaus[r][c]*10000000000)/10000000000;
        }
    }

    for (int r = 0; r < side; r++)
    {
        for (int c = 0; c < side*2; c++)
        {
            if (c < side && detMatr > 0)
            {
                if (matrixGaus[r][c] == 0)
                {
                    meetZero1++;
                }

                if (meetZero1 == side)
                {
                    for (int j = c+1; j < side*2; j++)
                    {
                        if (matrixGaus[r][j] == 0)
                        {
                            meetZero2++;
                        }

                        if (j == side*2 - 1)
                        {
                            if (meetZero2 < side)
                            {
                                noDec++;
                            }
                            if (meetZero2 == side)
                            {
                                infinityDec++;
                            }
                        }
                    }
                }
            }

            if (c >= side)
            {
                matrixX[r][c-side] = matrixGaus[r][c];
            }
        }
    }

    for (int rows = 0; rows < side; rows++)
    {
        for (int cols = 0; cols < side; cols++)
        {
            round(matrixX[rows][cols]*10000000000)/10000000000;
        }
    }

    for (int c = 0; c < side; c++)
    {
        for (int r = 0; r < side; r++)
        {
            transX[c][r] = matrixX[r][c];
            if (transX[c][r] == -0)
            {
                transX[c][r] = 0;
            }
            round(transX[c][r]*10000000000)/10000000000;
        }
    }
}

int main()
{
    double firstMatrixA[side][side] = {-4, 1, 1,
                                       1, -3, 2,
                                       1, 2, -4};

    double firstMatrixC[side][side] = {-1, -2, -2,
                                       -1, -3, -4,
                                       -1, -3, -5};

    double answerMatrixX[side][side];

    int noDecision = 0;
    int infinityDecision = 0;

    for (int r = 0; r < side; r++)
    {
        for (int c = 0; c < side; c++)
        {
            if (firstMatrixA[r][c] > 500 || firstMatrixA[r][c] < -500)
            {
                cout << "Big element in matrix A" << endl;
                return 0;
            }
        }
    }

    for (int r = 0; r < side; r++)
    {
        for (int c = 0; c < side; c++)
        {
            if (firstMatrixC[r][c] > 500 || firstMatrixC[r][c] < -500)
            {
                cout << "Big element in matrix C" << endl;
                return 0;
            }
        }
    }

    cout << "Equation: X*A = (-3)*A(transposed)*C - 5*X" << endl << endl;
    cout << "Matrix A: " << endl;

    for (int rows = 0; rows < side; rows++)
    {
        for (int cols = 0; cols < side; cols++)
        {
            cout << firstMatrixA[rows][cols] << " ";
        }
        cout << endl;
    }

    cout << endl;

    cout << "Matrix C: " << endl;

    for (int rows = 0; rows < side; rows++)
    {
        for (int cols = 0; cols < side; cols++)
        {
            cout << firstMatrixC[rows][cols] << " ";
        }
        cout << endl;
    }

    cout << endl;

    SolveMatrixEquation(firstMatrixA, firstMatrixC, answerMatrixX, noDecision, infinityDecision);

    if (noDecision > 0)
    {
        cout << "No decision!" << endl;
        return 0;
    }

    if (infinityDecision > 0)
    {
        cout << "Infinity decisions!" << endl;
        return 0;
    }

    cout << "Matrix X: " << endl;

    for (int r = 0; r < side; r++)
    {
        for (int c = 0; c < side; c++)
        {
            cout << round(answerMatrixX[r][c]*10000000000)/10000000000 << " ";
        }
        cout << endl;
    }

    return 0;
}



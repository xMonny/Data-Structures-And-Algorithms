#include <iostream>
#include <string>
#include <windows.h>
#include <math.h>
#include <stdio.h>

/** Solution for XA = C (squared matrix) */

using namespace std;

int main()
{
    //for example
    /*float matrixA[side][side] = {1, 3, 3,
                                 3, 8, 6,
                                 3, 6, 1};

    float matrixC[side][side] = {-20, -57, -50,
                                 -32, -73, -33,
                                 -18, -40, -17};*/

    cout << "Equation: XA = C" << endl;

    int side;

    cout << "Input side for square matrices: ";
    cin >> side;

    cout << "Input matrix A: " << endl;

    float matrixA[side][side];
    float matrixC[side][side];

    float numberIn;

    for (int i = 0; i < side; i++)
    {
        for (int j = 0; j < side; j++)
        {
            cin >> numberIn;
            matrixA[i][j] = numberIn;
        }
    }

    cout << endl << "Input matrix C: " << endl;

    for (int i = 0; i < side; i++)
    {
        for (int j = 0; j < side; j++)
        {
            cin >> numberIn;
            matrixC[i][j] = numberIn;
        }
    }

    cout << endl;

    float matrixX[side][side]; //searched matrix

    float transA[side][side]; //transposed A
    float transC[side][side]; //transposed C
    float transX[side][side]; // transposed of the searched matrix
    float matrixE[side][side]; //unit matrix

    float matrixGaus[side][side*2]; //Gauss matrix

    float helpMatrixGaus[side][side*2]; //matrix where we change the rows and then we put this matrix in the Gaus matrix

    float arr[side*2]; //array where we will record the row which is processed from Gauss matrix
    float zeroMatrix[side*2] = {}; //array where we will sum it with row from Gauss matrix if this row from Gauss matrix doesn't need processing
                                  //(if the number under the "circled"one is 0)

    float newArr[side]; //array where we will record a row from Gauss matrix in order to see if in the left side is the unit matrix

    float first = 0; //"circled" number
    float second = 0; //the number under the "circled"
    float multiply = 0; //number which we multiply with the next row from Gauss matrix in order to do elementary transformation

    int found = 0; //found number from Gauss matrix which is not 0

    float helper = 0; //number which we multiply in the end with the matrix in order to get the unit matrix in the left side

    int point = 0; //a variable which counts how many times we have met a number, which is not 1 -> this is for the end

    for (int c = 0; c < side; c++)
    {
        for (int r = 0; r < side; r++)
        {
            transA[c][r] = matrixA[r][c];
        }
    }

    for (int c = 0; c < side; c++)
    {
        for (int r = 0; r < side; r++)
        {
            transC[c][r] = matrixC[r][c];
        }
    }

     for (int r = 0; r < side; r++) //we get the first kind of Gauss matrix
     {
         for (int c = 0; c < side*2; c++)
         {
            if (c < side)
            {
                matrixGaus[r][c] = matrixA[r][c];
            }
            else
            {
                matrixGaus[r][c] = matrixC[r][c-side];
            }
            cout << matrixGaus[r][c] << " ";
        }
        cout << endl;
     }

     cout << endl;

     for (int r = 0; r < side; r++) //Gauss method
     {
        for (int c = 0; c < side*2; c++)
        {
            helpMatrixGaus[0][c] = matrixGaus[0][c]; //record in help matrix the first row of Gauss matrix
            arr[c] = matrixGaus[0][c]; //record in help array the first row of Gauss matrix
        }

        for (int i = 0; i < side; i++) //we crawl as many times as the size of the first square matrices -> we have for example 1 0 1 ..., we search
                                      //among the first 3 numbers for something that is not 0 so that we can do elementary transformations
        {
            if (arr[i] != 0) //if any found number is not 0
            {
                found++; //increase the number of the meetings if the number is not 0
                first = arr[i]; //we record the found number (like in algebra's exercises - we circle the number)
                int cols = i; //we write down the number of the column in which we have met the number, so that we can then see how much we have to
                //multiply the lower rows, so that by adding them to the upper one, the lower number below the one becomes 0
                for (int rows = 0; rows <= side-1; rows++)
                {
                    if (rows == side-1) //if we are in the last row
                    {
                        for (int f = 0; f < side; f++) //we crawl as much as the dimension of the above square matrices
                        {
                            if (f == side-1) //if we are in the last ro
                            {
                                for (int col = 0; col < side*2; col++)
                                {
                                    matrixGaus[f][col] = round(helpMatrixGaus[f-(side-1)][col]*10)/10;
                                    // the last row of the Gaussian matrix becomes equal to the first row of the auxiliary matrix
                                    //(we do this in order to make the crawled rows last and the necessary rows higher so that we can crawl all the
                                    //rows and thus the first one the row, as it was last, will be the first again, and so we will receive on the left
                                    //the single matrix, and on the right the searched matrix, which we have to transpose)
                                }
                            }
                            else //if we are not on the last row
                            {
                                for (int v = 0; v < side*2; v++)
                                {
                                    matrixGaus[f][v] = round(helpMatrixGaus[f+1][v]*10)/10;
                                    //The Gaussian matrix accepts the rows from the auxiliary matrix, the second row making it the first, the third
                                   //for the second, etc.
                                }
                            }
                        }
                    }
                    else
                    {
                        if (matrixGaus[rows+1][cols] == 0) //if the number below the met one is 0
                        {
                            for (int j = 0; j < side*2; j++)
                            {
                                helpMatrixGaus[rows+1][j] = matrixGaus[rows+1][j] + zeroMatrix[j];
                                //the next row of the auxiliary matrix becomes equal to the null matrix collected with the next row of Gaussian
                                //(we keep the row of Gaussian, we have nothing to change)
                            }
                        }
                        else
                        {
                            second = matrixGaus[rows+1][cols]; //we record the number below the met one
                            multiply = (-second)/first; //we find by how much we have to multiply the other order
                            for (int j = 0; j < side*2; j++)
                            {
                                helpMatrixGaus[rows+1][j] = arr[j]*multiply + matrixGaus[rows+1][j];
                                //the next row of the auxiliary matrix becomes equal to the first row that we have written in the auxiliary array,
                               //multiplied by the number found and summed by the next row of the Gaussian matrix
                            }
                        }
                    }
                }
            }
            if (found == 0 && i == side-1) //if no numbers are found that are not 0 and we have already crawled the entire row
            {
                cout << "No result!";
                return 0;
            }

            if (found == 1) //if such a number is found
            {
                found = 0; //we reset the number of occurrences so that we can then use it for the next rows
                break;
            }
        }
    }

    for (int r = 0; r < side; r++) //we crawl the entire matrix as many times as the dimension of the squares
    {
        for (int c = 0; c < side; c++)
        {
            newArr[c] = matrixGaus[r][c]; //we write in another auxiliary array the current row of the Gaussian matrix of as many elements as the dimension
        }
        for (int i = 0; i < side; i++) //we crawl the recorded elements
        {
            if (newArr[i] != 1 && newArr[i] != 0) //if we meet an element that is not 1 and that is not 0
            {
                point++; //increase the counter
                helper = 1/(newArr[i]); //we find a number by which to multiply this order to get the unit matrix on the left
                for (int cols = 0; cols < side*2; cols++)
                {
                    matrixGaus[r][cols]*= helper; //we multiply the whole Gaussian row by this number to get a left square matrix
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
            cout << round(matrixGaus[r][c]*10)/10 << " ";
        }
        cout << endl;
    }

    cout << endl;

    for (int r = 0; r < side; r++)
    {
        for (int c = 0; c < side*2; c++)
        {
            if (c >= side)
            {
                matrixX[r][c-side] = matrixGaus[r][c]; //minus the right matrix
            }
        }
    }

    for (int rows = 0; rows < side; rows++)
    {
        for (int cols = 0; cols < side; cols++)
        {
            if (matrixX[rows][cols] == -0)
            {
                matrixX[rows][cols] = 0;
            }
            cout << round(matrixX[rows][cols]*10)/10 << " ";
        }
        cout << endl;
    }

    cout << endl;

    cout << "Matrix X: " << endl;

    for (int c = 0; c < side; c++)
    {
        for (int r = 0; r < side; r++)
        {
            transX[c][r] = matrixX[r][c];
            cout << round(transX[c][r]*10)/10 << " "; //transpose the right matrix in order to get the right answer of this equation
        }
        cout << endl;
    }

    return 0;
}

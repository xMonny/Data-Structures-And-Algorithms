#include <iostream>

using namespace std;

void mergeAll(int arr[], int startTime[], long l, long m, long r)
{
   long i, j, k;
   long n1 = m-l+1;
   long n2 = r-m;

   int* L = new int[n1];
   int* R = new int[n2];
   int* Answer1 = new int[n1];
   int* Answer2 = new int[n2];

   for (i = 0; i < n1; i++)
   {
       L[i] = arr[i+l];
       Answer1[i] = startTime[i+l];
   }
   for (j = 0; j < n2; j++)
   {
       R[j] = arr[j+m+1];
       Answer2[j] = startTime[j+m+1];
   }
   i = 0;
   j = 0;
   k = l;
   while (i < n1 && j < n2)
   {
       if (L[i] <= R[j])
       {
           arr[k] = L[i];
           startTime[k] = Answer1[i];
           i++;
       }
       else
       {
           arr[k] = R[j];
           startTime[k] = Answer2[j];
           j++;
       }
       k++;
   }
   while (i < n1)
   {
       arr[k] = L[i];
       startTime[k] = Answer1[i];
       i++;
       k++;
   }
   while (j < n2)
   {
       arr[k] = R[j];
       startTime[k] = Answer2[j];
       j++;
       k++;
   }

   delete[] L;
   delete[] R;
   delete[] Answer1;
   delete[] Answer2;
}
void mergeSort(int arr[], int startTime[], long l, long r)
{
   if (l < r)
   {
       long m = l+(r-l)/2;
       mergeSort(arr, startTime, l, m);
       mergeSort(arr, startTime, m+1, r);
       mergeAll(arr, startTime, l, m, r);
   }
}
int main()
{
   long N;
   long cnt = 1;
   cin >> N;

   if (N == 0)
   {
       cout << 0;
       return 0;
   }

   int* startTime = new int[N];
   int* time = new int[N];
   int* endTime = new int[N];

   int Bi, Ti;

   for (long i = 0; i < N; i++)
   {
       cin >> Bi >> Ti;
       startTime[i] = Bi;
       time[i] = Ti;
       endTime[i] = startTime[i]+time[i];
   }

   mergeSort(endTime, startTime, 0, N-1);

   long miss = 0;

   for (int i = 0; i < N; i++)
   {
       for (int j = 1; j < N; j++)
       {
            if (startTime[i] == startTime[j])
            {
                if (endTime[i] == endTime[j])
                {
                    miss++;
                }
                else
                {
                    if (endTime[i] < endTime[j] && endTime[i] <= startTime[j])
                    {
                        cnt++;
                        i+=miss+1;
                        miss = 0;
                    }
                    else
                    {
                        miss++;
                    }
                }

            }
            else
            {
                if (startTime[i] < startTime[j] && endTime[i] <= startTime[j])
                {
                    cnt++;
                    i+=miss+1;
                    miss = 0;
                }
                else
                {
                    miss++;
                }
            }
       }
       break;
   }

   cout << cnt;

   delete[] startTime;
   delete[] time;
   delete[] endTime;

   return 0;
}

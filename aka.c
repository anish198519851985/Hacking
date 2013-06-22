/*
 ============================================================================
 Author         : James Chen
 Email          : a.james.chen@gmail.com
 Description    : Remove duplicates from array of prime numbers
 Created Data   : 15-06-2013 
 Last Modified  :
 ============================================================================
 */

#include <iostream>
#include <iomanip>
#include <iterator>
#include <algorithm>
using namespace std;

void RemoveDuplicatePrimes(int* arr, int& len)
{
    int *pArr(arr);
    long long product(1);
    int uniqueLen(-1);;

    while(pArr < arr + len){
        if(product % *pArr != 0){
            uniqueLen ++;
            arr[uniqueLen] = *pArr;
            product *= *pArr;
        }

        pArr ++;
    }

    len = uniqueLen + 1;
}

int main(int argc, char* argv[])
{
    int testCases[] = {13, 59, 23, 47, 3, 59, 53, 13, 19, 23, 3, 7 };
    cout << "The prime number array is" << endl;
    int len = sizeof(testCases) / sizeof(testCases[0]);
    copy(testCases, testCases + len, ostream_iterator<int>(cout, " "));
    cout << endl;
    
    RemoveDuplicatePrimes(testCases, len);

    cout << "After remove duplicates" << endl;
    copy(testCases, testCases + len, ostream_iterator<int>(cout, " "));
    cout << endl;
 return 0;
}

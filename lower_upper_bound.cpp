#include <bits/stdc++.h>
using namespace std;

/*
     ONLY WORKS FOR SORTED ARRAYS(VECTORS). IT ALSO WORKS FOR SETS.

     TO CHECK OUT OF BOUNDS YOU CAN DO ONE THING. 
     HANDLE TWO CASES MANUALLY. ONE WHEN THE ELEMENT IS THE SMALLEST AND YOU ARE TRYING TO 
     FIND THE ATMOST ELEMENT FOR IT. SECOND WHEN THE ELEMENT IS THE LARGEST AND YOU ARE TRYING 
     TO FIND THE ATLEST OR GREATER ELEMENT FOR IT.
*/

int atleast(int n, vector<int> array){
     int val = lower_bound(array.begin(), array.end(), n) - array.begin();
     if(val >= array.size() || val < 0){
          cout << "the index is outside the range";
          return val;
     }
     else
          return array[val];
}

int smallestElementGreaterThan(int n, vector<int> array){
     int val = upper_bound(array.begin(), array.end(), n) - array.begin();
     if(val >= array.size() || val < 0){
          cout << "the index is outside the range";
          return val;
     }
     else
          return array[val];
}

int atmost(int n, vector<int> array){
     int ub = upper_bound(array.begin(), array.end(), n) - array.begin();
     int lb = lower_bound(array.begin(), array.end(), n) - array.begin();
     if(ub == lb){
          cout << lb-1 << endl;
          return array[lb-1];
     }
     else{
          cout << lb << endl;
          return array[lb];
     }
}

int largestElementSmallerThan(int n, vector<int> array){
     int lb = lower_bound(array.begin(), array.end(), n) - array.begin();
     cout << lb-1 << endl;
     return array[lb-1];
     
     // this would have worked if the container would have been a set
     // auto lb = array.lower_bound(n);
     // lb--;
     // return *lb;
}

int main()
{
     vector<int> array = {1, 2, 4, 5, 6, 7};
     sort(array.begin(), array.end());
     cout << largestElementSmallerThan(2, array);
     
     // set<int> array;
     // array.insert(1);
     // array.insert(2);
     // array.insert(4);
     // array.insert(5);
     // array.insert(6);
     // array.insert(7);


     // for(auto x:array)
     //      cout << x << " ";
     // cout << endl;

     // int res = upper_bound(array.begin(), array.end(), 3) - array.begin();
     // int res = lower_bound(array.begin(), array.end(), 3) - array.begin();
     // int res = lower_bound(array.begin(), array.end(), 4) - array.begin();

     
     // for finding the atmost value:
     // int ub = upper_bound(array.begin(), array.end(), 5) - array.begin();
     // int lb = lower_bound(array.begin(), array.end(), 5) - array.begin();
     // if(ub == lb){
     //      ub = lb = lb-1;
     //      cout << array[lb] << " " << array[ub] << endl;
     // }
     // else{
     //      ub = lb-1;
     //      lb = lb;  
     //      cout << array[lb] << " " << array[ub] << endl;
     // }

     return 0;
}

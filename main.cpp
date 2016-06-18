//
//  main.cpp
//  Merge_Sort Project
//

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

template <typename InputIterator, typename OutputIterator>
void mymerge(InputIterator a_cur, InputIterator a_end,
        InputIterator b_cur, InputIterator b_end, OutputIterator output) {

   //while a and b still have something left
   //pick the smaller one and *output it
   //This is cool because you can use iterator(well, technically pointers) to tell when should
      // merge things
   while (a_cur != a_end && b_cur != b_end) {
      if(*a_cur < *b_cur){
         *output = *a_cur;
         ++a_cur;
      } else {
         *output = *b_cur;
         ++b_cur;
      }
      ++output;
   }

   // while a has something left, output it
   while (a_cur != a_end) {
      *output = *a_cur;
      ++a_cur;
      ++output;
   }

   while (b_cur != b_end) {
      *output = *b_cur;
      ++b_cur;
      ++output;
   }
}

template <typename T>
void merge_sort(vector<T>& vec, int low, int high) {
   // basically all sort algorithms are recursions
   // so it needs a base case and general case

   // base case in this case
   if (high - low <= 1) {
      return;
   }
   // general case
   int middle = low +(high + low) / 2;
   // sort left half first then sort right half of vec from low to high
   merge_sort(vec, low, middle);
   merge_sort(vec, middle, high);
   // up to here, all elements reach base case then we can do shits from now
      // which is merge
   vector<T> temp(high - low);
   mymerge(vec.begin() + low, vec.begin() + middle, vec.begin() + middle,
      vec.begin() + high, temp.begin());
   //copy temp back into vec
   for (int j = 0; j < temp.size(); ++j) {
      vec[low + j] = temp[j];
   }
}

int main() {
   vector<int> a = {2, 3, 5, 7, 8};
   vector<int> b = {1, 2, 3, 7, 10};
   vector<int> merged(a.size()+ b.size());
   mymerge(a.begin(), a.end(), b.begin(), b.end(),merged.begin());
   for (const auto& x: merged)
      cout << x << ' ';
   cout << endl;
}
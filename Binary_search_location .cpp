#include <bits/stdc++.h>
using namespace std;
int main()
{
     int tes;
     cin >> tes;

     while(tes--)
     {
         int n;
         vector <int> vc;
         cin >> n;

         for(int i = 0; i < n; i++)
         {
             int k;
             cin >> k;
             vc.push_back(k);

         }
         pair <vector <int> ::iterator , vector <int> :: iterator> it;
         sort(vc.begin(), vc.end());
         if(binary_search(vc.begin() , vc.end() , 10) == true)
         {
             it = equal_range(vc.begin(), vc.end(), 10);

             cout<<(it.first - vc.begin()) + 1 << endl;
         }
         vc.clear();
     }
}

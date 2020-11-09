// First solution for "Three base station" problem
#include <bits/stdc++.h>
using namespace std;
#define ll long long
int n ;
ll x[1000005] , k ;
  bool check (double mid)
  {
       double y = x[0] + mid;
  int t = *upper_bound(x, x+n, y);
  if(!t) return 1;
  y = t + mid;
  t = *upper_bound(x, x+n, y);
  if(!t) return 1;
  y = t + mid;
  t = *upper_bound(x, x+n, y);
  if(!t) return 1;
 
  return 0 ;
  }
 
double bs()
 {
     double l = 0 , h = 1e9 , mid ;
    for (int i = 0 ; i < 999 ;i++){
            mid = (h+l)/2 ;
          if (check(mid)) h = mid ;
        else l = mid ;
     }
     return mid ;
 }
 
int main()
{
     scanf("%d" , &n) ;
     for (int i = 0 ; i < n ; i++)
       scanf("%l64d" , &x[i]) ;
     sort(x, x+n) ;
     if (n == 3){
        cout << 0 << endl ;
        for (int i = 0 ; i < n ; i++) cout << x[i] << ' ' ;
        return 0 ;
     }
   double ans = bs() ;
    double  ans1 = ans/2 ;
   printf("%.6lf \n" , ans1) ;
   double p1 = x[0] + ans1;
  double    p2 = *upper_bound(x, x+n, p1+ans1) + ans1;
   double    p3 =*upper_bound(x, x+n, p2+ans1) + ans1 ;
   printf("%.6lf  %.6lf  %.6lf " , p1,p2,p3) ;
}
 
-------------------------------------------------------------
 
// There is another solution that we did NOT discuss in the session 
 
#include <bits/stdc++.h>
using namespace std;
#define ll long long
int n ;
ll x[1000005] , k ;
  bool check (double mid){
       int i = 0 , p = 0 ;
       while(i < n ) {
         i = upper_bound (x ,x+n ,x[i]+mid) - x ;
          p++ ;
       }
       return p <= 3 ;
  }
 
double bs()
 {
     double l = 0 , h = 1e9 , mid ;
    for (int i = 0 ; i < 999 ;i++){
            mid = (h+l)/2 ;
          if (check(mid)) h = mid ;
        else l = mid ;
     }
     return mid ;
 }
 
int main()
{
     scanf("%d" , &n) ;
     for (int i = 0 ; i < n ; i++)
       scanf("%lld" , &x[i]) ;
     sort(x, x+n) ;
     if (n == 3){
        cout << 0 << endl ;
        for (int i = 0 ; i < n ; i++) cout << x[i] << ' ' ;
        return 0 ;
     }
   double ans = bs() ;
    double  ans1 = ans/2 ;
   printf("%.6lf \n" , ans1) ;
   double p1 = x[0] + ans1;
  double    p2 = *upper_bound(x, x+n, p1+ans1) + ans1;
   double    p3 =*upper_bound(x, x+n, p2+ans1) + ans1 ;
   printf("%.6lf  %.6lf  %.6lf " , p1,p2,p3) ;
}

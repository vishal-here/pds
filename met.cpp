#include<bits/stdc++.h> 
using namespace std ;
int main(){
    int n, m ;
    cout << "enter number of machines :  " ;
    cin >> n ;
    cout << "enter number of tasks :  " ;
    cin >> m ;
    
    int e[m][n]  ; 
    vector<int> time(n , 0)  ;
   
    cout << "enter execution time Matrix\n" ;
   
     for( int i = 0 ; i< m ; i++){
        for(int j = 0 ; j< n ; j++){
            cin >>  e[i][j] ;
        }
    }
     int ready[n]   ;
      cout << "enter initial ready time of machines : " ;
         for(int j =0 ; j < n ; j++){
        cin >> ready[j] ;
    }
  
    // algorithm 
 
 cout << "Tasks    Completion Time\tMachine\n" ; 

    int k =0 , i=0   ;
    while(k < m ){
        int  pos = 0 ;
        int min = e[k][0] ;
        for( i =0 ; i< n ; i++){
            if(e[k][i] <= min) {
              
                min = e[k][i]  ;
                pos = i ;
             }
        }

        cout << "T" << k+1 << " \t\t "  ; 
        ready[pos] += e[k][pos] ; 
        cout << ready[pos] << "s \t\t M" << pos+1  <<"\n";
        k++ ;
    }

}
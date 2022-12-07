#include<bits/stdc++.h> 
using namespace std ;
int main(){
    int n, m ;
    cout << "enter number of machines :  " ;
    cin >> n ;
    cout << "enter number of tasks :  " ;
    cin >> m ;
    
    int e[m][n]  , c[m][n]; 
    int ready[n]   ;
   
    cout << "enter execution time Matrix\n" ;
    for( int i = 0 ; i< m ; i++){
        for(int j = 0 ; j< n ; j++){
            cin >>  e[i][j] ;
        }
    }
    cout << "enter initial ready time of machines : " ;
    for(int j =0 ; j < n ; j++){
        cin >> ready[j] ;
    }

    // algorithm 
     for( int i = 0 ; i< m ; i++){
        for(int j = 0 ; j< n ; j++){
          c[i][j] = e[i][j] +  ready[j] ;  
        }
    }
    // while all the unscheduled tasks are exausted 
     cout << "Tasks    Completion Time\tMachine\n" ; 

    int k =0   , pos = 0;
    while(k < m ){
        int min =  e[k][0] +  ready[0] ;
        for(int i =0 ; i< n ; i++){
            if( e[k][i] +  ready[i] <= min) {
                 min =e[k][i] +  ready[i]  ;
                pos = i ;
             }
        }
        cout << "T" << k+1 ; 
        ready[pos] += e[k][pos] ;
        cout << "\t\t "<< ready[pos] << "\t\tM" << pos+1 << "\n"; 
        k++ ; 
    }

}

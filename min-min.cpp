
#include <limits.h>
#include <bits/stdc++.h>
using namespace std ;

int main(){

int nT,nM;//number of tasks , number of machines

cout << "\nEnter number of machines and tasks\n" ;
cin >> nT >> nM ;
/*
Declare a 2d-array of size nM x nT
Data should be in the following format :

T1 T2 T3
M1 | 140 | 20 | 60 |
M2 | 100 | 100 | 70 |

*/

int minMin[nM][nT];
int tmp[nM][nT];
int makespan=0;

cout << "\nFill Data\n" ;
for(int i=0;i<nM;i++)
for(int j=0;j<nT;j++){
    cin >> minMin[i][j] ;
    tmp[i][j]=minMin[i][j];
}

// visualise data

cout << "\nOriginal Data\n" ;
for(int i=0;i<nM;i++){
for(int j=0;j<nT;j++)
cout << minMin[i][j] << endl  ;

}

//This array will hold the answer
vector<int> resultTask(nT) ;
vector<int> resultMachine(nT) ;
vector<int> resultTime(nT) ;


// int resultTask[nT];
// int resultMachine[nT];
// int resultTime[nT];
int ptr=-1; //Indicates if result set is full or not

while(ptr< nT-1){
//int time[nT],machine[nT]; 
vector<int> time(nT) , machine(nT) ; //stores minimum time w.r.t machine of each task
for(int j=0;j<nT;j++){
int minimum = INT_MAX;
int pos=-1;
for(int i=0;i<nM;i++){
if(minMin[i][j]<minimum){
minimum=minMin[i][j];
pos=i;
}
}
time[j]=minimum;
machine[j]=pos;
}

// Now we find task with minimum time

int minimum= INT_MAX;
int pos=-1;

// for(int j=0;j<nT;j++){
// if(time[j]<minimum){
// minimum=time[j];
// pos=j;
// }
// }

minimum = *min_element(time.begin() , time.end()) ;
pos = min_element(time.begin() , time.end()) - time.begin() ;

resultTask[++ptr]=pos;
resultMachine[ptr]=machine[pos];
resultTime[ptr]=tmp[machine[pos]][pos];
if(minimum>makespan)
makespan=minimum;
// resetting states

for(int i=0;i<nM;i++){
for(int j=0;j<nT;j++){
if(j==resultTask[ptr])
minMin[i][j]=INT_MAX;
else if(i==resultMachine[ptr] && minMin[i][j]!=INT_MAX)
minMin[i][j]+=minimum;
else
continue;
}
}

}

//printing answer
// printf(“\nScheduled Task are :\n”);
// for(int i=0;i<nT;i++){
// printf(“\nTask %d Runs on Machine %d with Time %d units\n”,resultTask[i]+1,resultMachine[i]+1,resultTime[i]);
// }

cout << "\nScheduled Task are :\n" ;
cout << "\nTask \t Runs on Machine\tTime " ;
for(int i=0 ; i< nT ; i++)
cout << "\n " << resultTask[i]+1 << "\t\t" <<  resultMachine[i]+1 << "\t\t " << resultTime[i] ;

cout << "\nMakespan : " << makespan << "units\n" ;
return 0;
}
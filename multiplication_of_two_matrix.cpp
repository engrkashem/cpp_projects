#include<bits/stdc++.h>

using namespace std;

void printArray(int *ar, int m, int n){
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            cout<<*(ar+i*n+j)<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}

int main(){
    int a[3][3];
    int b[3][3];
    int c[3][3];

    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            cin>>a[i][j];
        }
    }
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            cin>>b[i][j];
        }
    }
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            int sum=0;
            for(int k=0; k<3; k++){
                sum+=a[i][k]*b[k][j];
            }
            c[i][j]=sum;
        }
    }

    printArray(*c, 3, 3);

return 0;
}

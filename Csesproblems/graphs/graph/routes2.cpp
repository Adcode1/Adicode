#include<bits/stdc++.h>
using namespace std;
using ll=long long;
#define N 100000000000000000
int main(){
int n;cin>>n;
int m;cin>>m;
int q;cin>>q;
	ll dist[n][n];
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			dist[i][j]=N;
		}
		dist[i][i]=0;
	}
	for(int i=0;i<m;i++){
		int a,b;
		ll c;
		cin>>a>>b>>c;
		if(dist[a-1][b-1]>c){
		dist[a-1][b-1]=c;
		dist[b-1][a-1]=c;
		}
	}
	for(int k=0;k<n;k++){
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				if(dist[i][k]!=N and dist[k][j]!=N){
				dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);			
				}
			}
		}		
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(dist[i][j]==N){
				dist[i][j]=-1;
			}
		}
	}
	for(int i=0;i<q;i++){
		int f,l;
		cin>>f>>l;
		cout << dist[f-1][l-1] <<endl;
	}

}




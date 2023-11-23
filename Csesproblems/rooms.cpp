#include<bits/stdc++.h>
using namespace std;
char arr[1001][1001];
bool vis[1001][1001];
vector<pair<int,int>> moves={{1,0},{-1,0},{0,1},{0,-1}};
bool isvalid(int x,int y,int r,int c){
	if(x<0 or x>=r or y<0 or y>=c){
		return false;
	}
	if(arr[x][y]=='#'){
		return false;
	}
	if(vis[x][y]==1){
		return false;
	}
	return true;
}
void dfs(int x,int y,int r,int c){
	vis[x][y]=1;
	for(auto p:moves){
		int nx=x+p.first;
		int ny=y+p.second;
		if(isvalid(nx,ny,r,c)){
		   dfs(nx,ny,r,c);
		}
	}	
}
int main(){
	int r;cin>>r;
	int c;cin>>c;	
	for(int i=0;i<r;i++){
		for(int j=0;j<c;j++){
	      		cin >>arr[i][j];
		}
	}
	int rooms=0;
	for(int i=0;i<r;i++){
		for(int j=0;j<c;j++){
			if(vis[i][j]==0 and arr[i][j]=='.'){
				rooms++;
				dfs(i,j,r,c);	
			}
		}
	}
	cout << rooms << endl;
}
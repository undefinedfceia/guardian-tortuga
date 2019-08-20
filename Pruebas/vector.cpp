#include <iostream>
#include <queue>
#include <vector>
using namespace std;
 
struct node{
	int i;
	int j;
};
 
void bfs(int i, int j, vector< vector<int> > &v){
 
	queue<node*> q;
 
	int n=v.size(), m=v[0].size(),row,col;
	node * temp = new node;
	temp->i=i;
	temp->j=j;
	q.push(temp);
	int currDist;
	while(!q.empty()){
 
		temp=q.front();
		currDist = v[temp->i][temp->j];
		row=temp->i;
		col=temp->j;
		q.pop();
 
		if(row>0){
			if(currDist+1<v[row-1][col]){
				v[row-1][col]=currDist+1;
				node * newNode = new node;
				newNode->i=row-1;
				newNode->j=col;
				q.push(newNode);
			}
		}
 
		if(col>0){
			if(currDist+1<v[row][col-1]){
				v[row][col-1]=currDist+1;
				node * newNode = new node;
				newNode->i=row;
				newNode->j=col-1;
				q.push(newNode);
			}
		}	
		if(row<n-1){
			if(currDist+1<v[row+1][col]){
				v[row+1][col]=currDist+1;
				node * newNode = new node;
				newNode->i=row+1;
				newNode->j=col;
				q.push(newNode);
			}
		}	
 
 
		if(col<m-1){
			if(currDist+1<v[row][col+1]){
				v[row][col+1]=currDist+1;
				node * newNode = new node;
				newNode->i=row;
				newNode->j=col+1;
				q.push(newNode);
			}
		}	
 
		delete (temp);	
	}
}
 
int main() {
	int t,n,m,temp;
	string s;
	vector< vector<int> > v;
	vector <int> row,col;
	cin>>t;
	while(t--){
		v.clear();
		row.clear();
		col.clear();
		cin>>n>>m;
		vector<int> maxVal(m,500);
		for(int i=0;i<n;i++){
			cin>>s;
			for(int j=0;j<m;j++){
				temp=s[j]-'0';
				if(temp==1){
					row.push_back(i);
					col.push_back(j);
				}
 
			}
			v.push_back(maxVal);
		}
 
 
		for(int i=0;i<(int)row.size();i++)
			v[row[i]][col[i]]=0;
 
		for(int c=0;c<(int)row.size();c++)
			bfs(row[c],col[c],v);
 
		for(int i=0;i<n;i++){
			cout<<v[i][0];
			for(int j=1;j<m;j++)
				cout<<" "<<v[i][j];
			cout<<endl;
 
		}	
	}
	return 0;
}

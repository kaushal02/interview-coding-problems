/*
Samsung Bangalore NIT Agartala 2019

There is one spaceship. X and Y co-odinate of source of spaceship and destination spaceship is given.
There are N number of warmholes; each warmhole has 5 values.
First 2 values are starting co-ordinate of warmhole and after that value no. 3 and 4 represents ending
co-ordinate of warmhole and last 5th value is represents cost to pass through this warmhole. 
Now these warmholes are bi-directional. Now the to go from (x1,y1) to (x2,y2) is abs(x1-x2)+abs(y1-y2).
The main problem here is to find minimum distance to reach spaceship from source to destination
co-ordinate using any number of warm-hole. 
It is ok if you wont use any warmhole.
*/

#include<iostream>
using namespace std;

int ans,mask[10],w[10][5],n;

int distance(int sx,int sy,int dx,int dy) {
	int xd=(sx>dx)?(sx-dx):(dx-sx);
	int yd=(sy>dy)?(sy-dy):(dy-sy);
	return (xd+yd);
}

void cal(int sx,int sy,int dx,int dy,int dis) {

	ans=min(ans,distance(sx,sy,dx,dy)+dis);
	
	for(int i=0;i<n;i++) {
		if(mask[i]==0) {
			mask[i]=1;
			int temp=distance(sx,sy,w[i][0],w[i][1])+dis+w[i][4];
			cal(w[i][2],w[i][3],dx,dy,temp);
			temp=distance(sx,sy,w[i][2],w[i][3])+dis+w[i][4];
			cal(w[i][0],w[i][1],dx,dy,temp);
			mask[i]=0;
		}
	}
}
int main() {
	int t,index=1;
	cin>>t;
	while(t--) {

		cin>>n;
		int sx,sy,dx,dy;
		cin>>sx>>sy>>dx>>dy;
		
		for(int i=0;i<n;i++) {
			mask[i]=0;
			for(int j=0;j<5;j++) {
				cin>>w[i][j];
			}
		}
		ans=999999;
		cal(sx,sy,dx,dy,0);
		cout<<"#"<<index<<" "<<ans<<endl;
		index++;
	}
	return 0;
}

#include <iostream>
#include <vector>
using namespace std;





void islandFind(int** M,int n,int m){
	
	struct point{
		int i=0;
		int j=0;
		bool left=false, right=false,up=false, down=false,flagEnd=false;
		void print(){
			cout<<"i:"<<i<<" j:"<<j<<" "
			<<endl
			<<"up    "<<up<<endl
			<<"down  "<<down<<endl
			<<"left  "<<left<<endl
			<<"right "<<right<<endl;
		}
		
	};
	vector<point> v_points;

	for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				if((int)M[i*m+j]){
					  //  cout<<"i:"<<i<<" j:"<<j<<" ";
					    point one;
					    one.i=i;
					    one.j=j;
					  if(i>0 && (int) M[(i-1)*n+j]){
//						cout<<"up one ";					
						one.up=true;
					} if(i<(n-1) && (int) M[(i+1)*n+j]){
//						cout<<"down one ";			
						one.down=true;						
					} if(j<(m-1) && (int) M[i*m+(j+1)]){
//						cout<<"right one ";
						one.right=true;
					} if(j>0 && (int) M[i*m+(j-1)]){
//						cout<<"left one ";
						one.left=true;
					}
					v_points.push_back(one);
				
				}
						
			}				
		
			cout<<endl;
	}
	
	size_t v_size_p=v_points.size();

	if(v_size_p){
		for(int i=0;i<v_size_p;i++){
			point local=v_points.at(i);			
			
				if(local.up){
					
					
				}if(local.down){
					
				}if(local.left){
					
				}if(local.right){
					
				}
			
			
			
			
		}			
	}
}


int main(int argc, char** argv) {
	
	int M[5][5]={
	{0,0,0,1,0	},
	{0,0,1,1,1	},
	{0,1,0,1,0	},
	{1,0,1,0,0	},
	{0,0,0,0,0	}
	};
	
	
	islandFind((int**)M,5,5);
	
	return 0;
}

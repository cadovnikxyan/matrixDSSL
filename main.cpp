#include <iostream>
#include <vector>

using namespace std;

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
	

void isIsland(vector<point>* vector, int i_){
	
		int i=i_;
				
			if(i_!=vector.size()){
			
			point local=vector->at(i);			
			
				if(local.up){					
					isIsland(vector,i++);
				}if(local.down){
					isIsland(vector,i++);
				}if(local.left){
					isIsland(vector,i++);
				}if(local.right){
					isIsland(vector,i++);
				}	
			}
			
					
}



void islandFind(int** M,int n,int m){
	
	vector<point> v_points;

	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if((int)M[i*m+j]){					  
				    point one;
				    one.i=i;
				    one.j=j;
				    
				  if(i>0 && (int) M[(i-1)*n+j]){											
					one.up=true;
				} if(i<(n-1) && (int) M[(i+1)*n+j]){			
					one.down=true;						
				} if(j<(m-1) && (int) M[i*m+(j+1)]){
					one.right=true;
				} if(j>0 && (int) M[i*m+(j-1)]){
					one.left=true;
				}
				v_points.push_back(one);
			
			}					
		}				
	}
	isIsland(&v_points,0);	
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

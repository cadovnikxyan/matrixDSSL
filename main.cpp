#include <iostream>
#include <vector>

using namespace std;

	struct point{
		int i=0;
		int j=0;
		bool falgs[4]={0,0,0,0};
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
	
bool isIsland(int** M,int i, int j,int n, int m){
	
	int up=i-1;
	int down=i+1;
	int left=j-1;
	int rignt=j+1;
	
	int vi[4]={up,down, i ,  i  };
	int vj[4]={j,  j, left,right};
	
	
	  		  if(i>0 && (int) M[(i-1)*n+j]){											

					if(isIsland(M,vi[0],vj[0],n,m)){
						
					}
				} if(i<(n-1) && (int) M[(i+1)*n+j]){			

					if(isIsland(M,vi[1],vj[1],n,m)){
						
					}	
					
				} if(j>0 && (int) M[i*m+(j-1)]){

					if(isIsland(M,vi[2],vj[2],n,m)){
						
					}
					
				} if(j<(m-1) && (int) M[i*m+(j+1)]){

					if(isIsland(M,vi[3],vj[3],n,m)){
						
					}
				}
			
}





vector<point> v_points;
vector<point> savePoint;

	
void islandFind(int** M,int n,int m ){
	
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if((int)M[i*m+j]){					  
				    point one;
				    one.i=i;
				    one.j=j;
				    isIsland(M,i,j,n,m,&one);			
					v_points.push_back(one);			
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

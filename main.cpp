#include <iostream>
#include <vector>

using namespace std;

	struct point{
		int i=0;
		int j=0;
		void print(){
			cout<<"i:"<<i<<" j:"<<j<<" "
			<<endl;		
			}				
	};
	
static vector<point> save;
	
	bool isSave(vector<point>* _save,point one_){
		bool finded=false;
		for(int i=0;i<_save->size();i++){
			point b=_save->at(i);
			if((b.i==one_.i)&&(b.j==one_.j)){
				finded = true;	
			};
		}
		return finded;
	}
	
	
void isIsland(int** M,int i, int j,int n, int m, int* S){
				
			point one;
			one.i=i;
			one.j=j;
			if(isSave(&save,one)){

				return;
			}
	
	
		if(i>0 && (int) M[(i-1)*n+j]){
			save.push_back(one);
//			cout<<endl<<"i:"<<i+1<<" j:"<<j+1<<" "<<"up"<<"  "<<*S;
			isIsland(M,i-1,j,n,m,S);	
		}
		
		if(i<(n-1) && (int) M[(i+1)*n+j]){
			save.push_back(one);
//			cout<<endl<<"i:"<<i+1<<" j:"<<j+1<<" "<<"down"<<"  "<<*S;
			isIsland(M,i+1,j,n,m,S);			
			
		}
		
		if(j>0 && (int) M[i*m+(j-1)]){
			save.push_back(one);
//			cout<<endl<<"i:"<<i+1<<" j:"<<j+1<<" "<<"left"<<"  "<<*S;
			isIsland(M,i,j-1,n,m,S);			

		}
		
		if(j<(m-1) && (int) M[i*m+(j+1)])	{
			save.push_back(one);
//			cout<<endl<<"i:"<<i+1<<" j:"<<j+1<<" "<<"right"<<"  "<<*S;
			isIsland(M,i,j+1,n,m,S);			
		}
			(*S)++;
	
}



void islandFind(int** M,int n,int m ){
	
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){		
			if((int)M[i*m+j]){
			point one;
			one.i=i;
			one.j=j;
			
			if(!isSave(&save,one)){
					int s=0;
					
					cout<<endl<<"island start in point: "<<"i:"<<i+1<<" j:"<<j+1<<" ";	
					cout<<endl<<"---------------------";				  				    
				    isIsland(M,i,j,n,m,&s);
					cout<<endl<<"island area = : "<<s;
					cout<<endl<<"---------------------"<<endl;	
																
				}
			}					
		}				
	}	
}




int main(int argc, char** argv) {
	
	int M[5][5]={
					{0,0,1,1,1	},
					{0,0,0,1,1	},
					{1,0,0,0,1	},
					{1,0,0,0,0	},
					{0,0,1,0,0	}
	};
	
	islandFind((int**)M,5,5);


	

	
	return 0;
}

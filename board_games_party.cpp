#include <iostream>
#include <string> 
#include <vector>
#include <map>
#include <cstring>
#include <algorithm>
#include<sstream>
using namespace std;

string getss(int n){
	
	std::stringstream ss;
    ss << n;
    string str = ss.str();
    return str;
}
vector<string>temp1;
vector<vector<string> >canwesit;
vector<vector<string> >youcansit;
vector<vector<string> >youcansit2;

int main(){
	
int siz;
	cin>>siz;
	//a�a��da sandalye s�ras�na g�re o sandalyeye oturabilecek ki�ileri 
	//numaras� ile vekt�re koyuyoyuz
	for(int i=0;i<siz;i++){
		temp1.push_back(getss(i+1));
		if(i==0){
			temp1.push_back(getss(i+2));
			temp1.push_back(getss(siz));
		}
		else if(i==(siz-1)){
			temp1.push_back(getss(i));
			temp1.push_back(getss(1));
		}
		else{
			temp1.push_back(getss(i+2));
			temp1.push_back(getss(i));
		}
		canwesit.push_back(temp1);
		temp1.clear();
	}
	//iki boyutlu bir vekt�re ilk �� eleman�n� ilk sandalyeye oturabilecek 
	//ki�ileri yerle�tiriyoruz
	for(int i=0;i<3;i++){
		temp1.push_back(canwesit[0][i]);
		youcansit.push_back(temp1);
		temp1.clear();
	}
	//burada ise s�ras� ile di�er sandalyeye oturabilecek ki�ileri �nceki vekt�r�n herbirine 
	//ekliyor ve t�m ihtimalleri yazm�� oluyoruz
	for(int i=1;i<siz;i++){
		for(int j=0;j<3;j++){
			for(int k=0;k<youcansit.size();k++){
				bool door=true;
				for(int  n=0;n<youcansit[k].size();n++){
					if(youcansit[k][n]==canwesit[i][j]){
						door=false;
					}
				}
				if(door){
				    youcansit[k].push_back(canwesit[i][j]);
				    youcansit2.push_back(youcansit[k]);
				    youcansit[k].pop_back();
				}			
			}
		}
		youcansit=youcansit2;
		youcansit2.clear();
	}
	cout<<youcansit.size()<<" farkli sekilde oturabilirler...\n";
    for(int i=0;i<youcansit.size();i++){
		for(int j=0;j<youcansit[i].size();j++){
			cout<<youcansit[i][j]<<" ";
		}
		cout<<endl;
	}
	
	return 0;
}




  



#include<iostream>
#include<string>
#include<fstream>

using namespace std;
int main(){
    string inp,fileName;
    cout<<"enter the filename\n";
    cin>>fileName;
    cout<<"enter the query to be searched\n";
    //cin>>inp;
    cin.ignore();
    getline(cin,inp);

    ifstream inFile(fileName);
    
    string line;
    int i=0;
    while(getline(inFile,line)){
        i++;
        if(line.find(inp)!=string::npos){
            cout<<"line-"<<i<<": ' "<<line<<" ' "<<endl;
        }
    }

    inFile.close();
    return 0;
}
#include<iostream>
#include<string>
#include<fstream>

using namespace std;
int comp = 0;
bool myFind(string line, string query){
    for (int i=0;line[i]!='\0';i++){
        if(query[0] == line[i]){
            comp++;
            for(int j=1;query[j]!='\0'&&line[i+j]!='\0';j++){
                comp++;
                if(query[j]!=line[i+j]){
                    break;
                }
                else if(j==query.length()-1){
                    return true;
                }

            }
        }
    }
    return false;
}


int main()
{
    string fileName,inp;
    cout<<"enter file name to be searched\n";
    cin>>fileName;
    cout<<"enter the query to be searched\n";
    cin.ignore();
    getline(cin,inp);

    ifstream inFile(fileName);
    string line;
    int i=0;
    while(getline(inFile,line)){
        i++;
        if(myFind(line,inp)==true){
            cout<<"line-"<<i<<" '"<<line<<"'"<<endl;
        }
    }
    cout<<"no of comparisions:"<<comp<<endl;
    inFile.close();
    return 0;
}


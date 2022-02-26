#include <iostream>
#include <fstream>
#include <string>
using namespace std;
bool logged(){
    string uname, pword, un, pw;
    cout<<"enter user name: ";
    cin>>uname;
    cout<<"password: ";
    cin>>pword;
    ifstream read("data"+uname+".txt");
    getline(read, un);
    getline(read, pw);
    if(un==uname && pw==pword){
        return true;
    }
    else{
        return false;
    }
}
    int main(){
        int cho;
        cout<<"1: Register new user\n2Login\nEnter your choice: ";
        cin>>cho;
        if (cho==1){
            string uname, pword;
            cout<<"enter username: ";
            cin>>uname;
            cout<<"enter password: ";
            cin>>pword;
            ofstream file;
            file.open("data"+uname+".txt");
            file<<uname<<endl<<pword;
            file.close();
            main();
        }
        else if (cho==2){
            bool status=logged();
            if (!status){
                cout<<"false login"<<endl;
                return 0;
            }
            else{
                cout<<"login successful"<<endl;
                return 1;
            }
        }
    }
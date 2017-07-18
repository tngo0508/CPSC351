#include <iostream>
#include <cstring>
#include <fstream>
#include <cstdlib>
#include <unistd.h>
#include <sys/wait.h>
#include <vector>
using namespace std;


// compile & run
// g++ serial_download.cpp -o Serial
// time ./Serial urls.txt




vector<string> urls;
int count = 0 ;

void load_urls(){
    string urlline;
    ifstream reader("urls.txt");
    if (!reader.is_open()){
        cout <<" fail to open the urls.txt file\n";
        exit (1);
    }
    while (!reader.eof())
    {
        reader >>urlline;
        urls.push_back(urlline);
        count++;
        
    }
    reader.close();
}
void create_child(){
    pid_t pid;
    for ( int i = 1 ; i < count; i++){
        pid = fork();
        if ( pid < 0 ){
            cerr <<"cannot fork";
            exit (1);
        }
        else if (pid ==0){
            cerr<< " # file " << i << ".......downloaing now \n\n ";
            execlp("/usr/bin/wget", "wget",urls.back().c_str(), NULL);
        }
        else{
            urls.pop_back();
            urls.end();
            wait(NULL);
        }
    }
}

int main(int argc, char* argv[])
{
    vector<string> urls;
    load_urls();
    
    cerr << count << endl;
    create_child();
    
    return 0;
    
}
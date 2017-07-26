#include <iostream>
#include <cstring>
#include <fstream>
#include <cstdlib>
#include <unistd.h>
#include <sys/wait.h>
#include <vector>
using namespace std;    

vector<string> urls;
int count = 0 ;

void load_urls(){
    string urlline;
    ifstream reader("url.txt");
    if (!reader.is_open()){
        cout <<" fail to open the urls.txt file\n";
        exit (1);
    }
    while (!reader.eof())
    {
        reader >>urlline;
        if(!reader.eof()){

            urls.push_back(urlline);
            count++;
        }

    }  
    reader.close();
}
void create_child(){
    pid_t pid;
    for ( int i = 0 ; i < count ; i++){
        pid = fork();
        if ( pid < 0 ){
            cerr <<"cannot fork";
            exit (1);
        }
        else if (pid ==0){
            cerr<< " # file " << i << ".......downloading now \n\n ";
            if (execlp("wget", "wget",urls.back().c_str(), NULL)<0){
                perror("execlp");
                exit(1);
            }
        }
        else{  
            urls.pop_back();
            urls.end();
            wait(&pid);
        }

    }
}

int main(int argc, char* argv[])
{
    vector<string> urls;
    load_urls();

    create_child();
    wait(NULL);
    cout << endl;
    cout << " ________________DOWNLOADING DONE______________\n\n";
    return 0;

}


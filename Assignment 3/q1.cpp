#include <iostream>
#include <pthread.h>
#include <sys/wait.h>
#include <errno.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <cmath>
#include <thread>
#include <sys/types.h>
#include <sys/stat.h>
#include <fstream>

using namespace std;

pthread_t tid[26];
string file_name;
ifstream f;

int countcharacter(string str, char ch)
{
    int len = str.length();
    int c = 0;
    for (int i = 0; i < len; i++)
    {
        if (str[i] == (ch - 32) || str[i] == ch)
        {
            c++;
        }
    }
    return c;
}

void *charc_count(void *arg)
{
    int* c = new int;
    char *ch = (char *)arg;
    string str = "";
    *c = 0;
    
    while (!f.eof())
    {
        getline(f, str);
        *c += countcharacter(str, *ch);
    }
    f.clear();
    f.seekg(0, ios::beg);

    cout << "Character " << (char)((*ch) - 32) << "," << *ch << ": " << *c << endl;

    pthread_exit((void *) c);
}

int main()
{
    int total = 0;
    char alpha = 'a';
    void* status;

    cout << "PLease enter the file name: ";
    cin >> file_name;
    cout<<endl;

    f.open(file_name);

    while (!f)
    {
        cout << "file does not exist." << endl;
        cout<< "PLease enter the file name: ";
        cin >> file_name;

        f.open(file_name);
    }


    for(int i = 0; i < 26; i++) 
    {
        pthread_create(&tid[i], NULL, charc_count, (void*) (&alpha));
        pthread_join(tid[i], &status);
        total += *((int *) status);
        alpha++;
    }

    cout << "\nTotal Characters: " << total << endl;
    f.close();

    pthread_exit(NULL);
}

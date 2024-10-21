#include <iostream>
#include <unistd.h>
#include <sys/wait.h>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std; 

vector<string> k_names;

int main()
{
    cout << "¿Cuantos procesos quieres agregar?";
    
    int processes = 0;
    
    cin >> processes;

    srand(time(0)); // Inicializando Random

    for (int i = 0; i < processes; i++)
    {
        pid_t pid = fork();

        if (pid == 0)
        {   
            string name;
            cout << "Elige un nombre!!!: " << endl;
            cin >> name;
            k_names.push_back(name);
        }
        else if (pid > 0)    
        {
            wait(NULL);
            break;
           
        }
        else cout << "Error al crear el proceso hijo :c! " << endl;

        int random = rand() % k_names.size();
        string randomName = k_names[random];

        cout << "El nombre random es: " << randomName << endl;
        
    }
    
    return (0);

}
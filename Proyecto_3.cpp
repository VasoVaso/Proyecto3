#include <iostream>
#include <chrono>
#include <random>
#include <vector>
#include <algorithm>

using namespace std;

//--------------------------------- PROTOTIPOS ---------------------------------//

int getRandom(int min, int max);
vector<int> randomModeFill(int size);
vector<int> randomDuplicateModeFill(int size, int min, int max);
vector<int> orderedModeFill(int size);
vector<int> inverselyOrderedModeFill(int size);

//-------------------------------- FUNCIÓN MAIN --------------------------------//

int main()
{/*
    const int minQueue = 100000;
    const int maxQueue = 110000;
    int randomQueue = getRandom(minQueue, maxQueue);

    const int minObjects = 1000*15;
    const int maxObjects = 1500*15;
    int randomObjects = getRandom(minObjects, maxObjects);

    const int minEvents = 60000;
    const int maxEvents = 80000;
    int randomEvents = getRandom(minEvents, maxEvents);*/
    
    const int minQueue = 1;
    const int maxQueue = 10;
    int randomQueue = getRandom(minQueue, maxQueue);

    vector<int> playersQueue;
    vector<int> objects;
    vector<int> events; 

    int option = 0, raceType = 0, raceMode = 0;

    do
    {
        cout << "   ALGORITHMS RACE\n" << endl;
        cout << "1. Start Race.\n2. Select Race.\n3. Select Mode.\n4. Exit.\n\n>> Your option: ";
        cin >> option;
        switch (option)
        {
        case 1:
            system("cls");

            if (raceType != 0 && raceMode != 0)
            {
                
            }
            else
            {
                cout << "\n>> Before starting, you must choose a race and the race mode.\n" << endl;
            }

            system("pause");
            system("cls");
            break;
        case 2:
            system("cls");

            do
            {
                cout << "   Selecting Race\n" << endl;
                cout << "1. Queue Race.\n2. Object Race.\n3. Event Race.\n4. Go back.\n\n>> Your option: ";
                cin >> option;
                switch (option)
                {
                case 1:
                    raceType = 1;
                    cout << "\n>> You have selected the Queue Race.\n" << endl;
                    system("pause");
                    break;
                case 2:
                    raceType = 2;
                    cout << "\n>> You have selected the Object Race.\n" << endl;
                    system("pause");
                    break;
                case 3:
                    raceType = 3;
                    cout << "\n>> You have selected the Event Race.\n" << endl;
                    system("pause");
                    break;
                default:
                    break;
                }
                
                system("cls");
            } while (option != 4);
            option = 0;

            system("cls");
            break;
        case 3:
            system("cls");

            do
            {
                cout << "   Selecting Mode\n" << endl;
                cout << "1. Random Mode.\n2. Random with Duplicates Mode.\n3. Ordered Mode.\n4. Inversely Ordered Mode.\n5. Go Back.\n\n>> Your option: ";
                cin >> option;
                switch (option)
                {
                case 1:
                    raceMode = 1;
                    cout << "\n>> You have selected the Random Mode.\n" << endl;
                    system("pause");
                    break;
                case 2:
                    raceMode = 2;
                    cout << "\n>> You have selected the Random with Duplicates Mode.\n" << endl;
                    system("pause");
                    break;
                case 3:
                    raceMode = 3;
                    cout << "\n>> You have selected the Ordered Mode.\n" << endl;
                    system("pause");
                    break;
                case 4:
                    raceMode = 4;
                    cout << "\n>> You have selected the Inversely Ordered Mode.\n" << endl;
                    system("pause");
                    break;
                default:
                    break;
                }

                system("cls");
            } while (option != 5);
            option = 0;

            system("cls");
            break;
        default:
            system("cls");
            break;
        }
    } while (option != 4);

    cout << "\n>> Closing Program..." << endl;
}

//--------------------------------- FUNCIONES ---------------------------------//

int getRandom(int min, int max)
{
    random_device rd;
    mt19937 generator(rd());

    uniform_int_distribution<int> distribution(min, max);

    return distribution(generator);
}

vector<int> randomModeFill(int size) 
{
    vector<int> result;

    for (int i = 1; i <= size; i++) 
    {
        result.push_back(i);
    }

    random_device rd;
    mt19937 g(rd());
    shuffle(result.begin(), result.end(), g);

    return result;
}

vector<int> randomDuplicateModeFill(int size, int min, int max)
{
    vector<int> vector;

    random_device rd;
    mt19937 generator(rd());
    uniform_int_distribution<int> distribution(min, max);

    for (int i = 0; i < size; i++)
    {
        int randomNum = distribution(generator);
        vector.push_back(randomNum);
    }

    return vector;
}

vector<int> orderedModeFill(int size) 
{
    vector<int> vector;

    for (int i = 1; i <= size; i++) 
    {
        vector.push_back(i);
    }

    return vector;
}

vector<int> inverselyOrderedModeFill(int size) 
{
    vector<int> vector;

    for (int i = size; i >= 1; i--) 
    {
        vector.push_back(i);
    }

    return vector;
}
#include <iostream>
#include <chrono>
#include <random>
#include <vector>
#include <algorithm>

using namespace std;

//--------------------------------- PROTOTIPOS ---------------------------------//

int getRandom(int min, int max);

// CREACIÓN DE VECTORES

vector<int> randomModeFill(int size);
vector<int> randomDuplicateModeFill(int size, int min, int max);
vector<int> orderedModeFill(int size);
vector<int> inverselyOrderedModeFill(int size);

// ALGORITMOS DE ORDENAMIENTOS

void selectionSort(vector<int>& arr);
void bubbleSort(vector<int>& arr);
void insertionSort(vector<int>& arr);
void shellSort(vector<int>& arr);

void merge(vector<int>& arr, int left, int middle, int right);
void mergeSort(vector<int>& arr, int left, int right);
void quickSort(vector<int>& arr, int low, int high);
int partition(vector<int>& arr, int low, int high);
void heapSort(vector<int>& arr);
void heapify(vector<int>& arr, int n, int i);

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
    const int maxQueue = 20;
    int randomQueue = getRandom(minQueue, maxQueue);

    vector<int> playersQueue;
    vector<int> objects;
    vector<int> events; 

    int option = 0, raceType = 0, raceMode = 0;

    do
    {
        cout << "   ALGORITHMS RACE             | Race: ";
        switch (raceType)
        {   
        case 1:
            cout << "Queue |";
            break;
        case 2:
            cout << "Objects |";
            break;
        case 3:
            cout << "Events |";
            break;
        default:
            cout << "None |";
            break;
        } 
        switch (raceMode)
        {
        case 1:
            cout << " Mode: Random";
            break;
        case 2:
            cout << " Mode: Random with Duplicates";
            break;
        case 3:
            cout << " Mode: Ordered";
            break;
        case 4:
            cout << " Mode: Inversely Ordered";
            break;
        default:
            cout << " Mode: None";
            break;
        }
        cout << "\n\n1. Start Race.\n2. Select Race.\n3. Select Mode.\n4. Exit.\n\n>> Your option: ";
        cin >> option;
        switch (option)
        {
        case 1:
            system("cls");

            if (raceType == 0 && raceMode == 0) // !=
            {
                vector<int> miVector = randomModeFill(10);

                cout << "Vector ordenado: \n";
                for (int i : miVector) {
                    cout << i << " ";
                }

                heapSort(miVector);
                //quickSort(miVector, 0, miVector.size() - 1);

                // Mostrar el vector ordenado
                cout << "\n\nVector ordenado: \n";
                for (int i : miVector) {
                    std::cout << i << " ";
                }
            }
            else
            {
                cout << "\n>> Before starting, you must choose a race and the race mode.\n" << endl;
            }
            
            cout << "\n" << endl;
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

    for (int i = 1; i <= size; ++i) 
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

    for (int i = 0; i < size; ++i)
    {
        int randomNum = distribution(generator);
        vector.push_back(randomNum);
    }

    return vector;
}

vector<int> orderedModeFill(int size) 
{
    vector<int> vector;

    for (int i = 1; i <= size; ++i) 
    {
        vector.push_back(i);
    }

    return vector;
}

vector<int> inverselyOrderedModeFill(int size) 
{
    vector<int> vector;

    for (int i = size; i >= 1; --i) 
    {
        vector.push_back(i);
    }

    return vector;
}

void selectionSort(vector<int>& arr)
{
    int n = arr.size();
    for (int i = 0; i < n; ++i)
    {
        for (int j = i; j < n; ++j)
        {
            if (arr[j] < arr[i])
            {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

void bubbleSort(vector<int>& arr) 
{
    int n = arr.size();
    bool swapped;

    for (int i = 0; i < n - 1; ++i) 
    {
        swapped = false;

        for (int j = 0; j < n - i - 1; ++j) 
        {
            if (arr[j] > arr[j + 1]) 
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swapped = true;
            }
        }

        if (!swapped) 
        {
            break;
        }
    }
}

void insertionSort(vector<int>& arr) 
{
    int n = arr.size();

    for (int i = 1; i < n; i++) 
    {
        int key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > key) 
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

void shellSort(vector<int>& arr) 
{
    int n = arr.size();

    for (int gap = n / 2; gap > 0; gap /= 2) 
    {
        for (int i = gap; i < n; i++)
        {
            int temp = arr[i];
            int j;

            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap) 
            {
                arr[j] = arr[j - gap];
            }
            arr[j] = temp;
        }
    }
}

void mergeSort(vector<int>& arr, int left, int right) 
{
    if (left < right) 
    {
        int middle = left + (right - left) / 2;

        mergeSort(arr, left, middle);

        mergeSort(arr, middle + 1, right);

        merge(arr, left, middle, right);
    }
}

void merge(vector<int>& arr, int left, int middle, int right) 
{
    int n1 = middle - left + 1;
    int n2 = right - middle;

    vector<int> leftArray(n1);
    vector<int> rightArray(n2);

    for (int i = 0; i < n1; i++)
    {
        leftArray[i] = arr[left + i];
    }
        
    for (int j = 0; j < n2; j++)
    {
        rightArray[j] = arr[middle + 1 + j];
    }
        
    int i = 0;
    int j = 0;
    int k = left;

    while (i < n1 && j < n2) 
    {
        if (leftArray[i] <= rightArray[j]) 
        {
            arr[k] = leftArray[i];
            i++;
        }
        else 
        {
            arr[k] = rightArray[j];
            j++;
        }
        k++;
    }

    while (i < n1) 
    {
        arr[k] = leftArray[i];
        i++;
        k++;
    }

    while (j < n2) 
    {
        arr[k] = rightArray[j];
        j++;
        k++;
    }
}

void quickSort(vector<int>& arr, int low, int high)
{
    if (low < high)
    {
        int pivotIndex = partition(arr, low, high);

        quickSort(arr, low, pivotIndex - 1);
        quickSort(arr, pivotIndex + 1, high);
    }
}

int partition(vector<int>& arr, int low, int high)
{
    int pivot = arr[high];

    int i = (low - 1);

    for (int j = low; j <= high; j++)
    {
        if (arr[j] < pivot)
        {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return (i + 1);
}

void heapSort(vector<int>& arr) 
{
    int n = arr.size();

    for (int i = n / 2 - 1; i >= 0; i--)
    {
        heapify(arr, n, i);
    }

    for (int i = n - 1; i > 0; i--) 
    {
        swap(arr[0], arr[i]); 

        heapify(arr, i, 0);
    }
}

void heapify(vector<int>& arr, int n, int i) 
{
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest])
    {
        largest = left;
    }
        
    if (right < n && arr[right] > arr[largest])
    {
        largest = right;
    }
        
    if (largest != i) 
    {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}
#include <iostream>
#include <chrono>
#include <random>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;
using chrono::high_resolution_clock;
using chrono::duration;
using chrono::duration_cast;

//--------------------------------- PROTOTIPOS ---------------------------------//

int getRandom(int min, int max);
void initRace(vector<int>& aux, vector<int>& arr);

// CREACIÓN DE VECTORES

vector<int> randomModeFill(int size);
vector<int> randomDuplicateModeFill(int size, int min, int max);
vector<int> orderedModeFill(int size);
vector<int> inverselyOrderedModeFill(int size);

// ALGORITMOS DE ORDENAMIENTOS

double selectionSort(vector<int>& arr);
double bubbleSort(vector<int>& arr);
double insertionSort(vector<int>& arr);
double shellSort(vector<int>& arr);

double mergeSort(vector<int>& arr, int left, int right);
void merge(vector<int>& arr, int left, int middle, int right);
double quickSort(vector<int>& arr, int low, int high);
int partition(vector<int>& arr, int low, int high);
void swap(int& a, int& b);
double heapSort(vector<int>& arr);
void heapify(vector<int>& arr, int n, int i);

//-------------------------------- FUNCIÓN MAIN --------------------------------//

int main()
{
    const int minQueue = 100000;
    const int maxQueue = 110000;
    int randomQueueNum = 0;

    const int minObjects = 1000 * 15;
    const int maxObjects = 1500 * 15;
    int randomObjectsNum = 0;

    const int minEvents = 60000;
    const int maxEvents = 80000;
    int randomEventsNum = 0;

    vector<int> playersQueue;
    vector<int> objects;
    vector<int> events;
    vector<int> aux;

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
        case 1: // COMENZAR CARRERA
            system("cls");

            randomQueueNum = getRandom(minQueue, maxQueue);
            randomObjectsNum = getRandom(minObjects, maxObjects);
            randomEventsNum = getRandom(minEvents, maxEvents);

            if (raceType != 0 && raceMode != 0)
            {

                switch (raceMode)
                {
                case 1: // ALEATORIO
                    if (raceType == 1)
                    {
                        cout << ">> Starting Random Race with " << randomQueueNum << " players in queue.\n" << endl;
                        playersQueue = randomModeFill(randomQueueNum);
                        initRace(aux, playersQueue);
                    }
                    else if (raceType == 2)
                    {
                        cout << ">> Starting Random Race with " << randomObjectsNum << " objects merging.\n" << endl;
                        objects = randomModeFill(randomObjectsNum);
                        initRace(aux, objects);
                    }
                    else
                    {
                        cout << ">> Starting Random Race with " << randomEventsNum << " events to explore.\n" << endl;
                        events = randomModeFill(randomEventsNum);
                        initRace(aux, events);
                    }
                    break;
                case 2: // ALEATORIO CON DUPLICADOS
                    if (raceType == 1)
                    {
                        cout << ">> Starting Random with Duplicates Race with " << randomQueueNum << " players in queue.\n" << endl;
                        playersQueue = randomDuplicateModeFill(randomQueueNum, minQueue, maxQueue);
                        initRace(aux, playersQueue);
                    }
                    else if (raceType == 2)
                    {
                        cout << ">> Starting Random with Duplicates Race with " << randomObjectsNum << " objects merging.\n" << endl;
                        objects = randomDuplicateModeFill(randomObjectsNum, minObjects, maxObjects);
                        initRace(aux, objects);
                    }
                    else
                    {
                        cout << ">> Starting Random with Duplicates Race with " << randomEventsNum << " events to explore.\n" << endl;
                        events = randomDuplicateModeFill(randomEventsNum, minEvents, maxEvents);
                        initRace(aux, events);
                    }
                    break;
                case 3: // ORDENADO
                    if (raceType == 1)
                    {
                        cout << ">> Starting Ordered Race with " << randomQueueNum << " players in queue.\n" << endl;
                        playersQueue = orderedModeFill(randomQueueNum);
                        initRace(aux, playersQueue);
                    }
                    else if (raceType == 2)
                    {
                        cout << ">> Starting Ordered Race with " << randomObjectsNum << " objects merging.\n" << endl;
                        objects = orderedModeFill(randomObjectsNum);
                        initRace(aux, objects);
                    }
                    else
                    {
                        cout << ">> Starting Ordered Race with " << randomEventsNum << " events to explore.\n" << endl;
                        events = orderedModeFill(randomEventsNum);
                        initRace(aux, events);
                    }
                    break;
                case 4: // INVERSAMENTE ORDENADO
                    if (raceType == 1)
                    {
                        cout << ">> Starting Inversely Ordered Race with " << randomQueueNum << " players in queue.\n" << endl;
                        playersQueue = inverselyOrderedModeFill(randomQueueNum);
                        initRace(aux, playersQueue);
                    }
                    else if (raceType == 2)
                    {
                        cout << ">> Starting Inversely Ordered Race with " << randomObjectsNum << " objects merging.\n" << endl;
                        objects = inverselyOrderedModeFill(randomObjectsNum);
                        initRace(aux, objects);
                    }
                    else
                    {
                        cout << ">> Starting Inversely Ordered Race with " << randomEventsNum << " events to explore.\n" << endl;
                        events = inverselyOrderedModeFill(randomEventsNum);
                        initRace(aux, events);
                    }
                    break;
                default:
                    break;
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
        case 2: // SELECCIÓN DE CARRERA
            system("cls");

            do
            {
                cout << "   Selecting Race\n" << endl;
                cout << "1. Queue Race.\n2. Object Race.\n3. Event Race.\n4. Go back.\n\n>> Your option: ";
                cin >> option;
                switch (option)
                {
                case 1: // COLAS
                    raceType = 1;
                    cout << "\n>> You have selected the Queue Race.\n" << endl;
                    system("pause");
                    break;
                case 2: // OBJETOS
                    raceType = 2;
                    cout << "\n>> You have selected the Object Race.\n" << endl;
                    system("pause");
                    break;
                case 3: // EVENTOS
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
        case 3: // SELECCIÓN DE MODO
            system("cls");

            do
            {
                cout << "   Selecting Mode\n" << endl;
                cout << "1. Random Mode.\n2. Random with Duplicates Mode.\n3. Ordered Mode.\n4. Inversely Ordered Mode.\n5. Go Back.\n\n>> Your option: ";
                cin >> option;
                switch (option)
                {
                case 1: // ALEATORIO
                    raceMode = 1;
                    cout << "\n>> You have selected the Random Mode.\n" << endl;
                    system("pause");
                    break;
                case 2: // ALEATORIO CON DUPLICADOS
                    raceMode = 2;
                    cout << "\n>> You have selected the Random with Duplicates Mode.\n" << endl;
                    system("pause");
                    break;
                case 3: // ORDENADO
                    raceMode = 3;
                    cout << "\n>> You have selected the Ordered Mode.\n" << endl;
                    system("pause");
                    break;
                case 4: // INVERSAMENTE ORDENADO
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

double selectionSort(vector<int>& arr)
{
    int n = arr.size();

    auto start = high_resolution_clock::now();

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

    auto end = high_resolution_clock::now();
    return duration_cast<duration<double>>(end - start).count();
}

double bubbleSort(vector<int>& arr)
{
    int n = arr.size();
    bool swapped;

    auto start = high_resolution_clock::now();

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

    auto end = high_resolution_clock::now();
    return duration_cast<duration<double>>(end - start).count();
}

double insertionSort(vector<int>& arr)
{
    int n = arr.size();

    auto start = high_resolution_clock::now();

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

    auto end = high_resolution_clock::now();
    return duration_cast<duration<double>>(end - start).count();
}

double shellSort(vector<int>& arr)
{
    int n = arr.size();

    auto start = high_resolution_clock::now();

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

    auto end = high_resolution_clock::now();
    return duration_cast<duration<double>>(end - start).count();
}

double mergeSort(vector<int>& arr, int left, int right)
{
    auto start = high_resolution_clock::now();

    if (left < right)
    {
        int middle = left + (right - left) / 2;

        mergeSort(arr, left, middle);

        mergeSort(arr, middle + 1, right);

        merge(arr, left, middle, right);
    }

    auto end = high_resolution_clock::now();
    return duration_cast<duration<double>>(end - start).count();
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

double quickSort(vector<int>& arr, int low, int high)
{
    auto start = high_resolution_clock::now();

    stack<pair<int, int>> st;
    st.push({ low, high });

    while (!st.empty())
    {
        low = st.top().first;
        high = st.top().second;
        st.pop();

        if (low < high)
        {
            int pivotIndex = partition(arr, low, high);

            st.push({ low, pivotIndex - 1 });
            st.push({ pivotIndex + 1, high });
        }
    }

    auto end = high_resolution_clock::now();
    return duration_cast<duration<double>>(end - start).count();
}

int partition(vector<int>& arr, int low, int high)
{
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j <= high - 1; j++)
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

void swap(int& a, int& b)
{
    int temp = a;
    a = b;
    b = temp;
}

double heapSort(vector<int>& arr)
{
    int n = arr.size();

    auto start = high_resolution_clock::now();

    for (int i = n / 2 - 1; i >= 0; i--)
    {
        heapify(arr, n, i);
    }

    for (int i = n - 1; i > 0; i--)
    {
        swap(arr[0], arr[i]);

        heapify(arr, i, 0);
    }

    auto end = high_resolution_clock::now();
    return duration_cast<duration<double>>(end - start).count();
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

void initRace(vector<int>& aux, vector<int>& arr)
{
    double timeTaken[7];
    int timeTakenIndex = 0;

    aux = arr;
    timeTaken[0] = selectionSort(arr);
    cout << "1. Selection Sort, " << timeTaken[0] << endl;
    arr = aux;
    timeTaken[1] = bubbleSort(arr);
    cout << "2. Bubble Sort, " << timeTaken[1] << endl;
    arr = aux;
    timeTaken[2] = insertionSort(arr);
    cout << "3. Insertion Sort, " << timeTaken[2] << endl;
    arr = aux;
    timeTaken[3] = shellSort(arr);
    cout << "4. Shell Sort, " << timeTaken[3] << endl;
    arr = aux;
    timeTaken[4] = mergeSort(arr, 0, arr.size() - 1);
    cout << "5. Merge Sort, " << timeTaken[4] << endl;
    arr = aux;
    timeTaken[5] = quickSort(arr, 0, arr.size() - 1);
    cout << "6. Quick Sort, " << timeTaken[5] << endl;
    arr = aux;
    timeTaken[6] = heapSort(arr);
    cout << "7. Heap Sort, " << timeTaken[6] << endl;

    double fastestTime = timeTaken[0];

    for (int i = 0; i < 7; i++)
    {
        if (fastestTime > timeTaken[i])
        {
            fastestTime = timeTaken[i];
            timeTakenIndex = i;
        }
    }

    switch (timeTakenIndex)
    {
    case 0:
        cout << "\n>> The winner algorithm is Selection Sort with a time of " << timeTaken[0] << " seconds!" << endl;
        break;
    case 1:
        cout << "\n>> The winner algorithm is Bubble Sort with a time of " << timeTaken[1] << " seconds!" << endl;
        break;
    case 2:
        cout << "\n>> The winner algorithm is Insertion Sort with a time of " << timeTaken[2] << " seconds!" << endl;
        break;
    case 3:
        cout << "\n>> The winner algorithm is Shell Sort with a time of " << timeTaken[3] << " seconds!" << endl;
        break;
    case 4:
        cout << "\n>> The winner algorithm is Merge Sort with a time of " << timeTaken[4] << " seconds!" << endl;
        break;
    case 5:
        cout << "\n>> The winner algorithm is Quick Sort with a time of " << timeTaken[5] << " seconds!" << endl;
        break;
    case 6:
        cout << "\n>> The winner algorithm is Heap Sort with a time of " << timeTaken[6] << " seconds!" << endl;
        break;
    default:
        break;
    }
}
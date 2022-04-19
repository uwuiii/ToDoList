using namespace std;
#include <string>
#include <iostream>

struct DEEDS
{
    string name;
    int priority;
    string description;
    int date[2];
    int time[2];

    void input()
    {
        cout << "#Name: ";
        getline(cin, name);
        cout << "#Description: ";
        getline(cin, description);
        cout << "#Priority: ";
        cin >> priority;
        cout << "#Date:\n*Day: ";
        cin >> date[0];
        cout << "*Month: ";
        cin >> date[1];
        cout << "#Time:\n*Hours: ";
        cin >> time[0];
        cout << "*Minutes: ";
        cin >> time[1];
    }

    void show()
    {
        cout << "###################################\n";
        cout << "1.Name: " << name << endl;
        cout << "2.Description: " << description << endl;
        cout << "3.Priority: " << priority << endl;
        cout << "4.Date: " << date[0] << '.' << date[1] << endl;
        cout << "5.Time: " << time[0] << ':' << time[1] << endl;
        cout << "###################################\n";
    }
};

DEEDS* add(DEEDS* arr1, int size)
{
    int size2 = size + 1;
    DEEDS* arr2 = new DEEDS[size2];
    for (int i = 0; i < size; i++)
        arr2[i] = arr1[i];
    delete[] arr1;
    return arr2;
}

void edit(DEEDS* arr, int n)
{
    int a;
    cout << "Number of thing u want to edit: ";
    cin >> a;
    cin.ignore();

    switch (a)
    {
    case 1:
        getline(cin, arr[n - 1].name);
        break;
    case 2:
        getline(cin, arr[n - 1].description);
        break;
    case 3:
        cin >> arr[n - 1].priority;
        break;
    case 4:
        cout << "Day: ";
        cin >> arr[n - 1].date[0];
        cout << "Month: ";
        cin >> arr[n - 1].date[1];
        break;
    case 5:
        cout << "Hours: ";
        cin >> arr[n - 1].time[0];
        cout << "Minutes: ";
        cin >> arr[n - 1].time[0];
        break;
    default:
        cout << "Wrong input!";
        break;
    }
    arr[n - 1].show();
}

DEEDS* _delete(DEEDS* arr1, int size, int n)
{
    int size2 = size - 1;
    DEEDS* arr2 = new DEEDS[size2];
    for (int i = n; i < size; i++)
        arr1[i] = arr1[i + 1];
    for (int i = 0; i < size2; i++)
        arr2[i] = arr1[i];
    delete[] arr1;
    return arr2;
}

void search(DEEDS* arr, int size, string b, int n)
{
    int d, m, h, t;

    switch (n)
    {
    case 1:
        cout << "Enter name: ";
        getline(cin, b);
        for (int i = 0; i < size; i++)
        {
            if (b == arr[i].name)
                arr[i].show();
        }
        break;
    case 2:
        cout << "Enter descripton: ";
        getline(cin, b);
        for (int i = 0; i < size; i++)
        {
            if (b == arr[i].description)
                arr[i].show();
        }
        break;
    case 3:
        cout << "Enter priority: ";
        cin >> n;
        for (int i = 0; i < size; i++)
        {
            if (n == arr[i].priority)
                arr[i].show();
        }
        break;
    case 4:
        cout << "Enter date n time:\n";
        cout << "Day: ";
        cin >> d;
        cout << "Month: ";
        cin >> m;
        cout << "Hours: ";
        cin >> h;
        cout << "Minutes: ";
        cin >> t;

        for (int i = 0; i < size; i++)
        {
            if (d == arr[i].date[0] && m == arr[i].date[1] && h == arr[i].time[0] && arr[i].time[1])
                arr[i].show();
        }
        break;
    default:
        cout << "Wrong input!";
        break;
    }
}

void showBusiness(DEEDS* arr, int size, int choice)
{
    int _count = 0;
    int m, d;

    switch (choice)
    {
    case 1:
        cout << "Enter day n month:\n";
        cout << "Month: ";
        cin >> m;
        cout << "Day: ";
        cin >> d;

        for (int i = 0; i < size; i++)
        {
            if (m == arr[i].date[1] && d == arr[i].date[0])
            {
                arr[i].show();
                _count++;
            }
        }
        if (!_count)
            cout << "No business for today\n";
        else
        {
            cout << "Sorting...";
            sortDay(arr, size, _count, m, d);
        }
        break;
    case 2:
        cout << "Enter month: ";
        cin >> m;

        for (int i = 0; i < size; i++)
        {
            if (m == arr[i].date[1])
            {
                arr[i].show();
                _count++;
            }
        }
        if (!_count)
            cout << "No business for the month\n";
        break;
    default:
        cout << "Wrong input!";
        break;
    }
}

void sortDay(DEEDS* arr, int size, int n, int m, int d)
{
    DEEDS* sortArr = new DEEDS[n];
    int k = 0;
    for (int i = 0; i < size; i++)
    {
        if (m == arr[i].date[1] && d == arr[i].date[0])
        {
            sortArr[k] = arr[i];
            ++k;
        }
    }

    cout << "1| Sort by priority\n2| Sort by time\n#";
    int choice;
    cin >> choice;

    switch (choice)
    {
    case 1:
        for (int i = 0; i < n - 1; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                if (sortArr[i].priority > sortArr[j].priority)
                    swap(sortArr[i], sortArr[j]);
            }
        }
        break;
    case 2:
        for (int i = 0; i < n - 1; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                if ((sortArr[i].time[1] > sortArr[j].time[1]) || (sortArr[i].time[1] == sortArr[j].time[1] && sortArr[i].time[0] > sortArr[j].time[0]))
                    swap(sortArr[i], sortArr[j]);
            }
        }
        break;
    default:
        cout << "Wrong input!";
        break;

        for (int i = 0; i < n; i++)
        {
            sortArr[i].show();
        }
    }

    delete[] sortArr;
}

void sortMonth(DEEDS* arr, int size, int n, int m)
{
    DEEDS* sortArr = new DEEDS[n];
    int k = 0;
    for (int i = 0; i < size; i++)
    {
        if (m == arr[i].date[1])
        {
            sortArr[k] = arr[i];
            ++k;
        }
    }

    cout << "1| Sort by priority\n2| Sort by date n time\n#";
    int choice;
    cin >> choice;

    switch (choice)
    {
    case 1:
        for (int i = 0; i < n - 1; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                if (sortArr[i].priority > sortArr[j].priority)
                    swap(sortArr[i], sortArr[j]);
            }
        }
        break;
    case 2:
        for (int i = 0; i < n - 1; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                if ((sortArr[i].date[0] > sortArr[j].date[0]) || (sortArr[i].date[0] == sortArr[j].date[0] && sortArr[i].time[1] > sortArr[j].time[1]) || (sortArr[i].date[0] == sortArr[j].date[0] && sortArr[i].time[1] == sortArr[j].time[1] && sortArr[i].time[0] > sortArr[j].time[0]))
                    swap(sortArr[i], sortArr[j]);
            }
        }
        break;
    default:
        cout << "Wrong input!";
        break;
    }
}

int main()
{
    int size = 0;
    DEEDS* deed = new DEEDS[size];
    int choice, n, check;
    string b;
    cout << "####Welcome to your TO-DO LIST!####" << endl;
    do
    {
        cout << "###################################\n";
        cout << "\nChoose option:\n";
        cout << "\n1| Add\n2| Edit\n3| Delete\n4| Search\n5| Show\n0| Exit\n\n#";
        cin >> choice;
        cin.ignore();
        cout << "###################################\n";

        switch (choice)
        {
        case 1:
            deed = add(deed, size);
            size++;
            deed[size - 1].input();
            break;
        case 2:
            cout << "Number of deed u want to edit: ";
            cin >> n;
            deed[n - 1].show();
            do
            {
                edit(deed, n);
                cout << "1| Continue editing\n2| Stop editing\n#";
                cin >> check;
            } while (check != 2);
            break;
        case 3:
            cout << "Number of deed u want to delete: ";
            cin >> n;
            _delete(deed, size, n);
            cout << "Deed №" << n << "was deleted successfully\n";
            break;
        case 4:
            cout << "Choose option:\n1| Search by name\n2| Search by description\n3| Search by priority\n4| Search by date n time\n#";
            cin >> n;
            cin.ignore();
            search(deed, size, b, n);   
            break;
        case 5:
            cout << "Choose option:\n1| Deeds for the day\n2| Deeds for the month\n#";
            cin >> choice;
            showBusiness(deed, size, choice);
            break;
        case 0:
            return 0;
        default:
            cout << "Wrong input!";
            break;
        }
    } while (true);

}

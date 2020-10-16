#include<iostream>
#include<iomanip>

using namespace std;

/*
        ДОМАШНЕЕ ЗАДАНИЕ:
        1. Написать программу, реализующую журнал академической группы
        с произвольным количеством студентов. Программа должна
        предоставлять возможность добавления студента в группу,
        удаления студента из группы, редактирования данных о студенте,
        вывода информации о студентах каждой группы в консоль.
        2. В программе должно быть реализовано 2 типа структур: Group и Student. Структура
        Group должна содержать в себе название и список студентов (массив структур Student).
        3. Данные студента: Имя и средний балл
    */


struct Student
{
    char studentName[20];
    unsigned int averagePoints;
};



struct Group
{
    char groupName[20];
    int size = 2;
    Student* set = new Student[size];
};



void printAllLists(Group** arr, const int quantityGroup)
{
    bool act = true;
    for (int i = 0; i < quantityGroup; i++)
    {
        cout << "\n----------------------------------------\n";
        cout << '\n' << i << ") " << "Group name\t";
        cout << arr[i]->groupName << endl;
        act = false;
        cout << "\n\n#\tName\t\t\t\Points\n";
        for (int j = 0; j < arr[i]->size; j++)
        {
            cout << j << '\t' << arr[i]->set[j].studentName << "\t\t\t";
            cout << arr[i]->set[j].averagePoints << '\n';
        }
    }
    if (act)
    {
        cout << "You not have group\n";
    }
    cout << "\n----------------------------------------\n";
}




void printGroupLists(Group** arr, const int group)
{
    bool act = true;
    for (int i = group; i < group + 1; i++)
    {
        cout << "\n----------------------------------------\n";
        cout << '\n' << i << ") " << "Group name\t";
        cout << arr[i]->groupName << endl;

        cout << "\n\n#\tName\t\t\t\Points\n";
        for (int j = 0; j < arr[i]->size; j++)
        {
            cout << j << '\t' << arr[i]->set[j].studentName << "\t\t\t";
            cout << arr[i]->set[j].averagePoints << '\n';
            act = false;
        }
    }
    if (act)
    {
        cout << "\n\n-\t-\t\t\t\-\nNot student\n";
    }
    cout << "\n----------------------------------------\n";
}



void addStudent(Group**& arr, int group) {
    for (int i = group; i < group + 1; i++)
    {
        cout << "Add Student in " << arr[i]->groupName << " group\n\n";
        for (int j = arr[i]->size; j < (arr[i]->size + 1); j++)
        {
            cout << "Enter Studen name\n";
            cin >> arr[i]->set[j].studentName;

            cout << "Enter Studen average points\n";
            cin >> arr[i]->set[j].averagePoints;
        }
        arr[i]->size++;
    }
}




void deleteStudent(Group**& arr, int quantityGroup, int qroup, int student) {

    cout << "Delete Student in " << arr[qroup]->groupName << " group\n\n";

    Group** tmp = new Group * [quantityGroup];
    for (int i = 0, b = 0; i < quantityGroup; i++)
    {
        tmp[i] = new Group;
        tmp[i] = arr[i];
        if (i == qroup)
        {
            for (int j = 0, u = 0; j < arr[i]->size; j++)
            {
                if (j != student)
                {
                    tmp[i]->set[u] = arr[i]->set[j];
                    u++;
                }
            }
            arr[i]->size--;;
        }
    }
    delete[] arr;
    arr = tmp;
}




void studentEditing(Group**& arr, int group, int student)
{
    cout << "Edit Student in " << arr[group]->groupName << " group\n\n";
    cout << "Name\t" << arr[group]->set->studentName << "\tAverage point\t" << arr[group]->set->averagePoints << "\n\n";
    for (int i = group; i < group + 1; i++)
    {
        for (int j = student, u = 0; u < 1; u++)
        {
            cout << "Enter Studen name\n";
            cin >> arr[i]->set[j].studentName;

            cout << "Enter Studen average points\n";
            cin >> arr[i]->set[j].averagePoints;
        }

    }
}



enum {
    Exit,
    AddGroup,
    DeleteSpecificGroup,
    AddStudent,
    DeleteSpecificStudent,
    PrintSpecificGroup,
    PrintAllGroup,
    StudentEditing
};



int main()
{
    int quantityGroup;
    do
    {
        cout << "Enter quantity group\n";
        cin >> quantityGroup;

        if (quantityGroup >= 1) {
            break;
        }
        else {
            cout << "\nGroup size must be greater than or equal to 1 \n";
        }

    } while (true);


    Group** arr = new Group * [quantityGroup];

    for (size_t i = 0; i < quantityGroup; i++)
    {
        arr[i] = new Group;

        cout << "Enter name group\n";
        cin >> arr[i]->groupName;


        for (size_t j = 0; j < arr[i]->size; j++)
        {
            cout << "Enter Studen name\n";
            cin >> arr[i]->set[j].studentName;

            cout << "Enter Studen average points\n";
            cin >> arr[i]->set[j].averagePoints;
        }
    }

    int action;
    do
    {

        cout << R"(
Choose an action :

0 - Exit
1 - Add Group
2 - Delete Specific Group
3 - Add Student
4 - Delete Specific Student
5 - Print Specific Group
6 - Print All Group
7 - Student editing

)";
        cin >> action;
        system("cls");
        if (action == Exit)
        {
            cout << "You have left the program\n";
            break;
        }
        else if (action == AddGroup)
        {
            Group** tmp = new Group * [quantityGroup + 1];
            for (int i = 0; i < quantityGroup; i++)
            {
                tmp[i] = new Group;
                tmp[i] = arr[i];
            }

            for (int i = quantityGroup; i < (quantityGroup + 1); i++)
            {
                tmp[i] = new Group;
                cout << "Enter name group\n";
                cin >> tmp[i]->groupName;

                for (int j = 0; j < tmp[i]->size; j++)
                {
                    cout << "Enter Studen name\n";
                    cin >> tmp[i]->set[j].studentName;

                    cout << "Enter Studen average points\n";
                    cin >> tmp[i]->set[j].averagePoints;
                }
            }
            quantityGroup++;
            delete[] arr;

            arr = tmp;
        }
        else if (action == DeleteSpecificGroup)
        {
            int act;
            do
            {
                cout << "Select the group number to delete\n";
                cin >> act;
                if (act < quantityGroup)
                {
                    Group** tmp = new Group * [quantityGroup - 1];
                    for (int i = 0, b = 0; i < quantityGroup; i++)
                    {
                        if (act != i)
                        {
                            tmp[b] = new Group;
                            tmp[b] = arr[i];
                            b++;
                        }
                    }
                    quantityGroup--;
                    delete[] arr;

                    arr = tmp;

                    cout << "\nThis group is deleted\n";
                    break;
                }
                else if (quantityGroup == 0)
                {
                    cout << "You not have group\n";
                    break;
                }
                else {
                    cout << "Wrong choice try again\n";
                }
            } while (true);
        }
        else if (action == AddStudent)
        {
            int act4;
            do
            {
                cout << "In which group to add a student ?\n";
                cin >> act4;
                if (act4 < quantityGroup)
                {
                    cout << "You add a student to  " << arr[act4]->groupName << " group\n\n";
                    addStudent(arr, act4);
                    cout << "Upload completed successfully\n\n";
                    printGroupLists(arr, act4);
                    break;
                }
                else
                {
                    cout << "Such a group does not exist. Try again\n\n";
                }
            } while (true);
        }
        else if (action == DeleteSpecificStudent)
        {
            int act2;
            do
            {
                cout << "Choose from which group to remove the student\n\n";
                cin >> act2;
                if (act2 < quantityGroup)
                {
                    int act3;
                    cout << "Selected  " << arr[act2]->groupName << " group\n";
                    printGroupLists(arr, act2);
                    do
                    {
                        cout << "\nChoose a student\n\n";
                        cin >> act3;

                        if (act3 < arr[act2]->size)
                        {
                            deleteStudent(arr, quantityGroup, act2, act3);
                            cout << "\n\nStudent removed\n\n";

                            printGroupLists(arr, act2);
                            break;
                        }
                        else {
                            cout << "Wrong selection, try again.\n";
                        }

                    } while (true);
                    break;
                }
                else if (quantityGroup == 0) {
                    cout << "You not have group\n";
                    break;
                }
                else {
                    cout << "Wrong selection , this group does not exist , try again.\n\n";
                }
            } while (true);
        }
        else if (action == PrintSpecificGroup)
        {
            int act1;
            do
            {
                cout << "Which group to print (#) ?\n";
                cin >> act1;
                if (act1 < quantityGroup)
                {
                    printGroupLists(arr, act1);
                    break;
                }
                else if (quantityGroup == 0) {
                    cout << "You not have group\n";
                    break;
                }
                else {
                    cout << "Wrong selection , this group does not exist , try again.\n\n";
                }
            } while (true);
        }
        else if (action == PrintAllGroup)
        {
            cout << "Print all list\n\n";
            printAllLists(arr, quantityGroup);
        }
        else if (action == StudentEditing)
        {
            int groupNum;
            do
            {
                cout << "Select a group to edit (#) ?\n";
                cin >> groupNum;
                if (groupNum < quantityGroup)
                {
                    int studentNum;
                    cout << "Select student number to edit information\n";
                    cin >> studentNum;

                    if (studentNum < arr[groupNum]->size)
                    {
                        studentEditing(arr, groupNum, studentNum);
                        cout << "You edited student datae\n";
                        printGroupLists(arr, groupNum);
                        break;
                    }
                    else {
                        cout << "The wrong choice of such a student does not exist\n";
                    }
                }
                else if (quantityGroup == 0) {
                    cout << "You not have group\n";
                    break;
                }
                else {
                    cout << "Wrong selection, try again.\n";
                }
            } while (true);

        }
        else
        {
            cout << "Wrong selection, try again.\n";
        }
    } while (true);



    for (int i = 0; i < quantityGroup; i++)
    {
        delete[] arr[i];
    }

    delete[] arr;

}
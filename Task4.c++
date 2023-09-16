#include <iostream>
#include <vector>

using namespace std;

struct Task {
    string description;
    bool completed;
};

class TodoList {
public:
    void addTask(const string& taskDesc) {
        Task task;
        task.description = taskDesc;
        task.completed = false;
        tasks.push_back(task);
        cout << "Task added: " << taskDesc << endl;
    }

    void viewTasks() {
        cout << "To-Do List:" << endl;
        for (size_t i = 0; i < tasks.size(); ++i) {
            cout << i + 1 << ". ";
            if (tasks[i].completed)
                cout << "[X] ";
            else
                cout << "[ ] ";
            cout << tasks[i].description << endl;
        }
    }

    void markTaskCompleted(int taskIndex) {
        if (taskIndex >= 1 && taskIndex <= tasks.size()) {
            tasks[taskIndex - 1].completed = true;
            cout << "Task marked as completed: " << tasks[taskIndex - 1].description << endl;
        } else {
            cout << "Invalid task index. Please try again." << endl;
        }
    }

    void removeTask(int taskIndex) {
        if (taskIndex >= 1 && taskIndex <= tasks.size()) {
            cout << "Task removed: " << tasks[taskIndex - 1].description << endl;
            tasks.erase(tasks.begin() + taskIndex - 1);
        } else {
            cout << "Invalid task index. Please try again." << endl;
        }
    }

private:
    vector<Task> tasks;
};

int main() {
    TodoList todoList;
    int choice;

    while (true) {
        cout << "\nMenu:" << endl;
        cout << "1. Add Task" << endl;
        cout << "2. View Tasks" << endl;
        cout << "3. Mark Task as Completed" << endl;
        cout << "4. Remove Task" << endl;
        cout << "5. Quit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                string taskDesc;
                cout << "Enter task description: ";
                cin.ignore();
                getline(cin, taskDesc);
                todoList.addTask(taskDesc);
                break;
            }
            case 2:
                todoList.viewTasks();
                break;
            case 3: {
                int taskIndex;
                cout << "Enter the task number to mark as completed: ";
                cin >> taskIndex;
                todoList.markTaskCompleted(taskIndex);
                break;
            }
            case 4: {
                int taskIndex;
                cout << "Enter the task number to remove: ";
                cin >> taskIndex;
                todoList.removeTask(taskIndex);
                break;
            }
            case 5:
                cout << "Exiting the program." << endl;
                return 0;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }

    return 0;
}

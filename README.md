[![Open in Visual Studio Code](https://classroom.github.com/assets/open-in-vscode-718a45dd9cf7e7f842a935f5ebbe5719a5e09af4491e668f4dbf3b35d5cca122.svg)](https://classroom.github.com/online_ide?assignment_repo_id=10960404&assignment_repo_type=AssignmentRepo)
# Priority Flow
 
 > Authors: \<[Jonathan Darius](https://github.com/Arkes123)\> \<[Jerry Li](https://github.com/Jeli04)\> \<[Subhon Ghosh](https://github.com/subGho)\> \<[Riyana Dutta](https://github.com/RiyanaD)\>

## Project Description

The idea of having an efficient way to track your tasks is for some people the cornerstone of their productivity, that’s why we see this project as an important contribution. The goal of our task manager is to provide users with an efficent way to list their tasks in a prioritized manner, store a student's courses and their respective assignments, and keep track of the events they need to attend. Another thing to note about our project is that it is a free and open source project, which isn’t very common amongst many productivity applications.

We plan on developing our project in the terminal using C++. Our project will have a terminal interface that allows the user to input their choices through input streams. 

The input of our project include user input prompts that allow the user to specify and edit details regarding their tasks, courses, and events. This includes the date, location, description, and priority of an item. Additional input includes the duration of an event, course instructor and the occuring days of a course.

The output of our project is a full display of the to-do list which includes all tasks, events, and courses. It can also display a list of all the users courses and the tasks assigned for that specific course. There is also an option to display the monthly calendar and the user can choose a day in that month to add tasks or view the to-do list for that day.

This application enables users to organize and document their tasks, courses, and events in a way that is efficient to them. The course list feature allows students to add all their courses to their schedule and input assignments for that specific course. When they view the course, it display all the tasks for that specific course. Another important feature is that they can pick the time of the day and priority they would like to allocate on the specific tasks and it will show up on their calendar and to-do list. Our project also stores all the tasks in a json file to save the tasks once the applications stop executing.

## User Interface Specification

### Navigation Diagram
![alt text](https://github.com/cs100/final-project-sghos026-jli793-rdutt010-jdari003/blob/master/images/updatedNavDiagram.png?raw=true)

This navigation diagram depicts how a user would navigate through the terminal to use our program. Our project is divided into four main sections for the user to navigate through: the home screen, course list, calendar, and task list. 

### Screen Layouts

This is the home menu selection screen which allows users to go into the calendar, task list, or course list.




![alt text](https://github.com/cs100/final-project-sghos026-jli793-rdutt010-jdari003/blob/master/images/currScreenLayout1.png?raw=true)
If a user chooses to open the calendar screen this is the calendar that appear. The user will also be given the option to go to a specific day.




![alt text](https://github.com/cs100/final-project-sghos026-jli793-rdutt010-jdari003/blob/master/images/currScreen2.png?raw=true)
If a user chooses to open the course list this is what is displayed. Each item that is a couse type is only displayed with the name of the course, the date, and its prioirty compared to other classes.




<!-- ![alt text](https://github.com/cs100/final-project-sghos026-jli793-rdutt010-jdari003/blob/master/images/screen-layout-4.png?raw=true) -->
If a user chooses to open the task list this is the task list that appears. The list shows what tasks they have including its date, description, and prioirty, and if its finished or not.
![alt text](https://github.com/cs100/final-project-sghos026-jli793-rdutt010-jdari003/blob/master/images/todoListLayout.png?raw=true)


## Class Diagram
![alt text](https://github.com/cs100/final-project-sghos026-jli793-rdutt010-jdari003/blob/master/images/updatedClassDiagram.png?raw=true)

**S:** We separate our classes based on responsibilities. For example, we have distinct classes for tasks, courses, and events. We also have separate classes for data management, user interaction, and data display. <br>
**O:** We establish friend relationships instead of inheritance to access the data stored in inherited variables. We also made the item class into a pure virtual class, so that we can create new instances of the Item class and add additional functions of that instance without modifying the functions of the item class, ensuring the open closed principle.
<br>
**L:** We made the edit and display function in the item class pure virtual to ensure abstraction of the different implementations of the edit and display functions throughout items’ derived classes.<br>
**I:** We create different friend or derived classes for different needs. Each class focuses on specific actions and does not share unnecessary functions with others.<br>
**D:** Our abstract "item" class forms the foundation for constructing various data sets and classes. Child and friend classes implement specific behaviors based on the described behavior in the item class.<br>

 
 ## Screenshots
<!--  > Screenshots of the input/output after running your application -->
 Opening prompt of PriorityFlow!
 ![alt text](https://github.com/cs100/final-project-sghos026-jli793-rdutt010-jdari003/blob/master/images/currScreenLayout1.png?raw=true)
 We can interact with our primary to do list.
 ![alt text](https://github.com/cs100/final-project-sghos026-jli793-rdutt010-jdari003/blob/master/images/screenAddTask.png?raw=true)
 Here is how we add tasks.
 ![alt text](https://github.com/cs100/final-project-sghos026-jli793-rdutt010-jdari003/blob/master/images/screenTaskAdded.png?raw=true)
 We can go back to our monthly view.
 ![alt text](https://github.com/cs100/final-project-sghos026-jli793-rdutt010-jdari003/blob/master/images/currScreen2.png?raw=true)
 We can view what assignments and courses we have on specific days within the current month.
 ![alt text](https://github.com/cs100/final-project-sghos026-jli793-rdutt010-jdari003/blob/master/images/dayView.png?raw=true)
 This is how we mark our to do items as complete.
 ![alt text](https://github.com/cs100/final-project-sghos026-jli793-rdutt010-jdari003/blob/master/images/markComplete.png?raw=true)
 
 
 ## Installation/Usage
 
Here are the instructions for installing or running our application:
1. Open a terminal on your local machine
2. Navigate to a directory where you would like to clone the repository using cd.
3. To recursively clone the repo, run the command: git clone --recursive https://github.com/cs100/final-project-sghos026-jli793-rdutt010-jdari003.git
4. Once you have the cloned repository on local machine run cmake .
5. Then run make
6. The bin file contains all of the runnable executables for Priority Flow. Run the command: ./bin/PriorityFlow
7. The program should now be running and the user should prompted with the Main Menu!

 ## Testing
 Our project utilized the Google Test framework to test each of our .cpp files from src folder. We had tested the functionality and the non-functionality part of our program to get a wide range of testing throughout our project. 

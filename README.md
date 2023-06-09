[![Open in Visual Studio Code](https://classroom.github.com/assets/open-in-vscode-718a45dd9cf7e7f842a935f5ebbe5719a5e09af4491e668f4dbf3b35d5cca122.svg)](https://classroom.github.com/online_ide?assignment_repo_id=10960404&assignment_repo_type=AssignmentRepo)
# Priority Flow
 
 > Authors: \<[Jonathan Darius](https://github.com/Arkes123)\> \<[Jerry Li](https://github.com/Jeli04)\> \<[Subhon Ghosh](https://github.com/subGho)\> \<[Riyana Dutta](https://github.com/RiyanaD)\>

## Project Description

The idea of having an efficient way to track your tasks is for some people the cornerstone of their productivity, that’s why we see this project as an important contribution. The interesting aspects of this project is ultimately going to come from learning about how to interact with users in an efficient way. Keeping in mind how users interact with our software is something that we will have to learn very quickly, and that experience within itself is an interesting goal. Another thing to note about our project is that it will be a free and open source project, which isn’t very common amongst many productivity applications.

We plan on developing our project in the terminal using C++. Our project will have a terminal interface that allows the user to input their choices through file streams and cin/getline statements.

The input of our project will be user inputted text into different boxes/sections that can create new tasks, reminders, or events in a calendar. The user should also have the ability to upload calendar files and also have the ability to edit multiple existing tasks, reminders, and events. 
The output of our project will be a calendar that displays upcoming or current tasks, reminders, and events in a month/week/day format. 

This application will enable users to create a schedule of their day and layout their tasks in a way that is efficient to them. When they input the tasks they can pick the time of the day and priority they would like to allocate on the specific tasks and it will show up on their calendar and to-do list. The application will also send users reminders of their pending tasks on that certain day. 

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




![alt text](https://github.com/cs100/final-project-sghos026-jli793-rdutt010-jdari003/blob/master/images/screen-layout-4.png?raw=true)
If a user chooses to open the task list this is the task list that appears. The list shows what tasks they have including its date, description, and prioirty, and if its finished or not.
![alt text](https://github.com/cs100/final-project-sghos026-jli793-rdutt010-jdari003/blob/master/images/todoListLayout.png?raw=true)


## Class Diagram
![alt text](https://github.com/cs100/final-project-sghos026-jli793-rdutt010-jdari003/blob/master/images/class-diagram.drawio-2.png?raw=true)

**S:** We separate our classes based on responsibilities. For example, we have distinct classes for tasks, courses, and events. We also have separate classes for data management, user interaction, and data display. <br>
**O:** We establish friend relationships instead of inheritance to access the data stored in inherited variables. We also made the item class into a pure virtual class, so that we can create new instances of the Item class and add additional functions of that instance without modifying the functions of the item class, ensuring the open closed principle.
<br>
**L:** We made the edit and display function in the item class pure virtual to ensure abstraction of the different implementations of the edit and display functions throughout items’ derived classes.<br>
**I:** We create different friend or derived classes for different needs. Each class focuses on specific actions and does not share unnecessary functions with others.<br>
**D:** Our abstract "item" class forms the foundation for constructing various data sets and classes. Child and friend classes implement specific behaviors based on the described behavior in the item class.<br>

 
 > ## Final deliverable
 > All group members will give a demo to the reader during lab time. ou should schedule your demo on Calendly with the same reader who took your second scrum meeting. The reader will check the demo and the project GitHub repository and ask a few questions to all the team members. 
 > Before the demo, you should do the following:
 > * Complete the sections below (i.e. Screenshots, Installation/Usage, Testing)
 > * Plan one more sprint (that you will not necessarily complete before the end of the quarter). Your In-progress and In-testing columns should be empty (you are not doing more work currently) but your TODO column should have a full sprint plan in it as you have done before. This should include any known bugs (there should be some) or new features you would like to add. These should appear as issues/cards on your Project board.
 > * Make sure your README file and Project board are up-to-date reflecting the current status of your project (e.g. any changes that you have made during the project such as changes to your class diagram). Previous versions should still be visible through your commit history. 
 
 ## Screenshots
 > Screenshots of the input/output after running your application
 ![alt text](https://github.com/cs100/final-project-sghos026-jli793-rdutt010-jdari003/blob/master/images/currScreenLayout1.png?raw=true)
 ![alt text](https://github.com/cs100/final-project-sghos026-jli793-rdutt010-jdari003/blob/master/images/screenAddTask.png?raw=true)
 ![alt text](https://github.com/cs100/final-project-sghos026-jli793-rdutt010-jdari003/blob/master/images/screenTaskAdded.png?raw=true)
 ![alt text](https://github.com/cs100/final-project-sghos026-jli793-rdutt010-jdari003/blob/master/images/currScreen2.png?raw=true)
 ![alt text](https://github.com/cs100/final-project-sghos026-jli793-rdutt010-jdari003/blob/master/images/dayView.png?raw=true)
 ![alt text](https://github.com/cs100/final-project-sghos026-jli793-rdutt010-jdari003/blob/master/images/markComplete.png?raw=true)
 
 
 ## Installation/Usage
 
Here are the instructions for installing or running our application:
1. First when you have the files from the repository, your going to want to run cmake .
2. After running that command, your program should be ready to fully compile, so then run make
3. After you've run make, you should be in the root directory (project repository)
4. While in the project repository move into the (project repository/bin)
5. The bin file contains all of the runnable executables for Priority Flow and once your in the bin folder run this command: ./PriorityFlow
6. After that your program should work!

 ## Testing
 Our project was tested through the google test suite by testing each of our .cpp files from src folder. We had tested the functionality and the non-functionality part of our program to get a wide range of testing throughout our project.
 

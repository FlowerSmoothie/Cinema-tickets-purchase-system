**This project is my course project from the second year of university on "object-oriented design and programming.**

The application is a system for managing the workflow of a cinema, or a system build for selling tickets specifically. The software features include:
- management of movie billboard, through which it is possible to purchase tickets;
  - purchasing tickets envolves generation of a receipt in the specific folder;
- storage of information about cinemas, movies, movie shows as well as tickets for them;
  - _user_ with normal role can view the billboard and buy tickets for interesting showings;
  - _content manager_ could do everything an usual user could, as well as managing data about movies stored in the database;
  - _showing manger_ could do everything an usual user could, as well as managing data about movie showings in the database and tickets for them;
  - _administrator_ could do everything listed above, as well as managing list of users (confirming users, changing their roles, blocking and unblocking), the basic administrator login and password is admin - admin;
- stored passwords are hashed using the SHA-256 algorithm.


The software is developed in C++ as a console application. The data is stored in various files.

The principles of object-oriented programming have been implemented in this application. Implemented 10 classes, including abstract. They were used to transfer parameters by reference and meaning. Built-in and custom namespaces were used, as well as template classes and methods, static fields and methods, overloading methods and operators, redefining methods etc.

Algorithms for functions were developed: main menu, authorization and registration forms, menu of user modules, session and content managers, administrator, search algorithms, sorting, etc. Also among them: user functions that allow to work with movies, movie theaters, shows and tickets (such as viewing, editing, adding, etc.) and with users of the program (registration, authorization, blocking, role switching), as well as other functions and methods that make the program complete. All the modules present in the software are important, and they all work well together, complementing each other where necessary.

<br/>

Some screenshots of work:

- Main menu of the application
  
  <img width="1092" height="501" alt="Image" src="https://github.com/user-attachments/assets/938aeaf9-91f5-4515-9e1d-47bcec17c0dd" />

- Registration of the user
  
  <img width="805" height="178" alt="Image" src="https://github.com/user-attachments/assets/2d4d74a6-174a-402d-98dd-f89c2df6b2dd" />

- Menu of an usual user
  
  <img width="283" height="154" alt="Image" src="https://github.com/user-attachments/assets/313c41b5-95a1-4c22-b2f4-b46a5e152628" />

- User account information
  
  <img width="330" height="404" alt="Image" src="https://github.com/user-attachments/assets/55a83211-22e6-4b1c-a890-6f7fe65eb647" />

- The movie billboard showing
  
  <img width="941" height="125" alt="Image" src="https://github.com/user-attachments/assets/86a0f92f-1efe-428a-8ea9-a3b0ceb450e5" />

- Movie showing information
  
  <img width="1093" height="235" alt="Image" src="https://github.com/user-attachments/assets/d9e67d00-d107-47fa-ac0e-6ef95329538d" />

- The interface to buy tickets to the showing
  
  <img width="691" height="316" alt="Image" src="https://github.com/user-attachments/assets/382ae2ca-be95-49df-8c81-06c04615b31e" />

- The information about ordered tickets
  
  <img width="346" height="274" alt="Image" src="https://github.com/user-attachments/assets/36117225-816b-4e47-abe0-8eef5edfe445" />

- Sample receipt of buying a ticket
  
  <img width="374" height="218" alt="Image" src="https://github.com/user-attachments/assets/2cc56962-05d3-4925-b926-713175f3534d" />

- Menu of an administrator
  
  <img width="518" height="270" alt="Image" src="https://github.com/user-attachments/assets/9a51e6cf-7d91-412e-a9c8-4048f6c6946b" />

- Movie statistics menu
  
  <img width="675" height="104" alt="Image" src="https://github.com/user-attachments/assets/5ee0d47b-34a7-473f-8607-92b5e6de6949" />

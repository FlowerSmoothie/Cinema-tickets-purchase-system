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

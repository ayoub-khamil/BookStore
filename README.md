# bookStore

A simple C++ console-based bookstore management system using text files as a database.

## Features

- **Admin**: Full system access — can manage all users, authors, and books.
- **Author**: Can create, update, and delete their own books. Also able to view comments left by users.
- **User**: Can browse books, buy or discard them, and leave comments.
- **Comment System**: Users can post comments on books.
- **Role-Based Design**: Each user role has different capabilities.
- **Inheritance Structure**:
  - `Person` base class inherited by `User` and `Author`
  - `Screen` base class for all app screens
- **Helper Classes**: `Util`, `Date`, and `Input` for utilities and input handling.

## How to Run

1. Open the project in **Microsoft Visual Studio**.
2. Build and run the solution (`Project1.sln`).
3. All source files are located under the `Project1` directory.

## Data Storage

- Data is persisted using `.txt` files.
- Each entity (books, users, etc.) has its own corresponding text file.

## Requirements

- C++ (Tested using MSVC in Visual Studio)
- Windows environment recommended

## Known Issues

- Bugs present in the **User screen** when viewing or buying books.
- No input validation or error handling for invalid user actions.
- Data format in text files is fragile — prone to break if files are edited manually.

## Notes

This is an old, beginner-level project meant to demonstrate OOP principles and basic file handling in C++.

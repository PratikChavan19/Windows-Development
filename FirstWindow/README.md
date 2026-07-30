-------------------------------------------------------------------------------------------------------------------------------------------------------------------

# Win32 First Window Application

A beginner-level Windows Desktop application built using the **Win32 API** in C. This project demonstrates the fundamental structure of a native Windows application, including window creation, message handling, and the event-driven programming model.

-------------------------------------------------------------------------------------------------------------------------------------------------------------------

## Features

- Register a custom window class using `RegisterClassEx()`
- Create a native Windows window with `CreateWindow()`
- Display and update the application window
- Implement the standard Windows message loop
- Handle `WM_DESTROY` to close the application gracefully
- Uses the default Windows cursor and application icon

-------------------------------------------------------------------------------------------------------------------------------------------------------------------

## Technologies Used

- C Programming
- Win32 API
- Windows SDK
- Microsoft Visual Studio
- MSVC Compiler (`cl.exe`)

-------------------------------------------------------------------------------------------------------------------------------------------------------------------

## Project Structure

```
.
├── Window.c
└── README.md
```

-------------------------------------------------------------------------------------------------------------------------------------------------------------------

## Concepts Covered

- WinMain Entry Point
- WNDCLASSEX Structure
- RegisterClassEx()
- CreateWindow()
- ShowWindow()
- UpdateWindow()
- Windows Message Loop
- GetMessage()
- TranslateMessage()
- DispatchMessage()
- Window Procedure (`WndProc`)
- DefWindowProc()
- PostQuitMessage()

-------------------------------------------------------------------------------------------------------------------------------------------------------------------

## Steps to Run

### 1. Open the **Developer Command Prompt for Visual Studio**

Navigate to the project directory.

### 2. Compile the source file

```cmd
cl.exe /c /EHsc Window.c
```

### 3. Link the object file

```cmd
link.exe Window.obj user32.lib gdi32.lib /SUBSYSTEM:WINDOWS
```

### 4. Run the application

```cmd
Window.exe
```

-------------------------------------------------------------------------------------------------------------------------------------------------------------------

## Output

The application creates a standard Windows desktop window with the title:

```
SHIVA WinDev-2026 : First Window
```

The window remains active until it is closed. When the user closes the window, the application exits gracefully.

-------------------------------------------------------------------------------------------------------------------------------------------------------------------

## Learning Objectives

This project helps understand:

- Windows application architecture
- Event-driven programming
- Window class registration
- Window creation using the Win32 API
- Windows message handling
- Basic GUI programming in C

-------------------------------------------------------------------------------------------------------------------------------------------------------------------

## Future Enhancements

- Handle keyboard input
- Handle mouse events
- Draw graphics using GDI
- Display text using GDI
- Add menus and custom icons
- Implement fullscreen mode
- Handle window resizing
- Add timers and animations
- Double buffering for smooth rendering

-------------------------------------------------------------------------------------------------------------------------------------------------------------------

## Author

**Pratik Chavan**

Learning Win32 API and Windows System Programming.

-------------------------------------------------------------------------------------------------------------------------------------------------------------------

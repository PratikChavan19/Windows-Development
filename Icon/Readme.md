------------------------------------------------------------------------------------------------------------------------------------------------------------------

# First Window with Custom Icon

A beginner-level **Win32 API** application written in C that demonstrates native Windows window creation with a **custom application icon** and header file integration.

This project is part of my **Windows Development** learning journey and focuses on understanding the basic structure of a Win32 desktop application.

------------------------------------------------------------------------------------------------------------------------------------------------------------------

## Features

* Creates a native Windows desktop window using the Win32 API.
* Registers a custom window class using `WNDCLASSEX`.
* Uses a separate header file (`Window.h`).
* Loads a custom application icon using a Windows resource identifier.
* Uses the custom icon for both the main window icon and the small window icon.
* Implements the standard Windows message loop.
* Handles `WM_DESTROY` to terminate the application gracefully.

------------------------------------------------------------------------------------------------------------------------------------------------------------------

## Technologies Used

* C
* Win32 API
* Windows SDK
* Microsoft Visual C++ (MSVC)
* Windows Resource Files

------------------------------------------------------------------------------------------------------------------------------------------------------------------

## Project Structure

```text
FirstWindowWithIcon/
│
├── Window.c
├── Window.h
├── Window.rc
├── GOAT.ico
└── README.md
```

> **Note:** The exact resource/header filenames may vary depending on the project structure.

------------------------------------------------------------------------------------------------------------------------------------------------------------------

## Win32 Concepts Covered

### Window Class

The application initializes a `WNDCLASSEX` structure and registers the window class using:

```c
RegisterClassEx(&myWindowClass);
```

### Window Creation

The application creates the window using:

```c
CreateWindow();
```

The window is then displayed and updated using:

```c
ShowWindow();
UpdateWindow();
```

### Custom Icon

Unlike the basic First Window application, this version loads a custom icon using:

```c
LoadIcon(hInstance, MAKEINTRESOURCE(GOAT_ICON));
```

The same custom icon is assigned to both:

```c
myWindowClass.hIcon
myWindowClass.hIconSm
```

This demonstrates how Windows resources can be integrated into a Win32 application.

### Message Loop

The application continuously processes Windows messages using:

```c
while (GetMessage(&msg, NULL, 0, 0))
{
    TranslateMessage(&msg);
    DispatchMessage(&msg);
}
```

### Window Procedure

The `WndProc()` function handles messages sent to the window.

Currently, the application handles:

```c
WM_DESTROY
```

and calls:

```c
PostQuitMessage(0);
```

to terminate the application.

## Build and Run

This project requires the **Developer Command Prompt for Visual Studio** or an equivalent MSVC build environment.

### Compile

```cmd
cl.exe /c /EHsc Window.c
```

### Link

If the application uses a resource file containing the custom icon, compile the resource file first:

```cmd
rc.exe Window.rc
```

Then link:

```cmd
link.exe Window.obj Window.res user32.lib gdi32.lib /SUBSYSTEM:WINDOWS
```

### Run

```cmd
Window.exe
```

------------------------------------------------------------------------------------------------------------------------------------------------------------------

## Output

The application creates a standard Windows desktop window with the title:

```text
SHIVA WinDev-2026 : First Window
```

The custom icon is displayed as the application's window icon.

------------------------------------------------------------------------------------------------------------------------------------------------------------------

## Learning Objectives

This project helps understand:

* Win32 application structure
* `WinMain()` entry point
* `WNDCLASSEX`
* Window class registration
* Native window creation
* Windows message loop
* Window procedures
* Windows resources
* Custom application icons
* Header file integration
* MSVC compilation and linking

------------------------------------------------------------------------------------------------------------------------------------------------------------------ 

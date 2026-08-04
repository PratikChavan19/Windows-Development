-------------------------------------------------------------------------------------------------------------------------------------------------------------------

# First Window with Batch File

A beginner-level **Win32 API** application written in C that demonstrates the creation of a native Windows desktop window. This version includes a **batch file** to automate the compilation and linking process using the Microsoft Visual C++ (MSVC) toolchain.

-------------------------------------------------------------------------------------------------------------------------------------------------------------------

## Features

- Create a native Windows desktop application using the Win32 API
- Register a custom window class
- Create and display a standard overlapped window
- Implement the Windows message loop
- Handle `WM_DESTROY` for graceful application termination
- One-click build using a batch file

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
├── build.bat
└── README.md
```

-------------------------------------------------------------------------------------------------------------------------------------------------------------------

## Concepts Covered

- WinMain Entry Point
- WNDCLASSEX
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
- Batch file automation

-------------------------------------------------------------------------------------------------------------------------------------------------------------------

## Steps to Run

### Method 1: Using the Batch File (Recommended)

1. Open the **Developer Command Prompt for Visual Studio**.
2. Navigate to the project directory.
3. Run:

```cmd
build.bat
```

The batch file will:
- Clear the console.
- Delete any existing `.exe` and `.obj` files.
- Compile `Window.c`.
- Link the executable.

Run the generated executable:

```cmd
Window.exe
```

---

### Method 2: Manual Build

Compile:

```cmd
cl.exe /c /EHsc Window.c
```

Link:

```cmd
link.exe Window.obj user32.lib gdi32.lib /SUBSYSTEM:WINDOWS
```

Run:

```cmd
Window.exe
```

-------------------------------------------------------------------------------------------------------------------------------------------------------------------

## Output

The application creates a standard Windows desktop window titled:

```
SHIVA WinDev-2026 : First Window
```

The application exits cleanly when the window is closed.

-------------------------------------------------------------------------------------------------------------------------------------------------------------------

## Learning Objectives

- Understand the structure of a Win32 application
- Learn the Windows message-driven architecture
- Build native GUI applications using the Win32 API
- Automate compilation and linking using Windows batch scripts

-------------------------------------------------------------------------------------------------------------------------------------------------------------------

## Future Enhancements

- Keyboard input handling
- Mouse input handling
- GDI graphics rendering
- Custom icons and menus
- Fullscreen mode
- Window resizing support
- Double buffering
- Resource files (.rc)

-------------------------------------------------------------------------------------------------------------------------------------------------------------------

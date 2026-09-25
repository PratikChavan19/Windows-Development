# MessageBox – Windows Development 🪟

-------------------------------------------------------------------------------------------------------------------------------------------------------------------

## 📌 Project Overview

A Windows Desktop Development project using the **Win32 API** to create a native Windows application and handle window lifecycle messages.

This project demonstrates how to:

* Register a Windows window class using `WNDCLASSEX`.
* Create a native application window using `CreateWindow`.
* Display message boxes using the `MessageBox` API.
* Handle `WM_CREATE` and `WM_DESTROY` window messages.
* Implement the Windows message loop using `GetMessage`, `TranslateMessage`, and `DispatchMessage`.

The project is part of my ongoing learning journey in Windows API programming and system-level software development.

-------------------------------------------------------------------------------------------------------------------------------------------------------------------

## 🎯 Learning Objectives

* Understand the basic structure of a Win32 GUI application.
* Learn the purpose of the `WinMain` entry-point function.
* Understand window class registration and window creation.
* Explore the Windows message-driven programming model.
* Handle window lifecycle events using a window procedure.
* Learn how to display informational dialogs using the Windows API.

-------------------------------------------------------------------------------------------------------------------------------------------------------------------

## ⚙️ Application Workflow

```text
Application Entry (WinMain)
          |
          v
Initialize WNDCLASSEX
          |
          v
Register Window Class
          |
          v
Create Window
          |
          v
Show and Update Window
          |
          v
Start Windows Message Loop
          |
          v
Dispatch Messages to WndProc
          |
          v
Handle WM_CREATE / WM_DESTROY
          |
          v
Display MessageBox
```

-------------------------------------------------------------------------------------------------------------------------------------------------------------------

## 🧠 Win32 API Concepts

### 1. WinMain

The `WinMain` function acts as the entry point of the Windows application.

It performs the following operations:

* Declares and initializes the window class.
* Registers the window class.
* Creates the application window.
* Displays and updates the window.
* Starts the Windows message loop.

### 2. WNDCLASSEX

The `WNDCLASSEX` structure is used to configure the window class.

The implementation configures:

* Window procedure callback (`WndProc`)
* Window class name
* Background brush
* Cursor
* Window icons
* Application instance

### 3. CreateWindow

The application creates a window using the `CreateWindow` function.

The window title configured in the source code is:

```text
SHIVA WinDev-2026 : First Window
```

### 4. Windows Message Loop

The application processes Windows messages using:

```cpp
while (GetMessage(&msg, NULL, 0, 0))
{
    TranslateMessage(&msg);
    DispatchMessage(&msg);
}
```

The message loop retrieves messages, translates keyboard input messages when applicable, and dispatches messages to the window procedure.

-------------------------------------------------------------------------------------------------------------------------------------------------------------------

## 💬 MessageBox Event Handling

The application handles two window messages in `WndProc`.

### WM_CREATE

When the window receives the `WM_CREATE` message, the application displays an informational message box.

**Message:**

```text
WM_CREATE Message Received.
```

**Configuration:**

```cpp
MessageBox(
    hwnd,
    TEXT("WM_CREATE Message Received."),
    TEXT("Message"),
    MB_OK | MB_ICONINFORMATION
);
```

### WM_DESTROY

When the window receives the `WM_DESTROY` message, the application displays an informational message box.

**Message:**

```text
WM_DESTROY Message Received.
```

The application then calls:

```cpp
PostQuitMessage(0);
```

This posts a quit message to the application's message queue, allowing the message loop to terminate.

-------------------------------------------------------------------------------------------------------------------------------------------------------------------

## 🛠️ Technologies Used

| Technology          | Purpose                                      |
| ------------------- | -------------------------------------------- |
| C                   | Application implementation                   |
| Windows API (Win32) | Native Windows application development       |
| `WNDCLASSEX`        | Window class configuration                   |
| `CreateWindow`      | Window creation                              |
| `MessageBox`        | Displaying modal message boxes               |
| `WndProc`           | Handling window messages                     |
| `GetMessage`        | Retrieving messages                          |
| `DispatchMessage`   | Dispatching messages to the window procedure |

-------------------------------------------------------------------------------------------------------------------------------------------------------------------

## ▶️ How to Build and Run

### Prerequisites

* Microsoft Windows
* A C compiler supporting the Windows API
* Windows SDK
* Visual Studio or another compatible development environment

### Build

Open the project in your Windows development environment and compile the source file together with its required header and resource definitions.

The source includes:

```cpp
#include "Window.h"
```

Ensure that the corresponding header file is available and that the `GOAT_ICON` resource identifier is defined in the project.

### Run

Execute the generated Windows application.

The application creates the window and displays informational message boxes when the corresponding window lifecycle messages are received.

-------------------------------------------------------------------------------------------------------------------------------------------------------------------

## 📚 Key Learning Outcomes

Through this project, I am learning:

* Win32 API programming fundamentals.
* Native Windows application structure.
* Window class registration and creation.
* Event-driven programming using the Windows message loop.
* Window procedure callbacks.
* Handling window creation and destruction events.
* Using Windows API functions for user interaction.

-------------------------------------------------------------------------------------------------------------------------------------------------------------------

## 🚀 Future Enhancements

Potential improvements include:

* Handling additional window messages.
* Adding keyboard and mouse event handling.
* Implementing custom window painting using `WM_PAINT`.
* Exploring menu creation and command handling.
* Learning Windows resource management.
* Expanding the project into a more interactive Win32 application.

-------------------------------------------------------------------------------------------------------------------------------------------------------------------

## 👨‍💻 Author

**Pratik Chavan**

Software Engineer | C/C++ Developer | Windows Development Learner

Exploring Windows API programming, system-level development, and software engineering through practical implementations.

-------------------------------------------------------------------------------------------------------------------------------------------------------------------

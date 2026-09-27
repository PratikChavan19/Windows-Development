# HelloWorld 🪟

A basic Windows GUI application developed using **C** and the **Win32 API** to understand the fundamentals of Windows application development, window creation, message handling, and GDI-based text rendering.

This repository is part of the **Windows Development** learning series and demonstrates the basic architecture and lifecycle of a native Win32 application.

---

## 📌 About the Repository

The objective of this project is to understand how a basic Windows GUI application is created and how Windows communicates with an application through messages.

The application demonstrates:

- Creating a native Windows application
- Registering a custom window class
- Creating and displaying a window
- Implementing a Windows message loop
- Handling window messages using `WndProc`
- Processing `WM_CREATE`, `WM_PAINT`, and `WM_DESTROY`
- Obtaining a Device Context (`HDC`)
- Rendering text using Windows GDI
- Working with the client area of a window

The application displays the following message in the center of the window:

```text
Hello World, WinDev-2026!

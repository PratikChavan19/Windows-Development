-------------------------------------------------------------------------------------------------------------------------------------------------------------------

# MulticolouredWindow

A collection of Windows GUI applications developed using **C and the Win32 API** to explore event-driven programming, window message handling, timer-based updates, and dynamic background color changes.

This repository demonstrates how a Windows application's appearance and behavior can be controlled through keyboard events, mouse interactions, timers, and music-assisted timer functionality.

-------------------------------------------------------------------------------------------------------------------------------------------------------------------

## 📌 About the Repository

The objective of this repository is to understand how Windows messages and timer events can be used to create interactive and dynamic GUI applications.

The repository contains four implementations:

- **OnKeyPress** – Changes the window's behavior or appearance in response to keyboard input.
- **OnLeftMouseButtonClick** – Responds to left mouse button clicks.
- **OnTimer** – Uses timer events to trigger periodic updates to the window.
- **OnTimerWithMusic** – Combines timer-based behavior with music-related functionality.

These applications provide practical exposure to the Windows message-driven programming model and the use of the Win32 API to build interactive desktop applications.

-------------------------------------------------------------------------------------------------------------------------------------------------------------------

## 📚 Applications Included

### 1. OnKeyPress ⌨️

Demonstrates keyboard-driven interaction in a Windows GUI application.

**Concepts covered:**
- Keyboard event handling
- `WM_KEYDOWN` and keyboard messages
- Window procedure (`WndProc`)
- Processing user input
- Dynamic window behavior

### 2. OnLeftMouseButtonClick 🖱️

Demonstrates handling left mouse button clicks within a Windows window.

**Concepts covered:**
- Mouse event handling
- `WM_LBUTTONDOWN`
- Windows message processing
- Mouse interaction
- Event-driven programming

### 3. OnTimer ⏱️

Demonstrates timer-based updates in a Windows GUI application.

**Concepts covered:**
- Timer creation and handling
- `SetTimer()`
- `WM_TIMER`
- Periodic event processing
- Dynamic window updates
- Windows message loop

### 4. OnTimerWithMusic 🎵

Explores timer-based window behavior combined with music-related functionality.

**Concepts covered:**
- Timer events
- `SetTimer()` and `WM_TIMER`
- Event-driven programming
- Multimedia integration
- Coordinating timer-based updates with music-related behavior

*The exact behavior and implementation details of each application depend on the source code in its respective directory.*

-------------------------------------------------------------------------------------------------------------------------------------------------------------------

## 🧠 Core Win32 Concepts

### Windows Message Handling

Windows applications receive messages from the operating system in response to user interactions and system events. The `WndProc()` function processes these messages and determines the application's response.

### Keyboard Events

Keyboard messages allow applications to respond to key presses and implement keyboard-driven interactions.

### Mouse Events

Mouse messages allow applications to detect user interactions, such as pressing the left mouse button.

### Timer Events

The Win32 timer mechanism allows an application to receive periodic `WM_TIMER` messages. Timers can be used to trigger repeated updates without requiring a continuously running manual loop.

### Event-Driven Programming

The applications demonstrate how Windows GUI programs respond to events instead of executing all their behavior sequentially.

-------------------------------------------------------------------------------------------------------------------------------------------------------------------

## 📂 Repository Structure

```text
MulticolouredWindow/
│
├── OnKeyPress/
│
├── OnLeftMouseButtonClick/
│
├── OnTimer/
│
├── OnTimerWithMusic/
│
└── README.md
```

Each directory contains a separate implementation demonstrating a particular interaction or event-handling technique.

-------------------------------------------------------------------------------------------------------------------------------------------------------------------

## 🛠️ Technologies Used

- C
- Win32 API
- Windows GUI Programming
- Windows Message Handling
- Windows Timer Mechanism
- Visual Studio
- Windows Desktop Application Development

-------------------------------------------------------------------------------------------------------------------------------------------------------------------

## ▶️ Getting Started

### Clone the Repository

```bash
git clone https://github.com/PratikChavan19/Windows-Development.git
cd Windows-Development/MulticolouredWindow
```

### Run an Application

1. Open the desired application directory.
2. Open its project in Visual Studio, or create a Windows Desktop project using the provided source files.
3. Ensure that the required source files, header files, resources, and dependencies are included.
4. Build the application.
5. Run the executable and interact with the window using the input or timer behavior implemented in that directory.

**Note:** These are Windows-specific applications and require a compatible Windows development environment.

-------------------------------------------------------------------------------------------------------------------------------------------------------------------

## 🎯 Learning Objectives

Through this repository, I aim to:

- Understand the Win32 message-driven programming model.
- Handle keyboard and mouse input.
- Implement timer-based application behavior.
- Understand Windows timer messages.
- Explore interactive GUI development using C.
- Learn how event handlers modify application behavior.
- Explore the integration of multimedia functionality into Windows applications.
- Strengthen my understanding of Windows application architecture.

-------------------------------------------------------------------------------------------------------------------------------------------------------------------

## 🚀 Future Enhancements

Possible improvements include:

- Add additional keyboard event handlers.
- Support more mouse interactions.
- Introduce configurable timer intervals.
- Add more dynamic window color transitions.
- Improve timer-based animations.
- Extend multimedia functionality.
- Add additional Win32 message-handling examples.
- Explore Windows GDI drawing and animation techniques.

-------------------------------------------------------------------------------------------------------------------------------------------------------------------

## 🤝 Contributions

This repository is primarily maintained as a personal learning and practice project.

Suggestions, improvements, and alternative implementations are welcome.

-------------------------------------------------------------------------------------------------------------------------------------------------------------------

## ⭐ Support

If you find this repository useful for learning Windows development, consider giving it a star.

-------------------------------------------------------------------------------------------------------------------------------------------------------------------

## 👨‍💻 Author

**Pratik Chavan**

Software Engineer | C++ | System Programming | Windows Development

Passionate about systems programming, Windows development, software engineering, and continuous learning through practical implementation.

-------------------------------------------------------------------------------------------------------------------------------------------------------------------

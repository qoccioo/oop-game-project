# OOP Game Project (C++)

Project for the discipline **Object-Oriented Programming**.  
The project represents a turn-based console game implemented in C++ with an event-driven architecture.

---

## 📌 Project Overview

The game is built around classical OOP principles and design patterns:
- **Command Pattern** — for handling user input
- **Event Dispatcher** — for decoupled communication between subsystems
- **MVC-like separation** — game logic, rendering, and input are separated
- **Configurable controls** — key bindings are loaded from a configuration file

The application runs in a terminal and visualizes the game field using Unicode symbols.

---

## 🧩 Key Features

- Turn-based gameplay
- Player, enemies, allies, traps, towers, and buildings
- Event-driven logging system
- Console visualization
- Save / Load game state
- Configurable key bindings
- Modular and extensible architecture

---

## 🏗 Project Structure

```text
oop-game-project/
├── app/        
├── config/         # Configuration file 
├── examples/      
├── include/        # Header files
├── src/            # Source files
├── CMakeLists.txt
├── Makefile
└── README.md
```
---

## ⚙️Build Instructions
Makefile is provided for convenience: 
- make

---

## ▶️ Run
After building, run the executable from the build directory:
./GameCLI

---

## 🎮 Controls
Key bindings are configurable via the file:
config/keymap.cfg

Example configuration:

- move_up = w
- move_down = s
- move_left = a
- move_right = d
- use_spell = z
- toggle_mode = t
- save = p
- load = l
- quit = q

---

## 🖥 Platform Support

The project is cross-platform and can be built on:
- Windows
- Linux
- macOS

---


Console rendering uses Unicode symbols.

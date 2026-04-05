
# 🏓 Raylib Pong Game (C++)

A simple **Pong-style game** built using **C++ and Raylib**, featuring two-player controls, collision physics, and dynamic ball movement.

---

## 🚀 Features

- 🎮 Two-player gameplay  
  - Left Paddle → `W` (up), `S` (down)  
  - Right Paddle → `↑` (up), `↓` (down)

- ⚡ Smooth movement using `GetFrameTime()` (frame-independent physics)

- 🧠 Ball collision mechanics:
  - Bounces off top and bottom walls
  - Interacts with paddles
  - Angle changes based on impact point

- 📈 Progressive difficulty:
  - Ball speed increases after each paddle hit

- 🏆 Win detection:
  - Displays winner when ball exits screen

- 🔄 Restart system:
  - Press `SPACE` to reset game

---

## 🛠️ Built With

- **Language:** C++  
- **Graphics Library:** [Raylib](https://www.raylib.com/)  

---

## 📦 Installation & Setup

### 1. Install Raylib

Follow official instructions:  
👉 https://www.raylib.com/

Or (Linux/WSL example):

```bash
sudo apt install libraylib-dev 

# Compilation 

g++ hello.cpp -o game -lraylib -lGL -lm -lpthread -ldl -lrt -lX1
./game



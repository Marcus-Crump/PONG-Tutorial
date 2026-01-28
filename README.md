# PONG-Tutorial (Win32 / C++)

## Overview
A Win32 + C++ learning project organized as incremental snapshots (CPP1–CPP4). Each CPP file is a runnable step that builds up from a blank window to a simple Pong-style game loop with input, rendering, and collisions.
## Status
### Incomplete
## What’s Implemented
- Win32 window creation + message loop (CPP1)
- Software rendering primitives via a small renderer module (CPP2 / renderer.cpp)
- Keyboard input state tracking (platformCommon.cpp, util.cpp)
- Game loop + state update + basic Pong gameplay/collision handling (CPP3–CPP4, game.cpp)

## What's Missing
- A score counter
- Something to check for and end game state and a winner
- Basic NPC logic for a single player mode
- Options for single or multiplayer

At this time, I have no intention on adding these features as I have gained the skills needed from this to apply to future projects. However, this is a playable demo.

## Repo Layout
- `CPP1WindowsandPointers.cpp` — window setup
- `CPP2DrawingGraphics.cpp` — basic rendering
- `CPP3InputMovementandTime.cpp` — input + timing + game state plumbing
- `CPP4GameplayCollisionsBetterMovement.cpp` — gameplay + collisions
- `renderer.cpp` — drawing routines
- `platformCommon.cpp` — button states
- `util.cpp` — small helpers (e.g., clamp)
- `game.cpp` — game state + update logic

## Build (MinGW g++)
From the repo root:
```bash
g++ -std=c++17 CPP4GameplayCollisionsBetterMovementandTime.cpp renderer.cpp platformCommon.cpp util.cpp game.cpp -o pong.exe -lgdi32

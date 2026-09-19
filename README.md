# C Console Tetris

A Tetris implementation in C built from scratch to practice game loops,
collision detection, rendering, and core programming concepts.

## Goals

Getting the hang of Github while rebuilting this project from scratch as a programming exercise. 

The main goals are to:

- understand how game state is represented
- implement collision detection
- understand the input-update-render game loop
- practice modular program design
- **learn debugging through incremental development**
- maintain development history **using Git**

## Current Progress

**Current phase:** Phase 1 — Console & Stage

Currently working on:
> rendering active blocks

Next:
> Phase 3 — Player Control

## Controls

| Key | Action |
|---|---|
| ← | Move left |
| → | Move right |
| ↓ | Soft drop |
| ↑ | Rotate |
| Space | Hard drop |

## Development Roadmap

### Phase 1 — Console & Stage
- [x] Initialize Windows console
- [x] Hide console cursor
- [x] Enable UTF-8 output
- [x] Draw the game stage
- [x] Create `stageInfo` board representation
- [x] Initialize walls and empty cells

### Phase 2 — Tetromino System
- [x] Define tetromino shapes using 4×4 matrices
- [ ] Store active block position
- [ ] Store active block type and rotation
- [ ] Render the active block

### Phase 3 — Player Control
- [ ] Move block left and right
- [ ] Soft drop
- [ ] Rotate block
- [ ] Prevent movement through walls

### Phase 4 — Collision & Locking
- [ ] Implement collision detection
- [ ] Detect collision with the floor
- [ ] Detect collision with locked blocks
- [ ] Lock the active block into the board

### Phase 5 — Game Loop
- [ ] Add automatic gravity
- [ ] Spawn a new block after locking
- [ ] Implement lock delay
- [ ] Detect game over

### Phase 6 — Line Clearing
- [ ] Detect completed rows
- [ ] Clear completed rows
- [ ] Move upper rows downward

### Phase 7 — Additional Gameplay
- [ ] Add next-piece preview
- [ ] Add ghost piece
- [ ] Add hard drop
- [ ] Add scoring
- [ ] Add levels and increasing fall speed

### Phase 8 — Refactoring
- [ ] Separate rendering from game state
- [ ] Reduce unnecessary global variables
- [ ] Organize functions by responsibility
- [ ] Add comments for important algorithms
- [ ] Document controls and architecture
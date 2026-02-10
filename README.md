# Agentless LLM Tool Execution

This repository demonstrates a **clean, testable C++ architecture** for handling
AI / LLM tool calls using an **explicit state machine** instead of ad-hoc control
flow (`if/else`, retries hidden in logic, etc).

The goal is to show how modern AI-driven systems (agents, tools, MCP-like servers)
can be built with **deterministic, unit-testable core logic**, suitable for
production systems.

---

## Why this repository exists

Most AI / agent examples today:
- Mix business logic with retries and error handling
- Hide state inside loops and conditionals
- Are hard to unit test
- Depend directly on LLM frameworks

This repository takes a **different approach**:

> The LLM suggests — the system decides.

All decisions are driven by a **state machine**, not by the model.

---

## Core ideas

- Explicit **Execution State Machine**
- No retries or branching logic hidden in executors
- LLMs never control execution directly
- Every transition is testable
- Infrastructure and logic are clearly separated

---

## High-level flow

1. Tool call is received (from an LLM or any other source)
2. Input is parsed into a structured representation
3. Tool call is validated against an allowed schema
4. State machine decides whether execution is allowed
5. Tool is executed inside a sandbox
6. Final state is recorded and logged

---

## Architecture overview
LLM / Input
|
v
ToolCallParser
|
v
InputValidator ----> ToolSchema
|
v
StateMachine ----> (Allowed / Aborted)
|
v
ToolExecutor ----> Sandbox
|
v
Final State (Success / Failed)

---

## State Machine

The system is driven by the following states:

- `Idle`
- `Received`
- `Allowed`
- `Executing`
- `Success`
- `Failed`
- `Aborted`

Transitions are **explicit** and controlled via events:
- `onToolReceived`
- `onValidation`
- `onExecution`

This makes it trivial to unit test *every possible path*.

---

## Project structure
src/
├── llm/
│ ├── ToolCall.h
│ ├── ToolCallParser.h
│ └── ToolSchema.h
│
├── validation/
│ ├── InputValidator.h
│ └── ValidationResult.h
│
├── execution/
│ ├── ToolExecutor.h
│ ├── Sandbox.h
│ └── ExecutionResult.h
│
├── state/
│ ├── ExecutionState.h
│ └── StateMachine.h
│
├── logging/
│ └── AuditLogger.h
│
└── main.cpp

---

## What this repository demonstrates

- How to design AI-adjacent systems **without coupling to AI frameworks**
- How to make agent-like behavior **predictable**
- How to design systems that scale to:
  - retries
  - quotas
  - rate limits
  - human approval steps
  - auditability

---

## What this repository is NOT

- Not a full agent framework
- Not an LLM client implementation
- Not production-ready security code

This is an **architectural reference**.

---

## How to extend this project

Some natural next steps:

- Add a `RetryPolicy` driven by the state machine
- Add human-in-the-loop approval states
- Replace `Sandbox` with a real execution environment
- Add unit tests per state transition
- Generate PlantUML diagrams directly from the design

---

## Build

This project assumes **C++17**.

```bash
mkdir build
cd build
cmake ..
make
```

---
## License

MIT License — use it freely for learning, demos, or commercial projects.

---
## Author

Built as part of a personal exploration into modern AI system architecture
from a C++ and systems programming perspective.

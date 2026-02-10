/**
 * @file main.cpp
 * @brief Entry point for the application.
 * @author lePuffin
 * @copyright Copyright (c) 2026 Carlos Estevao
 * @date 2026-01-31
 */

/****** Includes ******/
#include <iostream>
#include "execution/tool_executor.hpp"
#include "llm/tool_call_parser.hpp"
#include "log/audit_logger.hpp"
#include "state/state_machine.hpp"
#include "validation/input_validator.hpp"

/****** Defines ******/
using namespace thecpuffin;
static constexpr const char* TAG = "[Main]";

/****** Functions ******/
// Public

int main() {
    // Initialization phase: Print a message and create the TaskManager.
    std::cout << "Initializing application..." << std::endl;

    ToolSchemaStruct schema{{"echo", "ls"}};
    ToolCallParser   parser;
    InputValidator   validator;
    Sandbox          sandbox;
    ToolExecutor     executor(sandbox);
    StateMachine     sm;
    AuditLogger      logger;

    auto call = parser.Parse("echo:msg=hello");
    sm.OnToolReceived();

    auto v = validator.Validate(call, schema);
    sm.OnValidation(v);

    if (sm.CanExecute()) {
        auto r = executor.Execute(call);
        sm.OnExecution(r);
        logger.Log("Execution finished");
    } else {
        logger.Log("Execution aborted due to validation failure");
    }

    // Cleanup phase: Print a message before exiting.
    std::cout << TAG << " Cleaning up and exiting..." << std::endl;

    return EXIT_SUCCESS;
}

// End of file

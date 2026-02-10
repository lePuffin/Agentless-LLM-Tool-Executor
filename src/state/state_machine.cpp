/**
 * @file: state_machine.cpp
 * @brief: Brief description of the file
 * @author: lePuffin
 * @copyright: Copyright (c) 2026 Carlos Estevao
 * @date: 2026-02-10
 */

/****** Includes ******/
#include "state_machine.hpp"

/****** Namespace ******/
namespace thecpuffin {

/****** Defines ******/

/****** Functions ******/
// Public
ExecState StateMachine::State() const {
    return state_;
}

void StateMachine::OnToolReceived() {
    logger_.Log("Tool received, transitioning to Received state");
    state_ = ExecState::kReceived;
}

void StateMachine::OnValidation(ValidationResult result) {
    logger_.Log("Validation result: " +
                std::string((result == ValidationResult::kAllowed) ? "Allowed" : "Rejected"));
    state_ = (result == ValidationResult::kAllowed) ? ExecState::kAllowed : ExecState::kAborted;
}

bool StateMachine::CanExecute() {
    logger_.Log("Checking if can execute in state: " + std::to_string(static_cast<int>(state_)));
    return state_ == ExecState::kAllowed;
}

void StateMachine::OnExecution(ExecutionResult result) {
    logger_.Log("Execution result: " +
                std::string((result == ExecutionResult::kSuccess) ? "Success" : "Failure"));
    state_ = (result == ExecutionResult::kSuccess) ? ExecState::kSuccess : ExecState::kFailed;
}

// Private

}  // namespace thecpuffin

// End of file

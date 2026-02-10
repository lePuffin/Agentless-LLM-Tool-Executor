/**
 * @file: state_machine.hpp
 * @brief: Brief description of the file
 * @author: lePuffin
 * @copyright: Copyright (c) 2026 Carlos Estevao
 * @date: 2026-02-10
 */

#ifndef _state_machine_hpp_
#define _state_machine_hpp_

/****** Includes ******/
#include "../execution/execution_results.hpp"
#include "../validation/validation_results.hpp"
#include "execution_state.hpp"
#include "log/audit_logger.hpp"

/****** Namespace ******/
namespace thecpuffin {

/****** Defines ******/

/****** Classes ******/

class StateMachine {
  private:
    ExecState   state_ = ExecState::kIdle;
    AuditLogger logger_;

  public:
    StateMachine()  = default;
    ~StateMachine() = default;

    ExecState State() const;

    void OnToolReceived();
    void OnValidation(ValidationResult result);
    void OnExecution(ExecutionResult result);

    bool CanExecute();
};

};  // namespace thecpuffin

#endif  // _state_machine_hpp_

// End of file

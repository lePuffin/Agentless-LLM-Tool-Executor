/**
 * @file: execution_state.hpp
 * @brief: Brief description of the file
 * @author: lePuffin
 * @copyright: Copyright (c) 2026 Carlos Estevao
 * @date: 2026-02-10
 */

#ifndef _execution_state_hpp_
#define _execution_state_hpp_

/****** Includes ******/

/****** Namespace ******/
namespace thecpuffin {

/****** Defines ******/
enum class ExecState {
    kIdle,
    kReceived,
    kValidating,
    kAllowed,
    kExecuting,
    kSuccess,
    kFailed,
    kAborted
};

/****** Classes ******/

class ExecutionState {
  private:
  public:
    ExecutionState()  = default;
    ~ExecutionState() = default;
};

};  // namespace thecpuffin

#endif  // _execution_state_hpp_

// End of file

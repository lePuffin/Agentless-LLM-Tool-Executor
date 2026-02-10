/**
 * @file: tool_executor.hpp
 * @brief: Brief description of the file
 * @author: lePuffin
 * @copyright: Copyright (c) 2026 Carlos Estevao
 * @date: 2026-02-10
 */

#ifndef _tool_executor_hpp_
#define _tool_executor_hpp_

/****** Includes ******/
#include "../llm/tool_call.hpp"
#include "execution_results.hpp"
#include "sandbox.hpp"

/****** Namespace ******/
namespace thecpuffin {

/****** Defines ******/

/****** Classes ******/

class ToolExecutor {
  private:
    Sandbox& sandbox_;

  public:
    explicit ToolExecutor(Sandbox& sandbox);
    ~ToolExecutor() = default;

    ExecutionResult Execute(const ToolCallStruct& call);
};

};  // namespace thecpuffin

#endif  // _tool_executor_hpp_

// End of file

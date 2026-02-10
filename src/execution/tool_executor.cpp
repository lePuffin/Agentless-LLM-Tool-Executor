/**
 * @file: tool_executor.cpp
 * @brief: Brief description of the file
 * @author: lePuffin
 * @copyright: Copyright (c) 2026 Carlos Estevao
 * @date: 2026-02-10
 */

/****** Includes ******/
#include "tool_executor.hpp"

/****** Namespace ******/
namespace thecpuffin {

/****** Defines ******/

/****** Functions ******/
// Public
ToolExecutor::ToolExecutor(Sandbox& sandbox) : sandbox_(sandbox) {
}

ExecutionResult ToolExecutor::Execute(const ToolCallStruct& call) {
    return sandbox_.run(call.tool_name) ? ExecutionResult::kSuccess : ExecutionResult::kFailure;
}

// Private

}  // namespace thecpuffin

// End of file

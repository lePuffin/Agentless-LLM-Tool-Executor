/**
 * @file: tool_call.hpp
 * @brief: Brief description of the file
 * @author: lePuffin
 * @copyright: Copyright (c) 2026 Carlos Estevao
 * @date: 2026-02-10
 */

#ifndef _tool_call_hpp_
#define _tool_call_hpp_

/****** Includes ******/
#include <map>
#include <string>

/****** Namespace ******/
namespace thecpuffin {

/****** Defines ******/
struct ToolCallStruct {
    std::string                        tool_name;
    std::map<std::string, std::string> arguments;
};

/****** Classes ******/

class ToolCall {
  private:
  public:
    ToolCall()  = default;
    ~ToolCall() = default;
};

};  // namespace thecpuffin

#endif  // _tool_call_hpp_

// End of file

/**
 * @file: tool_call_parser.hpp
 * @brief: Brief description of the file
 * @author: lePuffin
 * @copyright: Copyright (c) 2026 Carlos Estevao
 * @date: 2026-02-10
 */

#ifndef _tool_call_parser_hpp_
#define _tool_call_parser_hpp_

/****** Includes ******/
#include <string>
#include "tool_call.hpp"

/****** Namespace ******/
namespace thecpuffin {

/****** Defines ******/

/****** Classes ******/

class ToolCallParser {
  private:
  public:
    ToolCallParser()  = default;
    ~ToolCallParser() = default;

    ToolCallStruct Parse(const std::string& raw);
};

};  // namespace thecpuffin

#endif  // _tool_call_parser_hpp_

// End of file

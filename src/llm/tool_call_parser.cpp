/**
 * @file: tool_call_parser.cpp
 * @brief: Brief description of the file
 * @author: lePuffin
 * @copyright: Copyright (c) 2026 Carlos Estevao
 * @date: 2026-02-10
 */

/****** Includes ******/
#include "tool_call_parser.hpp"

/****** Namespace ******/
namespace thecpuffin {

/****** Defines ******/

/****** Functions ******/
// Public

// Private
ToolCallStruct ToolCallParser::Parse(const std::string& raw) {
    ToolCallStruct call;
    auto           sep = raw.find(':');
    call.tool_name     = raw.substr(0, sep);

    if (sep != std::string::npos) {
        auto arg = raw.substr(sep + 1);
        auto eq  = arg.find('=');
        if (eq != std::string::npos) {
            call.arguments[arg.substr(0, eq)] = arg.substr(eq + 1);
        }
    }
    return call;
}

}  // namespace thecpuffin

// End of file

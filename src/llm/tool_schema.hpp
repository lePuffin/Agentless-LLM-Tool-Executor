/**
 * @file: tool_schema.hpp
 * @brief: Brief description of the file
 * @author: lePuffin
 * @copyright: Copyright (c) 2026 Carlos Estevao
 * @date: 2026-02-10
 */

#ifndef _tool_schema_hpp_
#define _tool_schema_hpp_

/****** Includes ******/
#include <set>
#include <string>

/****** Namespace ******/
namespace thecpuffin {

/****** Defines ******/
struct ToolSchemaStruct {
    std::set<std::string> allowed_tools;

    bool IsAllowed(const std::string& tool) const { return allowed_tools.count(tool) > 0; }
};

/****** Classes ******/

class ToolSchema {
  private:
  public:
    ToolSchema()  = default;
    ~ToolSchema() = default;
};

};  // namespace thecpuffin

#endif  // _tool_schema_hpp_

// End of file

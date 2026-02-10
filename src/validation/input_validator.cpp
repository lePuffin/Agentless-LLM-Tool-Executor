/**
 * @file: input_validator.cpp
 * @brief: Brief description of the file
 * @author: lePuffin
 * @copyright: Copyright (c) 2026 Carlos Estevao
 * @date: 2026-02-10
 */

/****** Includes ******/
#include "input_validator.hpp"

/****** Namespace ******/
namespace thecpuffin {

/****** Defines ******/

/****** Functions ******/
// Public
ValidationResult InputValidator::Validate(const ToolCallStruct&   call,
                                          const ToolSchemaStruct& schema) const {
    return schema.IsAllowed(call.tool_name) ? ValidationResult::kAllowed
                                            : ValidationResult::kRejected;
}

// Private

}  // namespace thecpuffin

// End of file

/**
 * @file: input_validator.hpp
 * @brief: Brief description of the file
 * @author: lePuffin
 * @copyright: Copyright (c) 2026 Carlos Estevao
 * @date: 2026-02-10
 */

#ifndef _input_validator_hpp_
#define _input_validator_hpp_

/****** Includes ******/
#include "../llm/tool_call.hpp"
#include "../llm/tool_schema.hpp"
#include "validation_results.hpp"

/****** Namespace ******/
namespace thecpuffin {

/****** Defines ******/

/****** Classes ******/

class InputValidator {
  private:
  public:
    InputValidator()  = default;
    ~InputValidator() = default;

    ValidationResult Validate(const ToolCallStruct& call, const ToolSchemaStruct& schema) const;
};

};  // namespace thecpuffin

#endif  // _input_validator_hpp_

// End of file

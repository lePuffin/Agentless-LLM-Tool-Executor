/**
 * @file: validation_tests.cpp
 * @brief: Brief description of the file
 * @author: lePuffin
 * @copyright: Copyright (c) 2026 Carlos Estevao
 * @date: 2026-02-10
 */

/****** Includes ******/
#include "llm/tool_call.hpp"
#include "llm/tool_schema.hpp"
#include "validation/input_validator.hpp"
#include "validation/validation_results.hpp"

#include "CppUTest/TestHarness.h"

/****** Defines ******/

/****** Functions ******/
// Test group

// clang-format off
TEST_GROUP(ValidationGroup) {
    void setup() {
        // Code here will be called immediately before each test
    }
    void teardown() {
        // Code here will be called immediately after each test
    }
};
// clang-format on

// Tests
TEST(ValidationGroup, AllowsToolThatIsInSchema) {
    thecpuffin::InputValidator   validator;
    thecpuffin::ToolSchemaStruct schema;
    schema.allowed_tools = {"echo", "ls"};

    thecpuffin::ToolCallStruct call;
    call.tool_name = "echo";

    thecpuffin::ValidationResult result = validator.Validate(call, schema);

    CHECK_TRUE(thecpuffin::ValidationResult::kAllowed == result);
}

TEST(ValidationGroup, RejectsToolThatIsNotInSchema) {
    thecpuffin::InputValidator   validator;
    thecpuffin::ToolSchemaStruct schema;
    schema.allowed_tools = {"echo", "ls"};

    thecpuffin::ToolCallStruct call;
    call.tool_name = "rm";

    thecpuffin::ValidationResult result = validator.Validate(call, schema);

    CHECK_TRUE(thecpuffin::ValidationResult::kRejected == result);
}

TEST(ValidationGroup, RejectsEmptyToolName) {
    thecpuffin::InputValidator   validator;
    thecpuffin::ToolSchemaStruct schema;
    schema.allowed_tools = {"echo", "ls"};

    thecpuffin::ToolCallStruct call;
    call.tool_name = "";

    thecpuffin::ValidationResult result = validator.Validate(call, schema);

    CHECK_TRUE(thecpuffin::ValidationResult::kRejected == result);
}

// End of file

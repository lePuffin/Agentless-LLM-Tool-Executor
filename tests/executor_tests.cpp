/**
 * @file: executor_tests.cpp
 * @brief: Brief description of the file
 * @author: lePuffin
 * @copyright: Copyright (c) 2026 Carlos Estevao
 * @date: 2026-02-10
 */

/****** Includes ******/
#include "execution/execution_results.hpp"
#include "execution/sandbox.hpp"
#include "execution/tool_executor.hpp"
#include "llm/tool_call.hpp"

#include "CppUTest/TestHarness.h"

/****** Defines ******/
using namespace thecpuffin;

/****** Functions ******/
// Test group

// clang-format off
TEST_GROUP(ExecutorGroup) {
    Sandbox sandbox;
    ToolExecutor executor{sandbox};
    
    void setup() {
        // Code here will be called immediately before each test
    }
    void teardown() {
        // Code here will be called immediately after each test
    }
};
// clang-format on

// Tests

TEST(ExecutorGroup, SuccessfulExecutionReturnsSuccess) {
    ToolCallStruct call;
    call.tool_name = "echo";

    auto result = executor.Execute(call);

    CHECK_TRUE(ExecutionResult::kSuccess == result);
}

TEST(ExecutorGroup, FailingToolReturnsFailure) {
    ToolCallStruct call;
    call.tool_name = "fail";

    auto result = executor.Execute(call);

    CHECK_TRUE(ExecutionResult::kFailure == result);
}

// End of file

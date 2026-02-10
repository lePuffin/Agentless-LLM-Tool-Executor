/**
 * @file: state_machine_tests.cpp
 * @brief: Brief description of the file
 * @author: lePuffin
 * @copyright: Copyright (c) 2026 Carlos Estevao
 * @date: 2026-02-10
 */

/****** Includes ******/
#include "execution/execution_results.hpp"
#include "state/execution_state.hpp"
#include "state/state_machine.hpp"
#include "validation/validation_results.hpp"

#include "CppUTest/TestHarness.h"

/****** Defines ******/
using namespace thecpuffin;

/****** Functions ******/
// Test group

// clang-format off
TEST_GROUP(StateMachineGroup) {
    StateMachine sm;

    void setup() {
        // Code here will be called immediately before each test
    }
    void teardown() {
        // Code here will be called immediately after each test
    }
};
// clang-format on

// Tests

TEST(StateMachineGroup, StartsInIdleState) {
    CHECK_TRUE(ExecState::kIdle == sm.State());
}

TEST(StateMachineGroup, MovesToReceivedWhenToolIsReceived) {
    sm.OnToolReceived();

    CHECK_TRUE(ExecState::kReceived == sm.State());
}

TEST(StateMachineGroup, AllowedValidationMovesToAllowedState) {
    sm.OnToolReceived();
    sm.OnValidation(ValidationResult::kAllowed);

    CHECK_TRUE(ExecState::kAllowed == sm.State());
}

TEST(StateMachineGroup, RejectedValidationMovesToAbortedState) {
    sm.OnToolReceived();
    sm.OnValidation(ValidationResult::kRejected);

    CHECK_TRUE(ExecState::kAborted == sm.State());
}

TEST(StateMachineGroup, CanExecuteOnlyWhenAllowed) {
    sm.OnToolReceived();
    sm.OnValidation(ValidationResult::kAllowed);

    CHECK_TRUE(sm.CanExecute());
}

TEST(StateMachineGroup, CannotExecuteWhenAborted) {
    sm.OnToolReceived();
    sm.OnValidation(ValidationResult::kRejected);

    CHECK_FALSE(sm.CanExecute());
}

TEST(StateMachineGroup, SuccessfulExecutionMovesToSuccess) {
    sm.OnToolReceived();
    sm.OnValidation(ValidationResult::kAllowed);
    sm.OnExecution(ExecutionResult::kSuccess);

    CHECK_TRUE(ExecState::kSuccess == sm.State());
}

TEST(StateMachineGroup, FailedExecutionMovesToFailed) {
    sm.OnToolReceived();
    sm.OnValidation(ValidationResult::kAllowed);
    sm.OnExecution(ExecutionResult::kFailure);

    CHECK_TRUE(ExecState::kFailed == sm.State());
}

// End of file

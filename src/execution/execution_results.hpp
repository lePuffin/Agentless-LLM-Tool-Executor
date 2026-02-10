/**
 * @file: execution_results.hpp
 * @brief: Brief description of the file
 * @author: lePuffin
 * @copyright: Copyright (c) 2026 Carlos Estevao
 * @date: 2026-02-10
 */

#ifndef _execution_results_hpp_
#define _execution_results_hpp_

/****** Includes ******/

/****** Namespace ******/
namespace thecpuffin {

/****** Defines ******/
enum class ExecutionResult { kSuccess, kFailure };

/****** Classes ******/

class ExecutionResults {
  private:
  public:
    ExecutionResults()  = default;
    ~ExecutionResults() = default;
};

};  // namespace thecpuffin

#endif  // _execution_results_hpp_

// End of file

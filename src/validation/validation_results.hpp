/**
 * @file: validation_results.hpp
 * @brief: Brief description of the file
 * @author: lePuffin
 * @copyright: Copyright (c) 2026 Carlos Estevao
 * @date: 2026-02-10
 */

#ifndef _validation_results_hpp_
#define _validation_results_hpp_

/****** Includes ******/

/****** Namespace ******/
namespace thecpuffin {

/****** Defines ******/
enum class ValidationResult { kAllowed, kRejected };

/****** Classes ******/

class ValidationResults {
  private:
  public:
    ValidationResults()  = default;
    ~ValidationResults() = default;
};

};  // namespace thecpuffin

#endif  // _validation_results_hpp_

// End of file

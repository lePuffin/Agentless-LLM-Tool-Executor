/**
 * @file: sandbox.hpp
 * @brief: Brief description of the file
 * @author: lePuffin
 * @copyright: Copyright (c) 2026 Carlos Estevao
 * @date: 2026-02-10
 */

#ifndef _sandbox_hpp_
#define _sandbox_hpp_

/****** Includes ******/
#include <string>

/****** Namespace ******/
namespace thecpuffin {

/****** Defines ******/

/****** Classes ******/

class Sandbox {
  private:
  public:
    Sandbox()  = default;
    ~Sandbox() = default;

    bool run(const std::string& tool);
};

};  // namespace thecpuffin

#endif  // _sandbox_hpp_

// End of file

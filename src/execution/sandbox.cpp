/**
 * @file: sandbox.cpp
 * @brief: Brief description of the file
 * @author: lePuffin
 * @copyright: Copyright (c) 2026 Carlos Estevao
 * @date: 2026-02-10
 */

/****** Includes ******/
#include "sandbox.hpp"

/****** Namespace ******/
namespace thecpuffin {

/****** Defines ******/

/****** Functions ******/
// Public
bool Sandbox::run(const std::string& tool) {
    // simula execução
    return tool != "fail";
}

// Private

}  // namespace thecpuffin

// End of file

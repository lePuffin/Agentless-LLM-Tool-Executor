/**
 * @file: audit_logger.cpp
 * @brief: Brief description of the file
 * @author: lePuffin
 * @copyright: Copyright (c) 2026 Carlos Estevao
 * @date: 2026-02-10
 */

/****** Includes ******/
#include "audit_logger.hpp"
#include <iostream>

/****** Namespace ******/
namespace thecpuffin {

/****** Defines ******/

/****** Functions ******/
// Public
void AuditLogger::Log(const std::string& msg) {
    std::cout << "[AUDIT] " << msg << std::endl;
}

// Private

}  // namespace thecpuffin

// End of file

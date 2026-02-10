/**
 * @file: audit_logger.hpp
 * @brief: Brief description of the file
 * @author: lePuffin
 * @copyright: Copyright (c) 2026 Carlos Estevao
 * @date: 2026-02-10
 */

#ifndef _audit_logger_hpp_
#define _audit_logger_hpp_

/****** Includes ******/
#include <string>

/****** Namespace ******/
namespace thecpuffin {

/****** Defines ******/

/****** Classes ******/

class AuditLogger {
  private:
  public:
    AuditLogger()  = default;
    ~AuditLogger() = default;

    void Log(const std::string& msg);
};

};  // namespace thecpuffin

#endif  // _audit_logger_hpp_

// End of file

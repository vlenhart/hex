/*
 * HEX Programming Language
 * Copyright (C) 2013  Yanzheng Li
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, version 3 of the License.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "ast_compound_stmt.h"
#include "ast_target_list.h"
#include "ast_stmt_group.h"

#ifndef _AST_CATCH_STMT_H_
#define _AST_CATCH_STMT_H_

typedef class _HexAstCatchStmt : public _HexAstCompoundStmt {
public:
  _HexAstCatchStmt(HexAstTargetList, char*, HexAstStmtGroup);

  virtual bool reprOK();
private:
  HexAstTargetList _targets;
  char* _alias;
} * HexAstCatchStmt;

#endif /* _AST_CATCH_STMT_H_ */

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

#include "ast_simple_stmt.h"
#include "ast_expr_list.h"

#ifndef _AST_RETURN_STMT_H_
#define _AST_RETURN_STMT_H_

typedef class _HexAstReturnStmt : public _HexAstSimpleStmt {
public:
  _HexAstReturnStmt(HexAstExprList, HexAstExpr);

  virtual bool reprOK();
private:
  HexAstExprList _return_vals;
  HexAstExpr _predicate;
} * HexAstReturnStmt;

#endif /* _AST_RETURN_STMT_H_ */

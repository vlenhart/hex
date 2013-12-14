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

#include "ast_equality_expr.h"
#include "ast_expr.h"
#include "../visitor/ast_visitor.h"

#ifndef _AST_IS_NOT_EXPR_H_
#define _AST_IS_NOT_EXPR_H_

typedef class _HexAstIsNotExpr : public _HexAstEqualityExpr {
public:
  _HexAstIsNotExpr(HexAstExpr lexpr, HexAstExpr rexpr):
    _HexAstEqualityExpr(lexpr, rexpr)
  {
  }

  virtual void accept(AstVisitor* visitor) {
    visitor->visit(this);
  }
} * HexAstIsNotExpr;

#endif /* _AST_IS_NOT_EXPR_H_ */
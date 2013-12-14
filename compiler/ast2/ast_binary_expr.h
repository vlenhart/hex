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

#include <boost/smart_ptr.hpp>
#include "ast_expr.h"
#include "ast_expr_associativity.h"
#include "ast_expr_precedence.h"
#include "../../base/assert.h"

#ifndef _HEX_AST_BINARY_EXPR_H_
#define _HEX_AST_BINARY_EXPR_H_

class _HexAstBinaryExpr : public _HexAstExpr {
public:
  _HexAstBinaryExpr(
    HexAstExpr lexpr,
    HexAstExpr rexpr,
    HexAstExprAssociativity associativity,
    HexAstExprPrecedence precedence
  ):
    _lexpr(lexpr),
    _rexpr(rexpr),
    _HexAstExpr(associativity, precedence)
  {
    this->reprOK();
  }

  virtual void reprOK() {
    HEX_ASSERT(this->lexpr());
    HEX_ASSERT(this->rexpr());

    // Check for precedence.
    HEX_ASSERT(this->lexpr()->precedence() >= this->precedence());
    if(this->rexpr()->associativity() == EXPR_ASSOCIATIVITY_LEFT) {
      HEX_ASSERT(this->rexpr()->precedence() >= this->precedence());
    }
  }

  HexAstExpr lexpr() { return this->_lexpr.get(); }
  HexAstExpr rexpr() { return this->_rexpr.get(); }

protected:
  boost::scoped_ptr<_HexAstExpr> _lexpr;
  boost::scoped_ptr<_HexAstExpr> _rexpr;
};

#endif /* _HEX_AST_BINARY_EXPR_H_ */
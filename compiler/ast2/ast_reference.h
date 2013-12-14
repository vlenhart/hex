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

#include "ast_expr_associativity.h"
#include "ast_expr_precedence.h"
#include "ast_primary.h"

#ifndef _AST_REFERENCE_H_
#define _AST_REFERENCE_H_

typedef class _HexAstReference : public _HexAstPrimary {
public:
  _HexAstReference(
    HexAstExprAssociativity associativity,
    HexAstExprPrecedence precedence
  ):
   _HexAstPrimary(associativity, precedence)
  {
  }
} * HexAstReference;

#endif /* _AST_REFERENCE_H_ */
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

#include "examiner.h"
#include "../../base/assert.h"
#include "ast_commutative_binary_expr.h"


_HexAstCommutativeBinaryExpr::_HexAstCommutativeBinaryExpr(
  HexAstExpr left,
  HexAstExpr right
) :_HexAstBinaryExpr(left, right)
{
}

/*
bool
_HexAstCommutativeBinaryExpr::equals(void* obj)
{
  return this->examine(Examiners::Equals, obj);
}

bool
_HexAstCommutativeBinaryExpr::isomorphic(void* obj)
{
  return this->examine(Examiners::Isomorphic, obj);
}

bool
_HexAstCommutativeBinaryExpr::equivalent(void* obj)
{
  return this->examine(Examiners::Equivalent, obj);
}

bool
_HexAstCommutativeBinaryExpr::examine(Examiner e, void* obj)
{
  if(obj == NULL) return false;

  HexAstCommutativeBinaryExpr that = (HexAstCommutativeBinaryExpr)obj;

  if(this == that) return true;

  bool leftLeft = e->examine(this->left(), that->left());
  bool rightRight = e->examine(this->right(), that->right());
  if(leftLeft == true && rightRight == true) return true;

  bool leftRight = e->examine(this->left(), that->right());
  bool rightLeft = e->examine(this->right(), that->left());
  if(leftRight == true && rightLeft == true) return true;

  return false;
}
*/

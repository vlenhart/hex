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


#include "ast_power_expr.h"
#include "../../base/assert.h"


_HexAstPowerExpr::_HexAstPowerExpr(
  HexAstExpr left,
  HexAstExpr right
): _HexAstBinaryExpr(left, right)
{
}

void*
_HexAstPowerExpr::create(
  HexAstExpr left,
  HexAstExpr right
)
{
  HEX_ASSERT(left);
  HEX_ASSERT(right);

  HexAstPowerExpr obj = new _HexAstPowerExpr(left, right);
  HEX_ASSERT(obj);
  return obj;
}

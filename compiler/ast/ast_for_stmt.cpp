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

#include "ast_for_stmt.h"
#include "ast_target_list.h"
#include "ast_expr_list.h"
#include "ast_expr.h"
#include "ast_stmt_group.h"
#include "../../base/assert.h"

_HexAstForStmt::_HexAstForStmt(
  HexAstTargetList targets,
  HexAstExprList exprs,
  HexAstExpr predicate,
  HexAstStmtGroup stmts
):_targets(targets), _exprs(exprs), _predicate(predicate), _HexAstCompoundStmt(stmts)
{
  this->reprOK();
}

bool
_HexAstForStmt::reprOK()
{
  HEX_ASSERT(this->_targets);
  HEX_ASSERT(this->_exprs);
  HEX_ASSERT(this->_stmts);
}

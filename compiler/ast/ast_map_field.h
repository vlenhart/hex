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

#include "ast_node.h"
#include "ast_expr.h"
#include "ast_val_atom.h"

#ifndef _AST_MAP_FIELD_H_
#define _AST_MAP_FIELD_H_

typedef class _HexAstMapField : public _HexAstNode {
public:
  _HexAstMapField(HexAstExpr, HexAstValAtom);

  virtual bool reprOK();

  static _HexAstMapField* create(HexAstExpr, HexAstValAtom);
private:
  HexAstExpr _key;
  HexAstValAtom _val;
} * HexAstMapField;

#endif /* _AST_MAP_FIELD_H_ */

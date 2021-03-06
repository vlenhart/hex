/*
 * HEX Programming Language
 * Copyright (C) 2012  Yanzheng Li
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

#ifndef _SCOPE_H_
#define _SCOPE_H_

#ifdef __cplusplus
extern "C" {
#endif


/* scope type */
typedef unsigned char hex_scope_type_t;

#define HEX_VAR_SCOPE_TYPE_GLOBAL (hex_scope_type_t)0x0001
#define HEX_VAR_SCOPE_TYPE_LOCAL  (hex_scope_type_t)0x0002
#define HEX_VAR_SCOPE_TYPE_MEMBER (hex_scope_type_t)0x0004


#ifdef __cplusplus
}
#endif

#endif /* _SCOPE_H_ */

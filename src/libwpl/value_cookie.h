/*

-------------------------------------------------------------

Copyright (c) MMXIII-MMXIV Atle Solbakken
atle@goliathdns.no

-------------------------------------------------------------

This file is part of P* (P-star).

P* is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

P* is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with P*.  If not, see <http://www.gnu.org/licenses/>.

-------------------------------------------------------------

*/

#pragma once

#include "types.h"
#include "value_hash.h"
#include "exception.h"
#include "value_list.h"
#include "array.h"

#include <tuple>
#include <memory>
#include <unordered_map>

class wpl_operator_struct;

class wpl_value_cookie : public wpl_value {
	private:

	bool did_parse;
	void parse();

	wpl_value_hash hash;

	// Initialized in .cpp
	static const wpl_type_array type_array;
	static const wpl_type_bool type_bool;
	static const wpl_type_array_instance type_complete_array;

	public:
	PRIMITIVE_TYPEINFO(get)
	wpl_value_cookie(int dummy) :
		hash(&type_complete_array),
		did_parse(false)
	{}
	wpl_value_cookie *clone() const { return new wpl_value_cookie(0); };
	wpl_value_cookie *clone_empty() const { return new wpl_value_cookie(0); };

	int do_operator (
			wpl_expression_state *exp_state,
			wpl_value *final_result,
			const wpl_operator_struct *op,
			wpl_value *lhs,
			wpl_value *rhs
	);
};

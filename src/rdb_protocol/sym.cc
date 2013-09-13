// Copyright 2010-2013 RethinkDB, all rights reserved.
#include "rdb_protocol/sym.hpp"

#include "containers/archive/archive.hpp"
#include "rdb_protocol/error.hpp"

namespace ql {

RDB_IMPL_SERIALIZABLE_1(sym_t, value);

void debug_print(printf_buffer_t *buf, sym_t sym) {
    buf->appendf("var_%" PRIi64 "", sym.value);
}

bool function_emits_implicit_variable(const std::vector<sym_t> &arg_names) {
    return arg_names.size() == 1 && arg_names[0].value >= 0;
}

}  // namespace ql
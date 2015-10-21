// Copyright 2014 MongoDB Inc.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
// http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#include <mongocxx/options/distinct.hpp>
#include <mongocxx/private/read_preference.hpp>

namespace mongocxx {
MONGOCXX_INLINE_NAMESPACE_BEGIN
namespace options {

void distinct::max_time_ms(std::int64_t max_time_ms) {
    _max_time_ms = std::move(max_time_ms);
}

void distinct::read_preference(class read_preference rp) {
    _read_preference = std::move(rp);
}

const bsoncxx::stdx::optional<std::int64_t>& distinct::max_time_ms() const {
    return _max_time_ms;
}
const bsoncxx::stdx::optional<class read_preference>& distinct::read_preference() const {
    return _read_preference;
}

}  // namespace options
MONGOCXX_INLINE_NAMESPACE_END
}  // namespace mongocxx

#include <mongocxx/config/postlude.hpp>
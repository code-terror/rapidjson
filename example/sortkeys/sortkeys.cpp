#include "rapidjson/document.h"
#include "rapidjson/filewritestream.h"
#include <rapidjson/prettywriter.h>

#include <algorithm>
#include <iostream>

using namespace rapidjson;
using namespace std;


struct NameComparator {
    bool operator()(const Value::Member &lhs, const Value::Member &rhs) const {
        return (strcmp(lhs.name.GetString(), rhs.name.GetString()) < 0);
    }
};

int main() {
    Document d(kObjectType);
    Document::AllocatorType &allocator = d.GetAllocator();

    d.AddMember("zeta", Value().SetBool(false), allocator);
    d.AddMember("gama", Value().SetString("test string", allocator), allocator);
    d.AddMember("delta", Value().SetInt(123), allocator);
    d.AddMember("alpha", Value(kArrayType).Move(), allocator);

#if __cplusplus >= 201103L || (!defined(__GLIBCXX__) && (!defined(_MSC_VER) || _MSC_VER >= 1900))
    std::sort(d.MemberBegin(), d.MemberEnd(), NameComparator());

#endif
}

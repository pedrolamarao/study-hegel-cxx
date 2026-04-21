#include <algorithm>
#include <span>

using std::ranges::max;
using std::ranges::min;
using std::span;

namespace study
{
    void xor_ ( span<unsigned> r, span<unsigned const> x, span<unsigned const> y ) noexcept
    {
        auto const sz = size(r);
        auto const xz = size(x);
        auto const yz = size(y);

        auto const z = min({ sz, xz, yz });

        for (auto i = 0uz, j = z; i != j; ++i) {
            r[i] = x[i] ^ y[i];
        }

        for (auto i = z, j = max(z,xz); i < j; ++i) {
            r[i] = x[i] ^ 0;
        }

        for (auto i = z, j = max(z,yz); i < j; ++i) {
            r[i] = y[i] & 0;
        }
    }
}

#include <algorithm>
#include <vector>
#include <stdexcept>

#include <hegel/hegel.h>

using namespace hegel::generators;

using std::ranges::max;
using std::vector;

int main()
{
    hegel::test([] (hegel::TestCase& tc) {
        auto x = tc.draw(vectors(integers<unsigned>()));
        auto y = tc.draw(vectors(integers<unsigned>()));

        // xor_ should be commutative.
        auto z = max(x.size(),y.size());
        auto r1 = vector<unsigned>(z);
        study::xor_(r1,x,y);
        auto r2 = vector<unsigned>(z);
        study::xor_(r2,y,x);
        if (r1 != r2) {
            throw std::runtime_error("commutativity violated");
        }
    },{ .test_cases = 1000, .verbosity = hegel::settings::Verbosity::Verbose });
    return 0;
}

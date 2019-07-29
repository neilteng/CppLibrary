#include <iostream>
#include <iterator>
#include <vector>
#include <utility>

template<typename Range1, typename Range2, typename OutputIterator>
void cartesian_product(Range1 const &r1, Range2 const &r2, OutputIterator out) {
    using std::begin; using std::end;

    for (auto i = begin(r1);i != end(r1); ++i) {
        for (auto j = begin(r2); j != end(r2); ++j) {
            *out++ = std::make_tuple(*i, *j);
        }
    }
}

int main() {
    std::vector<int> a{1,2,3};
    std::vector<char> b{'a','b','c','d','e','f'};

    std::vector<std::tuple<int, char>> c;
    cartesian_product(a, b, back_inserter(c));

    for (auto &&v : c) {
        std::cout << "(" << std::get<int>(v) << "," << std::get<char>(v) << ")";
    }
}
/* 
Prints:

(1,a)(1,b)(1,c)(1,d)(1,e)(1,f)(2,a)(2,b)(2,c)(2,d)(2,e)(2,f)(3,a)(3,b)(3,c)(3,d)(3,e)(3,f)
*/
template<typename T, int N> constexpr int size(T (&)[N]) { return N; }

int main() {
    int M[2] = {1,2};
    int J[3] = {0,1,2};

    std::tuple<int, int> product[size(M) * size(J)];

    cartesian_product(M, J, product);

    for (auto &&v : product) {
        std::cout << "(" << std::get<0>(v) << "," << std::get<1>(v) << ")";
    }
}

/*
The output is:

(1,0)(1,1)(1,2)(2,0)(2,1)(2,2)
 */
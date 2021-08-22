#include <algorithm>
#include <array>
#include <cassert>
#include <chrono>
#include <cmath>
#include <cstring>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <vector>
using namespace std;

// http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2016/p0200r0.html
template<class Fun> class y_combinator_result {
    Fun fun_;
public:
    template<class T> explicit y_combinator_result(T &&fun): fun_(std::forward<T>(fun)) {}
    template<class ...Args> decltype(auto) operator()(Args &&...args) { return fun_(std::ref(*this), std::forward<Args>(args)...); }
};
template<class Fun> decltype(auto) y_combinator(Fun &&fun) { return y_combinator_result<std::decay_t<Fun>>(std::forward<Fun>(fun)); }


template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { os << '{'; string sep; for (const T &x : v) os << sep << x, sep = ", "; return os << '}'; }

void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }
#ifdef NEAL_DEBUG
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#else
#define dbg(...)
#endif


int N, B;
int64_t P;

void run_case(int) {
    vector<string> numbers(N);

    for (int iter = 0; iter < N * B; iter++) {
        int d;
        cin >> d;
        int where = -1;

        if (d == 9) {
            for (int i = 0; i < N; i++)
                if (int(numbers[i].size()) + 1 == B) {
                    where = i;
                    goto finish;
                }
        }

        if (d >= 6) {
            for (int i = 0; i < N; i++)
                if (int(numbers[i].size()) + 2 == B) {
                    where = i;
                    goto finish;
                }
        }

        for (int i = 0; i < N; i++)
            if (int(numbers[i].size()) + 2 < B) {
                where = i;
                goto finish;
            }

        for (int i = 0; i < N; i++)
            if (where < 0 || numbers[i].size() < numbers[where].size())
                where = i;

        finish:
        assert(where >= 0);
        numbers[where] = char('0' + d) + numbers[where];
        cout << where + 1 << endl;
    }
}

int main() {
    int tests;
    cin >> tests;
    cin >> N >> B >> P;

    for (int tc = 1; tc <= tests; tc++) {
        run_case(tc);
        cout << flush;
    }
}

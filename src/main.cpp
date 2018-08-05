#include "webview.hpp"

int main()
{
    lys::view v{"Minimal webview example", "index.html"};

    v.run();
}
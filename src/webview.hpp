#pragma once

#include <webview.h>
#include <string>
#include <string_view>
#include <filesystem>
#include <iostream>
#include <thread>

namespace lys
{
struct view
{
  private:
    std::string adapt_url(std::string local_url)
    {
        std::filesystem::path path = std::filesystem::current_path();
        path /= local_url;
        return std::string{"file://"} + std::string{path.c_str()};
    }

  public:
    view(std::string title, std::string local_url)
        : _title{title}, _local_url{local_url}
    {
        _wv.title = _title.c_str();
        auto path{adapt_url(_local_url)};
        _wv.url = path.c_str();
        std::cout << "adapted_url: " << path.c_str() << '\n';
        _wv.width = 800;
        _wv.height = 600;
        _wv.debug = /* is debug */ 1;
        _wv.resizable = /* is resizable */ 1;

        webview_init(&_wv);
    }

    void run()
    {
        auto start = std::chrono::high_resolution_clock::now();
        while (webview_loop(&_wv, /*blocking */ 0) == 0)
        {
            auto stop = std::chrono::high_resolution_clock::now();
            if (stop - start > std::chrono::seconds{5})
            {
                _wv.title = "asdasdasd";
            }
        }

        webview_exit(&_wv);
    }

  private:
    struct ::webview _wv;
    std::string _title;
    std::string _local_url;
};
} // namespace lys
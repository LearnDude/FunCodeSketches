#include "HTMLStubs.hpp"

#include <string>
#include <string_view>

const std::string_view Stubs::HTMLheader = R"delimiter(
    <!DOCTYPE html>
        <html>
            <head>
                <meta charset = "utf-8">
                <title>"HTML Table View"</title>
            </head>
            <body>
                <p>
                )delimiter";

const std::string_view Stubs::HTMLfooter = R"delimiter(
            </body>
        </html>
)delimiter";

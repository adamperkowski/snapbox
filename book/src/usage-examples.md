# Usage Examples
Below are some simple examples of how to use snapbox.

## GET Request
```jule
// main.jule

use "snapbox"
use "snapbox/header"
use "snapbox/status"
use "std/os"

fn main() {
    let headerMap: header::HeaderMap = {
        header::ACCEPT: "application/json"
    }

    request := snapbox::GET("https://httpbin.org/get").Headers(headerMap)
    response := request.Send()

    if !status::IsSuccess(response.status) {
        print("Request failed with code: ")
        println(response.status)
        os::Exit(1)
    }

    print(response.body)
}
```

See the [examples directory] for a full list of examples.

[examples directory]: https://github.com/adamperkowski/snapbox/tree/main/examples

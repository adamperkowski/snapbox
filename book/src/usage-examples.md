# Usage Examples
Below are some simple examples of how to use snapbox.

## Basic Requests
```jule
// get.jule
use "snapbox"
use "snapbox/header"
use "snapbox/status"

fn main() {
	let headerMap: header::HeaderMap = {
		header::ACCEPT: "application/json",
	}

	request := snapbox::GET("https://httpbin.org/get").Headers(headerMap)
	response := request.Send()

	if !status::IsSuccess(response.status) {
		println("Error: ")
		println(response.status)
	}

	print(response.body)
}

// post.jule
use "snapbox"
use "snapbox/header"
use "snapbox/status"

const DATA = "Hello, World!"

fn main() {
	let headerMap: header::HeaderMap = {
		header::ACCEPT: "application/json",
		header::CONTENT_TYPE: "text/plain",
	}

	request := snapbox::POST("https://httpbin.org/post").Data(DATA).Headers(headerMap)
	response := request.Send()

	if !status::IsSuccess(response.status) {
		println("Error: ")
		println(response.status)
	}

	print(response.body)
}
```

## File Downloading
```jule
// download.jule
use "snapbox"

fn main() {
	snapbox::Download("https://httpbin.org/get", "output.txt") else {
		println(error)
	}
}
```
See the [examples directory] for a full list of examples.

[examples directory]: https://github.com/adamperkowski/snapbox/tree/main/examples

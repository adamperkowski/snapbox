## Index

[Variables](#variables)\
[fn Slice\(headers: HeaderMap\): \[\]str](#slice)\
[type HeaderMap](#headermap)


## Variables

```jule
const ACCEPT = "Accept"
const ACCEPT_CHARSET = "Accept-Charset"
const ACCEPT_ENCODING = "Accept-Encoding"
const ACCEPT_LANGUAGE = "Accept-Language"
const ACCEPT_RANGES = "Accept-Ranges"
const ACCESS_CONTROL_ALLOW_CREDENTIALS = "Access-Control-Allow-Credentials"
const ACCESS_CONTROL_ALLOW_HEADERS = "Access-Control-Allow-Headers"
const ACCESS_CONTROL_ALLOW_METHODS = "Access-Control-Allow-Methods"
const ACCESS_CONTROL_ALLOW_ORIGIN = "Access-Control-Allow-Origin"
const ACCESS_CONTROL_EXPOSE_HEADERS = "Access-Control-Expose-Headers"
const ACCESS_CONTROL_MAX_AGE = "Access-Control-Max-Age"
const ACCESS_CONTROL_REQUEST_HEADERS = "Access-Control-Request-Headers"
const ACCESS_CONTROL_REQUEST_METHOD = "Access-Control-Request-Method"
const AGE = "Age"
const ALLOW = "Allow"
const ALT_SVC = "Alt-Svc"
const AUTHORIZATION = "Authorization"
const CACHE_CONTROL = "Cache-Control"
const CACHE_STATUS = "Cache-Status"
const CDN_CACHE_CONTROL = "CDN-Cache-Control"
const CONNECTION = "Connection"
const CONTENT_DISPOSITION = "Content-Disposition"
const CONTENT_ENCODING = "Content-Encoding"
const CONTENT_LANGUAGE = "Content-Language"
const CONTENT_LENGTH = "Content-Length"
const CONTENT_LOCATION = "Content-Location"
const CONTENT_RANGE = "Content-Range"
const CONTENT_SECURITY_POLICY = "Content-Security-Policy"
const CONTENT_SECURITY_POLICY_REPORT_ONLY = "Content-Security-Policy-Report-Only"
const CONTENT_TYPE = "Content-Type"
const COOKIE = "Cookie"
const DATE = "Date"
const DNT = "Dnt"
const ETAG = "Etag"
const EXPECT = "Expect"
const EXPIRES = "Expires"
const FORWARDED = "Forwarded"
const FROM = "From"
const HOST = "Host"
const IF_MATCH = "If-Match"
const IF_MODIFIED_SINCE = "If-Modified-Since"
const IF_NONE_MATCH = "If-None-Match"
const IF_RANGE = "If-Range"
const IF_UNMODIFIED_SINCE = "If-Unmodified-Since"
const LAST_MODIFIED = "Last-Modified"
const LINK = "Link"
const LOCATION = "Location"
const MAX_FORWARDS = "Max-Forwards"
const ORIGIN = "Origin"
const PRAGMA = "Pragma"
const PROXY_AUTHENTICATE = "Proxy-Authenticate"
const PROXY_AUTHORIZATION = "Proxy-Authorization"
const PUBLIC_KEY_PINS = "Public-Key-Pins"
const PUBLIC_KEY_PINS_REPORT_ONLY = "Public-Key-Pins-Report-Only"
const RANGE = "Range"
const REFERER = "Referer"
const REFERRER_POLICY = "Referrer-Policy"
const RETRY_AFTER = "Retry-After"
const SEC_WEBSOCKET_ACCEPT = "Sec-Websocket-Accept"
const SEC_WEBSOCKET_EXTENSIONS = "Sec-Websocket-Extensions"
const SEC_WEBSOCKET_KEY = "Sec-Websocket-Key"
const SEC_WEBSOCKET_PROTOCOL = "Sec-Websocket-Protocol"
const SEC_WEBSOCKET_VERSION = "Sec-Websocket-Version"
const SERVER = "Server"
const SET_COOKIE = "Set-Cookie"
const STRICT_TRANSPORT_SECURITY = "Strict-Transport-Security"
const TE = "Te"
const TRAILER = "Trailer"
const TRANSFER_ENCODING = "Transfer-Encoding"
const UPGRADE = "Upgrade"
const UPGRADE_INSECURE_REQUESTS = "Upgrade-Insecure-Requests"
const USER_AGENT = "User-Agent"
const VARY = "Vary"
const VIA = "Via"
const WARNING = "Warning"
const WWW_AUTHENTICATE = "Www-Authenticate"
const X_CONTENT_TYPE_OPTIONS = "X-Content-Type-Options"
const X_DNS_PREFETCH_CONTROL = "X-Dns-Prefetch-Control"
const X_FRAME_OPTIONS = "X-Frame-Options"
const X_XSS_PROTECTION = "X-Xss-Protection"
```


## Slice
```jule
fn Slice(headers: HeaderMap): []str
```
Slices a HeaderMap into a \[\]str\.


## HeaderMap
```jule
type HeaderMap = map[str]str
```
The map of headers type used for requests\.

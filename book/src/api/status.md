## Index

[Variables](#variables)\
[fn IsInformational\(code: StatusCode\): bool](#isinformational)\
[fn IsSuccess\(code: StatusCode\): bool](#issuccess)\
[fn IsRedirection\(code: StatusCode\): bool](#isredirection)\
[fn IsClientError\(code: StatusCode\): bool](#isclienterror)\
[fn IsServerError\(code: StatusCode\): bool](#isservererror)\
[type StatusCode](#statuscode)

## Variables

```jule
const CONTINUE: StatusCode = 100
const SWITCHING_PROTOCOLS: StatusCode = 101
const PROCESSING: StatusCode = 102
const OK: StatusCode = 200
const CREATED: StatusCode = 201
const ACCEPTED: StatusCode = 202
const NON_AUTHORITATIVE_INFORMATION: StatusCode = 203
const NO_CONTENT: StatusCode = 204
const RESET_CONTENT: StatusCode = 205
const PARTIAL_CONTENT: StatusCode = 206
const MULTI_STATUS: StatusCode = 207
const ALREADY_REPORTED: StatusCode = 208
const IM_USED: StatusCode = 226
const MULTIPLE_CHOICES: StatusCode = 300
const MOVED_PERMANENTLY: StatusCode = 301
const FOUND: StatusCode = 302
const SEE_OTHER: StatusCode = 303
const NOT_MODIFIED: StatusCode = 304
const USE_PROXY: StatusCode = 305
const TEMPORARY_REDIRECT: StatusCode = 307
const PERMANENT_REDIRECT: StatusCode = 308
const BAD_REQUEST: StatusCode = 400
const UNAUTHORIZED: StatusCode = 401
const PAYMENT_REQUIRED: StatusCode = 402
const FORBIDDEN: StatusCode = 403
const NOT_FOUND: StatusCode = 404
const METHOD_NOT_ALLOWED: StatusCode = 405
const NOT_ACCEPTABLE: StatusCode = 406
const PROXY_AUTHENTICATION_REQUIRED: StatusCode = 407
const REQUEST_TIMEOUT: StatusCode = 408
const CONFLICT: StatusCode = 409
const GONE: StatusCode = 410
const LENGTH_REQUIRED: StatusCode = 411
const PRECONDITION_FAILED: StatusCode = 412
const PAYLOAD_TOO_LARGE: StatusCode = 413
const URI_TOO_LONG: StatusCode = 414
const UNSUPPORTED_MEDIA_TYPE: StatusCode = 415
const RANGE_NOT_SATISFIABLE: StatusCode = 416
const EXPECTATION_FAILED: StatusCode = 417
const IM_A_TEAPOT: StatusCode = 418
const MISDIRECTED_REQUEST: StatusCode = 421
const UNPROCESSABLE_ENTITY: StatusCode = 422
const LOCKED: StatusCode = 423
const FAILED_DEPENDENCY: StatusCode = 424
const UPGRADE_REQUIRED: StatusCode = 426
const PRECONDITION_REQUIRED: StatusCode = 428
const TOO_MANY_REQUESTS: StatusCode = 429
const REQUEST_HEADER_FIELDS_TOO_LARGE: StatusCode = 431
const UNAVAILABLE_FOR_LEGAL_REASONS: StatusCode = 451
const INTERNAL_SERVER_ERROR: StatusCode = 500
const NOT_IMPLEMENTED: StatusCode = 501
const BAD_GATEWAY: StatusCode = 502
const SERVICE_UNAVAILABLE: StatusCode = 503
const GATEWAY_TIMEOUT: StatusCode = 504
const HTTP_VERSION_NOT_SUPPORTED: StatusCode = 505
const VARIANT_ALSO_NEGOTIATES: StatusCode = 506
const INSUFFICIENT_STORAGE: StatusCode = 507
const LOOP_DETECTED: StatusCode = 508
const NOT_EXTENDED: StatusCode = 510
const NETWORK_AUTHENTICATION_REQUIRED: StatusCode = 511
```


## IsInformational
```jule
fn IsInformational(code: StatusCode): bool
```
Checks if a status code is informational\. \(1xx\)

## IsSuccess
```jule
fn IsSuccess(code: StatusCode): bool
```
Checks if a status code is a success\. \(2xx\)

## IsRedirection
```jule
fn IsRedirection(code: StatusCode): bool
```
Checks if a status code is a redirection\. \(3xx\)

## IsClientError
```jule
fn IsClientError(code: StatusCode): bool
```
Checks if a status code is a client error\. \(4xx\)

## IsServerError
```jule
fn IsServerError(code: StatusCode): bool
```
Checks if a status code is a server error\. \(5xx\)

## StatusCode
```jule
type StatusCode: int
```
The status code type used for responses\.
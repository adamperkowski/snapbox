## Index

[fn GET\(url: str\): Request](#get)\
[fn HEAD\(url: str\): Request](#head)\
[fn POST\(url: str\): DataRequest](#post)\
[fn PUT\(url: str\): DataRequest](#put)\
[fn DELETE\(url: str\): DataRequest](#delete)\
[fn Download\(url: str, path: str\)\!](#download)\
[struct Request](#request)\
&nbsp;&nbsp;&nbsp;&nbsp;[fn Send\(\*self\): cpp\.Response](#send)\
&nbsp;&nbsp;&nbsp;&nbsp;[fn Headers\(\*self, headers: header::HeaderMap\): Request](#headers)\
[struct DataRequest](#datarequest)\
&nbsp;&nbsp;&nbsp;&nbsp;[fn Send\(\*self\): cpp\.Response](#send-1)\
&nbsp;&nbsp;&nbsp;&nbsp;[fn Headers\(\*self, headers: header::HeaderMap\): DataRequest](#headers-1)\
&nbsp;&nbsp;&nbsp;&nbsp;[fn Data\(\*self, data: str\): DataRequest](#data)



## GET
```jule
fn GET(url: str): Request
```
Builds a GET request object\.

## HEAD
```jule
fn HEAD(url: str): Request
```
Builds a HEAD request object\.

## POST
```jule
fn POST(url: str): DataRequest
```
Builds a POST request object\.

## PUT
```jule
fn PUT(url: str): DataRequest
```
Builds a PUT request object\.

## DELETE
```jule
fn DELETE(url: str): DataRequest
```
Builds a DELETE request object\.

## Download
```jule
fn Download(url: str, path: str)!
```
Uses the internal C\+\+ function to download a file from the given URL and save it to the given path\.

## Request
```jule
struct Request {
	// NOTE: contains filtered hidden or unexported fields
}
```
Request structure for non\-data requests\.

### Send
```jule
fn Send(*self): cpp.Response
```
Executes the request and returns the response\.

### Headers
```jule
fn Headers(*self, headers: header::HeaderMap): Request
```
Sets headers for the request\.

## DataRequest
```jule
struct DataRequest {
	// NOTE: contains filtered hidden or unexported fields
}
```
Request structure for data requests\.

### Send
```jule
fn Send(*self): cpp.Response
```
Executes the request and returns the response\.

### Headers
```jule
fn Headers(*self, headers: header::HeaderMap): DataRequest
```
Sets headers for the request\.

### Data
```jule
fn Data(*self, data: str): DataRequest
```
Sets data for the request\.